#include <stdio.h>


int Jump(int n)
{
    int sum = 0;
    if (n > 2)
    {
        sum = Jump(n - 1) + Jump(n - 2);
        return sum;
    }
    else
        return n;
}

int main() {

    int n = 0;
    scanf("%d", &n);
    printf("%d", Jump(n));

    return 0;
}