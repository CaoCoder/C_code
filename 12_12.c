#define _CRT_SECURE_NO_WARNINGS
/*BC63 ����ͼ�� */
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
/*BC64 K��ͼ�� */
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
/*BC65 ����ͼ�� */
#include <stdio.h>
int main()
{
	int a;
	while (scanf("%d", &a) != EOF)//����ѭ��Ҫ��
	{
		for (int i = 1; i <= a + 1; i++)//������ĿҪ���ȱ�ʾ���ϰ����ͷ
		{
			for (int j = 1; j <= (a + 1 - i) * 2 + i; j++)//���ѭ�����ж�ȷ���ո��*�ĸ���
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
			printf("\n");//ע�⻻�з���λ�ã�
		}
		for (int m = 1; m <= a; m++)//ͬ���ķ�ʽ��ʾ���°����ͷ
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
/*BC73 �ҿ�Σ�� */
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
/*BC74 HTTP״̬�� */
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
			printf("�������\n");
			break;
		}
	}
	return 0;
}
/*BC77 �������в���һ���� */
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
