#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    char One[] = "One";
    char Two[] = "Two";
    char Three[] = "Three";
    char Four[] = "Four";
    char Exit[] = "Exit";
    char menu[5];
    int k = 0;
    int i = 1;
    int j = 1;
    int N;
    int M;
    int **b;
    int x = 0;
    char str[256];
    int count[26];
    int num = 0;
    char str1[256];
    while (strcmp(menu, Exit) != 0)
    {
        puts("������� ������� ��� ���������� �������");
        puts("One - ������� �1");
        puts("Two - ������� �2");
        puts("Three - ������� �3");
        puts("Four - ������� �4");
        puts("Exit - ����� �� ���������");
        scanf(" %s", menu);

        if (strcmp(menu, One) == 0)
        {
            int i, q, w, n;
            int a[n];
            printf("������� ����� ��������� �������:");
            scanf("%d", &n);
            printf("������� �������� �������:");
            for (i = 0; i < n; i++)
                scanf("%d", &a[i]);
            for (i = 0; i < n; i++)
                for (w = i + 1; w < n; w++)
                    if (a[i] < a[w])
                    {
                        q = a[i];
                        a[i] = a[w];
                        a[w] = q;
                    }
            for (i = 0; i < n; i++)
                printf("%d ", a[i]);
            printf("\n");
        }

        else if (strcmp(menu, Two) == 0)
        {
            system("chcp 1251");
            system("cls");
            puts("������� N:");
            scanf("%d", &N);
            puts("������� M:");
            scanf("%d", &M);
            b = (int **)malloc(N * sizeof(int *));
            printf("���� �������� �������:\n");
            for (i = 0; i < N; i++)
            {
                b[i] = (int *)malloc(M * sizeof(int));
                printf("���� ������ %d:\n", i);
                for (j = 0; j < M; j++)
                {
                    printf("b[%d][%d] = ", i, j);
                    scanf("%d", &b[i][j]);
                }
            }
            printf("����� ��������� �������:\n");
            for (i = 0; i < N; i++)
            {
                for (j = 0; j < M; j++)
                {
                    printf("%3d ", b[i][j]);
                }
                printf("\n");
            }
            int f = 1;
            int min = 0;
            int T, R;
            for (i = 0; i < N; i++)

                for (j = 0; j < M; j++)
                    if ((j < i) && (f != 0))
                    {
                        if (b[i][j] % 2 == 0)
                        {
                            min = b[i][j];
                            f = 0;
                            T = i;
                            R = j;
                        }
                    }
                    else if (j < i)
                    {
                        if (b[i][j] % 2 == 0)
                        {
                            if (b[i][j] < min)
                            {
                                min = b[i][j];
                                T = i;
                                R = j;
                            }
                        }
                    }
            free(b[i]);
            printf("������� � ����������� ������ ��������� �����:%d\n", min);
            printf("������� ��������� � %d ������ � � %d �������\n", T, R);
        }

        else if (strcmp(menu, Three) == 0)
        {
            printf("��������� ������: \n");
            getchar();
            gets(str);
            for (int i = 0; i < 26; i++)
                count[i] = 0;
            for (int i = 0; i < strlen(str); i++)
            {
                num = -1;
                if (str[i] >= 'a' && str[i] <= 'z')
                    num = str[i] - 'a';
                if (str[i] >= 'A' && str[i] <= 'Z')
                    num = str[i] - 'A';
                if (num >= 0)
                    count[num]++;
            }
            for (int i = 0; i < 26; i++)
            {
                if (count[i] > 0)
                {
                    printf("%c - %d\n", 'A' + i, count[i]);
                    x = x + count[i];
                }
            }
            printf("����� ����: %d\n", x);
        }

        else if (strcmp(menu, Four) == 0)
        {
            SetConsoleCP(1251);
            SetConsoleOutputCP(1251);
            setlocale(LC_ALL, "rus");
            char S[100], L1, L2;
            int i;
            printf("������� �����:\n");
            getchar();
            gets(S);
            printf("������� ������ �����:\n");
            scanf(" %c", &L1);
            printf("������� ������ �����:\n");
            scanf(" %c", &L2);
            for (i = 0; S[i] != '\0'; i++)
            {
                if (S[i] == L1)
                {
                    S[i] = L2;
                }
                else if (S[i] == L2)
                {
                    S[i] = L1;
                }
            }
            printf("%s", S);
            printf("\n");
        }
        else if (strcmp(menu, Exit) == 0)
        {
            return 0;
        }

        else
        {
            printf("������!!\n����� ������� ���!\n\n\n");
        }
    }
    system("pause");
}
