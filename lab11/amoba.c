/*
Írj függvényt, mely egy 3x3-as, kétdimenziós tömböt kap paraméterként, mely egy tic-tac-toe tábla állását tartalmazza, és eldönti, 
hogy X vagy O megnyerte-e a játékot (valamelyik sorban, oszlopban vagy átlóban egymás mellett áll három 'X' vagy 'O'). 
A tömb char elemeket tartalmaz, az üres helyeket '.' jelzi. A függvény neve legyen check, 
visszatérési értéke pedig 'X', ha X nyert, 'O', ha O, és '\0' karakter, ha egyik játékos sem érte el a győzelmi feltételt.

Például az alábbi bemenetre a függvény visszatérési értéke 'X':

XOO
XXO
X..

*/

#include <stdio.h>

char check(char map[3][3])
{
    int xcount = 0;
    int ocount = 0;

    for (int i = 0; i < 3; i++)
    {
        xcount = 0;
        ocount = 0;

        for (int j = 0; j < 3; j++)
        {
            if (map[j][i] == 'X')
            {
                xcount++;
            }

            else if (map[j][i] == 'O')
            {
                ocount++;
            }
        }   

        if (xcount == 3)
        {
            return 'X';
        }

        else if (ocount == 3)
        {
            return 'O';
        }
    }

    for (int i = 0; i < 3; i++)
    {
        xcount = 0;
        ocount = 0;
        
        for (int j = 0; j < 3; j++)
        {
            if (map[i][j] == 'X')
            {
                xcount++;
            }

            else if (map[i][j] == 'O')
            {
                ocount++;
            }
        }    

        if (xcount == 3)
        {
            return 'X';
        }

        else if (ocount == 3)
        {
            return 'O';
        }
    }

    if (((map[0][0] == 'X' && map[2][2] == 'X') || (map[0][2] == 'X' && map[2][0])) && map[1][1] == 'X')
    {
        return 'X';
    }

    if (((map[0][0] == 'O' && map[2][2] == 'O') || (map[0][2] == 'O' && map[2][0])) && map[1][1] == 'O')
    {
        return 'O';
    }

    return '\0';
}

int main()
{
    char map[3][3] = {
        {'X', 'O', 'O'},
        {'O', 'X', 'X'},
        {'O', 'X', 'X'}
    };

    printf("%c\n", check(map));
}