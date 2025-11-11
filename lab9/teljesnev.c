/*
Írj függvényt, mely egy személy vezeték- és keresztnevét kapja paraméterként, és visszatér a teljes névvel. Az eredmény számára megfelelő méretű karaktertömb foglalása is a függvény feladata. A függvény neve concatenate legyen.

Nem használhatod a string.h függvényeit.
*/

#include <stdio.h>
#include <stdlib.h>

char* concatenate(char a[], char b[])
{
    int alen = 0;
    int blen = 0;

    for (int i = 0; a[i] != '\0'; i++)
    {
        alen++;
    }

    for (int i = 0; b[i] != '\0'; i++)
    {
        blen++;
    }

    char* str = (char *)malloc((alen + 1 + blen + 1) * sizeof(char));

    for (int i = 0; i < alen; i++)
    {
        str[i] = a[i];
    }

    str[alen] = ' ';

    for (int i = 0; i < blen; i++)
    {
        str[alen + 1 + i] = b[i];
    }

    str[alen + 1 + blen] = '\0';

    return str;
}

int main()
{
    char n1[] = "Example";
    char n2[] = "Xample";

    printf("%s\n", concatenate(n1, n2));
    return 0;
};