/*
Fordított lengyel jelöléssel megadott aritmetikai kifejezéseket szeretnénk kiszámítani. A fordított lengyel jelölésre postfix jelölésként is hivatkoznak, ugyanis a hagyományos, infix jelöléssel szemben az operátorok nem az operandusok között, hanem azok után állnak. Így nincs zárójelezés, a műveletek az operátorok sorrendjében hajtódnak végre. Például a 3 * (4 + 5) kifejezés fordított lengyel jelöléssel 3 4 5 + * vagy 4 5 + 3 * alakban írható fel. Az első alak kiértékelése a következőképpen történik: először az összeadás hajtódik végre, mely a 3 9 * kifejezést eredményezi, a szorzás végrehajtása pedig a 27 eredményt adja. (A második alak természetesen ugyanerre a végeredményre vezet, ott a közbülső kifejezésnél az operandusok sorrendje fordított lesz.)

A fordított lengyel jelöléssel megadott aritmetikai kifejezések kiértékelése nagyon egyszerűen végrehajtható egy verem segítségével. Amennyiben a kifejezés következő tokene (elemi objektuma) egy szám, akkor azt a verem tetejére helyezzük. Ha a token egy operátor, akkor az adott művelethez szükséges számú operandust kivesszük a verem tetejéről, végrehajtjuk a számítást, és az eredményt a verem tetejére helyezzük. A teljes kifejezést végigjárva az eredmény a verem tetején lesz. A korábbi kifejezés az alábbi lépésekben dolgozható fel:
Hátralévő tokenek	Verem tartalma (verem teteje jobb oldalon)
3 4 5 + *	
4 5 + *	3
5 + *	3 4
+ *	3 4 5
*	3 9
	27

Másik alakjának kiértékelése:
Hátralévő tokenek	Verem tartalma (verem teteje jobb oldalon)
4 5 + 3 *	
5 + 3 *	4
+ 3 *	4 5
3 *	9
*	9 3
	27

Írd meg az alábbi függvényeket:

void push(listelem* stack, double a);
double pop(listelem* stack);
double evaluate(char* tokens[], int n);

A push egy valós számot a verem tetejére helyez, a pop a verem tetejéről eltávolít egy elemet, és visszatér az eltávolított elem értékével. A listelem típus létrehozása is a feladat része, a verem egy elölstrázsás listával legyen megvalósítva (strázsa a verem tetjén).

Az evaluate függvény stringek tömbjét kapja paraméterként (mindegyik tömbelem egy-egy tokent tartalmaz), és visszatér a kiértékelt kifejezés eredményével. Csak a négy alapműveletet kell implementálni (operátorok: +, -, *, /). Ügyeljünk arra, hogy kivonásnál és osztásnál a korábban érkező operandus a kisebbítendő, illetve az osztandó, és a később érkező (amely a verem tetején lesz) a kivonandó, illetve az osztó. Például az 5 3 - kifejezés eredménye 2.

Az evaluate függvény az alábbi bemenetekre az alábbi kimeneteket adja:

{"1.5", "2", "+"} --> 3.5

{"1.5", "-2", "+"} --> -0.5

{"1.5", "2", "/"} --> 0.75

{"1", "2", "+", "3", "*"} --> 9

{"1", "2", "3", "4", "5", "+", "+", "+", "+"} --> 15
*/

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

typedef struct listelem
{
    double data;
    struct listelem* next;
} listelem;

int isOperator(char* token)
{
    if (strlen(token) == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
    {
        return 1;
    }

    return 0;
}

void push(listelem* stack, double a)
{
    listelem* tmp = stack->next;
    stack->next = malloc(sizeof(listelem));
    stack->next->data = a;
    stack->next->next = tmp;
}

double pop(listelem* stack)
{
    double val = stack->next->data;
    listelem* tmp = stack->next->next;
    free(stack->next);
    stack->next = tmp;
    return val;   
}

double evaluate(char* tokens[], int n)
{
    listelem* stack = malloc(sizeof(listelem));
    stack->data = 0;

    for (int i = 0; i < n; i++)
    {
        
        if (!isOperator(tokens[i]))
        {
            push(stack, atof(tokens[i]));
        }

        else
        {
            double second = pop(stack);
            double first = pop(stack);

            if (*tokens[i] == '+')
            {
                push(stack, first + second);
            }

            else if (*tokens[i] == '-')
            {
                push(stack, first - second);
            }

            else if (*tokens[i] == '*')
            {
                push(stack, first * second);
            }

            else if (*tokens[i] == '/')
            {
                push(stack, first / second);
            }
        }
    } 

    double result = pop(stack);
    free(stack);
    return result;
}

int main()
{
    char* operation[] = {"1", "2", "3", "4", "5", "+", "+", "+", "+"};
    printf("%lf\n", evaluate(operation, 9));
}