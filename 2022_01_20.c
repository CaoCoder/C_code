#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
menu()
{
	printf("******1.�ӷ�*******\n");
	printf("******2.����*******\n");
	printf("******3.�˷�*******\n");
	printf("******4.����*******\n");
}
Add(int x, int y)
{
	return x + y;
}
Sub(int x, int y)
{
	return x - y;
}
Mul(int x, int y)
{
	return x * y;
}
Div(int x, int y)
{
	return x / y;
}
Cal(int (*p)(int, int))
{
	int x = 0;
	int y = 0;
	int result = 0;
	printf("����������������\n");
	scanf("%d %d", &x, &y);
	result = p(x, y);
	printf("�����%d\n", result);
}
int main()
{
	int n = 0;
	do
	{
		menu();
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			Cal(Add);
			break;
		case 2:
			Cal(Sub);
			break;
		case 3:
			Cal(Mul);
			break;
		case 4:
			Cal(Div);
			break;
		case 0:
			printf("�˳�������\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (n);
	return 0;
}
/*qsort����ģ��*/
#include<stdio.h>
#include<stdlib.h>
int cmp(const void* e1, const void* e2)
{
	return *((int*)e1) - *((int*)e2);
}
int main()
{
	int arr[] = { 1,3,5,7,9,2,4,6,8,0};
	qsort(arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), cmp);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

