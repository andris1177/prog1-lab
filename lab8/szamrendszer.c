/*
Írj függvényt, mely egy karaktertömböt kap paraméterként, melyben egy nemnegatív egész érték található, valamint egy számot (unsigned típusút), mely azt határozza meg, hogy a szám milyen számrendszerben ábrázolt – 
a függvény neve legyen str_to_num, és térjen vissza a stringben található értékkel unsigned típusúvá alakítva! A számrendszer alapja 2<=b<=10, továbbá feltételezhető, hogy a stringben érkező karakterek az 
adott számrendszerben értelmezhetők, illetve a szám az unsigned típus értékkészletének eleme.

Például:
str_to_num("42", 10) -> 42
str_to_num("42", 5) -> 22
*/

#include <stdio.h>
#include <string.h>

unsigned int str_to_num(char str[], unsigned int nums)
{
    int sum = 0;
    int mutlipl = 1;
    for (int i = strlen(str) - 1; i > -1; i--)
    {
        sum += (unsigned int)(str[i] - '0') * mutlipl;
        mutlipl *=nums;
    }

    return sum;
}

int main()
{
    char buffer[1024];
    int nums;

    scanf("%s%d", &buffer, &nums);
    printf("%d\n", str_to_num(buffer, nums));
}