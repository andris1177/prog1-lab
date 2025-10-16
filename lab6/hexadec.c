/*
 Írj programot, mely a bemeneten érkező hexadecimális számot tízes számrendszerben írja ki a képernyőre! A beérkező karaktereket egyesével dolgozhatja csak fel a program, kivételesen nem elfogadható megoldás, ha a scanf függvény az egész számot egyben beolvassa! (Ennek megkísérlése furcsa, megmagyarázhatatlan hibákat eredményez a tesztelés során.) A korábban megírt hexa_value függvényt érdemes használni a megoldásban.

Például: F81 -> 3969

Segítség: A szám hosszát nem ismerjük előre, így egy adott karakter beérkezésekor nem tudjuk azt a tizenhat megfelelő hatványával szorozni. Tegyük fel, hogy már beérkezett a b3c karaktersorozat, és a következő karakter a 2. Vegyük észre, mi a kapcsolat a b3c, b3c0 és b3c2 hexa számok között!

Segítség 2: Ne használj tömböt, a bemenet tetszőlegesen hosszú lehet. Az előző segítségben leírtak alapján rögtön dolgozd fel a beérkező számjegyeket! 
*/
#include <stdio.h>

char lower(char hex)
{
    return hex + ('a' - 'A');
}

int hexa_value(char hex)
{
    if (hex >= 'A' && hex <= 'F')
    {
        hex = lower(hex);
    }

    if (hex >= '0' && hex <= '9')
    {
        return (int)(hex - '0');
    }

    else if (hex >= 'a' && hex <= 'f')
    {
        return 10 + ((int)(hex - 'a'));
    }

    return -1;
}

int main()
{
    char c;
    int sum = 0;

    while (scanf("%c", &c) == 1)
    {
        int result = hexa_value(c);

        if (result < 0)
        {
            break;
        }

        sum = sum * 16 + hexa_value(c);
    }

    printf("%d\n", sum);
}