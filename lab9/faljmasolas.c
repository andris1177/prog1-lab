/*
Írj programot, mely beolvassa a standard inputon két szöveges fájl nevét, 
és az első tartalmát átmásolja a másodikba. A fájlnevek nem tartalmaznak 
whitespace karaktereket, és mindkét fájlnév legfeljebb 30 karakter hosszú lehet.
*/

#include <stdio.h>

int main()
{
    char file1[30];
    char file2[20];

    scanf("%s%s", &file1, &file2);

    FILE* file1ptr = fopen(file1, "r");
    if (file1ptr == NULL)
    {
        return -1;
    }

    FILE* file2ptr = fopen(file2, "w");
    if (file2ptr == NULL)
    {
        return -1;
    }

    char buffer[1024];
    while (fgets(buffer, 1024, file1ptr) != 0)
    {
        fputs(buffer, file2ptr);
    }

    fclose(file1ptr);
    fclose(file2ptr);
}