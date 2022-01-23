#include <locale.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>


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
    printf ("Информация о %d учителе:\n", *n);
    printf ("Введите табельный номер учителя:");
    scanf ("%d", &(*(*a + *n - 1)).tabel);
    printf ("Введите фамилию учителя:");
    scanf (" %s", &(*(*a + *n - 1)).surname);
    printf ("Введите имя учителя:");
    scanf (" %s", &(*(*a + *n - 1)).name);
    printf ("Введите отчество учителя:");
    scanf (" %s", &(*(*a + *n - 1)).patronymic);
    printf ("Введите пол учителя:");
    scanf (" %s", &(*(*a + *n - 1)).gender);
    printf ("Введите дату рождения учителя:");
    scanf ("%d.%d.%d", &(*(*a + *n - 1)).born.day, &(*(*a + *n - 1)).born.month, &(*(*a + *n - 1)).born.year);
    printf ("Введите адрес учителя:");
    scanf (" %s", &(*(*a + *n - 1)).address);
    printf ("Введите мобильный номер учителя:");
    scanf (" %s", &(*(*a + *n - 1)).num);
    printf ("Введите предмет учителя:");
    scanf (" %s", &(*(*a + *n - 1)).subject);
    printf ("Введите стаж учителя:");
    scanf ("%d", &(*(*a + *n - 1)).experience);
}

struct uchitel *
del (int tabel, int *n, struct uchitel *A)
{
    for (int i = 0; i < *n; i++)
        {
            if (A[i].tabel == tabel)
                {
                    for (int j = i; j < *n; j++)
                        {
                            A[j] = A[j + 1];
                        }
                }
        }
    *n = *n - 1;
    A = (struct uchitel *)realloc(A, *n * sizeof(struct uchitel));
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
            if ((A[s - 1].gender[0] == 'Ж') && (!(strncmp (A[s - 1].subject, sub, 5))))
                {
                    count++;
                }
            printf ("%d", count);
        }
}

int
main ()
{
    setlocale (LC_ALL, "rus");
    enum Menu
    {
        Z1,
        Z2,
        Z3,
        Z4,
        Z5,
        E
    } c;
    int i, n = 0, tabel;
    char b;
    char sub[15];
    struct uchitel *A;
    A = (struct uchitel *)malloc (n * sizeof (struct uchitel));
    do
        {
            printf ("\n");
            puts ("Меню программы:");
            puts ("1.Добавление информации о новом учителе в начало массива");
            puts ("2.Удаление информации об учителе по табельному номеру");
            puts ("3.Отображение информации об учетелях в виде таблицы");
            puts ("4.Поиск инофрмации об учителях, фамилии которых начинаются на определенную букву");
            puts ("5.Определение количества учителей женского пола преподающих определенный предмет");
            puts ("6.Выход из программы");
            printf ("Выбранный пункт меню:");
            scanf ("%d", &c);
            switch (c)
                {
                case 1:
                    add (&n, &A);
                    break;

                case 2:
                    printf ("Введите табельный номер:");
                    scanf ("%d", &tabel);
                    del (tabel, &n, A);
                    printf ("\n");
                    break;

                case 3:
                    printf ("--------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf ("|Табельный номер|  Фамилия  |    Имя    |  Отчество   | Дата рождения | Пол |    Предмет    | Стаж |    Номер    |       Адрес       |\n");
                    printf ("|---------------|-----------|-----------|-------------|---------------|-----|---------------|------|-------------|-------------------|\n");
                    tab (n, A);
                    printf ("--------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf ("\n");
                    break;

                case 4:
                    printf ("Введите букву:");
                    scanf (" %c", &b);
                    printf ("--------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf ("|Табельный номер|  Фамилия  |    Имя    |  Отчество   | Дата рождения | Пол |    Предмет    | Стаж |    Номер    |       Адрес       |\n");
                    printf ("|---------------|-----------|-----------|-------------|---------------|-----|---------------|------|-------------|-------------------|\n");
                    poisk (b, n, A);
                    printf ("--------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf ("\n");
                    break;

                case 5:
                    printf ("Введите название предмета:");
                    scanf (" %s", &sub);
                    opr (sub, n, A);
                }
        }
    while (c != 6);
}
