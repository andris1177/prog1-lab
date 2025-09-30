#include <stdio.h>

int main()
{
    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);
    
    for (int i = 0; a*i <= c ; i++)
    {
        for (int j = 0; b*j <= c; j++)
        {
            if (i*a + j*b == c)
            {
                if (i == 0 || j == 0)
                    continue;
                printf("%d %d\n", i, j);
            }
        }
    }

    return 0;
}
