#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
/*冒泡排序优化*/
#include<stdio.h>
int main()
{
	int arr[] = { 5,4,3,2,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int j = 0;
	int t = 0;
	for (i = 0; i < len - 1; i++)
	{
		int flag = 1;
		for (j = 0; j < len - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
	for (i = 0; i < len; i++)
	{
		printf("%d", arr[i]);
	}
	return 0;
}
/*BC34 进制A+B */
#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	scanf("%x%o", &a, &b);
	printf("%d", a + b);
	return 0;
}
/*BC35 判断字母 */
#include<stdio.h>
int main()
{
	char a = getchar();
	if (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z')
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
	return 0;
}
/*BC36 健康评估 */
#include<stdio.h>
#include<math.h>
int main()
{
	int k = 0;
	float m = 0;
	scanf("%d%f", &k, &m);
	float a = 0;
	a = k / (pow(m, 2));
	if (a > 18.5 && a < 23.9)
	{
		printf("Normal");
	}
	else
	{
		printf("Abnormal");
	}
	return 0;
}
/*BC37 网购 */
#include<stdio.h>
int main()
{
	float a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	scanf("%f%d%d%d", &a, &b, &c, &d);
	if (11 == b && 11 == c)
	{
		a = a * 0.7;
		if (1 == d)
		{
			a = a - 50;
		}
	}
	if (12 == b && 12 == c)
	{
		a = a * 0.8;
		if (1 == d)
		{
			a -= 50;
		}
	}
	if (1 == d && (12 != b || 12 != c) && (11 != b || 11 != c))
	{
		a = a - 50;
	}
	if (a > 0)
	{
		printf("%.2f", a);
	}
	else
	{
		printf("0.00");
	}
	return 0;
}
/*BC38 变种水仙花 */
#include<stdio.h>
int main()
{

	return 0;
}