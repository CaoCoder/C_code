//#define _CRT_SECURE_NO_WARNINGS
////#include <stdio.h>
////// ϣ������
////void InsertSort(int* a, int n)
////{
////	int gap = n;
////	
////	while (gap > 1)
////	{
////		//�Ƚ���Ԥ����ֱ��gapΪ1.ֱ�Ӳ�������
////		gap = gap / 2;
////		for (int i = 0; i < n - gap; i++)
////		{
////			//��������
////			int end = i;
////			int tmp = a[end + gap];
////			while (end >= 0)
////			{
////				if (tmp < a[end])
////				{
////					a[end + gap] = a[end];
////					end = end - gap;
////				}
////				//ǰ�������ˣ�����ֱ������ѭ�������뼴ok
////				else
////				{
////					break;
////				}
////			}
////			a[end + gap] = tmp;
////		}
////	}
////}
////int main()
////{
////	int arr[] = {9,8,7,6,5,4,3,2,1,0};
////	int sz = sizeof(arr) / sizeof(arr[0]);
////	// ��������
////	InsertSort(arr, sz);
////	return 0;
////}
////������
//#include<stdio.h>
//void swap(int* x, int* y)
//{
//	int t = 0;
//	t = *x;
//	*x = *y;
//	*y = t;
//}
//void AdjustUp(int* a, int child)
//{
//	int parent = (child - 1) / 2;
//	while (child > 0)
//	{
//		if (a[child] < a[parent])
//		{
//			swap(&a[child], &a[parent]);
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//		else
//		{
//			break;
//		}
//	}
//	
//}
//void AdjustDown(int* a, int n, int root)
//{
//	int parent = root;
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		//ѡ�����Һ���С���Ǹ�
//		if (child + 1 < n && a[child + 1] > a[child])
//		{
//			++child;
//		}
//		//2.������״��ں��ӣ��򽻻������������µ������ס�
//		if (a[child] > a[parent])
//		{
//			swap(&a[child], &a[parent]);
//			//���µ�����ĸ����Ϊ��Ҫ��֤���������С��
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//void HeapSort(int* a, int n)
//{
//	//���ϵ�������
//	/*for (int i = 1; i < n; i++)
//	{
//		AdjustUp(a, i);
//	}*/
//	//���µ�������
//	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
//	{
//		AdjustDown(a, n, i);
//	}
//	int end = n - 1;
//	while (end > 0)
//	{
//		swap(&a[0], &a[end]);
//		AdjustDown(a, end, 0);
//		--end;
//	}
//}
//int main()
//{
//	int arr[] = { 4,2,7,8,5,1,0,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	HeapSort(arr, sz);
//}