/*
Egy vitorlás hajó által megtett útról egy olyan adathalmaz keletkezett, amelyben minden bejegyzés egy pozícióból és egy időtartamból áll. A pozíció egy kétdimenziós pont, melyen a hajó áthaladt, az időtartam pedig az az idő, ami alatt az előző pozíciótól az aktuális pozícióig elért. A pozíciók között (megfelelő közelítéssel) a hajó egyenesen haladt. A pontok euklideszi térben értelmezettek (laposföldön...), a koordináták méterben vannak megadva (azonban nem feltétlenül egész számok). Az időtartam óra, perc és másodperc tagból áll.

Hozd létre a bejegyzések tárolásához szükséges struktúrákat az alábbi azonosítókkal:

    point
        x (valós)
        y (valós)
    time
        hour (egész)
        minute (egész)
        second (egész)
    record
        position (point)
        interval (time)

Írj függvényt in_seconds névvel, mely egy time típussal megadott időintervallumot átvált az eltelt másodpercek számára!

Írd meg a distance nevű függvényt, mely két point típusú pont közötti távolsággal tér vissza!

Írj függvényt average_speed névvel, mely record típusú elemekből álló tömböt kap paraméterként, és visszatér az utazás átlagsebességével m/s mértékegységben (az átlagsebesség a szakaszok összhosszának és az összes eltelt időnek a hányadosa). A tömb első elemének interval tagja irreleváns, hiszen az első pont elérése előtti eseményekre nem vagyunk kíváncsiak.
*/

#include <stdio.h>
#include <math.h>

typedef struct 
{
    double x;
    double y;
} point;

typedef struct 
{   
    int hour;
    int minute;
    int second;
} time;

typedef struct 
{
    point position;
    interval time;
} record;

int in_seconds(time t)
{
    return (t.hour * 3600) + (t.minute * 60) + t.second;
}

double distance(point pa, point pb)
{
    return sqrt(((pb.x - pa.x)*(pb.x - pa.x)) + ((pb.y - pa.y)*(pb.y - pa.y));)
}

double average_speed(record r)
{
    
}