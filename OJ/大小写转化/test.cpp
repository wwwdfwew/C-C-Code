#include<stdio.h>
int main()
{
    char a;

    while (~scanf("%c", &a))
    {
        printf("%c\n", a + 32);
        getchar();
    }
}