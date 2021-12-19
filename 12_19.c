#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int m = 0;
	int k = 11;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);//10
	int left = 0;//0
	int right = sz - 1;                 
	while (left <= right)               
	{                                
		m = (left + right) / 2;
		if (arr[m] < k)
		{
			left = m + 1;
		}
		else if (arr[m] > k)
		{
			right = m - 1;
		}
		else
		{
			printf("找到了下标是%d", m);
			break;
		}
	}
	if (right < left)
	{
		printf("没找到");

	}
	return 0;
}
//0 1 2 3 4 5 6 7 8 9
//(0 + 9) / 2 = 4 = m
//(5 + 9) / 2 = 7 = m
//(5 + 6)/ 2 = 5 = m
//(6 + 6 )/ 2  = 6 = m