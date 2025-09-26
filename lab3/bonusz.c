#include <stdio.h>

int main()
{
    int cat;
    int sal;

    scanf("%d%d", &cat, &sal);

    switch (cat) 
    {
        case 0:
            printf("Bonus: 0 EUR\n");
        break;

        case 1:
            printf("Bonus: 1000 EUR\n");
        break;

        case 2:
            printf("Bonus: %d EUR\n", (int)(sal*0.1));
        break;

        case 3:
            printf("Bonus: %d EUR\n", (int)(sal*0.1 + 1000));
        break;

        default:
            printf("INVALID\nBonus: 0 EUR\n");
    }

    return 0;
}
