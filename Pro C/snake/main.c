#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include <time.h>
#include <ncursesw/ncurses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

#define DELAY 0.05
#define CONTROLS 2
#define MAX_FOOD_SIZE 10
#define FOOD_EXPIRE_SECONDS 5
#define PLAYERS 2

enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME='q'};
enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=3};

struct control_buttons 
{
    int down;
    int up;
    int left;
    int right;
};

struct control_buttons default_controls [CONTROLS]= {{KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT},
{'s', 'w', 'a', 'd'}};

typedef struct tail_t
{
    int x;
    int y;
} tail_t;


typedef struct snake_t
{
    int x;
    int y;
    int direction;
    size_t tsize;
    struct tail_t *tail;
    struct control_buttons controls;
    int id;
} snake_t;

struct food
{
    int x;
    int y;
    time_t put_time;
    char point;
    uint8_t enable;
} food[MAX_FOOD_SIZE];

void initTail(tail_t t[], size_t size);
void initSnake(snake_t *head[], size_t size, int x, int y,int i);
void initHead(snake_t *head,int x,int y);
void go(struct snake_t *head);
void goTail(struct snake_t *head);
void changeDirection(snake_t* snake, const int32_t key);
int checkReverse(snake_t* snake, const int32_t key);
int isCrush(snake_t* head);
int checkWallCrash(const snake_t* snake);
void initFood(struct food f[], size_t size);
void refreshFood(struct food f[], int nfood);
_Bool haveEat(struct snake_t *head, struct food f[]);
void addTail (snake_t* head);
void repairSeed(struct food f[], size_t nfood, snake_t *head);
void update(snake_t* head, struct food f[], int key_pressed);
void autoChangeDirection(snake_t *snake, struct food food[], int foodSize);
void setColor(int objectType);
void printTailSize(snake_t* snake);

int main()
{
    initscr();
    if (has_colors())
    {
        start_color();
        init_pair(1, COLOR_RED,   COLOR_BLACK);  // snake1
        init_pair(2, COLOR_BLUE,  COLOR_BLACK);  // snake2
        init_pair(3, COLOR_GREEN, COLOR_BLACK);  // food
    }
    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
    raw(); // Откдючаем line buffering
    noecho(); // Отключаем echo() режим при вызове getch
    curs_set(FALSE); //Отключаем курсор
    mvprintw(0, 1, "Use arrows for control. Press 'F10' for EXIT");
    timeout(0); //Отключаем таймаут после нажатия клавиши в цикле
    snake_t* snakes[PLAYERS];
    for (int i=0; i < PLAYERS; i++)
        initSnake(snakes,START_TAIL_SIZE,10+i*10,10+i*10,i);
    initFood(food, MAX_FOOD_SIZE);
    int key_pressed=0;
    int game_over = 0;

    while(key_pressed != STOP_GAME && !game_over) 
    {
        key_pressed = getch(); // Считываем клавишу
        
        for (int i=0; i<PLAYERS; i++)
        {
            update(snakes[i], food, key_pressed);
            if (isCrush(snakes[i]) || checkWallCrash(snakes[i]))
            {
                game_over = 1;
                break;
            }
            repairSeed(food, MAX_FOOD_SIZE, snakes[i]);
        }
    }
    mvprintw(5, 50, "GAME OVER");
    refresh();
    getchar();
    for (int i = 0; i < PLAYERS; i++)
    {
        free(snakes[i]->tail);
        free(snakes[i]);
    }
    endwin(); 
    return 0;
}

void update(snake_t* head, struct food f[], int key_pressed)
{
    changeDirection(head, key_pressed);
    clock_t begin = clock();
    go(head);
    if (haveEat(head, food))
    {
        addTail(head);
        printTailSize(head);
    }
    goTail(head);
    refreshFood(food, MAX_FOOD_SIZE);
    
    while ((double)(clock() - begin)/CLOCKS_PER_SEC<DELAY);
}

void initTail(tail_t t[], size_t size)
{
    struct tail_t init_t={0,0};
    for(size_t i=0; i<size; i++)
    {
        t[i]=init_t;
    }
}

void initSnake(snake_t *head[], size_t size, int x, int y,int i)
{
    head[i] = (snake_t*)malloc(sizeof(snake_t));
    tail_t* tail = (tail_t*) malloc(MAX_TAIL_SIZE*sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head[i], x, y);
    head[i]->tail = tail; // прикрепляем к голове хвост
    head[i]->tsize = size+1;
    head[i]->controls = default_controls[i];
    head[i]->id = i;
}

void initHead(snake_t *head,int x,int y)
{
    head->x = x;
    head->y = y;
    head->direction = RIGHT;
}

/* Движение головы с учетом текущего
направления движения */
void go(struct snake_t *head)
{
    char ch = '@';
    mvprintw(head->y, head->x, " "); //очищаем один символ
    setColor(head->id+1);
    switch (head->direction)
    {
        case LEFT:
            mvprintw(head->y, --(head->x), "%c", ch);//добавить проверку выхода
            break;
        case RIGHT:
            mvprintw(head->y, ++(head->x), "%c", ch);
            break;
        case UP:
            mvprintw(--(head->y), head->x, "%c", ch);
            break;
        case DOWN:
            mvprintw(++(head->y), head->x, "%c", ch);
            break;
        default:
            break;
    }
    attrset(A_NORMAL);
    refresh();
}

void goTail(struct snake_t *head)
{
    char ch = '*';
    mvprintw(head->tail[head->tsize-1].y, head->tail[head->tsize-1].x," ");
    setColor(head->id+1);
    for(size_t i = head->tsize-1; i>0; i--)
    {
        head->tail[i] = head->tail[i-1];
        if(head->tail[i].y || head->tail[i].x)
            mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
    }
    attrset(A_NORMAL);
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;
}

void changeDirection(snake_t* snake, int32_t key)
{
    if (checkReverse(snake, key))
    {
        if (key == snake->controls.down)
            snake->direction = DOWN;
        else if (key == snake->controls.up)
            snake->direction = UP;
        else if (key == snake->controls.right)
            snake->direction = RIGHT;
        else if (key == snake->controls.left)
            snake->direction = LEFT;
    }
}

int checkReverse(snake_t* snake, int32_t key)
{
    if ((snake->direction == LEFT || snake->direction == RIGHT) && (key != snake->controls.up && key != snake->controls.down))
        return 0;
    if ((snake->direction == UP || snake->direction == DOWN) && (key != snake->controls.left && key != snake->controls.right))
        return 0;
    return 1;
}

int isCrush(snake_t* head)
{
    for (size_t i=1; i<head->tsize; i++)
        if (head->x == head->tail[i].x && head->y == head->tail[i].y)
            return 1;
    
    return 0;
}

int checkWallCrash(const snake_t* snake)
{
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    if (snake->x < 0 || snake->x >= max_x)
        return 1;

    if (snake->y < 0 || snake->y >= max_y-1)
        return 1;

    return 0;
}

void initFood(struct food f[], size_t size)
{
    struct food init = {0,0,0,0,0};
    int max_y=0, max_x=0;
    getmaxyx(stdscr, max_y, max_x);
    for(size_t i=0; i<size; i++)
    {
        f[i] = init;
    }
}

void putFoodSeed(struct food *fp)
{
    int max_x=0, max_y=0;
    char spoint[2] = {0};
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(fp->y, fp->x, " ");
    fp->x = rand() % (max_x - 1);
    fp->y = rand() % (max_y - 2) + 1; //Не занимаем верхнюю строку
    fp->put_time = time(NULL);
    fp->point = '$';
    fp->enable = 1;
    spoint[0] = fp->point;
    setColor(3); 
    mvprintw(fp->y, fp->x, "%s", spoint);
    attrset(A_NORMAL); 
}

void putFood(struct food f[], size_t number_seeds)
{
    for(size_t i=0; i<number_seeds; i++)
    {
        putFoodSeed(&f[i]);
    }
}

void refreshFood(struct food f[], int nfood)
{
    int max_x=0, max_y=0;
    char spoint[2] = {0};
    getmaxyx(stdscr, max_y, max_x);
    for(size_t i=0; i<nfood; i++)
    {
        if( !f[i].put_time || !f[i].enable || (time(NULL) - f[i].put_time) > FOOD_EXPIRE_SECONDS )
        {
            putFoodSeed(&f[i]);
        }
    }
}

_Bool haveEat(snake_t *head, struct food f[])
{
    for (size_t i=0; i<MAX_FOOD_SIZE; i++)
    {
        if (f[i].enable && f[i].x == head->x && f[i].y == head->y)
        {
            f[i].enable = 0;
            return 1;
        }
    }
    return 0;
}

void addTail (snake_t* head)
{
    if (head->tsize < MAX_TAIL_SIZE)
        head->tsize++;
}

void repairSeed(struct food f[], size_t nfood, snake_t *head)
{

    for (size_t j = 0; j < nfood; j++)
    {
        if (!f[j].enable) continue;

        if (f[j].x == head->x && f[j].y == head->y) {
            putFoodSeed(&f[j]);
            j--;
            continue;
        }

        for (size_t i = 0; i < head->tsize; i++)
        {
            if (f[j].x == head->tail[i].x && f[j].y == head->tail[i].y)
            {
                putFoodSeed(&f[j]);
                j--;
                break;
            }
        }
    }

    for (size_t i = 0; i < nfood; i++)
    {
        if (!f[i].enable) continue;

        for (size_t j = i + 1; j < nfood; j++)
        {
            if (!f[j].enable) continue;

            if (f[i].x == f[j].x && f[i].y == f[j].y)
            {
                putFoodSeed(&f[j]);
                j--;
            }
        }
    }
}

//======Добавление ИИ========================================================

int distance(const snake_t snake, const struct food food) {   // вычисляет количество ходов до еды
    return (abs(snake.x - food.x) + abs(snake.y - food.y));
}

//Для автоизменения направления напишем функцию
//Она определяет ближайшую к себе еду и движется по направлению к ней
void autoChangeDirection(snake_t *snake, struct food food[], int foodSize)
{
    int pointer = 0;
    for (int i = 1; i < foodSize; i++) {   // ищем ближайшую еду
        pointer = (distance(*snake, food[i]) < distance(*snake, food[pointer])) ? i : pointer;
    }
    if ((snake->direction == RIGHT || snake->direction == LEFT) &&
        (snake->y != food[pointer].y)) {  // горизонтальное движение
        snake->direction = (food[pointer].y > snake->y) ? DOWN : UP;
    } else if ((snake->direction == DOWN || snake->direction == UP) &&
               (snake->x != food[pointer].x)) {  // вертикальное движение
        snake->direction = (food[pointer].x > snake->x) ? RIGHT : LEFT;
    }
}

void setColor(int objectType)
{
    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(2));
    attroff(COLOR_PAIR(3));
    switch (objectType)
    {
        case 1:
        { // SNAKE1
            attron(COLOR_PAIR(1));
            break;
        }
        case 2:
        { // SNAKE2
            attron(COLOR_PAIR(2));
            break;
        }
        case 3:
        { // FOOD
            attron(COLOR_PAIR(3));
            break;
        }
    }
}

void printTailSize(snake_t* snake)
{
    char str[100];
    snprintf(str, sizeof(str), "%s%zu", "LEVEL ", snake->tsize);
    setColor(snake->id+1);
    mvprintw(0, 48+snake->id*12, str);
    attrset(A_NORMAL); 
}