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
    if (length <= 0)
    {
        return NULL;
    }

    list_elem* first = (list_elem *)malloc(sizeof(list_elem));
    first->data = arr[length - 1];
    first->next = NULL;
    list_elem* curr = first;
   

    for (int i = length - 2; i > -1; i--)
    {
        curr->next = (list_elem *)malloc(sizeof(list_elem));
        curr = curr->next;
        curr->data = arr[i];
        curr->next = NULL;
    }

    return first;
}

int main()
{
    double arr[] = {};
    list_elem* first;
    first = array_to_list(arr, sizeof(arr) / sizeof(arr[0]));
}