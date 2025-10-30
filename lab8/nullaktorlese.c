/*
Írj függvényt, mely egy egészekből álló tömböt kap paraméterként, és a nulla értékű tömbelemeket elhagyja a tömbből! A függvény neve remove_zeros legyen, és a tömb helyben történő módosításán túl térjen vissza az átalakított tömb elemeinek számával (tehát a nem nulla elemek számával). A nem nulla elemek olyan sorrendben szerepeljenek az átalakítás után is, mint amilyen sorrendben eredetileg helyezkedtek el egymáshoz képest.

Például az alábbi bemeneti tömb hatására a függvény visszatérési értéke három, és a tömb memóriaképe az alábbiak szerint alakulhat:
1 0 2 0 3 -> 1 2 3 (0 3)

A zárójelbe tett negyedik és ötödik elem praktikusan a korábban ott lévő eredeti értékeket őrzik, azonban ez nem követelmény – a visszatérési érték által meghatározott méreten túl elhelyezkedő elemek érvénytelenné válnak, és a hívó fél nem feltételezhet semmit az ott található memória tartalmáról.

A törlő algoritmus kitatlálásában segíthet az alábbi gondolat: Képzeld el, hogy milyen algoritmussal dolgoznál, ha feladatod az lenne, hogy a bejövő tömb nem nulla elemeit át kell másolnod egy másik tömbbe (ez szerepelt előadáson is). Ugyanezt az algoritmust kövesd, csak a forrás- és céltömb egyezzen meg, vagyis másold a tömb elejébe a megtartandó elemeket. 
*/

int remove_zeros(int* list, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (list[i] == 0)
        {
            for (int j = i; j < length; j++)
            {
                list[j] = list[j+1];
            }
            length--;
        }
    }

    return length;
}

#include <stdio.h>

#define length 5

int main()
{
    int list[length] = {1, 0, 2, 0, 3};
    int modLength;
    modLength = remove_zeros(list, length);
    
    for (int i = 0; i < modLength; i++)
    {
        printf("%d ", list[i]);
    }

    printf("\n");

    return 0;
}