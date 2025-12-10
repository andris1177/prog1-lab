/*
Egy munkagép vasbeton-épületet bont. Különböző tömegű épületdarabokat szakít le markolókanalába, és a leszakított darabot egy 2 
tonna összteherbírású teherautóra teszi. Amennyiben a teherautó már nem bírná el az éppen leszakított darabot, elhajtanak vele, és új, üres teherautóra folytatják a pakolást.

Írj programot, mely a standard inputról olvassa a leszakított darabok tömegeit, és kiírja, hogy az egymás után elhaladó teherautóknak hány tonna kihasználatlan kapacitásuk van. 
Amikor már nem érkezik több valós érték a standard inputon, az utolsó teherautó is elhajt.

Amennyiben pl. a standard inputon a
0.2 1 0.7 0.3 0.6 0.3 1.1 0.3
sorozat érkezik, akkor a program kimenete
0.100 0.800 0.600

A kimeneten a valós értékeket 3 tizedes pontossággal jelenítsd meg, közöttük egy szóköz legyen. 
*/

#include <stdio.h>

int main()
{
    double itemWeight = 0;
    double currTruckLoad = 0;
    
    while (scanf("%lf", &itemWeight) == 1)
    {
        if (currTruckLoad + itemWeight > 2)
        {
            printf("%.3lf ", 2 - currTruckLoad);
            currTruckLoad = itemWeight;
        }

        else
        {
            currTruckLoad += itemWeight;
        }
    }

    printf("%.3lf\n", 2 - currTruckLoad);
    return 0;
}