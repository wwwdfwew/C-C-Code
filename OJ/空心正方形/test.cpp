#include <stdio.h>

int main() {
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
        {
            if (i == 1 || i == n)
            {
                for (int j = 1; j <= n; j++)
                    printf("* ");
            }
            else
            {
                for (int z = 1; z <= n; z++)
                {
                    if (z == 1 || z == n)
                        printf("* ");
                    else
                        printf("  ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
