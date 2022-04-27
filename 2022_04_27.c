//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
void swap(int* x, int* y)
{
	int t = 0;
	t = *x;
	*x = *y;
	*y = t;
}
//void AdjustDown(int* a, int n, int root)
//{
//	int parent = root;
//	int child = parent * 2 + 1;
//	
//	while (child  < n)
//	{
//		//ÿ�ε�������Ҫ����������ѡ�����������Ǹ�
//		//���������ӽϴ�ѡ�����Һ��Ӵ���Ǹ�
//		if (child + 1 < n && a[child + 1] > a[child])
//		{
//			++child;
//		}
//		//��ʼ������
//		if (a[child] > a[parent])
//		{
//			swap(&a[child], &a[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		//���������������ʼ�´�forѭ��������
//		else
//		{
//			break;
//		}
//	}
//
//}
//void AdjustUp(int* a, int child)
//{
//	int parent = (child - 1) / 2;
//	while (child > 0)
//	{
//		if (a[child] > a[parent])
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
//}
//void HeapSort(int* a, int n)
//{
//	//���µ�������O(N)
//	/*int i = 0;
//	for (i = (n - 1 - 1) / 2; i >= 0; i--)
//	{
//		AdjustDown(a, n, i);
//	}*/
//	//���ϵ�������O(N* LogN)
//	int i = 0;
//	for (i = 1; i < n; i++)
//	{
//		AdjustUp(a, i);
//	}
//	//���µ�������
//	int end = 0;
//	for (end = n-1; end > 0; end--)
//	{
//		swap(&a[0], &a[end]);
//		//���µ���ʱ���������Ǹ�ֵ������end��n-1��
//		AdjustDown(a, end, 0);
//
//	}
//}
//int main()
//{
//	int arr[] = { 4,2,7,8,5,1,0,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	HeapSort(arr, sz);
//	return 0;
//}
//�鲢����ݹ�汾
//#include <stdio.h>
//#include<assert.h>
//#include <stdlib.h>
//#include <string.h>
//_MergeSort(int* a, int begin, int end, int* tmp)
//{
//	if (begin >= end)
//		return;
//	int mid = (begin + end) / 2;
//	_MergeSort(a, begin, mid, tmp);
//	_MergeSort(a, mid + 1, end, tmp);
//	/*printf("�鲢[%d][%d]��[%d][%d]", 
//		begin, mid, mid + 1, end);*/
//	int begin1 = begin, end1 = mid;
//	int begin2 = mid + 1, end2 = end;
//	int t = begin;
//	//������һ������������ֵ��Ϊ�վͿ�ʼ�Ƚϴ�С
//	while (begin1 <= end1 && begin2 <= end2)
//	{
//		if (a[begin1] < a[begin2])
//		{
//			tmp[t] = a[begin1];
//			t++;
//			begin1++;
//		}
//		else
//		{
//			tmp[t] = a[begin2];
//			t++;
//			begin2++;
//		}
//	}
//	while (begin1 <= end1)
//	{
//		tmp[t++] = a[begin1++];
//	}
//	while (begin2 <= end2)
//	{
//		tmp[t++] = a[begin2++];
//	}
//
//	memcpy(a+ begin, tmp + begin, sizeof(int) * (end - begin + 1));
//}
//void MergeSort(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	assert(tmp);
//	_MergeSort(a, 0, n - 1, tmp);
//
//	free(tmp);
//}

//int main()
//{
//	int arr[] = { 10,6,7,1,3,9,4,2 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	MergeSort(arr, sz);
//	return 0;
//}

//ѡ������
//#include <stdio.h>
//void SelectSort(int* a, int n)
//{
//	int i = 0;
//	int j = 0;
//	for (j = 0; j < n; j++)
//	{
//		int min = a[j];
//		int mini = j;
//		for (i = j+1; i < n; i++)
//		{
//			if (a[i] < min)
//			{
//				mini = i;
//			}
//		}
//		swap(&a[j], &a[mini]);
//	}
//}
int PartSort(int* a, int begin, int end)
{
	//int midi = GetMidIndex(a, left, right);
//Swap(&a[midi], &a[left]);

	int key = begin;
	int prev = begin;
	int cur = begin + 1;
	while (cur <= end)
	{
		if (a[cur] < a[key] && a[++prev] != a[cur])
		{
			swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	swap(&a[prev], &a[key]);

	return prev;
}
void QuickSort(int* a, int left, int right)
{
	if (right <= left)
	{
		return;
	}
	int div = PartSort(a, left, right);
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
}
int main()
{
	int arr[] = {-1,2,-8,-10};
	int sz = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, sz-1);
	return 0;
}