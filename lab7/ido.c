/*
Hozz létre struct time azonosítójú struktúra típust időpont tárolására. A struktúra típus legyen elérhető az egyszavas time típusnévvel is! Három előjeles egész mezőjének azonosítói legyenek hour, min, sec. Az hour mező értékkészlete: [0, 23], vagyis a time típus csak egy napon belüli időpontokat tud tárolni.

Írj time2sec azonosítójú függvényt, mely paraméterként egy időpontot kap, és visszaadja az éjféltől (00:00:00) addig eltelt másodpercek számát.

Írj sec2time azonosítójú függvényt, mely paraméterként az éjfél óta eltelt másodpercek számát kapja, és visszaadja a megfelelő időpont struktúrát. A függvény működjön 86400-nál nagyobb és negatív bemenetre is, ekkor az időpontok csorduljanak túl, vagyis

    sec2time( 1000) -> {00:16:40}
    sec2time(86400) -> {00:00:00}
    sec2time(-3600) -> {23:00:00}

A fenti függvények hívását mutatja az alábbi main függvény. Ezt használhatod fejlesztésre (debuggerrel!), de az ellenőrzőbe csak a típust és a függvényeket másold be!

int main(void)
{
    time t1 = {2, 5, 0};
    int d = time2sec(t1);       // 7500
    time t2 = sec2time(6002);   // 1:40:02
    time t3 = sec2time(-600);   // 23:50:00
    return 0;
}
*/

typedef struct time
{
    int hour;
    int min;
    int sec;
} time;

int time2sec(time t)
{
    return ((t.hour * 60) * 60) + (t.min * 60) + t.sec;
}

time sec2time(int sec)
{
    time t;

    int day = 24 * 3600;

    sec = (sec % day + day) % day; 

    t.hour = sec / 3600;
    t.min = (sec % 3600) / 60;
    t.sec = sec % 60;

    return t;
}

/*
Írj timeplus azonosítójú függvényt, mely összead két paraméterként kapott időpontot, és visszaadja az eredményként kapott időpont struktúrát. A legegyszerűbben úgy járhatsz el, hogy mindkét időpontot másodperccé konvertálod, azokat összeadod, majd az eredményt időponttá alakítod vissza. A konverziókhoz a már megírt time2sec és sec2time függvényeket használd, ne kódolj le semmit újra!

Írj timecmp azonosítójú függvényt, mely összehasonlít két időpontot. Az összehasonlítás kövesse a C nyelv összehasonlító függvényeinek hagyományát, vagyis

    timecmp(a,b) > 0, ha a később van, mint b
    timecmp(a,b) < 0, ha b később van, mint a
    timecmp(a,b) == 0, ha b és a megegyeznek.

Vedd észre, hogy az összehasonlítás könnyen visszavezethető a time2sec függvény eredményeinek különbségképzésére. Természetesen az összehasonlítás csak azonos napon belül értelmezhető.

A fenti függvények teszteléséhez cseréld le a main-t az alábbira. Az ellenőrzőbe csak a két új függvényt másold be!

#include <stdio.h>

int main()
{
    time workout_begins = {23, 15, 0};
    time workout_duration = {1, 40, 0};
    time workout_ends = timeplus(workout_begins, workout_duration);
    if (timecmp(workout_ends, workout_begins) < 0)
        printf("Hamarabb van vege, mint mikor kezdodik\n");
    return 0;
}
*/

time timeplus(time a, time b)
{
    int asec = time2sec(a);
    int bsec = time2sec(b);

    return sec2time(asec + bsec);
}

int timecmp(time a, time b)
{
    int asec = time2sec(a);
    int bsec = time2sec(b);

    if (asec > bsec)
        return 1;

    else if (bsec > asec)
        return -1;

    return 0;
}

/*
Írj timereset azonosítójú függvényt, mely nem ad vissza semmit, viszont a paraméterként kapott időpontot nullázza.

Segítség: Mivel a függvény meg kell, hogy változtassa paraméterét, azt indirekt módon, mutatóval kell átvennie. Mivel a . operátor "erősebb", mint a *, a p mutatóval átvett struktúra mezőit a (*p).hour módon, zárójelezéssel éred el. Ennek alternatív megfogalmazása: p->hour.

A resetelő függvény hívását az alábbi main demonstrálja. Az ellenőrzőbe csak az új függvényt másold be!

int main(void)
{
    time workout_begins = {23, 15, 0};
    timereset(&workout_begins);
    return 0;
}
*/

void timereset(time* t)
{
    t->hour = 0;
    t->min = 0;
    t->sec = 0;
}

int main()
{
    time workout_begins = {23, 15, 0};
    timereset(&workout_begins);
    return 0;
}
