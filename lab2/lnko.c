#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    while (b != 0)
    {
        int c = b;
        b = a % b;
        a = c;
    }

    printf("%d\n", a);
    return 0;
}
