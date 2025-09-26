#include <stdio.h>
#include <math.h>

int main()
{
    int number;
    scanf("%d", &number);

    float out = sqrt(number);

    if (out == (int)out)
        printf("%s\n", "Negyzetszam");

    else
        printf("%s\n", "Nem negyzetszam");

    return 0;
}
