#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
    char word[20];
    struct list *next;
};

void add_to_list(struct list **head, char *w)
{
    struct list *n = calloc(1, sizeof(*n));
    strcpy(n->word, w);
    n->next = *head;
    *head = n; 
}

void swap_elements(struct list **head)
{
    int swapped = 1;
    if (*head == NULL) return;
    while(swapped) 
    {
        swapped = 0;
        struct list **curr = head;
        while ((*curr) && (*curr)->next)
        {
            struct list *a = *curr;
            struct list *b = a->next;

            if (strcmp(a->word, b->word) > 0)
            {
                a->next = b->next;
                b->next = a;
                *curr = b;
                swapped = 1;
            }

            curr = &((*curr)->next);
        }
    };
}

void print_list(struct list *head)
{
    while (head) 
    {
        printf("%s ", head->word);
        head = head->next;
    }
}

void delete_list(struct list **head)
{
    while (*head) {
        struct list *t = *head;
        *head = (*head)->next;
        free(t);
    }
}

int main(void)
{
    struct list *head = NULL;
    char buffer[20];
    int i = 0;
    int c;

    while ((c = getchar()) != '.')
    {
        if (c == ' ')
        {
            if (i > 0)
            {
                buffer[i] = '\0';
                add_to_list(&head, buffer);
                i = 0;
            }
        }
        else
        {
            buffer[i++] = c;
        }
    }

    if (i > 0)
    {
        buffer[i] = '\0';
        add_to_list(&head, buffer);
    }

    swap_elements(&head); 
    print_list(head);
    delete_list(&head);
    return 0;
}