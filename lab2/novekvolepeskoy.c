#include <stdio.h>

int main()
{
    int low, high;
    scanf("%d%d", &low, &high);
    for (int i = 1; low <= high; i++)
    {
        printf("%d ", low);
        low += i;
    }

    printf("\n");
    return 0;   
}
