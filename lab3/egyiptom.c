#include <stdio.h>

int main()
{
    int x, y, a = 1;

    scanf("%d%d", &x, &y); 

    while (x != 0)
    {
        if (x*a >= y)
        {
            x = x*a-y;
            y = y*a;
            printf("%d ", a);
        }

        a++;
    }

    return 0;
}
