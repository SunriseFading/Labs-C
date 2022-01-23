#include <io.h>
#include <locale.h>
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int i,j;

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
    char gender[2];
    struct Data born;
    char address[20];
    char num[12];
    char subject[15];
    int experience;
};

void
add (int *n, struct uchitel **a)
{
    *n = *n + 1;
    *a = (struct uchitel *)realloc (*a, *n * sizeof (struct uchitel));
    printf ("���������� � %d �������:\n", *n);
    printf ("������� ��������� ����� �������:");
    scanf ("%d", &(*(*a + *n - 1)).tabel);
    printf ("������� ������� �������:");
    scanf (" %s", &(*(*a + *n - 1)).surname);
    printf ("������� ��� �������:");
    scanf (" %s", &(*(*a + *n - 1)).name);
    printf ("������� �������� �������:");
    scanf (" %s", &(*(*a + *n - 1)).patronymic);
    printf ("������� ��� �������:");
    scanf (" %s", &(*(*a + *n - 1)).gender);
    printf ("������� ���� �������� �������:");
    scanf ("%d.%d.%d", &(*(*a + *n - 1)).born.day, &(*(*a + *n - 1)).born.month, &(*(*a + *n - 1)).born.year);
    printf ("������� ����� �������:");
    scanf (" %s", &(*(*a + *n - 1)).address);
    printf ("������� ��������� ����� �������:");
    scanf (" %s", &(*(*a + *n - 1)).num);
    printf ("������� ������� �������:");
    scanf (" %s", &(*(*a + *n - 1)).subject);
    printf ("������� ���� �������:");
    scanf ("%d", &(*(*a + *n - 1)).experience);
}

struct uchitel *
del (int tabel, int *n, struct uchitel *A)
{
    for ( i = 0; i < *n; i++)
        {
            if (A[i].tabel == tabel)
                {
                    for ( j = 1; j < *n; j++)
                        {
                            A[j] = A[j + 1];
                        }
                    *n = *n - 1;
                    A = (struct uchitel *)realloc (A, *n * sizeof (struct uchitel));
                }
        }
    return A;
}

int
tab (int s, struct uchitel *A)
{
    if (s == 0)
        return 0;
    else
        {
            tab (s - 1, A);
            printf ("| %14d|", A[s - 1].tabel);
            printf (" %10s|", A[s - 1].surname);
            printf (" %10s|", A[s - 1].name);
            printf (" %12s|", A[s - 1].patronymic);
            printf (" %6d.%d.%d|", A[s - 1].born.day, A[s - 1].born.month, A[s - 1].born.year);
            printf (" %4s|", A[s - 1].gender);
            printf (" %14s|", A[s - 1].subject);
            printf (" %5d|", A[s - 1].experience);
            printf (" %12s|", A[s - 1].num);
            printf (" %18s|\n", A[s - 1].address);
        }
}

int
poisk (char b, int s, struct uchitel *A)
{
    if (s == 0)
        return 0;
    else
        {
            poisk (b, s - 1, A);
            if (A[s - 1].surname[0] == b)
                {
                    printf ("| %14d|", A[s - 1].tabel);
                    printf (" %10s|", A[s - 1].surname);
                    printf (" %10s|", A[s - 1].name);
                    printf (" %12s|", A[s - 1].patronymic);
                    printf (" %6d.%d.%d|", A[s - 1].born.day, A[s - 1].born.month, A[s - 1].born.year);
                    printf (" %4s|", A[s - 1].gender);
                    printf (" %14s|", A[s - 1].subject);
                    printf (" %5d|", A[s - 1].experience);
                    printf (" %12s|", A[s - 1].num);
                    printf (" %18s|\n", A[s - 1].address);
                }
        }
}

int
opr (char sub[15], int s, struct uchitel *A)
{
    int count = 0;
    if (s == 0)
        return 0;
    else
        {
            opr (sub, s - 1, A);
            if ((A[s - 1].gender[0] == '�') && (!(strncmp (A[s - 1].subject, sub, 5))))
                {
                    count++;
                }
            printf ("%d", count);
        }
}

long int
filesize (FILE *fp)
{
    long int save_pos, size_of_file;

    save_pos = ftell (fp);
    fseek (fp, 0L, SEEK_END);
    size_of_file = ftell (fp);
    fseek (fp, save_pos, SEEK_SET);
    return (size_of_file);
}

int
main ()
{
    SetConsoleCP (1251);
    SetConsoleOutputCP (1251);
    setlocale (LC_ALL, "rus");
    enum Menu
    {
        Z1,
        Z2,
        Z3,
        Z4,
        Z5,
        Z6,
        Z7,
        E
    } c;
    int i, n = 0,j, tabel;
    char b;
    char sub[15];
    char f[250];
    struct uchitel *A;
    FILE *save;
    A = (struct uchitel *)malloc (n * sizeof (struct uchitel));
    do
        {
            printf ("\n");
            puts ("���� ���������:");
            puts ("1.���������� ���������� � ����� ������� � ������ �������");
            puts ("2.�������� ���������� �� ������� �� ���������� ������");
            puts ("3.����������� ���������� �� �������� � ���� �������");
            puts ("4.����� ���������� �� ��������, ������� ������� ���������� �� ������������ �����");
            puts ("5.����������� ���������� �������� �������� ���� ����������� ������������ �������");
            puts ("6.���������� ������ �� ������� �������� � ���� �� ���������� ����");
            puts ("7.������� ������ �� ����� � ������ ��������");
            puts ("8.����� �� ���������");
            printf ("��������� ����� ����:");
            scanf ("%d", &c);
            switch (c)
                {
                case 1:
                    add (&n, &A);
                    break;

                case 2:
                    printf ("������� ��������� �����:");
                    scanf ("%d", &tabel);
                    del (tabel, &n, A);
                    printf ("\n");
                    break;

                case 3:
                    printf ("--------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf ("|��������� �����|  �������  |    ���    |  ��������   | ���� �������� | ��� |    �������    | ���� |    �����    |       �����       |\n");
                    printf ("|---------------|-----------|-----------|-------------|---------------|-----|---------------|------|-------------|-------------------|\n");
                    tab (n, A);
                    printf ("--------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf ("\n");
                    break;

                case 4:
                    printf ("������� �����:");
                    scanf (" %c", &b);
                    printf ("--------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf ("|��������� �����|  �������  |    ���    |  ��������   | ���� �������� | ��� |    �������    | ���� |    �����    |       �����       |\n");
                    printf ("|---------------|-----------|-----------|-------------|---------------|-----|---------------|------|-------------|-------------------|\n");
                    poisk (b, n, A);
                    printf ("--------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf ("\n");
                    break;

                case 5:
                    printf ("������� �������� ��������:");
                    scanf (" %s", &sub);
                    opr (sub, n, A);

                case 6:
                    printf ("������� ���� � ����� � ��� �����: ");
                    gets (f);
                    gets (f);
                    save = fopen (f, "wb");
                    fwrite (&A[0], sizeof (struct uchitel), n, save);
                    //n = 0;
                    A = (struct uchitel *)realloc (A, n * sizeof (struct uchitel));
                    fclose (save);
                    break;

                case 7:
                    printf ("������� ���� � ����� � ��� ���: ");
                    gets (f);
                    gets (f);
                    save = fopen (f, "rb");
                    n = (filesize (save) / 120);
                    A = (struct uchitel *)realloc (A, n * sizeof (struct uchitel));
                    fread (&A[0], sizeof (struct uchitel), n, save);
                    fclose (save);
                    break;

                case 8:
                    return 0;
                    break;
                }
        }
    while (c != 8);
}
