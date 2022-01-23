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
    int **b;
    int T;
    int min;
    int c = 0;
    puts ("Введите N:");
    scanf ("%d", &N);
    puts ("Введите M:");
    scanf ("%d", &M);
    b = (int **)malloc (N * sizeof (int *));
    printf ("Ввод элментов массива:\n");
    for (i = 0; i < N; i++)
        {
            *(b + i) = (int *)malloc (M * sizeof (int *));
            printf ("Ввод строки %d:\n", i);
            for (j = 0; j < M; j++)
                {
                    printf ("b[%d][%d] = ", i, j);
                    scanf ("%d", &(*(*(b + i) + j)));
                }
        }
    printf ("Вывод элементов массива:\n");
    for (i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
                {
                    printf ("%3d ", (*(*(b + i) + j)));
                }
            printf ("\n");
        }
    for (j = 1; j < M; j = j + 2)
        {
            T = 0;
            min = 9999;
            for (i = 0; i < N; i++)
                {
                    if (((*(*(b + i) + j)) % 2 == 0))
                        {
                            if ((*(*(b + i) + j)) < min)
                                {
                                    min = (*(*(b + i) + j));
                                    T = i;
                                }
                        }
                }
            if (min == 9999)
                {
                    printf ("\nВ %d столбце нет четных значений\n", j);
                }
            for (i = 0; i < N; i++)
                {
                    if (min == (*(*(b + i) + j)))
                        {
                            c++;
                        }
                }
            if (c == 1)
                {
                    c = 0;
                    printf ("\nЭлемент %d столбца с минимальным четным значением находится в %d строке и равен %d\n", j, T, min);
                }
            else if (c > 1)
                {
                    c = 0;
                    printf ("\nЭлементы %d столбца с одинаково минимальными четными значениям находятся в ", j);
                    for (i = 0; i < N; i++)
                        {
                            if (min == (*(*(b + i) + j)))
                                {
                                    printf ("%d ", i);
                                }
                        }
                    printf ("строках и равны %d", min);
                }
        }
    free (*(b + i));
    return 0;
}
