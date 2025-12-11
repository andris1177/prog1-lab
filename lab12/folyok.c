/*
Egy bináris fa folyók összefolyását reprezentálja. 
A fa minden eleme egy folyó, melyet valós vízhozama és legfeljebb 20 karakter hosszú neve reprezentál. 
A fa levelei források, melyek vízhozama és neve ismert (a struktúra ki van töltve). 
A fa csomópontjaiban az összefolyáskor keletkező új folyók neve és vízhozama még kitöltetlen.

Duna(1.1)-----\
               ???(???)------\
Drava(0.3)----/
                              ???(???)
               Tisza(0.9)----/

A fa elemeihez használd az alábbi típust:

typedef struct r {
   struct r *left, *right;
   char name[20+1]; // neve
   double w;        // vizhozama
} *river_tree;

Írj void fill(river_tree root); fejlécű függvényt, mely paraméterként egy folyófát kap, 
és meghatározza (kitölti) a fa összes folyójának nevét és vízhozamát! 
Két folyó összeömlésekor a vízhozamok összeadódnak, és az eredő folyó a nagyobb vízhozamú folyó nevét örökli.

A függvénynek a fenti példafához a következő eredményt kell adnia:

Duna(1.1)-----\
               Duna(1.4)-----\
Drava(0.3)----/
                              Duna(2.3)
               Tisza(0.9)----/

Az ellenőrzőbe az adattípust ne, csak a függvényt és a szükséges include-okat másold be.
*/

#include <stdio.h>
#include <string.h>

typedef struct r {
   struct r *left, *right;
   char name[20+1]; // neve
   double w;        // vizhozama
} *river_tree;

void fill(river_tree root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    fill(root->left);
    fill(root->right);

    root->w = root->left->w + root->right->w;

    if (root->left->w > root->right->w)
    {
        strcpy(root->name, root->left->name);
    }

    else if (root->right->w > root->left->w)
    {
        strcpy(root->name, root->right->name);
    }
}