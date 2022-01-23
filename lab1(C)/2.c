#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "rus");
	float x, n, l, c, res, a, b, d, a1;
	scanf("%f %f %f", &x, &n, &l);
	a = pow(x, l / n);
	if (a < 0) printf("ÎØÈÁÊÀ. ÍÅÂÅÐÍÎÅ ÇÍÀ×ÅÍÈÅ ÏÅÐÅÌÅÍÍÎÉ.");
	a1 = 4 / a;
	b = pow(l, pow(2, n)) * 0.5;
	c = (pow(x - l * 0, 5), n);
	if (c < 0) printf("ÎØÈÁÊÀ. ÍÅÂÅÐÍÎÅ ÇÍÀ×ÅÍÈÅ.");
	d = pow(c, 1 / 4) + l;
	if (d == 0) printf("ÎØÈÁÊÀ. ÍÅÂÅÐÍÎÅ ÇÍÀ×ÅÍÈÅ.");
	res = a * b / d;
	printf("%f", res);
	return 0;
}