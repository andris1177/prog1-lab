/*
Egy szöveges fájl a Curiosity Marson készített mérési adatait tartalmazza az alábbi formában:

MEASUREMENT_TIME 04/11/2021 08:13:59
TEMPERATURE -81F
MEASUREMENT_TIME 04/11/2021 08:15:03
TEMPERATURE -79F

Írj C programot, mely a mérési adatokat beolvassa, majd lefordítja magyarra. 
A program standard inputjára érkezik az angol mérési fájl neve és a fordítást tartalmazni 
hivatott magyar eredményfájl neve. A fenti példa esetére az elvárt 
eredmény (figyelj a dátum- és hőmérsékletkonverzióra)

MERESI_IDO 2021.11.04 08.13.59
HOMERSEKLET -62.8C
MERESI_IDO 2021.11.04 08.15.03
HOMERSEKLET -61.7C

A Fahrenheit-Celsius konverzió formulája: C = (F-32) * 5/9

Egyik fájlnév sem tartalmaz whitespace karaktereket, és hosszuk nem 
lehet nagyobb 20 karakternél. A mérési fájl tetszőlegesen sok sorpárt tartalmazhat.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char iFile[20];
    char oFile[20];
    
    scanf("%s%s", &iFile, &oFile);

    FILE* iFilePtr = fopen(iFile, "r");
    FILE* oFilePtr = fopen(oFile, "w");

    char buffer[1024];
    
    int year; 
    int month;
    int day;

    int hour;
    int minute;
    int second;

    double temp;

    while (fgets(buffer, 1024, iFilePtr) != NULL)
    {
        if (strstr(buffer, "MEASUREMENT_TIME") != NULL)
        {
            char asd[1024];
            sscanf(buffer, "%s %d/%d/%d %d:%d:%d", asd, &day, &month, &year, &hour, &minute, &second);
            fprintf(oFilePtr, "MERESI_IDO %d.%02d.%02d %02d.%02d.%02d\n", year, month, day, hour, minute, second);
        }

        else if (strstr(buffer, "TEMPERATURE") != NULL)
        {
            char asd[1024];
            sscanf(buffer, "%s %lfF", asd, &temp);
            temp = (temp - 32) * (5.0 / 9.0);
            fprintf(oFilePtr, "HOMERSEKLET %0.1lfC\n", temp);
        }
    }

    fclose(iFilePtr);
    fclose(oFilePtr);
}