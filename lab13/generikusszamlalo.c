/*
Írj függvényt, mely egy karakterláncot kap paraméterként és egy adott tulajdonságot kielégítő karakterek 
számát adja vissza! Ehhez a stringen kívül egy függvénypointert is átvesz a függvény, 
amely egy adott karakterről eldönti, hogy kielégíti-e a kérdéses tulajdonságot. 
(Ilyen függvény például a korábban implementált is_vowel is.) A függvény neve legyen count_generic.

Például:
count_generic("uborkaleves", is_vowel) -> 5
count_generic("Esik az eso!", is_space) -> 2
*/

#include <string.h>

typedef int (*count)(char);

int count_generic(char str[], count c)
{
    int sum = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        sum += c(str[i]);
    }

    return sum;
}