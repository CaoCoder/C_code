#define _CRT_SECURE_NO_WARNINGS
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	int** ppa = &p;
//	matrix(ppa);
//	return 0;
//}
//int main()
//{
//	int* arr[10];
//	matrix(arr);
//	return 0;
//}
/*旋转数组*/
//#include<stdio.h>
//void roate(char* arr, int sz, int k)
//{
//	int j = 0;
//	char t = 0;
//	int i = 0;
//	for (i = 0; i < k; i++)
//	{
//		t = *arr;
//		for (j = 0; j < sz - 1; j++)
//		{
//			*(arr+j) = *(arr + j + 1);
//		}
//		*(arr + sz - 1) = t;
//	}
//}
//int main()
//{
//	char arr[] ="abcd";
//	int sz = sizeof(arr) / sizeof(arr[0])-1;
//	roate(arr, sz, 1);
//	printf("%s", arr);
//	return 0;
//}
#include<stdio.h>
menu()
{
	printf("********1.加法********\n");
	printf("********2.减法********\n");
}
ADD(int x, int y)
{
	return x + y;
}
SUB(int x, int y)
{
	return x - y;
}
int main()
{
	int n = 0;
	int x = 0;
	int y = 0;
	int ret = 0;
	int (*p[3])(int, int) = { 0, ADD, SUB };
	do
	{
		menu();
		scanf("%d", &n);
		if (n == 0)
		{
			printf("退出游戏");
			break;
		}
		if (n >= 1 && n <= 2)
		{
			scanf("%d %d", &x, &y);
			ret = p[n](x, y);
			printf("ret = %d", ret);
		}
		else
		{
			printf("选择错误\n");
		}
	} while (n);
	return 0;
}