#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/*27. 移除元素*/
//int removeElement(int* nums, int numsSize, int val)
//{
//	int* p = nums;
//	int* q = nums;
//	int Size = numsSize;
//	for (; p < nums + numsSize; p++)
//	{
//		if (*p == val)
//		{
//			Size--;//3  2 
//		}
//		else
//		{
//			*q++ = *p;//2 2 2 3
//		}
//	}
//	return Size;
//}
//int main()
//{
//	int nums[] = { 2,1,1,1 };
//	int numsSize = sizeof(nums) / sizeof(nums[0]);
//	int ret = removeElement(nums, numsSize, 2);
//	for (int i = 0; i < ret; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//	return 0;
//}
/*删除排序数组中的重复项*/
int removeDuplicates(int* nums, int numsSize)
{
	int* q = nums;
	int* p = nums + 1;
	int c = 0;
	while (p < nums + numsSize)
	{
		if (*p == *q)
		{
			p++;
		}
		else
		{
			c++;
			*(++q)= *p++;
		}
	}
	return c + 1;
}
#include<stdio.h>
int main()
{
	int nums[] = { 0,0,1,1,2,2,2,3,3,4 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int ret = removeDuplicates(nums, numsSize);
	for (int i = 0; i < ret; i++)
	{
		printf("%d ", nums[i]);
	}
	return 0;
}
