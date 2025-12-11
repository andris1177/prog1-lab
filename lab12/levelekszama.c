/*
Írj függvényt, mely megszámolja egy bináris fa levélelemeinek a számát! 
A függvény neve legyen leaf_nodes. Levélelem az, amelynek bal és jobb mutatója is NULL értékű. 
A fa elemei az alábbi típusúak (az ellenőrzőbe ezt nem szabad bemásolni):

typedef struct _node {
    int data;
    struct _node* left;
    struct _node* right;
} node;
*/

#include <stdio.h>

#include "beszureasfaba.c"

typedef struct _node {
    int data;
    struct _node* left;
    struct _node* right;
} node;

int leaf_nodes(node* root)
{

    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    
    return leaf_nodes(root->left) + leaf_nodes(root->right);
}

int main()
{
    node* tree = malloc(sizeof(node));
    tree->data = 5;
    tree->left = NULL;
    tree->right = NULL;
    int list[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++)
    {
        insert(tree, list[i]);
    }
    printf("%d\n" ,leaf_nodes(tree));
}