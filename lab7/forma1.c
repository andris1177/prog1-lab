/*


Írj kódrészletet, mely F1-es pilóták adott évi adatait tárolni képes struktúrát hoz létre! A típus neve legyen pilot. Minden pilótáról az alábbi adatokat tároljuk:

    racing_number: Rajtszám
    name: A pilóta nevének három karakterből álló azonosítója
    qualifying_results: Az adott év versenyhétvégéin az időmérő edzéseken nyújtott teljesítmény. (3 elemű tömb – az adott évben csak három versenyt tartottak...)
    Minden tömbelem az alábbi adatakot tartalmazza:
        pole_position: Az időmérő edzésen megszerzett rajthely.
        best_lap: A legjobb köridő másodpercben (a mérés ezredmásodperc pontosságú).

Ezt követően hozz létre egy két pilótát tartalmazó t azonosítójú tömböt az alábbi adatokkal:

    Első elem:
        Rajtszám: 1
        Név: MSC (Michael Schumacher)
        Időmérő eredmények:
            Első versenyhétvége:
                Rajthely: 1
                Legjobb köridő: 67.423 s
            Második versenyhétvége:
                Rajthely: 3
                Legjobb köridő: 46.735 s
            Harmadik versenyhétvége:
                Rajthely: 1
                Legjobb köridő: 70.264 s
    Második elem:
        Rajtszám: 2
        Név: MAS (Felipe Massa)
        Időmérő eredmények:
            Első versenyhétvége:
                Rajthely: 2
                Legjobb köridő: 67.433 s
            Második versenyhétvége:
                Rajthely: 5
                Legjobb köridő: 46.855 s
            Harmadik versenyhétvége:
                Rajthely: 3
                Legjobb köridő: 70.317 s
*/

typedef struct 
{
    int pole_position;
    double best_lap;
} qualifying_result;

struct pilot 
{
    int  racing_number;
    char name[4];                      
    qualifying_result qualifying_results[3];
};

typedef struct pilot pilot;          

pilot t[2] = {
    { 1, "MSC", { {1, 67.423}, {3, 46.735}, {1, 70.264} } },
    { 2, "MAS", { {2, 67.433}, {5, 46.855}, {3, 70.317} } }
};