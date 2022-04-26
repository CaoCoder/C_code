#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//������
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
//	//ѡ�����Һ��������Ǹ�
//	if (child + 1 < n && a[child + 1] > a[child])
//	{
//		child = child + 1;
//	}
//	//Ȼ���ж��Ƿ���Ҫ����
//	while (child < n)
//	{
//		if (a[child] > a[parent])
//		{
//			swap(&a[child], &a[parent]);
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
//	//���򽨴�ѣ����µ���
//	int i = 0;
//	for (i = (n - 1 - 1) / 2; i >= 0; i--)
//	{
//		AdjustDown(a, n, i);
//	}
//	//��ʼ�Ѷ�ȡԪ��������
//	int end = n - 1;
//	while (end > 0)
//	{
//		swap(&a[0], &a[end]);
//		//������end��������end��һ����������������BUG
//		AdjustDown(a, end, 0);
//		--end;
//	}
//}
//int main()
//{
//	int arr[] = {4,2,7,8,4,1,0,6};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	HeapSort(arr, sz);
//	return 0;
//}
//ϣ������
//#include <stdio.h>
//void ShellSort(int* a, int n)
//{
//	int gap = n;
//	while (gap > 1)
//	{
//		gap = gap / 2;
//		for (int i = 0; i < n - gap; i++)
//		{
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (tmp < a[end])
//				{
//					swap(&a[end], &a[end + gap]);
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
//	int arr[] = {9,1,2,5,7,4,8,6,3,5};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	ShellSort(arr, sz);
//	return 0;
//}

//��������Hoare
//int PartSort(int* a, int left,int right)
//{
//	int key = left;
//	while (left < right)
//	{
//		while (left < right && a[right] >= a[key])
//		{
//			--right;
//		}
//		while (left < right && a[left] <= a[key])
//		{
//			++left;
//		}
//		swap(&a[left], &a[right]);
//	}
//	swap(&a[left], &a[key]);
//
//	return left;
//}
//void QuickSort(int* a, int left, int right)
//{
//	//���и�����Ϊ�յ�ʱ��right-left��С��0��
//	if (right - left < 0)
//		return;
//
//	int div = PartSort(a, left, right);
//
//	QuickSort(a, left, div-1);
//	QuickSort(a, div+1, right);
//
//}
//int main()
//{
//	int arr[] = {6,1,2,7,9,3,4,5,10,8};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	QuickSort(arr, 0, sz-1);
//	return 0;
//}
//��������ǰ��ָ�뷨
//int PartSort(int* a, int left, int right)
//{
//	int prev = left;
//	int cur = left + 1;
//	int key = left;
//	while (cur <= right)
//	{
//		if (a[cur] < a[key] && a[++prev] != a[cur])
//		{
//			swap(&a[cur], &a[prev]);
//		}
//		++cur;
//	}
//	swap(&a[prev], &a[key]);
//
//	return prev;
//}
//QuickSort(int* a, int left, int right)
//{
//	if (right - left < 1)
//		return;
//	int div = PartSort(a, left, right);
//
//	QuickSort(a, left, div - 1);
//	QuickSort(a, div + 1, right);
//
//}
//int main()
//{
//	int arr[] = {6,1,2,7,9,3,4,5,10,8};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	QuickSort(arr, 0, sz-1);
//	return 0;
//}

//�鲢����
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);
	/*printf("�鲢[%d,%d][%d,%d]\n", 
		begin, mid, mid+1, end);*/
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int index = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];
	while (begin2 <= end2)
		tmp[index++] = a[begin2++];

	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}
MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp);
	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}
int main()
{
	int arr[] = {10,6,7,1,3,9,4,2};
	int sz = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, sz);
	return 0;
}