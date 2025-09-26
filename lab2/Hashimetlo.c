#include <stdio.h>

int main()
{
    long int  length;
    scanf("%d", &length);

    if (length > 101)
    {
        length = 100;
    }

    for (long int i = 1; i <= length; i++)
    {
        printf("%s", "#");
    }
    printf("\n");
    return 0;
}
