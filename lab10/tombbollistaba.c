/*
Írj függvényt (array_to_list), mely egy valósakat tartalmazó tömböt kap paraméterként, és a tömb elemeit bemásolja egy listába. 
A listában az elemek a tömb sorrendjéhez képest ellentétes sorrendben szerepeljenek. A függvény az újonnan épített listát adja vissza.

A lista egy elemének és a listapointernek típusdefiníciója:

typedef struct list_elem
{
	double data;
	struct list_elem *next;
} list_elem, *list_ptr;

A lista típusdefiníciót ne másold be az ellenőrzőbe!
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list_elem
{
	double data;
	struct list_elem *next;
} list_elem, *list_ptr;

list_elem* array_to_list(double arr[], int length)
{
    if (length == 0)
    {
        return NULL;
    }

    list_elem* firs;
    list_elem* curr;
    list_elem* next;

    for (int i = length - 1; i > -1; i--)
    {   
        if (i == length - 1)
        {
            curr = (list_elem *)malloc(sizeof(list_elem));
            firs = curr;
        }
        curr->data = arr[i];
        if (i != 0)
        {
            next = (list_elem *)malloc(sizeof(list_elem));
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
    double arr[] = {12,  20, 43, 54, 16, 34};
    list_elem* first;
    first = array_to_list(arr, sizeof(arr) / sizeof(arr[0]));
}