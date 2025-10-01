/*
Írj programot, mely kiírja a standard outputra a standard inputon érkező legnagyobb negatív és legkisebb pozitív számot. A standard inputon white space karakterekkel elválasztott egész számok érkeznek végjel nélkül. A program addig olvasson, amíg csak tud. Ha a bemeneten nem érkezik az adott feltételnek megfelelő szám (pl. nem jön egy pozitív sem), a program a kimenetre --- jelet írjon. Az elvárt kimenetet az alábbi példák demonstrálják:


	Input:  2 4 -3 1 -5 8
	Output: -3 1

	Input:  22 0 5 4 7
	Output: --- 4
	
	Input:  0
	Output: --- ---

*/ 

#include <stdio.h>

int main()
{
    int x, maxneg, minpos, maxnegset = 0, minposset = 0;

    while (scanf("%d", &x) == 1)
    {
        if (x < 0 && (!maxnegset || maxneg < x))
        {
            maxneg = x;
            maxnegset = 1;
        }

        else if (x > 0 && (!minposset || minpos > x))
        {
            minpos = x;
            minposset = 1;
        }
    }

    if (maxnegset)
    {
        printf("%d ", maxneg);
    }

    else 
    {
        printf("--- ");
    }

    if (minposset)
    {
        printf("%d\n", minpos);
    }

    else 
    {
        printf("---\n");
    }

    return 0;
}
