#include <stdio.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int arr[a + a][b + b];
    for (int i = 0; i < 2 * a; i++)
    {
        for (int j = 0; j < b; j++)
            scanf("%d", &arr[i][j]);
    }
    int c = 0;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if ((arr[i][j] - arr[a + i][j]) != 0)
                c = 1;
        }
    }
    if (c == 0)
        printf("Yes\n");
    else
        printf("No");
    return 0;
}