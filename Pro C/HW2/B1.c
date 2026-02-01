#include <stdio.h>
#include "inttypes.h"
#include "stdlib.h"

typedef struct list 
{
    uint64_t address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

list* memlist = NULL;

void insert(list **head, void *address, size_t size, char *comment);
_Bool delete(list **head, void *address);
void printList(list *head);
uint64_t findMaxBlock(list *head);
size_t totalMemoryUsage(list *head);

void* my_malloc(size_t size, const char *file, int line, const char *func)
{
    #undef malloc
    void *ptr = malloc(size);
    #define malloc(X) my_malloc( (X), __FILE__, __LINE__, __FUNCTION__)

    char coment[64] = {0};
    sprintf (coment,"Allocated = %s, %i, %s, %p[%li]", file, line, func, ptr, size);
    insert(&memlist,ptr,size,coment);
    return ptr;
}

void my_free(void *ptr, const char *file, int line, const char *func)
{
    #undef free
    free(ptr);
    delete(&memlist, ptr);
    #define free(X) my_free( (X), __FILE__, __LINE__, __FUNCTION__)
}

int main() 
{
    int *p = malloc(sizeof(int));
    int *ar = malloc(sizeof(int)*10);
    printList(memlist);
    printf("Total size: %d", totalMemoryUsage(memlist));
    return 0; 
}

void insert(list **head, void *address, size_t size, char *comment)
{
    #undef malloc
    list *tmp = malloc(sizeof(list));
    #define malloc(X) my_malloc( (X), __FILE__, __LINE__, __FUNCTION__)

    tmp->next = *head;
    tmp->address = (uint64_t) address;
    tmp->size = size;
    sprintf(tmp->comment,"%s",comment);
    *head = tmp;
}


_Bool delete(list **head, void *address)
{
    if(*head == NULL)
        return 0;
    
    list *del = NULL;
    if((*head)->address == address)
    {
        del = *head;
        *head = (*head)->next;
        free(del);
        return 1;
    }

    list *tmp = *head;
    while( tmp->next ) 
    {
        if( tmp->next->address == address ) 
        {
            del = tmp->next;
            tmp->next = del->next;
            free(del);
            return 1;
        }
        tmp=tmp->next;
    }
    return 0;
}

void printList(list *head)
{
    if(head == NULL) 
        printf("No memory leak detect\n");

    while(head) 
    {
        printf("%s\n",head->comment);
        head = head->next;
    }
}

uint64_t findMaxBlock(list *head)
{
    if(head == NULL) 
        printf("No memory leak detect\n");

    size_t max_size = 0;
    uint64_t max_address = 0;

    while (head)
    {
        if (head->size > max_size)
        {
            max_size = head->size;
            max_address = head->address;
        }

        head = head->next;
    }

    return max_address;
}

size_t totalMemoryUsage(list *head)
{
    if(head == NULL) 
        printf("No memory leak detect\n");

    size_t sum = 0;

    while (head)
    {
        sum += head->size;
        head = head->next;
    }

    return sum;
}