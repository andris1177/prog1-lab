/*
Írj függvényt, mely egy átvett, valósakat tartalmazó, nem üres tömb legkisebb és legnagyobb elemét paraméterlistán adja vissza! 
A függvény neve legyen minmax. Mivel a függvény a paraméterlistán adja vissza az értékeket, visszatérési értékének típusa void. 
A paraméterlistán először történjen meg a tömb átvétele, majd a minimum és végül a maximum visszaadásához szükséges paraméterek átvétele. 
*/

#include <stdio.h>

void minmax(double list[], int n, double* min, double* max)
{
    double fmin = list[0];
    double fmax = list[0];
    for (int i = 0; i < n; i++)
    {
        if (list[i] < fmin)
        {
            fmin = list[i];
        }

        else if (list[i] > fmax)
        {
            fmax = list[i];
        }
    }

    *min = fmin;
    *max = fmax;
}

int main()
{
    double list[] = {10.3, 1.2, 23.4, 45.7};
    double min, max;
    minmax(list, sizeof(list) / sizeof(double), &min, &max);
    printf("%lf, %lf\n", min, max);
    return 0;
}