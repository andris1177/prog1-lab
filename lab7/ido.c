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
    int minute;
    int sec;
} time;

int time2sec(time t)
{
    return ((t.hour * 60) * 60) + (t.minute * 60) + t.sec;
}

time sec2time(int sec)
{
    time t;

    if (sec > 0)
    {
        t.sec = sec % 60;
        t.minute = ((sec - t.sec) / 60) % 60;
    }
}
