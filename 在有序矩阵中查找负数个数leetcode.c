#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int BinarySearch(int* a, int n,int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (a[mid] < n)
//		{
//			left = mid + 1;
//		}
//		else if (a[mid] > n)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return a[mid];
//		}
//	}
//	if (left > right)
//	{
//		return -1;
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int b = BinarySearch(arr, 7, sz);
//	if (b == -1)
//	{
//		printf("√ª’“µΩ");
//	}
//	else
//	{
//		printf("%d", b);
//	}
//	return 0;
//}
int countNegatives(int** grid, int gridSize, int* gridColSize) {
    int count = 0;
    for (int i = 0; i < gridSize; i++)
    {
        int left = 0; int right = *gridColSize;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (grid[i][mid] < 0)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        count += ((*gridColSize) - left);
    }
    return count;
}
int main()
{
    int arr[4][4] = { {4,3,2,-1 }, {3, 2, 1, -1},{1, 1, -1, -2},{-1, -1, -2, -3 } };
    int sz = sizeof(arr) / sizeof(arr[0][0]);
    int count = countNegatives(arr, sz, )
    return 0;
}
