/*
Egy legfeljebb kétbemenetű logikai kapukból álló kapcsolást bináris fában tárolunk. 
A fában tárolt elemek tartalmazzák a logikai kapu típusát, illetve két pointert, 
melyek a bemenetét meghajtó kapu(k)ra mutatnak. Egybemenetű kapu esetén a második pointer NULL értékű. 
A fa levelei logikai IGAZ és HAMIS értékeket tárolnak. 
A teljes kapcsolás egykimenetű, de tetszőleges mélységű (szintű), egy példát mutat az alábbi ábra:

       1-----\
              NOT---\
                     AND
0-----\
       NOT---\
              NOR---/
       1-----/

Az alábbi felsorolt típus egy kapu fajtáját adja meg:

typedef enum
{
	AND,
	OR,
	NAND,
	NOR,
	NOT,
	FALSE,
	TRUE
} type_t;

Az alábbi fatípus a bináris fa egy elemét, illetve az arra mutató pointert adja meg:

typedef struct g {
	type_t type;
	struct g *in1, *in2;
} gate_t, *gate_tree;

Implementálj int eval(gate_tree root) fejlécű függvényt, mely egy fával reprezentált kombinációs logikát kap, 
és visszatér az áramkör kimenetének értékével! Az ellenőrzőbe a fenti típusokat nem szabad bemásolnod.
*/

#include <stdio.h>

typedef enum
{
	AND,
	OR,
	NAND,
	NOR,
	NOT,
	FALSE,
	TRUE
} type_t;

typedef struct g {
	type_t type;
	struct g *in1, *in2;
} gate_t, *gate_tree;

int eval(gate_tree root)
{
    if (root->in1 == NULL && root->in2 == NULL)
    {

        // for leaf nodes
        if (root->type == TRUE)
        {
            return 1;
        }

        else if (root->type == FALSE)
        {
            return 0;
        }
    }

    switch (root->type)
    {
        case AND:
            return eval(root->in1) && eval(root->in2);
            break;

        case OR:
            return eval(root->in1) || eval(root->in2);
            break;

        case NAND:
            return !(eval(root->in1) && eval(root->in2));
            break;

        case NOR:
            return !(eval(root->in1) || eval(root->in2));
            break;

        case NOT:
            return !eval(root->in1);
            break;
    }
}