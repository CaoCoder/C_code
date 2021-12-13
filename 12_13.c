#define _CRT_SECURE_NO_WARNINGS
/*字符金字塔*/
#include<stdio.h>
int main()
{
	char n = 0;
	scanf("%c", &n);
	int i = 0;
	int j = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = i; j < 4; j++)
		{
			printf(" ");
		}
		for (j = 0; j < i + 1; j++)
		{
			printf("%c ", n);
		}
		printf("\n");
	}
	return 0;
}
/*BC14 出生日期输入输出 */
#include<stdio.h>
int main()
{
	int year = 0;
	int month = 0;
	int date = 0;
	scanf("%4d%2d%2d", &year, &month, &date);
	printf("year=%0d\nmonth=%02d\ndate=%02d\n", year, month, date);
	return 0;
}
/*BC26 计算三角形的周长和面积 */
#include<stdio.h>
#include<math.h>
int main()
{
	int a = 0;
	int b = 0;
	int d = 0;
	scanf("%d%d%d", &a, &b, &d);
	float c = 0;
	float s = 0;
	float p = 0;
	c = a + b + d;
	p = c / 2.0;
	s = sqrt(p * (p - a) * (p - b) * (p - d));
	printf("circumference=%.2f area=%.2f", c, s);
	return 0;
}
/*BC28 大小写转换*/
#include<stdio.h>
int main()
{
	char n = 0;
	while (scanf("%c", &n) != EOF)
	{
		getchar();
		printf("%c\n", n + 32);
	}
	return 0;
}
/*BC30 KiKi和酸奶 */
#include<stdio.h>
int main()
{
	int n = 0;
	int h = 0;
	int m = 0;
	while (scanf("%d%d%d", &n, &h, &m) != EOF)
	{
		if ((n * h > m) && (m % h != 0))
		{
			printf("%d\n", n - (m / h)-1);
		}
		else if (n * h > m && m % h == 0)
		{
			printf("%d\n", n - (m / h));
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}