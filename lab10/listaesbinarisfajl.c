/*
Egy strázsa nélküli lista háromdimenziós pontokat tartalmaz, a listaelemek az alábbi típusúak:

typedef struct _point_listelem {
    double x, y, z;
    struct _point_listelem* next;
} point_listelem;

A listában tárolt pontok adatait egy bináris fájlba szeretnénk írni – természetesen a next pointer nélkül, tehát a fájlban csak a pontok koordinátái szerepelnek egymás után: x1 y1 z1 x2 y2 z2 x3 y3 z3...

Írd meg a save függvényt, mely egy stringet és egy pontokat tartalmazó listát kap paraméterként, és kiírja a pontok adatait a stringben meghatározott nevű fájlba!

Írd meg a restore függvényt, mely egy pontokat tartalmazó fájl nevét kapja paraméterül, és visszatér az abban található adatokkal feltöltött láncolt lista kezdőelemének címével!

Az x, y és z mezőket külön-külön kell írni és olvasni, hiszen a struktúrák mezői között fordító- és architektúrafüggő kitöltések lehetségesek! Érdeklődők bővebb információt itt találhatnak: 
https://stackoverflow.com/questions/119123/why-isnt-sizeof-for-a-struct-equal-to-the-sum-of-sizeof-of-each-member

Az ellenőrzőbe a struktúra definícióját nem szabad bemásolni.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _point_listelem {
    double x, y, z;
    struct _point_listelem* next;
} point_listelem;

void save(char fileame[], point_listelem* first)
{
    FILE* f;
    f = fopen(fileame, "wb");

    while (first != NULL)
    {
        fwrite(&first->x, sizeof(first->x), 1, f);
        fwrite(&first->y, sizeof(first->y), 1, f);
        fwrite(&first->z, sizeof(first->z), 1, f);
        first = first->next;
    }
    fclose(f);
}

point_listelem* restore(char filename[])
{
    FILE* f;
    f = fopen(filename, "rb");
    double x, y, z;

    point_listelem* first = NULL; 
     point_listelem* curr = NULL;

    while (1)
    {
        if (fread(&x, sizeof(x), 1, f) != 1)
        {
            break;
        }

        if (fread(&y, sizeof(y), 1, f) != 1)
        {
            break;
        }

        if (fread(&z, sizeof(z), 1, f) != 1)
        {
            break;
        }

        if (first == NULL)
        {
            first = (point_listelem *)malloc(sizeof(point_listelem));
            curr = first;
        }

        else
        {
            curr->next = (point_listelem *)malloc(sizeof(point_listelem));
            curr = curr->next;
        }

        curr->x = x;
        curr->y = y;
        curr->z = z;
        curr->next = NULL;
    }
    
    fclose(f);
    
    return first;
}

point_listelem* array_to_list(double arr[][3], int length)
{

    point_listelem* first = (point_listelem *)malloc(sizeof(point_listelem));
    first->x = arr[0][0];
    first->y = arr[0][1];
    first->z = arr[0][2];
    first->next = NULL;
    point_listelem* curr = first;
   

    for (int i = 1; i < length; i++)
    {
        curr->next = (point_listelem *)malloc(sizeof(point_listelem));
        curr = curr->next;
        curr->x = arr[i][0];
        curr->y = arr[i][1];
        curr->z = arr[i][2];
        curr->next = NULL;
    }

    return first;
}

void list_free(point_listelem* first)
{
    while (first != NULL)
    {
        point_listelem* tmpNext = first->next;
        free(first);
        first = tmpNext;
    }  
}

int main()
{
    double array[2][3] = {{1.0, 2.3, 4.6}, {4.2, 65.34, 78.35}};
    point_listelem* list = array_to_list(array, 2);
    save("../asd", list);
    point_listelem* result = restore("../asd");

    while (result != NULL)
    {
        printf("x: %lf y: %lf z: %lf\n", result->x, result->y, result->z);
        result = result->next;
    }
    
}