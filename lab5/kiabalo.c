/*
Írj programot, mely a bemenetére érkező szöveget úgy írja ki a kimenetre, hogy minden nagybetűvel kezdődő szót csupa nagybetűssé alakít, a többit változatlanul hagyja. A bemenetre érkező szöveg szavait egyetlen szóköz választja el megymástól. Az elvárt működést az alábbi példa demonstrálja:

Input:     ez EgY pElda A felaDat EGY lehetseges Bemenetere
Output:    ez EGY pElda A felaDat EGY lehetseges BEMENETERE

A megoldásban nem használhatod a ctype.h-t.
*/ 

#include <stdio.h>

int main()
{
    char letter;
    int isWordStart = 1;
    int cap = 0;

    while (scanf("%c", &letter) == 1)
    {
        if (letter == ' ')
        {
            printf("%c", letter);
            isWordStart = 1;
            continue;
        }

        if (isWordStart)
        {
            if (letter >= 'A' && letter <= 'Z') 
            {
                cap = 1;
            } 

            else 
            {
                cap = 0;
            }

            isWordStart = 0;
        }

        if (cap && letter >= 'a' && letter <= 'z') 
        {
            letter = letter - ('a' - 'A');
        }

        printf("%c", letter);
    } 
    return 0;
}
