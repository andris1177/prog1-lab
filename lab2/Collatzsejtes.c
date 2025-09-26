#include <stdio.h>

int main()
{
    int x;
    int done = 0;
    int count = 0;
    scanf("%d", &x);

    if (x == 1)
        done = 1;

    while (!done)
    {        
        if (x % 2 == 0)
            x = x/2;

        else
            x = 3*x+1;

        if (x == 1)
            done = 1;

        count++;
    }

    printf("%d\n", count);
    return 0;
}
