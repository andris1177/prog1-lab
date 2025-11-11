/*
Két darab, egész számokat tartalmazó tömb egy-egy halmazként értelmezett, 
a két halmaz metszetét szeretnénk előállítani (azon számok halmazát, amelyek 
mindkét halmaznak elemei), és ezeket a számokat egy új tömbben tárolni. 
A bemeneti tömbök egy értéket legfeljebb egyszer tartalmaznak, és ezt a tulajdonságot 
várjuk a kimeneti tömbtől is. Halmazokról lévén szó a tömbökben az elemek sorrendje nem számít.

Segédfüggvényként implementáld az isin nevű függvényt, 
mely egy tömböt és egy egész értéket kap paraméterül, és eldönti, 
hogy a kapott értéket tartalmazza-e a tömb!

Az előző függvényt felhasználva írd meg az intersection nevű függvényt, 
mely két halmaz metszetét képzi! A függvény az új tömb kezdőcímével térjen vissza, 
annak méretét a paraméterlista végén adja vissza, a paraméterátadás során először az egyik, 
majd a másik tömböt leíró információkat vegye át (ne keverje a kettőt).

Például: [3 4 1 -3 -2 5 2] & [-3 8 4 5 6] -> [4 -3 5] (vagy bármely permutáció, pl. [-3 4 5])
*/

#include <stdio.h>
#include <stdlib.h>

int isin(int* list, int n, int number)
{
    for (int i = 0; i < n; i++)
    {
        if (list[i] == number)
        {
            return 1;
        }
    }

    return 0;
}

int * intersection(int* a, int an, int* b, int bn, int * m)
{
    int lm = 0;

    for (int i = 0; i < an; i++)
    {
        if (isin(b, bn, a[i]))
        {
            lm++;
        }
    }

    int* metszet = (int *)malloc(lm * sizeof(int));

    int index = 0;

    for (int i = 0; i < an; i++)
    {
        if (isin(b, bn, a[i]) && !isin(metszet, index, a[i]))
        {
            metszet[index] = a[i];
            index++;
        }
    }

    *m = index;
    return metszet;
}

int main()
{
    int a[] = {3, 4, 1, -3, -2, 5, 2, 2};
    int b[] = {-3, 8, 4, 5, 6, 2};

    int* result;
    int rlength = 0;
    result = intersection(a, 8, b, 6, &rlength);

    if (rlength != 0)
    {
        for (int i = 0; i < rlength; i++)
        {
            printf("%d ", result[i]);
        }
    }
    printf("\n");
    
    free(result);

    return 0;
}