/*
Egy fésűs lista kocsmák itallapját tartalmazza. A fésű szárán helyezkednek el a kocsmák nevét és az itallapra mutató pointert tartalmazó listaelemek, míg a fogakon az italok nevét és árát tartalmazó elemek. A listaelemek az alábbi típusúak (ezt nem szabad az ellenőrzőbe bemásolni):

typedef struct drink {
    char name[32];
    int price;
    struct drink* next;
} drink;
typedef struct pub {
    char name[32];
    drink* price_list;
    struct pub* next;
} pub;

Írj függvényt, mely meghatározza, hogy melyik kocsmában vásárolható meg legolcsóbban egy ital! A függvény neve legyen find_cheapest, vegyen át egy fésűs listára mutató pointert, illetve egy stringet, mely a kívánt ital nevét tartalmazza, és térjen vissza a választott kocsmára mutató pointerrel. Amennyiben egyik kocsmában sem lehet beszerezni az italt, akkor NULL pointer legyen a visszatérési érték.

A függvény fejléce legyen

pub* find_cheapest(pub *list, char *alc_drink);

Teszteléshez hozzunk létre egy fájlt az alábbihoz hasonló tartalommal:

Nagypapa Borozoja
Egri Bikaver...360
*****
Sarki Kocsma
Gosser...300
Heineken...400
*****
Fancy Bistro
Heineken...700
Limonade...980

A következő függvény az ilyen formátumú fájlokból felépít egy fésűs listát (a függvény használ néhány trükköt, például kétszeres indirekciót, statikus strázsát – természetesen ezen technikák nélkül is felépíthető a lista, úgyhogy aki gyakorolni szeretne, megírhatja a saját változatát, akár egyszerűbb fájlformátumot választva):

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

pub* read_pubs(char* name) {
    pub head = {"", NULL, NULL};
    pub** current_pub = &(head.next);
    char buffer[32];
    int price;
    FILE* f = fopen(name, "rt");
    while (fscanf(f, "%31[^\n]\n", buffer) == 1) {
        pub* new_pub = (pub*)malloc(sizeof(pub));
        drink** current_drink;
        strcpy(new_pub->name, buffer);
        new_pub->next = NULL;
        *current_pub = new_pub;
        current_pub = &(new_pub->next);
        new_pub->price_list = NULL;
        current_drink = &(new_pub->price_list);
        while (fscanf(f, "%31[^*.]...%d\n", buffer, &price) == 2) {
            drink* new_drink = (drink*)malloc(sizeof(drink));
            new_drink->price = price;
            strcpy(new_drink->name, buffer);
            new_drink->next = NULL;
            *current_drink = new_drink;
            current_drink = &(new_drink->next);
        }
        fscanf(f, "%*[^\n]\n");
    }
    fclose(f);
    return head.next;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct drink {
    char name[32];
    int price;
    struct drink* next;
} drink;
typedef struct pub {
    char name[32];
    drink* price_list;
    struct pub* next;
} pub;

pub* read_pubs(char* name) {
    pub head = {"", NULL, NULL};
    pub** current_pub = &(head.next);
    char buffer[32];
    int price;
    FILE* f = fopen(name, "rt");
    while (fscanf(f, "%31[^\n]\n", buffer) == 1) {
        pub* new_pub = (pub*)malloc(sizeof(pub));
        drink** current_drink;
        strcpy(new_pub->name, buffer);
        new_pub->next = NULL;
        *current_pub = new_pub;
        current_pub = &(new_pub->next);
        new_pub->price_list = NULL;
        current_drink = &(new_pub->price_list);
        while (fscanf(f, "%31[^*.]...%d\n", buffer, &price) == 2) {
            drink* new_drink = (drink*)malloc(sizeof(drink));
            new_drink->price = price;
            strcpy(new_drink->name, buffer);
            new_drink->next = NULL;
            *current_drink = new_drink;
            current_drink = &(new_drink->next);
        }
        fscanf(f, "%*[^\n]\n");
    }
    fclose(f);
    return head.next;
}

pub* find_cheapest(pub *list, char *alc_drink)
{
    int minPrice = -1;
    pub* cheapest = NULL;

    pub* place = list;
    while (place != NULL)
    {
        drink* curr = place->price_list;
        while (curr != NULL)
        {
            if (strcmp(curr->name, alc_drink) == 0)
            {
                if (minPrice < 0)
                {
                    minPrice = curr->price;
                    cheapest = place;
                }

                else if (curr->price < minPrice)
                {
                    minPrice = curr->price;
                    cheapest = place;
                }
            }

            curr = curr->next;
        }
        place = place->next;
    }
    
    return cheapest;
}

void pFree(pub* list)
{
    while (list != NULL)
    {
        while (list->price_list != NULL)
        {
            drink* tmp = list->price_list->next;
            free(list->price_list);
            list->price_list = tmp;
        }

        pub* tmp = list->next;
        free(list);
        list = tmp;
    }
}

int main()
{
    pub* p = read_pubs("../kocsmak.txt");
    pub* cheapest = find_cheapest(p, "Heineken");
    printf("%s\n", cheapest->name);
    pFree(p);
}