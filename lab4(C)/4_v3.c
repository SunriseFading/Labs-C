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
            printf ("Меню:\n");
            printf ("1 - Добавить информацию о новых учителе или ученике\n");
            printf ("2 - Отображение информации об учителях и учениках\n");
            printf ("3 - Отображение информации об учителях в виде таблицы\n");
            printf ("4 - Определение количества учеников\n");
            printf ("5 - Поиск информации об учениках из 1А\n");
            printf ("6 - Выход из программы\n");
            printf ("Выберите нужный вам пункт:\n");
            scanf (" %d", &c);
            switch (c)
                {
                case 1:
                    printf ("Добавить информацию о новых учителях или учениках\n");
                    printf ("Введите количество новых учителей или учеников:");
                    scanf (" %d", &n);
                    printf ("Кого вы хотите добавить?\n1-учитель\n2-ученик\n");
                    scanf (" %d", &k);
                    if (k == 1)
                        {
                            for (int i = 0; i < n; i++)
                                {
                                    printf ("Введите данные о %d учителе\n", i + 1);
                                    printf ("Введите табельный номер учителя:");
                                    scanf (" %d", &C[i].teacher.tabel);
                                    for (int j = i - 1; j >= 0; j--)
                                        {
                                            if (C[i].teacher.tabel == C[j].teacher.tabel)
                                                {
                                                    printf ("Учитель с таким табельным номером уже существует! Введите новый табельный номер:");
                                                    scanf (" %d", &C[i].teacher.tabel);
                                                }
                                        }
                                    printf ("Введите фамилию учителя:");
                                    scanf (" %s", &C[i].teacher.surname);
                                    printf ("Введите имя учителя:");
                                    scanf (" %s", &C[i].teacher.name);
                                    printf ("Введите отчество учителя:");
                                    scanf (" %s", &C[i].teacher.patronymic);
                                    printf ("Введите дату рождения учителя:");
                                    scanf (" %d.%d.%d", &C[i].teacher.born.day, &C[i].teacher.born.month, &C[i].teacher.born.year);
                                    printf ("Введите пол учителя:");
                                    scanf (" %s", &C[i].teacher.gender);
                                    printf ("Введите адрес учителя:\n");
                                    getchar ();
                                    gets (C[i].teacher.address);
                                    printf ("Введите номер учителя:\n");
                                    scanf (" %s", &C[i].teacher.num);
                                    printf ("Введите предмет учителя:\n");
                                    getchar ();
                                    gets (C[i].teacher.subject);
                                    printf ("Введите стаж учителя:\n");
                                    scanf (" %d", &C[i].teacher.experience);
                                    n1++;
                                }
                        }
                    else
                        {
                            for (int i = 0; i < n; i++)
                                {
                                    printf ("Введите данные о %d ученике:\n", i + 1);
                                    printf ("Введите код ученика:");
                                    scanf (" %d", &C[i].student.tabel);
                                    for (int j = i - 1; j >= 0; j--)
                                        {
                                            if (C[i].student.tabel == C[j].student.tabel)
                                                {
                                                    printf ("Ученик с таким кодом уже существует! Введите новый код:");
                                                    scanf (" %d", &C[i].student.tabel);
                                                }
                                        }
                                    printf ("Введите фамилию ученика:");
                                    scanf (" %s", &C[i].student.surname);
                                    printf ("Введите имя ученика:");
                                    scanf (" %s", &C[i].student.name);
                                    printf ("Введите отчество ученика:");
                                    scanf (" %s", &C[i].student.patronymic);
                                    printf ("Введите пол ученика:");
                                    scanf (" %s", &C[i].student.gender);
                                    printf ("Введите дату рождения ученика:");
                                    scanf (" %d.%d.%d", &C[i].student.born.day, &C[i].student.born.month, &C[i].student.born.year);
                                    printf ("Введите номер ученика:\n");
                                    scanf (" %s", &C[i].student.num);
                                    printf ("Введите адрес ученика:\n");
                                    getchar ();
                                    gets (C[i].student.address);
                                    printf ("Введите класс ученика:\n");
                                    scanf (" %s", &C[i].student.class);
                                    n2++;
                                }
                        }
                    break;
                case 2:
                    printf ("Отображение информации об учителях и учениках\n");
                    if (n1 > 0)
                        {
                            printf ("Учителя:");
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
                            printf ("Ученики:");
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
                    printf ("Отображение информации об учителях в виде таблицы\n");
                    printf ("Таблица учителей\n");
                    printf ("\n");
                    printf ("--------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf ("|Табельный номер|  Фамилия  |    Имя    |  Отчество   | Дата рождения | Пол |    Предмет    | Стаж |    Номер    |       Адрес       |\n");
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
                    printf ("Определение количества учеников\n");
                    printf ("\n");
                    printf ("Количество учеников- %d\n", n2);
                    printf ("\n");
                    break;
                case 5:
                    printf ("Поиск информации об учениках из 1А");
                    printf ("\n");
                    for (int j = 0; j < n2; j++)
                        {
                            if ((C[j].student.class[0] == '1') && (C[j].student.class[1] == 'А'))
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
                    printf ("ОШИБКА!!  Такого пункта меню не существует\n");
                    printf ("\n");
                    break;
                }
        }
    while (c != 6);
    system ("pause");
}
