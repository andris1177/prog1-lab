/*
Írj programot, mely beolvas egy pozitív egész számot, és kiírja, hogy Negyzetszam vagy Nem negyzetszam, attól függően, hogy a beolvasott szám négyzetszám-e. A bemenetet nem kell ellenőrizned, biztos lehetsz benne, hogy pozitív egész érkezik.
3 -> Nem negyzetszam
36 -> Negyzetszam
*/ 

#include <stdio.h>

int main()
{
    int number;

    scanf("%d", &number);
    
    for (int i = 0; i * i <= number; i++)
    {
        if (i * i == number)
        {
            printf("Negyzetszam\n");
            return 0;
        }
    }

    printf("Nem negyzetszam\n");  

    return 0;
}
