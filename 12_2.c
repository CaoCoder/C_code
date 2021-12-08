#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
///*用max()函数求两个整数的最大值*/
//#include<stdio.h>
//int Max(int a, int b)
//{
//	int max = a > b ? a : b;
//	return max;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int n = 0;
//	scanf("%d%d", &a, &b);
//	n = Max(a, b);
//	printf("%d", n);
//	return 0;
//}
///*定义一个求n个整数和的函数sum（）*/
//#include<stdio.h>
//int sum(int n)//功能
//{
//	int i = 0;
//	int a = 0;
//	int s = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &a);
//		s = s + a;
//	}
//	return s;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int a = sum(n);
//	printf("%d", a);
//	return 0;
//}
///*计算组合数使用嵌套函数*/
//#include<stdio.h>
//int mn(m, n)
//{
//	int a = m - n;
//	int s = 1;
//	while (a != 1)
//	{
//		s = s * a;
//		a = a - 1;
//	}
//	return s;
//	
//}
//int nnn(n)
//{
//	int s = 1;
//	while (n != 1)
//	{
//		 s = s * n;
//		 n = n - 1;
//	}
//	return s;
//}
//int mmm(m)
//{
//	int s = 1;
//	while (m != 1)
//	{
//		s = s * m;
//		m = m - 1;
//	}
//	return s;
//}
//int math(int n,int m)
//{
//	mmm(m);
//	nnn(n);
//	mn(m, n);
//	return (mmm(m) / nnn(n) * mn(m, n));
//}
//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d%d", &n, &m);
//	printf("%d", math(n, m));
//	return 0;
//}
///*求两点的距离*/
//#include<stdio.h>
//#include<math.h>
//double dist(double x, double y, double x1, double y1)
//{
//	double a = sqrt((abs(x - x1)) * abs(x - x1) + abs(y - y1) * abs(y - y1));
//	return a;
//}
//int main()
//{
//	double x = 0;
//	double y = 0;
//	double x1 = 0;
//	double y1 = 0;
//	scanf("%lf%lf%lf%lf", &x, &y, &x1, &y1);
//	double b = dist(x, y, x1, y1);
//	printf("%.2lf", b);
//	return 0;
//}
///*计算标准体重*/
//#include<stdio.h>
//float fun(int x)
//{
//	return ((x - 100) * 0.9 * 2);
//}
//int main()
//{
//	int h = 0;
//	float w = 0;
//	scanf("%d", &h);
//	float a = fun(h); 
//	printf("%.1f", a);
//	return 0;
//}
///*编写一个函数让数组中每一个数乘以5输出*/
//#include<stdio.h>
//void fun(int arr[], int n)
//{
//	int a = 0;
//	while (a<n)
//	{
//		 arr[a] = arr[a]* 5;
//		 ++a;
//	}
//}
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	fun(arr,5);
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
///*求阶乘和数*/
//#include<stdio.h>
//int fac(int arr[])
//{
//	int a = 1;
//	int n = 0;
//	int t = 1;
//	while (t != 3)
//	{
//		a = a * n;
//		n = n - 1;
//		++t;
//	}
//	return a;
//}
//int fun(int m)
//{
//	int i = 0;
//	int arr[3] = { 0 };
//	int s = 0;
//
//	while (m)
//	{
//		arr[i] = m % 10;
//		m = m / 10;
//		s = s + fac(arr[i]);
//		i++;
//	}
//	if (m == s)
//	{
//		printf("%d",)
//	}
//}
//int main()
//{
//	int m = 0;
//	scanf("%d", &m);
//	fun(m);
//	return 0;
//}
///*求任意整数的逆序数*/
//#include<stdio.h>
//void fun(int n)
//{
//	do
//	{
//		int a = n % 10;
//		printf("%d", a);
//		n = n / 10;
//	} while(n);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	fun(n);
//	return 0;
//}
///*利用递归求n的阶乘*/
//#include<stdio.h>
//int fun(int n)
//{
//	if (1 == n)
//	{
//		return 1;
//	}
//	if (n > 1)
//	{
//		return n * fun(n - 1);
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", fun(n));
//	return 0;
//}
///*打印数字金字塔*/
//#include<stdio.h>
//void py(int n)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = i; j < n - 1; j++)
//		{
//			printf(" ");
//		}
//		int k = 0;
//		for (k = 0; k < 2 * (i + 1) - 1; k++)
//		{
//			printf("%d", i+1);
//		}
//		printf("\n");
//	}
//	
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	py(n);
//	return 0;
//}
///*输出3-100之间的素数*/
//#include<stdio.h>
//#include<math.h>
//void prime()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 3; i <= 100; i++)
//	{
//		for (j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (i == j)
//		{
//			printf("%d  ", i);
//		}
//	}
//}
//int main()
//{
//	prime();
//	return 0;
//}
