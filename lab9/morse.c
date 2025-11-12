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
#include <stdlib.h>

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

int isin(char c)
{
    for (int i = 0; i < sizeof(codebook) / sizeof(codebook_t); i++)
    {
        if  (c == codebook[i].letter)
        {
            return i;
        }
    }

    return -1;
}

char* morse(char* s) 
{
    int len = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        int j = isin(s[i]);

        if (s[i] == ' ')
        {
            len += 3;
        }

        else if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
        {
            if (j > -1)
            {
                len += strlen(codebook[j].code);

                if (i + 1 < strlen(s) && s[i + 1] != ' ')
                {
                    len++;
                }
            }
        }
    }

    char* string = (char *)malloc((len + 1) * sizeof(char));
    int index = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        int j = isin(s[i]);

        if (s[i] == ' ')
        {
            for (int k = 0; k < 3; k++)
            {
                string[index] = ' ';
                index++;
            }
        }

        else if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
        {
            if (j > -1)
            {
                for (int k = 0; k < strlen(codebook[j].code); k++)
                {
                    string[index] = codebook[j].code[k];
                    index++;
                }

                if (i + 1 < strlen(s) && s[i + 1] != ' ')
                {
                    string[index++] = ' ';
                }
            }
        }
    }

    string[index] = '\0';

    return string;
}

int main()
{
    char* s = "";
    char* result;
    result = morse(s);

    if (result != NULL)
    {
        printf("%s\n", result);
        printf("%d\n", strlen(result));
    }
}

/*
-----
Test case #1
Input:
A
-----
Your output:
Your output's length is 3 which needs 4 bytes instead of 3.

Correct output:
.-

-----
Test case #2
Input:
AB CD
-----
Your output:
Your output's length is 20 which needs 21 bytes instead of 20.

Correct output:
.- -...   -.-. -..

-----
Test case #3
Input:
EhT_E
-----
Your output:
Your output's length is 6 which needs 7 bytes instead of 6.

Correct output:
. - .

-----
Test case #4
Input:

-----
Your output:
0 bytes were allocated instead of 1 (or 2 if you put space to the end).

Correct output:


-----
Test case #5
Input:
OJ8S44 092OX9 331MJ3
-----
Your output:
102 bytes were allocated instead of 100 (or 101 if you put space to the end).

Correct output:
--- .--- ---.. ... ....- ....-   ----- ----. ..--- --- -..- ----.   ...-- ...-- .---- -- .--- ...--

-----
Test case #6
Input:
3QGSD5CD PW2MJQXM FEU3GVL
-----
Your output:
111 bytes were allocated instead of 109 (or 110 if you put space to the end).

Correct output:
...-- --.- --. ... -.. ..... -.-. -..   .--. -.. ..--- -- .--- --.- -..- --   ..-. . ..- ...-- --. ...- .-..
*/