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
    printf ("������� ������ �������:");
    scanf ("%d", &n);
    a = (int *)malloc (n * sizeof (int));
    printf ("������� ������:");
    for (i = 0; i < n; i++)
        {
            scanf ("%d", a + i);
        }
    while (1)
        {
            printf ("\n");
            puts ("���� ���������");
            puts ("1.�������� ������� � �����");
            puts ("2.��������� ������� �� ��������� �������");
            puts ("3.���������� �������� ��������� �������");
            puts ("4.�������� ������");
            puts ("5.����� ������� ���������� ��������");
            puts ("6.������������� �������� ������� �� ��������");
            puts ("7.����� �� ���������");
            printf ("\n");
            printf ("��������� �������:");
            scanf ("%d", &s);
            printf ("\n");
            switch (s)
                {
                case 1:
                    n++;
                    a = (int *)realloc (a, n * sizeof (int));
                    printf ("������� �������:");
                    scanf ("%d", &*(a + (n - 1)));
                    printf ("\n");
                    break;

                case 2:
                    printf ("������� ������� ��������(��������� � 1):");
                    scanf ("%d", &del);
                    *(a + del - 1) = 0;
                    printf ("\n");
                    break;

                case 3:
                    printf ("������: ");
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
                    printf ("������� �������:");
                    scanf ("%d", &poisk);
                    for (i = 0; i < n; i++)
                        {
                            if (*(a + i) == poisk)
                                {
                                    printf ("������� ��������:%d(��������� � 1)", *(a + i));
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
                    printf ("������ ������ � ���� ���\n");
                    break;
                }
        }
}
