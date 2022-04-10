#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int a = 5;
//void fun(int b)
//{
//	static int a = 10;
//	a += b++;
//	printf("a = %d", a);
//}
//int main()
//{
//	int b = 20;
//	fun(b++);//a = 30 b = 21
//	a += b;//a = 5+21
//	fun(b);// a = 30 + 21
//	printf("a = %d", a);// a= 26
//	return 0;
//}
int main()
{
	float x = 1;
	float y = 0.0;
	//y = ++x * ++x;
	++x;
	++x;
	y = x * x;


	printf("%f\n", y);
}