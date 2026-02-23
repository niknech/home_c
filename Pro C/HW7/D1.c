#include <stdio.h> 
#include "stdlib.h"

typedef int datatype;

typedef struct tree {
datatype key;
struct tree *left, *right;
} tree;

void insert(tree **root, int new_key)
{

    while (*root != NULL)
    {
        if (new_key < (*root)->key)
            root = &((*root)->left);
        else if (new_key > (*root)->key)
            root = &((*root)->right);
        else
            return;
    }

    tree *new_node = calloc(1, sizeof(tree));
    if (new_node == NULL)
        return;

    new_node->key = new_key;
    new_node->left = NULL;
    new_node->right = NULL;

    *root = new_node;
}

void printFromLeft(tree* t)
{
    if (!t) return;
    if (t->left) printFromLeft(t->left);
    printf("%d ", t->key);
}

void printToRight(tree* t)
{
    if (!t) return;
    tree* cur = t->right;
    while (cur)
    {
        printf("%d ", cur->key);
        cur = cur->right;
    }
}

void btUpView(tree *root)
{
    if (!root) return;
    printFromLeft(root);
    printToRight(root);
}

void btUpView(tree *root)
{
    printFromLeft(root);
    printToRight(root);
} 

int main() 
{
    tree* t = NULL;
    int number;  
    char ch;

    while (1)
    {
        if (scanf("%d", &number) != 1)
            break;

        insert(&t, number);

        ch = getchar();

        if (ch == '\n')
            break;
    }

    btUpView(t);
    return 0; 
}

