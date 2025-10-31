/*
Írj függvényt, mely egy karakterláncot (sztring) kap paraméterként és visszaadja, hogy hány magánhangzó szerepel benne! A függvény neve legyen count_vowels. A megoldáshoz használd a korábban megírt is_vowel függvényt, azonban ezt ne küldd be értékelésre!

Például: "uborkaleves" -> 5, "Esik az eso!" -> 5
*/

#include <stdio.h>
#include <string.h>

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

int count_vowels(char word[])
{
    int count = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        if (is_vowel(word[i]))
        {
            count++;
        }
    }

    return count;
    
}

int main()
{
    char input[512];
    int count;

    scanf("%s", &input);
    count = count_vowels(input);
    printf("%d\n", count);

    return 0;
}