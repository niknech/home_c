#include <stdio.h> 

typedef int datatype;

typedef struct tree {
    datatype key;
    struct tree *left, *right;
    struct tree *parent;
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

tree* search_tree_i(tree *root, int key)
{
    tree *find=root;
    while(find && find->key!=key) 
    {
        if(key < find->key)
            find = find->left;
        else
            find = find->right;
    }
    return find;
}

tree* findBrother(tree *root, int key)
{
    tree* node = search_tree_i(root, key);
    if (!node) return 0;
    if (!node->parent) return 0;

    if (node->parent->left == node)
        return node->parent->right;
    else
        return node->parent->left;
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

    return 0; 
} 
