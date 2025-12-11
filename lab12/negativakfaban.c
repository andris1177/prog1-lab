/*
Írj függvényt, mely megszámolja egy bináris fa azon elemeinek a számát, 
amelyek data változója negatív értéket tartalmaz! A függvény neve legyen negatives.

A fa elemei az alábbi típusúak (az ellenőrzőbe ezt nem szabad bemásolni).

typedef struct _node {
    double data;
    struct _node* left;
    struct _node* right;
} node;

Teszteléshez ötlet: Hozz létre egy gyökérelemet, 
majd egy double típusú tömb elemeit szúrd be a fába az előző feladatban implementált insert függvény segítségével! 
Az elemek sorrendjének változtatásával a fa struktúrája is változik (például egy rendezett tömb olyan fát alakít ki, 
ahol mindig csak az egyik oldalon találhatóak a leszármazó elemek).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    double data;
    struct _node* left;
    struct _node* right;
} node;

void insert(node* root, double v)
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

int negatives(node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int a = 0;

    if (root->data < 0)
    {
        a = 1;
    }

    return negatives(root->left) + negatives(root->right) + a;
}

int main()
{
    node* tree = malloc(sizeof(node));
    tree->data = 3;
    tree->left = NULL;
    tree->right = NULL;
    double list[20] = {
    17.42, -5.13, 42.77, -18.09, 9.58,
    73.04, -31.66, 0.31, 66.89, -44.22,
    28.73, 11.05, -7.91, 59.47, -23.38,
    4.26, 91.12, -12.84, 38.63, -60.57
    };

    for (int i = 0; i < 20; i++)
    {
        insert(tree, list[i]);
    }

    printf("%d\n", negatives(tree));
}