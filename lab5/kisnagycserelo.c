/*
Írj programot, mely a bemenetére érkező szöveget úgy írja ki a kimenetre, hogy minden nagybetűt kisbetűvé, illetve minden kisbetűt nagybetűvé alakít, a többit változatlanul hagyja. Az elvárt működést az alábbi példa demonstrálja:

Input:     ez Egy ## pElda ? A felaDat EGY lehetseges Bemenetere
Output:    EZ eGY ## PeLDA ? a FELAdAT egy LEHETSEGES bEMENETERE

A megoldásban nem használhatod a ctype.h-t.
*/ 

#include <stdio.h>

int main()
{
    char letter;

    while (scanf("%c", &letter) == 1)
    {
        if (letter <= 'Z' && letter >= 'A')
        {
            printf("%c", letter + ('a' - 'A'));
        }

        else if ( letter <= 'z' && letter >= 'a') 
        {
            printf("%c", letter - ('a' - 'A'));
        }

        else 
        {
            printf("%c", letter);
        }
    }

    return 0;
}
