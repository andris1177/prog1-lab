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
    int len = 0;

    listelem* list;

    listelem* curra = a;
    listelem* currb = b;
    while (curra != NULL)
    {
        while (currb != NULL)
        {
           if(curra->data > currb->data || curra->data == currb->data )
           {
                list = (listelem *)malloc(sizeof(listelem));
                list->data = curra->data;
                list->next = (listelem *)malloc(sizeof(listelem));
                list->data = currb->data;
           }

           if(curra->data < currb->data)
           {
                list = (listelem *)malloc(sizeof(listelem));
                list->data = currb->data;
                list->next = (listelem *)malloc(sizeof(listelem));
                list->data = curra->data;
           }
           currb = currb->next;
        }
        curra = curra->next;
    }
    
    return list;
}

listelem* array_to_list(double arr[], int length)
{
    if (length == 0)
    {
        return NULL;
    }

    listelem* firs;
    listelem* curr;
    listelem* next;

    for (int i = 0; i < length; i++)
    {   
        if (i == 0)
        {
            curr = (listelem *)malloc(sizeof(listelem));
            firs = curr;
        }
        curr->data = arr[i];
        if (i != length - 1)
        {
            next = (listelem *)malloc(sizeof(listelem));
            curr->next = next;
            curr = next;
        }

        else 
        {
            curr->next = NULL;
        }
    }

    return firs;
}

int main()
{
    double a[] = {1.3, 3.2, 4.6, 7.0};
    double b[] = {2.7, 2.9, 5.1};

    listelem* listA = array_to_list(a, 4);
    listelem* listB = array_to_list(b, 3);

    listelem* result = merge(listA, listB);

    while (result != NULL)
    {
        printf("%lf ", result->data);
        result = result->next;
    }
}