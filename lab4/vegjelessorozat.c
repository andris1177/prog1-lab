/*
Írj programot, mely egész számokat olvas a bemenetről egészen addig, amíg 0 nem érkezik – ez jelzi a bemenet végét. Ekkor számítsa ki a program, és írja ki két tizedesjegy pontossággal a számok átlagát!

Például: 2 4 5 1 2 0 -> 2.80
*/

#include <stdio.h>

int main()
{
    int x, sum, i;

    while (scanf("%d", &x) == 1 && x != 0)
    {
        sum = sum + x;
        i++;
    }

    printf("%.2f\n", (double)sum/(double)i);
    return 0;
}
