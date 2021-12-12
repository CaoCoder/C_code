#define _CRT_SECURE_NO_WARNINGS
/*BC63 菱形图案 */
#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n + 1; i++)
		{
			for (j = i; j < n; j++)
			{
				printf(" ");
			}
			for (j = 0; j < i + 1; j++)
			{
				printf("* ");
			}
			printf("\n");

		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < i + 1; j++)
			{
				printf(" ");
			}
			for (j = i; j < n; j++)
			{
				printf("* ");
			}
			printf("\n");
		}
	}
	return 0;
}
/*BC64 K形图案 */
#include<stdio.h>
int main()
{
	int n = 0;
	int i = 0;
	int j = 0;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n + 1; i++)
		{
			for (j = i; j < n + 1; j++)
			{
				printf("* ");
			}
			printf("\n");
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < i + 2; j++)
			{
				printf("* ");
			}
			printf("\n");
		}
	}
	return 0;
}
/*BC65 箭形图案 */
#include <stdio.h>
int main()
{
	int a;
	while (scanf("%d", &a) != EOF)//符合循环要求
	{
		for (int i = 1; i <= a + 1; i++)//根据题目要求先表示出上半个箭头
		{
			for (int j = 1; j <= (a + 1 - i) * 2 + i; j++)//结合循环和判断确定空格和*的个数
			{
				if (j <= (a + 1 - i) * 2)
				{
					printf(" ");
				}
				else
				{
					printf("*");
				}
			}
			printf("\n");//注意换行符的位置；
		}
		for (int m = 1; m <= a; m++)//同样的方式表示出下半个箭头
		{
			for (int n = 1; n <= m * 2 + a + 1 - m; n++)
			{
				if (n <= (m * 2))
				{
					printf(" ");
				}
				else
				{
					printf("*");
				}
			}
			printf("\n");
		}
	}
	return 0;
}
/*BC73 挂科危险 */
#include<stdio.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	if (n >= 10)
	{
		printf("Danger++");
	}
	else if (n >= 4 && n < 10)
	{
		printf("Danger");
	}
	else
	{
		printf("Good");
	}
	return 0;
}
/*BC74 HTTP状态码 */
#include<stdio.h>
int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		switch (n)
		{
		case 200:
			printf("OK\n");
			break;
		case 202:
			printf("Accepted\n");
			break;
		case 400:
			printf("Bad Request\n");
			break;

		case 403:
			printf("Forbidden\n");
			break;

		case 404:
			printf("Not Found\n");
			break;

		case 500:
			printf("Internal Server Error\n");
			break;

		case 502:
			printf("Bad Gateway\n");
			break;
		default :
			printf("输入错误\n");
			break;
		}
	}
	return 0;
}
/*BC77 有序序列插入一个数 */
#include<stdio.h>
int main()
{
	int n = 0;
	int i = 0;
	int j = 0;
	int arr[100] = { 0 };
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int c = 0;
	scanf("%d", &c);
	arr[i] = c;
	for (i = 0; i < n; i++)
	{
		int flag = 1;
		for (j = 0; j < n-i; j++)
		{
			int t = 0;
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
				flag = 0;
			}
		}
		if (1 == flag)
		{
			break;
		}

	}
	for (i = 0; i < n + 1; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
