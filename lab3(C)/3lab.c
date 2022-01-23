#include <locale.h>
#include <stdio.h>
#include <windows.h>

struct Data
{
    int day;
    int month;
    int year;
};

struct uchitel
{
    int tabel;
    char surname[20];
    char name[20];
    char patronymic[20];
    char gender[10];
    struct Data born;
    char address[20];
    char num[20];
    char subject[15];
    int experience;
};

enum Menu
{
    Z1,
    Z2,
    Z3,
    Z4,
    Z5,
    Z6,
    E
} c;
int
main ()
{
    SetConsoleCP (1251);
    SetConsoleOutputCP (1251);
    setlocale (LC_ALL, "rus");
    struct uchitel A[150];
    char inf[] = "�����������";
    char bukva[] = "�";
    int n, k5 = 0, k6 = 0, k7, d, m, y;
    do
        {
            printf ("\n����:\n");
            printf ("1 - �������� ���������� � ����� ��������\n");
            printf ("2 - ����� ���������� �� ��������, ������� ������� ���������� �� ����� �ʻ\n");
            printf ("3 - ����� ���������� �� �������� �� ������ ������ 10-20 ���\n");
            printf ("4 - ����������� ���������� �� �������� � ���� �������\n");
            printf ("5 - ����������� ���������� �������� �������� ����, ����������� ������� ������������\n");
            printf ("6 - ����������� �������� �������� ��������\n");
            printf ("7 - ����� �� ���������\n");
            printf ("�������� ������ ��� �����:\n");
            scanf (" %d", &c);
            switch (c)
                {
                case 1:
                    printf ("�������� ���������� � ����� ��������\n");
                    printf ("������� ���������� ����� ��������:");
                    scanf (" %d", &n);
                    for (int i = 0; i < n; i++)
                        {
                            printf ("������� ������ � %d �������:\n", i + 1);
                            printf ("������� ��������� ����� �������:");
                            scanf (" %d", &A[i].tabel);
                            for (int j = i - 1; j >= 0; j--)
                                {
                                    if (A[i].tabel == A[j].tabel)
                                        {
                                            printf ("������� � ����� ��������� ������� ��� ����������! ������� ����� ��������� �����:");
                                            scanf (" %d", &A[i].tabel);
                                        }
                                }
                            printf ("������� ������� �������:");
                            scanf (" %s", &A[i].surname);
                            printf ("������� ��� �������:");
                            scanf (" %s", &A[i].name);
                            printf ("������� �������� �������:");
                            scanf (" %s", &A[i].patronymic);
                            printf ("������� ���� �������� �������:");
                            scanf (" %d.%d.%d", &A[i].born.day, &A[i].born.month, &A[i].born.year);
                            printf ("������� ��� �������:");
                            scanf (" %s", &A[i].gender);
                            printf ("������� ����� �������:\n");
                            getchar ();
                            gets (A[i].address);
                            printf ("������� ����� �������:\n");
                            scanf (" %s", &A[i].num);
                            printf ("������� ������� �������:\n");
                            getchar ();
                            gets (A[i].subject);
                            printf ("������� ���� �������:\n");
                            scanf (" %d", &A[i].experience);
                        }
                    break;
                case 2:
                    printf ("����� ���������� �� ��������, ������� ������� ���������� �� ����� �ʻ\n");
                    printf ("\n");
                    for (int i = 0; i < n; i++)
                        {
                            if (A[i].surname[0] == bukva[0])
                                {
                                    printf ("%d ", i + 1);
                                    printf (" %s %s %s", A[i].surname, A[i].name, A[i].patronymic);
                                    printf (" %s", A[i].address);
                                    printf (" %s", A[i].num);
                                    printf (" %d.%d.%d", A[i].born.day, A[i].born.month, A[i].born.year);
                                }
                        }
                    printf ("\n");
                    break;
                case 3:
                    printf ("����� ���������� �� �������� �� ������ ������ 10-20 ���\n");
                    printf ("\n");
                    for (int i = 0; i < n; i++)
                        {
                            if ((A[i].experience >= 10) && (A[i].experience <= 20))
                                {
                                    printf ("%d ", i + 1);
                                    printf (" %s %s %s", A[i].surname, A[i].name, A[i].patronymic);
                                    printf (" %s ", A[i].subject);
                                    printf (" %d ", A[i].experience);
                                }
                        }
                    printf ("\n");
                    break;

                case 4:
                    printf ("������� ��������\n");
                    printf ("\n");
                    printf ("-------------------------------------------------------------------------------------\n");
                    printf ("|��������� �����|  �������  |    ���    |  ��������   |    �������    |    �����    |\n");
                    printf ("|---------------|-----------|-----------|-------------|---------------|-------------|\n");
                    for (int i = 0; i < n; i++)
                        {
                            printf ("| %14d|", A[i].tabel);
                            printf (" %10s|", A[i].surname);
                            printf (" %10s|", A[i].name);
                            printf (" %12s|", A[i].patronymic);
                            printf (" %13s |", A[i].subject);
                            printf (" %12s|\n", A[i].num);
                        }
                    printf ("-------------------------------------------------------------------------------------\n");
                    printf ("\n");
                    break;
                case 5:
                    printf ("����������� ���������� �������� �������� ����, ����������� ������� ������������\n");
                    printf ("\n");
                    for (int i = 0; i < n; i++)
                        {
                            if ((A[i].gender[0] == '�') && (!(strncmp (A[i].subject, inf, 5))))
                                {
                                    k5++;
                                }
                        }
                    printf ("���������: %d\n", k5);
                    printf ("\n");
                    break;
                case 6:
                    printf ("����������� �������� �������� ��������\n");
                    printf ("����� ������� �����?(� ���� d.y.m)\n");
                    scanf (" %d.%d.%d", &d, &m, &y);
                    for (int i = 0; i < n; i++)
                        {
                            if ((A[i].born.month > m) || ((A[i].born.month == m) && (A[i].born.day > d)))
                                {
                                    k6 = k6 + (y - A[i].born.year);
                                }
                            else if ((A[i].born.month == m) && (A[i].born.day < d) || (A[i].born.month < m))
                                {
                                    k6 = k6 + (y - A[i].born.year - 1);
                                }
                        }
                    k7 = k6 / n;
                    printf ("���������: %d\n", k7);
                    printf ("\n");
                    break;
                case 7:
                    return 0;
                    break;
                default:
                    printf ("������!!  ������ ������ ���� �� ����������\n");
                    printf ("\n");
                    break;
                }
        }
    while (c != 7);
}
