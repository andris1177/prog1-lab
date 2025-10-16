/*
Írj függvényt, mely egy karaktert kap paraméterként és visszaadja, hogy magánhangzó-e! Elég csak az angol abc betűit kezelni. A függvény neve legyen is_vowel.

Például: 'u' -> 1, 'K' -> 0

Tippek a megoldáshoz:

A függvényben tárolj egy tömböt, melyben felsorolod a magánhangzókat. Járd be a tömböt, és ha találkozol a bemenettel, térj vissza igaz értékkel.

A tömbnek nem kell tartalmaznia a kis és nagy betűket is. A bemenetet alakítsd kisbetűssé (írd felül), és aztán járd be a tömböt. A kisbetűssé alakításhoz akár segédfüggvényt is írhatsz, hiszen ez egy jól megfogható, önmagában is értelmes tevékenység, "funkció". 
*/
#include <stdio.h>

#define vowelsc 5

char lower(char letter)
{
    return letter + ('a' - 'A');
}

int is_vowel(char letter)
{
    char vowels[vowelsc] = { 'a', 'e', 'i', 'o', 'u' };

    if (letter >= 'A' && letter <= 'Z')
    {
        letter = lower(letter);
    }

    for (int i = 0; i < vowelsc; i++)
    {
        if (vowels[i] == letter)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    char letter;

    scanf("%c", &letter);

    printf("%d\n", is_vowel(letter));
}