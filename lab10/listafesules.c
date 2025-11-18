/*
Írj függvényt, mely két darab valós számokat tároló (strázsa nélküli) láncolt listát kap paraméterként, melyekben az értékek növekvő sorrendben rendezettek, 
és visszatér egy összefésült listával, mely mindkét lista elemeit tartalmazza növekvő sorrendben!

Például: [1.3-->3.2-->4.6-->7.0] & [2.7-->2.9-->5.1] -> [1.3-->2.7-->2.9-->3.2-->4.6-->5.1-->7.0]

A két lista elemeit kell újraláncolni, a függvény nem módosíthatja a listaelemek adatmezőjét! A függvény fejléce:

listelem* merge(listelem* a, listelem* b);

A listaelemek az alábbi típusúak (nem szabad az ellenőrzőbe másolni):

typedef struct _listelem {
    double data;
    struct _listelem* next;
} listelem;

Teszteléshez segítségként felhasználhatóak az alábbi függvények (aki gyakorolni szeretne, implementálhatja ezeket a függvényeket is):

#include <stdlib.h>

listelem* list_from_array(double t[], int n) {
    listelem* last = NULL;
    int i;
    for (i = n - 1; i >= 0; i--) {
        listelem* new = (listelem*)malloc(sizeof(listelem));
        new->data = t[i];
        new->next = last;
        last = new;
    }
    return last;
}

void free_list(listelem* root) {
    while (root != NULL) {
        listelem* next = root->next;
        free(root);
        root = next;
    }
}

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _listelem {
    double data;
    struct _listelem* next;
} listelem;

listelem* merge(listelem* a, listelem* b)
{
    listelem* first;

    if (a == NULL)
    {
        return b;
    }

    else if (b == NULL)
    {
        return a;
    }

    if (a->data > b->data)
    {
        first = b;
        b = b->next;
    }

    else 
    {
        first = a;
        a = a->next;
    }

    listelem* curr = first;

    while (a != NULL && b != NULL)
    {
        if (a->data > b->data)
        {
            curr->next = b;
            b = b->next;
        }

        else if (a->data < b->data)
        {
            curr->next = a;
            a = a->next;
        }

        else 
        {
            curr->next = b;
            b = b->next;
        }
        
        curr = curr->next;
    }

    if (a == NULL && b != NULL)
    {
        curr->next = b;
    }

    else if (a != NULL && b == NULL)
    {
        curr->next = a;
    }

    return first;
}

listelem* array_to_list(double arr[], int length)
{

    listelem* first = (listelem *)malloc(sizeof(listelem));
    first->data = arr[0];
    first->next = NULL;
    listelem* curr = first;
   

    for (int i = 1; i < length; i++)
    {
        curr->next = (listelem *)malloc(sizeof(listelem));
        curr = curr->next;
        curr->data = arr[i];
        curr->next = NULL;
    }

    return first;
}

void list_free(listelem* first)
{
    while (first != NULL)
    {
        listelem* tmpNext = first->next;
        free(first);
        first = tmpNext;
    }  
}

int main()
{
    double a[] = {8.5, 14.6, 19.8, 20.7, 32.3, 39.4, 43.1, 49.0};
    double b[] = {1.9, 3.6, 13.0, 14.5, 16.4, 27.8, 28.1, 35.7};

    listelem* listA = array_to_list(a, 8);
    listelem* listB = array_to_list(b, 8);

    listelem* result = merge(listA, listB);

    while (result != NULL)
    {
        printf("%lf ", result->data);
        result = result->next;
    }

    printf("\n");

    list_free(result);
}