#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	float a = 0;
	float b = 0;
	float c = 0;
	scanf("%f%f", &a, &b);
	c = (a + b) * 0.54;
	printf("%.2f", c);
	return 0;
}