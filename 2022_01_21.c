#define _CRT_SECURE_NO_WARNINGS
/*qsort函数冒泡排序模拟*/
//#include<stdio.h>
//int cmp(const void* e1, const void* e2)
//{
//	return *(char*)e1 - *(char*)e2;
//}
//void swap(char* x, char* y, int base)
//{
//	int i = 0;
//	for (i = 0; i < base; i++)
//	{
//		char t = 0;
//		t = *x;
//		*x = *y;
//		*y = t;
//		x++;
//		y++;
//	}
//}
//void Bubble(int* arr, int sz, int base, int (*p)(const void* e1, const void* e2))
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		for (j = 0; j < sz-1-i; j++)
//		{
//			if (p((char*)arr+j*base, (char*)arr+(j+1)*base)>0)
//			{
//				swap((char*)arr + j * base, (char*)arr + (j + 1) * base, base);
//			}
//		}
//	}
//}
//void Print(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	int arr[] = { 5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Bubble(arr, sz, sizeof(arr[0]),cmp);
//	Print(arr, sz);
//	return 0;
//}
///*qsort函数的使用*/
////#include<stdlib.h>
////#include<stdio.h>
////int cmp(const void* e1, const void* e2)
////{
////	return *(int*)e1 - *(int*)e2;
////}
////void Print(int* arr, int num)
////{
////	int i = 0;
////	for (i = 0; i < num; i++)
////	{
////		printf("%d ", *(arr + i));
////	}
////}
////int main()
////{
////	int arr[] = { 5,4,3,2,1 };
////	int num = sizeof(arr) / sizeof(arr[0]);
////	qsort(arr, num, sizeof(arr[0]), cmp);
////	Print(arr, num);
////	return 0;
////}
// /*简单的冒泡排序*/
//#include<stdio.h>
//void Bubble(int* arr, int sz)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int t = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = t;
//			}
//		}
//	}
//}
//void Print(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	int arr[] = { 5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Bubble(arr, sz);
//	Print(arr, sz);
//	return 0;
//}