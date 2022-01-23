#include <stdio.h>
#include <locale.h>
int main(){
	setlocale(LC_ALL, "rus");
	char n;
	float a1, p1, a2, b2, p2, a3, b3, p3;
	do
    {
		puts("S - площадь квадрата");
		puts("T - площадь треугольника");
		puts("R - площадь ромба");
		puts("E - выход из программы");
		scanf(" %c ", &n);
		switch (n){
		case 'S':
			scanf("%f", &a1);
			if (a1 <= 0) puts("Ошибка\n");
			else p1 = a1 * a1;
			printf("%f\n", p1);
			break;
		case 'T':
			scanf("%f %f", &a2, &b2);
			if (a2 <= 0) puts("Ошибка\n");
			else if (b2 <= 0) puts("Ошибка\n");
			else p2 = (a2 * b2) / 2;
			printf("%f\n", p2);
			break;
		case 'R':
			scanf("%f %f", &a3, &b3);
			if (a3 <= 0) puts("Ошибка\n");
			else if (b3 <= 0) puts("Ошибка\n");
			else p3 = a3 * b3;
			printf("%f\n", p3);
			break;
		case 'E':
			return 0;
			break;
		default:
		    puts("Ошибка\n");
		}
	}
	while (n!='E');
	system("pause");
}
