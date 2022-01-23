#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Menu
{
    Z1,
    Z2,
    Z3,
    Z4,
    Z5,
    Z6,
    Z7,
    Z8,
    Z9
} c;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    char s[255];
    char s_s[255];
    char split[] = " ";
    char *s1;
    char *s2 = NULL;
    int i, j, count, count_num, count_alph, count_dot, count_s, n, max = 0, off, off1, l1 = 0, len3, pr;
    char vowel[] = "aeiouAEIOU�������Ũ���������";
    FILE *f = NULL, *f1 = NULL, *f2 = NULL;
    do
    {
        printf("\n");
        puts("����");
        puts("1 - �������� ����� � ����");
        puts("2 - ���������� ���������� ������ ���������� � �����");
        puts("3 - ���������� ���� � ����� ������: ���� ��� ����");
        puts("4 - ���������� ���������� ������� ���� � �������� ������� �����");
        puts("5 - ����� ����� ������� �����");
        puts("6 - �������� � ������ ����� ��� �� �����, ���������� ��������� �������");
        puts("7 - ��������������� ����� ����� �� ���������� �������: ����� ����� ������ ������ ���� ������, � ��������� ����� ������ ���� ���������");
        puts("8 - ������� �� ����� ���������� �����");
        puts("9 - �����");
        printf("\n�������� �����: ");
        scanf("%d", &c);
        printf("\n");
        switch (c)
        {
        case 1:
            printf("������� ������: ");
            gets(s);
            gets(s);
            f = fopen("file.txt", "a");
            for (i = 0; i < strlen(s); i++)
                fputc(s[i], f);
            fclose(f);
            break;

        case 2:
            f = fopen("file.txt", "r");
            count = 0;
            while (fgets(s, 255, f))
            {
                size_t len = strlen(s);
                for (i = 0; i < len; ++i)
                {
                    if (ispunct(s[i]))
                    {
                        count++;
                    }
                }
            }
            fclose(f);
            printf("���������� ������ = %d\n", count);
            break;
        case 3:
            f = fopen("file.txt", "r");
            count_alph = 0;
            count_num = 0;
            while (fgets(s, 255, f))
            {
                size_t len = strlen(s);
                for (i = 0; i < len; ++i)
                {
                    if (isalpha(s[i]))
                    {
                        count_alph++;
                    }
                }
            }
            fclose(f);
            f = fopen("file.txt", "r");
            while (fgets(s, 255, f))
            {
                size_t len = strlen(s);
                for (i = 0; i < len; ++i)
                {
                    if (isdigit(s[i]))
                    {
                        count_num++;
                    }
                }
            }
            fclose(f);
            if (count_alph > count_num)
            {
                printf("� ����� ������ ����\n");
            }
            else if (count_alph < count_num)
            {
                printf("� ����� ������ ����\n");
            }
            else
            {
                printf("���������� ���� � ���� ���������\n");
            }
            break;

        case 4:
            count = 0;
            pr = 1;
            f = fopen("file.txt", "r");
            while ((fgets(s, 255, f)) != '\0')
            {
                if (pr % 2 != 0)
                {
                    for (i = 0; i < strlen(s); ++i)
                    {
                        for (j = 0; j < strlen(vowel); ++j)
                        {
                            if (s[i] == vowel[j])
                            {
                                count++;
                            }
                        }
                    }
                    pr++;
                }
                else if (pr % 2 == 0)
                {
                    pr++;
                }
            }
            fclose(f);
            printf("���������� ������� ���� = %d\n", count);
            break;

        case 5:
            f = fopen("file.txt", "r");
            while (fgets(s, 255, f))
            {
                s1 = strtok(s, split);
                while (s1 != NULL)
                {
                    int len1 = strlen(s1);
                    if (max < strlen(s1))
                    {
                        s2 = strdup(s1);
                        max = len1;
                    }
                    s1 = strtok(NULL, split);
                }
            }
            fclose(f);
            printf("����� ������� �����: %s", s2);
            break;

        case 6:
            f = fopen("file.txt", "r");
            f1 = fopen("file1.txt", "w+");
            while (fgets(s, 255, f))
            {
                for (i = 0; i < strlen(s); i++)
                {
                    fprintf(f1, "%c", toupper(s[i]));
                }
            }
            fclose(f);
            fclose(f1);
            break;

        case 7:
            f = fopen("file.txt", "r");
            f2 = fopen("file2.txt", "a");
            while (fgets(s, 255, f))
            {
                for (i = 0; i < strlen(s); i++)
                {
                    if (s[i] != '.')
                    {
                        fprintf(f2, "%c", (s[i]));
                    }
                    else
                    {
                        fprintf(f2, ". %c", toupper(s[i + 1]));
                        i++;
                    }
                }
            }
            fclose(f);
            fclose(f2);

            f2 = fopen("file2.txt", "r");
            f = fopen("file.txt", "w");
            while (fgets(s, 255, f2))
            {
                for (i = 0; i < strlen(s); i++)
                {
                    fprintf(f, "%c", (s[i]));
                }
            }
            fclose(f2);
            fclose(f);
            break;

        case 8:
            f = fopen("file.txt", "r");
            while ((s[i] = fgetc(f)) != EOF)
            {
                if (s[i] == '\n')
                {
                    s[i] = '\0';
                    printf("%s\n", s);
                    i = 0;
                }
                else
                    i++;
            }
            s[i] = '\0';
            printf("%s\n", s);
            fclose(f);
            break;

        case 9:
            return 0;
            break;

        default:
            printf("error\n\n");
        }
    } while (c != 9);
}
