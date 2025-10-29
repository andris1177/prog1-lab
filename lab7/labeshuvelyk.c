/*
Hozz létre imperial azonosítójú struktúra típust hosszúság angolszász mértékegységben való tárolására! A struktúrának két tagja foot és inch legyen, mindkettő előjeles egész. Az angolszász rendszerben egy láb (foot) pontosan 12 hüvelyk (inch), illetve metrikus rendszerbe való átváltása: 1 láb = 0.3048 m.

Írj függvényt (imperial_to_metric), mely paraméterként egy imperial struktúrát kap, és visszatér annak valós méterbe átváltott értékével.

(2,4) --> 0.7112

Írj függvényt (plus), mely két imperial struktúrát kap paraméterként, és visszatér összegükkel! Összegzésnél figyelj arra, hogy az összeg inch tagjának értéke 12-nél kisebb kell, hogy legyen

(3,5) + (4,8) --> (8,1)

Az ellenőrzőbe a struktúra definícióját és a két függvényt kell bemásolnod.
*/

typedef struct 
{
    int foot;
    int inch;
} imperial;

double imperial_to_metric(imperial imp)
{
    return (imp.foot + imp.inch / 12.0) * 0.3048;
}

imperial plus(imperial a, imperial b)
{
    imperial imp = {a.foot + b.foot, a.inch + b.inch};

    imp.foot += imp.inch / 12;
    imp.inch %= 12;
    return imp;
}

/*
Írj programot, mely a standard inputról egész számpárokat olvas be, amíg csak tud. A számpárok tagjai angolszász hosszmértékegység láb és hüvelyk mérőszámai. Minden beolvasott számpárból állíts elő imperial struktúrát, majd azt az előző feladatban megírt imperial_to_metric függvénnyel váltsd át méterbe, és a méter értéket írd ki a standard outputra négy tizedes pontossággal. A standard outputon megjelenő valós értékeket egyetlen szóköz válassza el.

Ha a bemenet például
0 0 1 0
akkor a kimenet legyen
0.0000 0.3048

A struktúra típusdefiníciót és az imperial_to_metric függvényt ne másold be, csak a szükséges include-okat és a main függvényt. 
*/
#include <stdio.h>

int main()
{
    imperial imp;

    while (scanf("%d%d", &imp.foot, &imp.inch) == 2)
    {
        printf("%.4lf ", imperial_to_metric(imp));
    }
    
    return 0;
}