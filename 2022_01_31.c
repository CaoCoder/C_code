//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
////int removeDuplicates(int* nums, int numsSize)
////{
////	int left = 0;
////	int right = 0;
////	if (numsSize == 0) {
////		return 0;
////	}
////	while (right < numsSize)
////	{
////		if (nums[left] == nums[right])
////		{
////			right++;
////		}
////		else
////		{
////			left++;
////			nums[left] = nums[right];
////		}
////	}
////	return left+1;
////}
//int removeDuplicates(int* nums, int numsSize)
//{
//    if (numsSize == 0)
//    {
//        return 0;
//    }
//    int i = 0, j = 1;
//    while (j < numsSize)
//    {
//        if (nums[i] != nums[j])
//        {
//            i++;
//            nums[i] = nums[j];
//        }
//        j++;
//    }
//    return i + 1;
//}
//int main()
//{
//	int arr[] = {0,0,1,1,1,2,2,3,3,4};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = removeDuplicates(arr, sz);
//	int i = 0;
//	for (i = 0; i < ret; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}