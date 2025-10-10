/*
Írj programot, mely a bemenetére érkező szöveget úgy írja ki a kimenetre, hogy minden nagybetűvel kezdődő szót csupa nagybetűssé alakít, a többit változatlanul hagyja. A bemenetre érkező szöveg szavait egyetlen szóköz választja el megymástól. Az elvárt működést az alábbi példa demonstrálja:

Input:     ez EgY pElda A felaDat EGY lehetseges Bemenetere
Output:    ez EGY pElda A felaDat EGY lehetseges BEMENETERE

A megoldásban nem használhatod a ctype.h-t.
*/ 

#include <stdio.h>

int main()
{
    int toCapital = -32;
    char letter;

    while (scanf("%c", &letter) == 1)
    {
        if (letter > 64 && letter < 91)
        {
            while (letter != 32)
            {
                printf("%c", letter + toCapital);
            }
        }

        else 
        {
            printf("%c", letter);
        }
    }
}
