#include <stdio.h>
main()
{
    int a, b;
    scanf_s("%d%d", &a, &b);
    int c = a + ++b + 2;
    printf("%d", c);
}