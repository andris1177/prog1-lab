/*
Írj programot, mely B(n, k) binomiális együtthatókat számít. A program olvassa be n és k értékét, majd írja ki B(n, k) értékét, melynek definíciója

            n!
B(n,k) = ---------
         (n-k)! k!

Definíció szerint számolva igen gyorsan túlcsordulhat az egész aritmetika. Ezért az alábbi két algoritmus valamelyike szerint végezd a számítást:
A) Egyszerű, de nem optimális

    B(n, k) = B(n, n-k). Ezt kihasználva k értékét tartsd alacsonyan: B(10, 6) helyett számítsd B(10, 4)-et.
    A faktoriálisokat formálisan kifejtve, majd a triviális egyszerűsítéseket végrehajtva az alábbi tört adódik:

       10!      10 9 8 7
    --------- = --------
    (10-4)! 4!   4 3 2 1
            

    Ha a szorzásokat és osztásokat az alábbi sorrendben végzed (nevező tényezői fordítva)

    10 9 8 7
    -------- = 10 / 1 * 9 / 2 * 8 / 3 * 7 / 4
    4 3 2 1
        

    akkor minden osztás maradék nélkül elvégezhető.

A módszer hátránya, hogy szerencsétlen esetekben részletszámítások túlcsordulhatnak akkor is, ha az eredmény egyébként ábrázolható lenne.
B) Munkás, de nem csordul túl

Az alábbi módszer teljesen kiküszöböli a túlcsordulás problémáját:

    A számláló és a nevező szorzó tényezőit tárold el egy-egy k-elemű tömbben:


    num = {10, 9, 8, 7}
    den = {4, 3, 2, 1}

    Járd be a két tömböt, és végezd el az összes lehetséges számláló/nevező egyszerűsítést. Mivel az eredménynek egésznek kell lennie, biztos lehetsz benne, hogy egyszerűsítések után a nevező tényezőit tartalmazó tömb csupa 1 értéket tárol.


    num = {5, 3, 2, 7}
    den = {1, 1, 1, 1}

    Az eredményt a számláló tömb elemeinek szorzataként számolhatod.

Vedd észre, hogy csak az utolsó lépés elvégzésekor fordulhat elő túlcsordulás. Ezáltal ha az eredmény ábrázolható, akkor az algoritmus helyesen adja meg azt.

Bármelyik algoritmussal számolsz, az alábbiakat tartsd be:

    Lebegőpontos típust nem használhatsz.
    Az eredményt long long unsigned típusban tárold, figyelj a kiírás formátumkódjára!
    A B) módszernél biztos lehetsz benne, hogy 40 elemű tömbökben az összes teszteset együtthatói elférnek.
*/


#include <stdio.h>

#define listSize 40

typedef struct 
{
    int x;
    int y;
} vec2;

int lnko(vec2 data)
{
    while (data.y != 0)
    {
        int c = data.y;
        data.y = data.x % data.y;
        data.x = c;
    }

    return data.x;
}


int main()
{
    int run = 1;
    unsigned long long value, result = 1, k, n;

    scanf("%llu%llu", &n, &k);

     if (k > n) 
    {
        printf("0\n");
        return 0;
    }

    if (k == 0 || k == n) 
    {
        printf("1\n");
        return 0;
    }

    if (k > n - k)
    {
        k = n - k;
    }

    unsigned long long num[listSize], den[listSize];

value = n;
    for (int i = 0; i < k; i++)
    {
        num[i] = value;
        value--;
    }

    value = k;
    for (int i = 0; i < k; i++)
    {
        den[i] = value;
        value--;
    }

    int test = 0;
    while (run)
    {
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                vec2 data = {num[i], den[j]};
                int lnkon = lnko(data);

                if (lnkon > 1)
                {
                    num[i] = num[i] / lnkon;
                    den[j] = den[j] / lnkon;
                }

                else 
                {
                    test = 1;
                }
            }
        }

        if (test)
        {
            run = 0;
        }
    }

    for (int i = 0; i < k; i++)
    {
        result *= num[i];
    }

    printf("%llu\n", result);

    return 0;
}
