#define _CRT_SECURE_NO_WARNINGS
//╡ЕхКеепР
//#include <stdio.h>
//void InsertSort(int* a, int n)
//{
//	
//	int i = 0;
//	//n-1лиеепР
//	for (i = 0; i < n - 1; i++)
//	{
//		//╣╔лкеепР
//		int end = i;
//		int tmp = a[end + 1];
//		while (end >= 0)
//		{
//			if (tmp < a[end])
//			{
//				a[end + 1] = a[end];
//				end = end - 1;
//			}
//			else
//			{
//				break;
//			}
//		}
//		a[end + 1] = tmp;
//	}
//}
//#include <stdio.h>
//void InsertSort(int* a, int n)
//{
//
//	int i = 0;
//	//n-1лиеепР
//	for (i = 0; i < n - 1; i++)
//	{
//		//╣╔лкеепР
//		int end = i;
//		int tmp = a[end + 1];
//		while (end >= 0)
//		{
//			if (tmp < a[end])
//			{
//				a[end + 1] = a[end];
//				end = end - 1;
//			}
//			else
//			{
//				break;
//			}
//		}
//		a[end + 1] = tmp;
//	}
//}
//int main()
//{
//	int arr[] = { 5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	InsertSort(arr, sz);
//	return 0;
//}
//#include <stdio.h>
////оё╤ШеепР
//void ShellSort(int* a, int n)
//{
//	//т╓еепР
//	int gap = n;
//	while (gap > 1)
//	{
//		gap = gap / 2;
//		//╫Ьпп╪Д╦Тн╙gap╣д╡ЕхКеепР
//		int i = 0;
//		for (i = 0; i < n - gap; i++)
//		{
//			//╣╔лкеепР
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (tmp < a[end])
//				{
//					a[end + gap] = a[end];
//					end = end - gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			a[end + gap] = tmp;
//		}
//	}
//
//}
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	ShellSort(arr, sz);
//	return 0;
//}