#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n][n];
    int up = 0;
    int right = n - 1;
    int da = n - 1;
    int left = 0;
    int a = 1;
    while (a <= n * n) {
        for (int i = left; i <= right; i++)
        {
            arr[up][i] = a++;

        }
        up++;
        for (int i = up; i <= da; i++)
        {
            arr[i][right] = a++;

        }
        right--;
        for (int i = right; i >= left; i--)
        {
            arr[da][i] = a++;

        }
        da--;
        for (int i = da; i >= up; i--)
        {
            arr[i][left] = a++;

        }
        left++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}