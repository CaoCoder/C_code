#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void BubbleSort(int* a, int n)
{
	int i = 0;
	int tag = 1;
	for (i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				tag = 0;
				int t = 0;
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
		if (tag == 1)
		{
			break;
		}
	}
}
void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
void BubbleTest()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, n);
	Print(arr, n);
}

void swap(int* left, int* right)
{
	int tmp = 0;
	tmp = *left;
	*left = *right;
	*right = tmp;
}

// ¿ìËÙÅÅÐòhoare°æ±¾
int PartSort1(int* a, int left, int right)
{
	int key = left;
	while (left < right)
	{
		while (left < right && a[right] > a[key])
		{
			right--;
		}
		while (left < right && a[left] < a[key])
		{
			left++;
		}
		swap(&a[left], &a[right]);
	}
	swap(&a[key], &a[left]);

	return left;
}
void QuickSort(int* a, int left, int right)
{
	if (right - left < 1)
		return;
	int div = PartSort1(a, left, right);

	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
}
void QuickTest()
{
	//int arr[] = { 9,8,7,6,5,4,3,2,1,0};
	int arr[] = { 6,1,2,7,9,3,4,5,10,8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, n - 1);
}
int main()
{
	//Ã°ÅÝÅÅÐò
	//BubbleTest();
	//¿ìËÙÅÅÐò
	QuickTest();
	return 0;
}