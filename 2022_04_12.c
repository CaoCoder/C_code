#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void Slesort(int a[], int n);
void output(int a[], int n);
int findb(int a[], int n, int x);
void main()
{
	int ar[10] = {9,7,8,6,4,5,1,2,3 };
	int m = 10, i, x, k, mid;
	printf("排序前数组为\n:");
	output(ar, m);
	Slesort(ar, m);
	scanf("%d", &x);
	k = findb(ar, m, x);
	if (k == -1)
		printf("没找到");
	else 
		printf("%d", k);
}
void output(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%5d", a[i]);
	printf("\n");
}
void Slesort(int a[], int n)
{
	int i, j, min, tem;

	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		tem = a[i];
		a[i] = a[min];
		a[min] = tem;
	}
	printf("排序后数组为\n:");
	for (i = 0; i < n; i++)
		printf("%5d", a[i]);
}
int findb(int a[], int n, int x)
{
	int left = 0;
	int right = n - 1;
	int mid = 0; 
	int k = -1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == x)
		{
			k = mid;
			return k;
		}
		else if (x < a[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}