/*
Írj függvényt, mely egy egészeket tartalmazó, nem üres bináris keresőfába beszúr egy új elemet! A függvény neve legyen insert, 
először a fa gyökérelemére mutató pointert vegye át, majd a beszúrandó egész értéket. A rekurziót alkalmazó megoldást már láttuk előadáson, 
ezért most rezurzió nélkül, iteratívan oldjuk meg a feladatot! A fa elemei az alábbi típusúak (az ellenőrzőbe ezt nem szabad bemásolni).

typedef struct _node {
    int data;
    struct _node* left;
    struct _node* right;
} node;

A keresőfában az adott elemnél kisebb értékek a left, míg a nagyobbak a right pointer alatt találhatók. Minden érték csak egyszer szerepel – í
gy a függvény nem szúrja be újra az értéket, amennyiben az már megtalálható a fában.
*/

#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node* left;
    struct _node* right;
} node;

void insert(node* root, int v)
{
    while (1)
    {
        if (root->data == v)
        {
            return;
        }

        else if (root->data > v)
        {
            if (root->left == NULL)
            {
                root->left = malloc(sizeof(node));
                root->left->data = v;
                root->left->left = NULL;
                root->left->right = NULL;
                return;
            }
            root = root->left;
        }

        else if (root->data < v)
        {
            if (root->right == NULL)
            {
                root->right = malloc(sizeof(node));
                root->right->data = v;
                root->right->right = NULL;
                root->right->left = NULL;
                return;
            }
            root = root->right;
        }
    }
}