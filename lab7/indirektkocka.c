/*
Írj cube azonosítójú, void visszatérési típusú függvényt, mely paraméterként egy kocka valós oldalhosszát kapja, és paraméterlistán visszaadja a kocka felszínét és térfogatát.

A függvény teszteléséhez az alábbi main-t használd, de az ellenőrzőbe csak a függvényt másold be!

int main()
{
    double sidelength = 3.5;

    // memoriafoglalas az eredmenynek
    double area;
    double volume;

    cube(sidelength, &area, &volume);

    return 0;
}
*/

void cube(double a, double* S, double* V)
{
    *S = 6.0 * a * a;
    *V = a * a * a;
}