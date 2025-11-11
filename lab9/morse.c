/*
Írd meg a morse függvényt, mely egy karaktersorozatot kap paraméterként, 
és visszatér annak morzekódjával. A függvény feladata a kódhoz szükséges méretű 
memóriaterület lefoglalása is. A kódolt kimenetben a morzejelek között egy-egy 
szóköznek kell állnia. (Az utolsó morzejel után is állhat szóköz, de el is hagyható.) 
Szóhatáron három szóköznek kell állnia. Feltételezhetjük, hogy a paraméterként kapott 
szövegben a szavak között pontosan egy szóköz áll. A megoldáshoz használd a szövegmezőben 
található kódvázlatot. Azon karakterek, amelyek nem szerepelnek a kódkönyvben, ne 
eredményezzenek morzejelet, egyszerűen maradjanak ki a kódból!
*/

#include <stdio.h>
#include <string.h>

typedef struct 
{
    char letter;
    char code[6];
} codebook_t;

#define CODEBOOKSIZE 37
codebook_t codebook[CODEBOOKSIZE] = 
{
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."}, {'G', "--."},
    {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."},
    {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"}, {'U', "..-"},
    {'V', "...-"}, {'W', "-.."}, {'X', "-..-"}, {'Y', "-.--"}, {'Z', "--.."},
    {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."},
    {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."}, {'0', "-----"}, {' ', " "}
};

char* morse(char* s) 
{
    for (int i = 0; i < strlen(s), i++)
    {
        for (int j = 0; j < sizeof(codebook) / sizeof(codebook_t); j++)
        {
            if (s[i] == codebook[j].letter || s[i] == (codebook[j].letter - ''))
        }
    }
}
