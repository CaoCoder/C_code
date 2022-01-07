#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		int i = 0;
		for (i = 1; i <= n; i++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
#include<stdio.h>
int main()
{
	printf("Happy New Year*2019*");
	return 0;
}
/*BC72 平均身高 */
#include<stdio.h>
int main()
{
	float arr[5] = { 0 };
	float sum = 0;
	for (int i = 0; i < 5; i++)
	{
		scanf("%f", &arr[i]);
		sum += arr[i];
	}
	float b = sum / 5.0;
	printf("%.2f", b);
	return 0;
}