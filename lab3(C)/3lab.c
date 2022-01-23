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
    char inf[] = "Информатика";
    char bukva[] = "К";
    int n, k5 = 0, k6 = 0, k7, d, m, y;
    do
        {
            printf ("\nМеню:\n");
            printf ("1 - Добавить информацию о новых учителях\n");
            printf ("2 - Поиск информации об учителях, фамилии которых начинаются на букву «К»\n");
            printf ("3 - Поиск информации об учителях со стажем работы 10-20 лет\n");
            printf ("4 - Отображение информации об учителях в виде таблицы\n");
            printf ("5 - Определение количества учителей женского пола, преподающих предмет «Информатика»\n");
            printf ("6 - Определение среднего возраста учителей\n");
            printf ("7 - Выход из программы\n");
            printf ("Выберите нужный вам пункт:\n");
            scanf (" %d", &c);
            switch (c)
                {
                case 1:
                    printf ("Добавить информацию о новых учителях\n");
                    printf ("Введите количество новых учителей:");
                    scanf (" %d", &n);
                    for (int i = 0; i < n; i++)
                        {
                            printf ("Введите данные о %d учителе:\n", i + 1);
                            printf ("Введите табельный номер учителя:");
                            scanf (" %d", &A[i].tabel);
                            for (int j = i - 1; j >= 0; j--)
                                {
                                    if (A[i].tabel == A[j].tabel)
                                        {
                                            printf ("Учитель с таким табельным номером уже существует! Введите новый табельный номер:");
                                            scanf (" %d", &A[i].tabel);
                                        }
                                }
                            printf ("Введите фамилию учителя:");
                            scanf (" %s", &A[i].surname);
                            printf ("Введите имя учителя:");
                            scanf (" %s", &A[i].name);
                            printf ("Введите отчество учителя:");
                            scanf (" %s", &A[i].patronymic);
                            printf ("Введите дату рождения учителя:");
                            scanf (" %d.%d.%d", &A[i].born.day, &A[i].born.month, &A[i].born.year);
                            printf ("Введите пол учителя:");
                            scanf (" %s", &A[i].gender);
                            printf ("Введите адрес учителя:\n");
                            getchar ();
                            gets (A[i].address);
                            printf ("Введите номер учителя:\n");
                            scanf (" %s", &A[i].num);
                            printf ("Введите предмет учителя:\n");
                            getchar ();
                            gets (A[i].subject);
                            printf ("Введите стаж учителя:\n");
                            scanf (" %d", &A[i].experience);
                        }
                    break;
                case 2:
                    printf ("Поиск информации об учителях, фамилии которых начинаются на букву «К»\n");
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
                    printf ("Поиск информации об учителях со стажем работы 10-20 лет\n");
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
                    printf ("Таблица учителей\n");
                    printf ("\n");
                    printf ("-------------------------------------------------------------------------------------\n");
                    printf ("|Табельный номер|  Фамилия  |    Имя    |  Отчество   |    Предмет    |    Номер    |\n");
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
                    printf ("Определение количества учителей женского пола, преподающих предмет «Информатика»\n");
                    printf ("\n");
                    for (int i = 0; i < n; i++)
                        {
                            if ((A[i].gender[0] == 'Ж') && (!(strncmp (A[i].subject, inf, 5))))
                                {
                                    k5++;
                                }
                        }
                    printf ("Результат: %d\n", k5);
                    printf ("\n");
                    break;
                case 6:
                    printf ("Определение среднего возраста учителей\n");
                    printf ("Какое сегодня число?(в виде d.y.m)\n");
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
                    printf ("Результат: %d\n", k7);
                    printf ("\n");
                    break;
                case 7:
                    return 0;
                    break;
                default:
                    printf ("ОШИБКА!!  Такого пункта меню не существует\n");
                    printf ("\n");
                    break;
                }
        }
    while (c != 7);
}
