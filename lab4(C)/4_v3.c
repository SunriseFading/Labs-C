#include <locale.h>
#include <stdio.h>
#include <strings.h>
#include <windows.h>

struct Data
{
    int day;
    int month;
    int year;
};

struct teacher
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
struct student
{
    int tabel;
    char surname[20];
    char name[20];
    char patronymic[20];
    char gender[10];
    struct Data born;
    char address[20];
    char num[20];
    char class[10];
};
union Uni
{
    struct teacher teacher;
    struct student student;
};

enum Menu
{
    Z1,
    Z2,
    Z3,
    Z4,
    Z5,
    E
} c;
int
main ()
{
    SetConsoleCP (1251);
    SetConsoleOutputCP (1251);
    setlocale (LC_ALL, "rus");
    struct teacher A[150];
    struct student B[150];
    union Uni C[100];
    int k, n, k5 = 0, k6 = 0, n1 = 0, n2 = 0;
    do
        {
            printf ("����:\n");
            printf ("1 - �������� ���������� � ����� ������� ��� �������\n");
            printf ("2 - ����������� ���������� �� �������� � ��������\n");
            printf ("3 - ����������� ���������� �� �������� � ���� �������\n");
            printf ("4 - ����������� ���������� ��������\n");
            printf ("5 - ����� ���������� �� �������� �� 1�\n");
            printf ("6 - ����� �� ���������\n");
            printf ("�������� ������ ��� �����:\n");
            scanf (" %d", &c);
            switch (c)
                {
                case 1:
                    printf ("�������� ���������� � ����� �������� ��� ��������\n");
                    printf ("������� ���������� ����� �������� ��� ��������:");
                    scanf (" %d", &n);
                    printf ("���� �� ������ ��������?\n1-�������\n2-������\n");
                    scanf (" %d", &k);
                    if (k == 1)
                        {
                            for (int i = 0; i < n; i++)
                                {
                                    printf ("������� ������ � %d �������\n", i + 1);
                                    printf ("������� ��������� ����� �������:");
                                    scanf (" %d", &C[i].teacher.tabel);
                                    for (int j = i - 1; j >= 0; j--)
                                        {
                                            if (C[i].teacher.tabel == C[j].teacher.tabel)
                                                {
                                                    printf ("������� � ����� ��������� ������� ��� ����������! ������� ����� ��������� �����:");
                                                    scanf (" %d", &C[i].teacher.tabel);
                                                }
                                        }
                                    printf ("������� ������� �������:");
                                    scanf (" %s", &C[i].teacher.surname);
                                    printf ("������� ��� �������:");
                                    scanf (" %s", &C[i].teacher.name);
                                    printf ("������� �������� �������:");
                                    scanf (" %s", &C[i].teacher.patronymic);
                                    printf ("������� ���� �������� �������:");
                                    scanf (" %d.%d.%d", &C[i].teacher.born.day, &C[i].teacher.born.month, &C[i].teacher.born.year);
                                    printf ("������� ��� �������:");
                                    scanf (" %s", &C[i].teacher.gender);
                                    printf ("������� ����� �������:\n");
                                    getchar ();
                                    gets (C[i].teacher.address);
                                    printf ("������� ����� �������:\n");
                                    scanf (" %s", &C[i].teacher.num);
                                    printf ("������� ������� �������:\n");
                                    getchar ();
                                    gets (C[i].teacher.subject);
                                    printf ("������� ���� �������:\n");
                                    scanf (" %d", &C[i].teacher.experience);
                                    n1++;
                                }
                        }
                    else
                        {
                            for (int i = 0; i < n; i++)
                                {
                                    printf ("������� ������ � %d �������:\n", i + 1);
                                    printf ("������� ��� �������:");
                                    scanf (" %d", &C[i].student.tabel);
                                    for (int j = i - 1; j >= 0; j--)
                                        {
                                            if (C[i].student.tabel == C[j].student.tabel)
                                                {
                                                    printf ("������ � ����� ����� ��� ����������! ������� ����� ���:");
                                                    scanf (" %d", &C[i].student.tabel);
                                                }
                                        }
                                    printf ("������� ������� �������:");
                                    scanf (" %s", &C[i].student.surname);
                                    printf ("������� ��� �������:");
                                    scanf (" %s", &C[i].student.name);
                                    printf ("������� �������� �������:");
                                    scanf (" %s", &C[i].student.patronymic);
                                    printf ("������� ��� �������:");
                                    scanf (" %s", &C[i].student.gender);
                                    printf ("������� ���� �������� �������:");
                                    scanf (" %d.%d.%d", &C[i].student.born.day, &C[i].student.born.month, &C[i].student.born.year);
                                    printf ("������� ����� �������:\n");
                                    scanf (" %s", &C[i].student.num);
                                    printf ("������� ����� �������:\n");
                                    getchar ();
                                    gets (C[i].student.address);
                                    printf ("������� ����� �������:\n");
                                    scanf (" %s", &C[i].student.class);
                                    n2++;
                                }
                        }
                    break;
                case 2:
                    printf ("����������� ���������� �� �������� � ��������\n");
                    if (n1 > 0)
                        {
                            printf ("�������:");
                            for (int i = 0; i < n1; i++)
                                {
                                    printf ("\n%d", C[i].teacher.tabel);
                                    printf (" %s %s %s", C[i].teacher.surname, C[i].teacher.name, C[i].teacher.patronymic);
                                    printf (" %d.%d.%d", C[i].teacher.born.day, C[i].teacher.born.month, C[i].teacher.born.year);
                                    printf (" %s", C[i].teacher.gender);
                                    printf (" %s", C[i].teacher.subject);
                                    printf (" %s", C[i].teacher.address);
                                    printf (" %s", C[i].teacher.num);
                                    printf (" %d", C[i].teacher.experience);
                                }
                        }
                    printf ("\n");
                    if (n2 > 0)
                        {
                            printf ("�������:");
                            for (int j = 0; j < n2; j++)
                                {
                                    printf ("\n%d", C[j].student.tabel);
                                    printf (" %s %s %s", C[j].student.surname, C[j].student.name, C[j].student.patronymic);
                                    printf (" %d.%d.%d", C[j].student.born.day, C[j].student.born.month, C[j].student.born.year);
                                    printf (" %s", C[j].student.gender);
                                    printf (" %s", C[j].student.address);
                                    printf (" %s", C[j].student.num);
                                    printf (" %s", C[j].student.class);
                                }
                        }
                    printf ("\n");
                    break;
                case 3:
                    printf ("����������� ���������� �� �������� � ���� �������\n");
                    printf ("������� ��������\n");
                    printf ("\n");
                    printf ("--------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf ("|��������� �����|  �������  |    ���    |  ��������   | ���� �������� | ��� |    �������    | ���� |    �����    |       �����       |\n");
                    printf ("|---------------|-----------|-----------|-------------|---------------|-----|---------------|------|-------------|-------------------|\n");
                    for (int i = 0; i < n; i++)
                        {
                            printf ("| %14d|", C[i].teacher.tabel);
                            printf (" %10s|", C[i].teacher.surname);
                            printf (" %10s|", C[i].teacher.name);
                            printf (" %12s|", C[i].teacher.patronymic);
                            printf (" %5d.%d.%d |", C[i].teacher.born.day, C[i].teacher.born.month, C[i].teacher.born.year);
                            printf (" %4s|", C[i].teacher.gender);
                            printf (" %13s |", C[i].teacher.subject);
                            printf (" %5d|", C[i].teacher.experience);
                            printf (" %12s|", C[i].teacher.num);
                            printf (" %17s |\n", C[i].teacher.address);
                        }
                    printf ("--------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf ("\n");
                    break;

                case 4:
                    printf ("����������� ���������� ��������\n");
                    printf ("\n");
                    printf ("���������� ��������- %d\n", n2);
                    printf ("\n");
                    break;
                case 5:
                    printf ("����� ���������� �� �������� �� 1�");
                    printf ("\n");
                    for (int j = 0; j < n2; j++)
                        {
                            if ((C[j].student.class[0] == '1') && (C[j].student.class[1] == '�'))
                                {
                                    printf ("%d", C[j].student.tabel);
                                    printf (" %s %s %s", C[j].student.surname, C[j].student.name, C[j].student.patronymic);
                                    printf (" %d.%d.%d", C[j].student.born.day, C[j].student.born.month, C[j].student.born.year);
                                    printf (" %s", C[j].student.gender);
                                    printf (" %s", C[j].student.address);
                                    printf (" %s", C[j].student.num);
                                    printf (" %s", C[j].student.class);
                                }
                        }
                    printf ("\n");
                    break;
                case 6:
                    return 0;
                    break;
                default:
                    printf ("������!!  ������ ������ ���� �� ����������\n");
                    printf ("\n");
                    break;
                }
        }
    while (c != 6);
    system ("pause");
}
