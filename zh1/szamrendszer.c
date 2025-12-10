/*
Írj value azonosítójú függvényt, mely egy számjegyeket tartalmazó sztringet és egy egész számot (b) kap paraméterként. 
A függvény adja vissza a sztringben ábrázolt szám értékét, feltételezve, hogy azt b alapú számrendszerben jegyezték le. 
Feltételezheted, hogy 2 ≤ b ≤ 10, illetve a sztring csak b-nél kisebb értékű számjegyekből áll.

Ha a függvény paraméterei pl "132" és 4, akkor visszatérési értéke 1 · 42 + 3 · 41 + 2 · 40 = 30. 
A megoldáshoz nem használhatsz könyvtári függvényeket.

Írj teljes programot, melyben a value függvényt meghívod a fenti példa paramétereivel, 
és a visszaadott értékkel térsz vissza az operációs rendszer felé. 
*/

int value(const char* strnum, int sza)
{
    int result = 0;
    int start = 1;
    int count = 0;

    for (; strnum[count] != '\0'; count++);
    count--;

    for (; count >= 0; count--)
    {
        result += (strnum[count] - '0') * start;
        start *= sza;
    }

    return result;
}

int main()
{
    const char* test = "132";
    return value(test, 4);
}