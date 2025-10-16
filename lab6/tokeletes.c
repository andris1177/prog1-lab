/*
Írj függvényt, mely egy pozitív egész számról eldönti, hogy az tökéletes szám-e! A függvény neve legyen perfect, a visszatérési érték igazodjon a C igazságérték-konvenciójához!

Például: 6 -> 1

Eddig egész programokat kellett írni, most azonban (és a későbbiekben jellemzően) függvényt. Teszteléshez írd meg a main függvényt, inicializálj változókat tesztadatokkal, majd hívd meg az implementált függvényt! Debugoláshoz helyezz el breakpointot a függvény belsejében, vagy a main függvényből lépj be a függvény belsejébe a Step Into (F11) funkcióval! Ehhez a feladathoz például az alábbi tesztkörnyezet használható:
*/ 

//#include <stdio.h>
//int main(void) {
//    int in = 6;
//    int out = perfect(in);
//    printf("%d\n", out); /* Ez nem feltétlenül szükséges,
//        debug módban lehet figyelni out változó értékét. */
//    return 0;
//}

/*
Az ellenőrzőbe mindig csak a feladat által kért kódot kell bemásolni, a tesztkörnyezet bemásolása hibát eredményez!
*/


#include <stdio.h>

int perfect(int number)
{
    int x = 0;

    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
        {
            x += i;
        } 
    }

    if (x == number)
    {
        return 1;
    }

    return 0;
}

int main()
{
    int number = 6;

    scanf("%d", &number);

    printf("%d\n", perfect(number));
}
