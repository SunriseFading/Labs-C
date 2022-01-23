#include <locale.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
int
main ()
{
    setlocale (LC_ALL, "rus");
    int *a;
    int n, i, s, j, del, poisk, q;
    printf ("Введите размер массива:");
    scanf ("%d", &n);
    a = (int *)malloc (n * sizeof (int));
    printf ("Введите массив:");
    for (i = 0; i < n; i++)
        {
            scanf ("%d", a + i);
        }
    while (1)
        {
            printf ("\n");
            puts ("Меню программы");
            puts ("1.Добавить элемент в конец");
            puts ("2.Удаленить элемент из указанной позиции");
            puts ("3.Отобразить значения элементов массива");
            puts ("4.Очистить массив");
            puts ("5.Поиск позиции указанного элемента");
            puts ("6.Отсортировать элементы массива по убыванию");
            puts ("7.Выход из программы");
            printf ("\n");
            printf ("Выбранная команда:");
            scanf ("%d", &s);
            printf ("\n");
            switch (s)
                {
                case 1:
                    n++;
                    a = (int *)realloc (a, n * sizeof (int));
                    printf ("Введите элемент:");
                    scanf ("%d", &*(a + (n - 1)));
                    printf ("\n");
                    break;

                case 2:
                    printf ("Введите позицию элемента(нумерация с 1):");
                    scanf ("%d", &del);
                    *(a + del - 1) = 0;
                    printf ("\n");
                    break;

                case 3:
                    printf ("Массив: ");
                    for (i = 0; i < n; i++)
                        {
                            printf ("%d ", *(a + i));
                        }
                    printf ("\n");
                    break;
                case 4:
                    for (i = 0; i < n; i++)
                        {
                            *(a + i) = 0;
                        }
                    printf ("\n");
                    break;
                case 5:
                    printf ("Введите элемент:");
                    scanf ("%d", &poisk);
                    for (i = 0; i < n; i++)
                        {
                            if (*(a + i) == poisk)
                                {
                                    printf ("Позиция элемента:%d(нумерация с 1)", *(a + i));
                                }
                        }
                    printf ("\n");
                    break;
                case 6:
                    for (i = 0; i < n; i++)
                        {
                            for (j = i + 1; j < n; j++)
                                {
                                    if (*(a + i) < *(a + j))
                                        {
                                            q = *(a + i);
                                            *(a + i) = *(a + j);
                                            *(a + j) = q;
                                        }
                                }
                        }
                    break;
                case 7:
                    return 0;
                    break;
                default:
                    printf ("Такого пункта в меню нет\n");
                    break;
                }
        }
}
