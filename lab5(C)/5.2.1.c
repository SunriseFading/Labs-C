#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
int
main ()
{
    SetConsoleCP (1251);
    SetConsoleOutputCP (1251);
    setlocale (LC_ALL, "rus");
    system ("chcp 1251");
    system ("cls");
    int N, M, i, j;
    int *b;
    int T;
    int min;
    int c = 0;
    puts ("??????? N:");
    scanf ("%d", &N);
    puts ("??????? M:");
    scanf ("%d", &M);
    b = (int *)malloc (N * M * sizeof (int));
    printf ("???? ???????? ???????:\n");
    for (i = 0; i < N; i++)
        {
            printf ("???? ?????? %d:\n", i);
            for (j = 0; j < M; j++)
                {
                    printf ("b[%d][%d] = ", i, j);
                    scanf ("%d", (b + i * M + j));
                }
        }
    printf ("????? ????????? ???????:\n");
    for (i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
                {
                    printf ("%3d ", *(b + i * M + j));
                }
            printf ("\n");
        }
    for (j = 1; j < M; j = j + 2)
        {
            T = 0;
            min = 9999;
            for (i = 0; i < N; i++)
                {
                    if (*(b + i * M + j) % 2 == 0)
                        {
                            if (*(b + i * M + j) < min)
                                {
                                    min = *(b + i * M + j);
                                    T = i;
                                }
                        }
                }
            if (min == 9999)
                {
                    printf ("\n? %d ??????? ??? ?????? ????????\n", j);
                }
            for (i = 0; i < N; i++)
                {
                    if (min == *(b + i * M + j))
                        {
                            c++;
                        }
                }
            if (c == 1)
                {
                    c = 0;
                    printf ("\n??????? %d ??????? ? ??????????? ?????? ????????? ????????? ? %d ?????? ? ????? %d\n", j, T, min);
                }
            else if (c > 1)
                {
                    c = 0;
                    printf ("\n???????? %d ??????? ? ????????? ???????????? ??????? ????????? ????????? ? ", j);
                    for (i = 0; i < N; i++)
                        {
                            if (min == *(b + i * M + j))
                                {
                                    printf ("%d ", i);
                                }
                        }
                    printf ("??????? ? ????? %d", min);
                }
        }
    free (b);
    return 0;
}
