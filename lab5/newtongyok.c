/*
Négyzetgyökvonásra használható az alábbi Newton-módszer:

Ha √a értékét szeretnénk meghatározni, vegyünk egy tetszőleges x0 > 0 értéket, majd ismételjük az alábbi iterációt:
xn+1 = xn / 2 + a / 2xn

A módszert √2-re és x0=1-re alkalmazva az egyes iterációk így alakulnak:

    x0 = 1.0000000000000000
    x1 = 1.5000000000000000
    x2 = 1.4166666666666665
    x3 = 1.4142156862745097
    x4 = 1.4142135623746899
    x5 = 1.4142135623730949

A példán látszik, hogy a módszer nagyon gyors. Ha elég közel kerül a megoldáshoz, minden iterációban megduplázza a pontos (félkövér) tizedesjegyek számát, és igen hamar eléri a gépi ábrázolás (machine precision) pontosságának határát (52-bites mantisszájú double esetén kb 16 tizedesjegy)

Írj programot, mely beolvassa a és x0 értékét, majd a Newton-módszerrel meghatározza √a értékét. A program annyi iterációt végezzen, amenyit érdemes, vagyis amíg az eredmény hibája el nem éri a gépi ábrázolási pontosságot.

Természetesen az eredmény |xn-√a| hibáját közvetlenül nem számíthatjuk, mivel ha √a-t ismernénk, meg se írtuk volna a programot. Helyette azt ellenőrizzük, hogy xn2-a milyen közel esik 0-hoz.

Az iterációt akkor állítsd le, ha az |xn2-a| / a relatív hiba 10 ε alá csökken, ahol ε = DBL_EPSILON a float.h beillesztése után elérhető. Valós számok abszolút értékét a math.h beillesztése után az fabs függvénnyel tudod számítani.

A program írja ki a kimenetre minden iteráció n indexét és tőle egy szóközzel elválasztva xn értékét %.16E formátumkóddal.

Ha a bemenet pl. 9.0 5.0, akkor a kimenet


0 5.0000000000000000E+00
1 3.3999999999999999E+00
2 3.0235294117647058E+00
3 3.0000915541313802E+00
4 3.0000000013969839E+00
5 3.0000000000000000E+00
*/ 

#include <stdio.h>

#define EPSILON 2.2204460492503131e-16

double abs_val(double x)
{
    return x < 0 ? -x : x;
}

int main()
{
    double a, x;
    scanf("%lf %lf", &a, &x);  

    int n = 0;
    double error;

    while (1) 
    {
        printf("%d %.16E\n", n, x);

        double diff = x * x - a;
        error = abs_val(diff) / a;

        if (error < 10 * EPSILON)
        {
            break;
        }

        x = 0.5 * (x + a / x);
        n++;
    }
}
