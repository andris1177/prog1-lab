/*


Egy szöveges fájl egy dráma szövegét tartalmazza az alábbi példa által demonstrált formában:

A BankBan.txt példafájl tartalma:

BÁNK
	Elárultattam?

TIBORC
	Én Tiborc vagyok, kegyes nagyúr - no, lám!

BÁNK
	Tiborc - (Gondolkodva járkál).

TIBORC
	Igen - mert szólni kellenék
	Nagy dolgokat -

BÁNK
	Melindáról?

TIBORC
	Nem arról.

BÁNK
	Nem!

TIBORC
	Lopni jöttem ide; mivel a szegény
	Anya s gyermekek velem - (Elfojtódik.)

BÁNK
	No jól van - úgy.

A drámafájlokban a beszélő nagybetűvel írt nevét tartalmazó sort szövegsorok követik, 
melyek tabulátor ('\t') karakterrel kezdődnek. A szövegsorokat pontosan egy üres sor követi.

Írj programot, mely beolvassa a standard inputról a drámafájl nevét és egy szereplő nevét, 
majd egy szöveges fájlba kigyűjti a szereplő összes szövegét.

Amennyiben a program standard inputja pl.
BankBan.txt Tiborc
akkor a program a Tiborc.txt fájlt hozza létre, melynek elvárt szerkezete:

Én Tiborc vagyok, kegyes nagyúr - no, lám!

Igen - mert szólni kellenék
Nagy dolgokat -

Nem arról.

Lopni jöttem ide; mivel a szegény
Anya s gyermekek velem - (Elfojtódik.)

    A drámafájl neve nem hosszabb 30 karakternél.
    A szereplők neve nem hosszabb 20 karakternél.
    A drámafájl egyik sora sem hosszabb 100 karakternél.
    Sem a drámafájl neve, sem a szereplők neve nem tartalmaz whitespace karaktereket.
    A standard inputon érkező szereplőnév nem feltétlenül csupa nagybetűs, de a drámafájlban 
    a beszélő neve az.
    Az eredményfájl sorai nem tabulátorral kezdődnek.
    Ékezetes karakterekkel nem kell foglalkoznod, a fenti példa hazaszeretetből született.

Segítség: Ez tipikusan olyan feladat, mely a fájl soronkénti feldolgozásával oldható meg a 
legegyszerűbben. Egy sor beolvasására használd az fgets függvényt, és a ciklust szervezd az 
fgets visszatérési értékére! 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char iFile[30];
    char oFile[24];
    char name[20];

    scanf("%s%s", &iFile, &name); 

    memcpy(oFile, name, 20);
    strcat(oFile, ".txt");

    for (int i = 1; i < strlen(name); i++)
    {
        name[i] = name[i] - ('a' - 'A');
    }

    FILE* iFilePtr = fopen(iFile, "r");
    FILE* oFilePtr = fopen(oFile, "w");

    char buffer[100];

    while (fgets(buffer, sizeof(buffer) / sizeof(char), iFilePtr) != NULL)
    {
        if (strstr(buffer, name))
        {
            if (fgets(buffer, sizeof(buffer) / sizeof(char), iFilePtr) != NULL)
            {
                while (buffer[0] == '\t')
                {
                    fputs(buffer + 1, oFilePtr);
                    fgets(buffer, sizeof(buffer) / sizeof(char), iFilePtr);
                }

                fputs("\n", oFilePtr);
            }
        }
    }
    

    fclose(iFilePtr);
    fclose(oFilePtr);
}