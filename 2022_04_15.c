#define _CRT_SECURE_NO_WARNINGS

//void fun(int n,int*s)
//{
//	int f1, f2;
//	if (n == 1 || n == 2)
//	*s = 1; 
//	else
//	{
//		fun(n - 1, &f1);
//		fun(n - 2, &f2);
//		*s = f1 + f2;
//	}
//}
//int main() 
//{
//	int x;
//	fun(6, &x);
//	printf("%d\n", x);
//}
#include <stdio.h>
void sub(char* a, char B)
{
	while (*(a++) != '\0')
	{
		;
	}
	while (*(a - 1) < B)
	{
		*(a--) = *(a - 1);
	}
	*(a--) = B;
}
void main()
{
	char s[20] = "prmfe", c;
	c = getchar();
	sub(s, c);
	puts(s);
}