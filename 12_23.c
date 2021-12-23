#define _CRT_SECURE_NO_WARNINGS
/*指针进阶二级指针应用*/
#include<stdio.h>
void test(int** p2)
{
	**p2 = 20;
}
int main()
{
	int a = 10;
	int* pa = &a;
	int** ppa = &pa;
	test(ppa);
	printf("%d", a);
	return 0;
}
/*函数指针*/
int Add(int x, int y)
{
	return x + y;
}
#include<stdio.h>
int main()
{
	int (*pa)(int, int) = Add;//不用写&符号。
	//所以pa==Add
	int ret = (*pa)(3,5);
	//int ret = Add(3,5);
	printf("%d", ret);
	return 0;
}
/*函数指针数组*/
/*简易计算器的制作*/
void menu()
{
	printf("**********1.Add**********\n");
	printf("**********2.Sub*************\n");
	printf("**********3.mul*************\n");
	printf("**********4.div*************\n");
	printf("**********0.exit*************\n");
	printf("****************************\n");
}
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
#include<stdio.h>
int main()
{
	int n = 0;
	do
	{
		menu();
		int (*pfarr[5])(int, int) = { NULL,Add,Sub,Mul,Div };
		int x = 0;
		int y = 0;
		int ret = 0;
		printf("请选择：");
		scanf("%d", &n);
		printf("请输入两个操作数");
		scanf("%d %d", &x, &y);
		ret = (pfarr[n])(x, y);
		printf("%d\n", ret);
	} while (n);
	return 0;
}