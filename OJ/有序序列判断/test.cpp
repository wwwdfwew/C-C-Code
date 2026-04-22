#include <stdio.h>

int main() {

    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    int r = arr[0] - arr[1];
    if (r < 0)
    {
        for (int i = 1; i < N - 1; i++)
        {
            if (arr[i] - arr[i + 1] > 0)
            {
                printf("unsorted");
                break;
            }
            if (i == N - 2)
                printf("sorted");
        }


    }
    else if (r > 0)
    {
        for (int i = 1; i < N - 1; i++)
        {
            if (arr[i] - arr[i + 1] < 0)
            {
                printf("unsorted");
                break;
            }
            if (i == N - 2)
                printf("sorted");
        }

    }
    else
    {
        for (int i = 1; i < N - 1; i++)
        {
            if ((arr[i] - arr[i + 1]) != 0)
            {
                printf("unsorted");
                break;
            }
            if (i == N - 2)
                printf("sorted");
        }

    }
    return 0;
}