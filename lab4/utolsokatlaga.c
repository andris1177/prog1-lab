/*
Írj programot, mely valós számokat olvas a standard inputról, amíg csak tud, majd kiírja a standard outputra az utoljára beolvasott 10 szám átlagát. Amennyiben a bemeneten kevesebb mint 10 szám érkezik, a program azok átlagát írja ki. Biztos lehetsz benne, hogy a bemeneten legkevesebb egy valós szám érkezik.

A megoldáshoz alkalmazd a ciklikus indexelést! (3. előadás, Tömbös algoritmusok videó)

Az eredményt 3 tizedesre kerekítve írd ki! (%.3f)
*/ 

#include <stdio.h>

#define size 10

int main()
{
    double numbers[size] = {0}, x, sum = 0.0;
    int mten = 0, i;    

    for (i = 1; scanf("%lf", &x) == 1 && i <= size; i++)
    {
        if (i%size == 0)
        {
            i = 0;
            mten = 1;
        }

        numbers[i] = x;
    }
    
    for (int j = 0; j < size; j++)
    {
        sum = sum + numbers[j];
    }

    if (mten)
    {
        printf("%.3lf\n", (double)sum / 10.0);
    }

    else 
    {
        printf("%.3lf\n", sum / (double)(i-1));
    }

    return 0;
}
