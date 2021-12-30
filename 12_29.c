#define _CRT_SECURE_NO_WARNINGS
/*删除有序排序数组的重复项*/
/*双指针，快慢指针*/
//int removeDuplicates(int* nums, int numsSize)
//{
//	int left = 0;
//	int right = 1;//1 1 2
//	while (right <= numsSize-1)
//	{
//		if (nums[left] == nums[right])
//		{
//			right++;
//		}
//		else
//		{
//			left++;
//			nums[left] = nums[right];
//		}
//	}
//	return left+1;
//}
//#include<stdio.h>
//int main()
//{
//	int nums[] = {1,1,1};
//	int numsSize = sizeof(nums) / sizeof(nums[0]);
//	int ret= removeDuplicates(nums, numsSize);
//	printf("%d", ret);
//	return 0;
//}
/*买卖股票最佳时机*/
/*贪心小算法*/
//int maxProfit(int* prices, int pricesSize)
//{
//	int i = 0;
//	int max = 0;
//	for (i = 0; i < pricesSize - 1; i++)
//	{
//		if (prices[i] < prices[i + 1])
//		{
//			max = max + prices[i + 1] - prices[i];
//		}
//	}
//	return max;
//}
//#include <stdio.h>
//int main()
//{
//	int prices[] = { 1,2,3,4,5 };
//	int pricesSize = sizeof(prices) / sizeof(prices[0]);
//	int max = maxProfit(prices, pricesSize);
//	printf("%d", max);
//	return 0;
//}
/*旋转数组*/
//void rotate(int* nums, int numsSize, int k)
//{
//	int i = 0;
//	int j = 0;
//	int a = 0;
//	for (i = 0; i < k; i++)
//	{
//		a = nums[numsSize - 1];
//		for (j = numsSize-1;j > 0;j--)
//		{
//			nums[j] = nums[j - 1];
//		}
//		nums[0] = a;
//
//	}
//}
//#include<stdio.h>
//int main()
//{
//	int nums[] = { -1,-100,3,99 };
//	int numsSize = sizeof(nums) / sizeof(nums[0]);
//	rotate(nums, numsSize, 2);
//	int i = 0;
//	for (i = 0; i < numsSize; i++)
//	{
//		printf("%d,", nums[i]);
//	}
//	return 0;
//}
/*存在重复元素*/
//int containsDuplicate(int* nums, int numsSize)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < numsSize - 1; i++)
//	{
//		for (j = 0; j < numsSize - 1 - i; j++)
//		{
//			if (nums[j] > nums[j + 1])
//			{
//				int t = nums[j];
//				nums[j] = nums[j + 1];
//				nums[j + 1] = t;
//			}
//		}
//	}
//	for (i = 0; i < numsSize; i++)
//	{
//		if (nums[i] == nums[i + 1])
//		{
//			return 0;
//			break;
//		}
//	}
//	if (i == numsSize)
//	{
//		return 1;
//	}
//}
//#include<stdio.h>
//int main()
//{
//	int nums[] = {1,2,3};
//	int numsSize = sizeof(nums) / sizeof(nums[0]);
//	int ret = containsDuplicate(nums, numsSize);
//	printf("%d", ret);
//	return 0;
//}

/*qsort函数*/
//#include<stdio.h>
//int sort(const void* e1 , const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//void print(int arr[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	int arr[] = { 2,4,6,1,3,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), sort);
//	print(arr, sz);
//	return 0;
//}
//qsort(void* base,
//	  int sum,
//	  int width,
//	  void(*)(int, int),
//)
/*只出现一次的数字*/
/*异或运算巧妙消消乐*/
//int singleNumber(int* nums, int numsSize)
//{
//	int i = 0;
//	int result = 0;
//	for (i = 0; i < numsSize; i++)
//	{
//		result ^= *(nums+i);
//	}
//	return result;
//}
//#include<stdio.h>
//int main()
//{
//	int nums[] = { 4,1,2,1,2 };
//	int numsSize = sizeof(nums) / sizeof(nums[0]);
//	int ret = singleNumber(nums, numsSize);
//	printf("%d", ret);
//	return 0;
//}
/*两个数组的交集*/
//int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
//{
//
//}
//#include<stdio.h>
//int main()
//{
//	int  nums1[] = { 1,2,2,1 };
//	int nums2[] = { 2,2 };
//	int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
//	int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
//	intersect(nums1,nums1Size,nums2,nums2Size,);
//	return 0;
//}
//int cmp(const void* _a, const void* _b)
//{
//	int* a = _a, * b = (int*)_b;
//	return *a == *b ? 0 : *a > *b ? 1 : -1;
//}
//int* intersect(int* nums1, int nus1Size, int* nums2, int nums2Size, int* returnSize)
//{
//	qsort(nums1, nums1Size, sizeof(int), cmp);
//	qsort(nums2, nums2Size, sizeof(int), cmp);
//	*returnSize = 0;
//	int* intersection = (int*)malloc(sizeof(int) * fmin(nums1Size, nums2Size));
//	int index1 = 0;
//	int index2 = 0;
//	while (index1 < nums1Size && index2 < nums2Size)
//	{
//		if (nums1[index1] > nums2[index2])
//		{
//			index1++;
//		}
//		else if (nums1[index1] > nums2[index2])
//		{
//			index2++;
//		}
//		else
//		{
//			intersection[(*returnSize)++] = nums1[index1];
//			index1++;
//			index2++;
//		}
//	}
//	return intersection;
//}