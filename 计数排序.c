//#include <assert.h>
//#include <stdlib.h>
//void CountSort(int* a, int n)
//{
//	int min = a[0], max = a[0];
//	for (int i = 1; i < n; ++i)
//	{
//		if (a[i] < min)
//			min = a[i];
//
//		if (a[i] > max)
//			max = a[i];
//	}
//
//	int range = max - min + 1;
//	int* countA = (int*)malloc(sizeof(int) * range);
//	assert(countA);
//	memset(countA, 0, sizeof(int) * range);
//
//	// ¼ÆÊý
//	for (int i = 0; i < n; ++i)
//	{
//		countA[a[i] - min]++;
//	}
//
//	// ÅÅÐò
//	int j = 0;
//	for (int i = 0; i < range; ++i)
//	{
//		while (countA[i]--)
//		{
//			a[j++] = i + min;
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	CountSort(arr, sz);
//	Print(arr, sz);
//	return 0;
//}