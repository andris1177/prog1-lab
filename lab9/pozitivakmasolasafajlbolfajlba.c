/*
Írj programot, mely a numbers.txt szöveges fájlban található valós számok közül a 
pozitívokat kiírja a positive_numbers.txt szöveges fájlba! A kiírásnál a számokat 4 
tizedesjegy pontossággal írja ki a program, azok között szóköz szerepeljen. Ha a 
numbers.txt fájl nem található, akkor 1 kóddal térjen vissza.
*/

#include <stdio.h>

int main()
{
    FILE* input = fopen("numbers.txt", "r");
    if (input == NULL)
    {
        return 1;
    }

    FILE* output = fopen("positive_numbers.txt", "w");

    double number;

    while (fscanf(input, "%lf", &number) == 1)
    {
        if (number > 0)
        {
            fprintf(output, "%0.4lf ", number);
        }
    }       

    fclose(input);
    fclose(output);

    return 0;
}