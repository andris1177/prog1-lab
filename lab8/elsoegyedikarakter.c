/*
Írj függvényt, mely egy karaktertömböt kap paraméterként, és visszatér az első egyedi karakter indexével! 
Ha nincs olyan karakter a stringben, amely csak egyszer fordul elő, akkor -1-gyel tér vissza. A függvény neve legyen first_unique.

Például: "alma" -> 1, "baba" -> -1
*/

#include <stdio.h>
#include <string.h>

int first_unique(char str[])
{
    int count[256] = {0};

    for (int i = 0; i < strlen(str); i++)
    {
        count[str[i]]++;
    }

    for (int i = 0; i < strlen(str); i++)
    {
        if (count[(unsigned char)str[i]] == 1)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    char buffer[1024];
    scanf("%s", &buffer);

    printf("%d\n", first_unique(buffer));
}