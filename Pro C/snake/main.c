#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncursesw/ncurses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

#define TICK_SEC 0.10
#define CONTROLS 2
#define MAX_FOOD_SIZE 1
#define FOOD_EXPIRE_SECONDS 5

enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME='q'};
enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=10};

struct control_buttons 
{
    int down;
    int up;
    int left;
    int right;
};
struct control_buttons
{
    int down;
    int up;
    int left;
    int right;
} control_buttons;

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
void initSnake(snake_t *head, size_t size, int x, int y);
void initHead(snake_t *head,int x,int y);
void go(struct snake_t *head);
void goTail(struct snake_t *head);
void changeDirection(snake_t* snake, const int32_t key);
int checkReverse(snake_t* snake, const int32_t key);
int checkCrash(snake_t* head);
int checkWallCrash(const snake_t* snake);
void initFood(struct food f[], size_t size);
void refreshFood(struct food f[], int nfood);

int main()
{
    snake_t* snake = (snake_t*)malloc(sizeof(snake_t));
    initSnake(snake,START_TAIL_SIZE,10,10);
    initFood(food, MAX_FOOD_SIZE);
    initscr();
    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
    raw(); // Откдючаем line buffering
    noecho(); // Отключаем echo() режим при вызове getch
    curs_set(FALSE); //Отключаем курсор
    mvprintw(0, 1, "Use arrows for control. Press 'F10' for EXIT");
    timeout(0); //Отключаем таймаут после нажатия клавиши в цикле
    int key_pressed=0;
    clock_t last_tick = clock();
    while( key_pressed != STOP_GAME ) 
    {
        key_pressed = getch(); // Считываем клавишу
        changeDirection(snake, key_pressed);

        clock_t now = clock();
        float elapsed = (float)(now - last_tick) / CLOCKS_PER_SEC;
        if (elapsed >= TICK_SEC)
        {
            last_tick = now;
            go(snake);
            goTail(snake);
        }
        refreshFood(food, 2);
        if (checkCrash(snake) || checkWallCrash(snake))
            break;
    }
    mvprintw(5, 50, "GAME OVER");
    refresh();
    getchar();
    free(snake->tail);
    free(snake);
    endwin(); // Завершаем режим curses mod
    return 0;
}

void initTail(tail_t t[], size_t size)
{
    struct tail_t init_t={0,0};
    for(size_t i=0; i<size; i++)
    {
        t[i]=init_t;
    }
}

void initSnake(snake_t *head, size_t size, int x, int y)
{
    tail_t* tail = (tail_t*) malloc(MAX_TAIL_SIZE*sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head, x, y);
    head->tail = tail; // прикрепляем к голове хвост
    head->tsize = size+1;
    head->controls = default_controls[1];
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
    refresh();
}

void goTail(struct snake_t *head)
{
    char ch = '*';
    mvprintw(head->tail[head->tsize-1].y, head->tail[head->tsize-1].x," ");
    for(size_t i = head->tsize-1; i>0; i--)
    {
        head->tail[i] = head->tail[i-1];
        if(head->tail[i].y || head->tail[i].x)
            mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
    }
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

int checkCrash(snake_t* head)
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
    mvprintw(fp->y, fp->x, "%s", spoint);
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
        if( f[i].put_time)
        {
            if( !f[i].enable || (time(NULL) - f[i].put_time) > FOOD_EXPIRE_SECONDS )
            {
                putFoodSeed(&f[i]);
            }
        }
    }
}