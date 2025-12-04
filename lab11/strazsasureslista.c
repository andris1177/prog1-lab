/*
Egészek tárolására alkalmas kétstrázsás láncolt listát szeretnénk készíteni.

Hozd létre a listaelemek típusát listelem néven! A listaelemben tárolt érték a data, míg a következő elem a next taggal legyen elérhető.

Az empty pointer mutasson egy logikailag üres listára!

A feladatod egy kódrészlet létrehozása, mely a típusdefiníciót és az üres lista létrehozását tartalmazza. Amit beküldesz, 
azt a tesztelő program a saját main függvényébe illeszti. Ez azt jelenti, hogy a típusdefiníció is main-be kerül, de ez legális, 
lokális típust eredményez. Ne include-olj header fájlokat. Az stdlib.h-t a tesztelő include-olja. 
*/

#include <stdlib.h>

int main()
{
    typedef struct listelem
    {
        int data;
        struct listelem* next;
    } listelem;

    listelem* empty = malloc(sizeof(listelem));
    empty->next = malloc(sizeof(listelem));
    empty->next->next = NULL;
}