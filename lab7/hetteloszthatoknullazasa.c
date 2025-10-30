/*
Írj függvényt, mely egy egészekből álló tömböt kap paraméterként, és a héttel osztható tömbelemeket kinullázza! A függvény neve seven_to_zero legyen. 
*/

void seven_to_zero(int* list, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (list[i] % 7 == 0)
        {
            list[i] = 0;
        }
    }
}