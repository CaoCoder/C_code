#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void Swap(int* x, int* y)
{
	int t = 0;
	t = *x;
	*x = *y;
	*y = t;
}
int PartSort(int* a, int left, int right)
{
	int key = left;
	int prev = left;
	int cur = left + 1;
	//推荐写法一，较好理解
	while (cur <= right)
	{
		if (a[cur] < a[key])
		{
			++prev;
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	Swap(&a[prev], &a[key]);

	return prev;
}
int PartSort(int* a, int left, int right)
{
	int keyval = a[left];
	int pit = left;
	while (left < right)
	{
		while (left < right && a[right] >= keyval)
		{
			right--;
		}
		a[pit] = a[right];
		pit = right;
		while (left < right && a[left] <= keyval)
		{
			left++;
		}
		a[pit] = a[left];
		pit = left;
	}

	a[pit] = keyval;

	return left;
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int div = PartSort(a, left, right);
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
}
int main()
{
	
	int arr[] = { 6,1,2,7,9,3,4,5,10,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, sz-1);
	return 0;
}