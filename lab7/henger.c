/*
Definiálj adattípust sugarával és magasságával definiált henger tárolására! Az adattípus neve legyen struct henger, de legyen elérhető cylinder azonosítóval is. A sugár mező neve legyen radius, a magasság mező neve legyen height, mindkét mező valós típusú.

Az ellenőrzőbe az új típust és az annak alternatív nevét létrehozó sorokat kell bemásolnod.
*/

typedef struct  henger
{
    double radius;
    double height;
} cylinder;

/*
Írj read_cylinder azonosítójú függvényt, melynek visszatérési értéke egy henger. A függvény nem kap paramétert, a visszaadandó henger szóközökkel elválasztott adatait (sugár, majd magasság) a standard inputról olvassa be.

Írj cylinder_volume azonosítójú függvényt, mely paraméterként egy hengert kap, és kiszámolja annak térfogatát.

π pontos ábrázolásához illeszd be a math.h-t, majd használd az M_PI azonosítót. Megjegyzés: Az M_PI azonosító nem szabványos, de nagyon elterjedt, majdnem minden fordító math.h-ja definiálja. Bizonyos fordítóverziók csak akkor, ha a math.h beillesztése előtt beírod, hogy #define _USE_MATH_DEFINES:

#define _USE_MATH_DEFINES
#include <math.h>

Az ellenőrzőbe csak a függvényeket másold be, a struktúra típust definiáló sorokat ne. 
*/

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

struct henger read_cylinder()
{
    double radius;
    double height;

    scanf("%lf%lf", &radius, &height);

    return (struct henger){radius, height};
}

double cylinder_volume(struct henger h)
{
    return M_PI * (h.radius * h.radius) * h.height;
}

/*
Írj főprogramot (main), mely az előző feladatok típusát és függvényeit használva a standard inputról feltölt egy hengereket tartalmazó 10 elemű tömböt, majd fordított sorrendben, egy-egy szóközzel elválasztva, két tizedes pontossággal kiírja a standard outputra a hengerek térfogatait!

A main függvény a henger típust kezelje fekete dobozként! Ez alatt azt értjük, hogy a main nem nyúl a henger változók mezőihez, hanem a hengerműveleteket 100%-ban a korábban megírt függvényekre bízza. Az ellenőrzőbe csak a main függvényt másold be! 
*/

int main()
{
    struct henger hengerek[10];

    for (int i = 0; i < 10; i++)
    {
        hengerek[i] = read_cylinder();
    }

    for (int i = 9; i > -1; i--)
    {
        printf("%.2lf ", cylinder_volume(hengerek[i]));
    }

    return 0;
}