#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int removeElement(int* nums, int numsSize, int val)
{
	int i = 0;
	int j = 0;
	while (i < numsSize)
	{
		if (nums[i] != val)
		{
			nums[j] = nums[i];
			i++;
			j++;
		}
		else
		{
			i++;
		}
	}
	return j;
}
int main()
{
	int arr[] = { 0,1,2,2,3,0,4,2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret  = removeElement(arr, sz, 2);
	printf("%d", ret);
	return 0;
}
