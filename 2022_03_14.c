#define _CRT_SECURE_NO_WARNINGS
// LeetCode189. ��ת����
//#include<stdio.h>
//void rotate1(int* begin, int* end)
//{
//	while (begin < end)
//	{
//		int t = 0;
//		t = *begin;
//		*begin = *end;
//		*end = t;
//		++begin;
//		--end;
//	}
//}
//void rotate(int* nums, int numsSize, int k) 
//{
//	//��������10����������7�����ֻص���ԭ�������ӡ�Ȼ������3�εĻ��ͱ�������3��һģһ����
//	if (k > numsSize)
//	{
//		k %= numsSize;
//	}
//	int* begin = nums;
//	int* end = nums + numsSize - 1;
//	rotate1(begin, end);
//	rotate1(begin, begin+k-1);
//	rotate1(begin + k, end);
//
//}
//int main()
//{
//	int nums[] = { 1,2,3,4,5,6,7 };
//	int sz = sizeof(nums) / sizeof(nums[0]);
//	rotate(nums, sz, 3);
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//	return 0;
//}
//LeetCode27. �Ƴ�Ԫ��
//#include<stdio.h>
//int removeElement(int* nums, int numsSize, int val)
//{
//        int src = 0;
//        int dst = 0;
//        while (src < numsSize)
//        {
//            // �������в�����val��ֵ����Ų��������Ŀ�ʼλ��
//            if (nums[src] != val)
//            {
//                nums[dst] = nums[src];
//                src++;
//                dst++;
//            }
//            else
//            {
//                //����Ǳ�ɾ����Ԫ�أ�ֱ��++srcλ�ã��ҵ���һ������val��λ��
//                src++;
//            }
//        }
//        return dst;
//}
//int main()
//{
//	int nums[] = { 3,2,2,3 };
//	int sz = sizeof(nums) / sizeof(nums[0]);
//	int ret = removeElement(nums, sz, 3);
//	return 0;
//}
//88. �ϲ�������������
#include<stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    //end1:nums1��ĩβ
    //end2:nums2��ĩβ
    //end:�ϲ�֮�����������ĩβ
    int end1 = m - 1;
    int end2 = n - 1;
    int end = m + n - 1;
    while (end1 >= 0 && end2 >= 0)
    {   //ѡ��β����Ԫ�أ���ŵ����������ĩβ
        //ÿ���һ��Ԫ�أ�β��ǰ�ƶ�һ��λ��
        if (nums1[end1] > nums2[end2])
        {
            nums1[end] = nums1[end1];
            end1--;
            end--;
        }
        else
        {
            nums1[end--] = nums2[end2--];
        }
    }
 //ʣ��Ԫ��������ĩβ���
    while (end1 >= 0)
    {
        nums1[end--] = nums1[end1--];
    }
    while (end2 >= 0)
    {
        nums1[end--] = nums2[end2--];
    }
}
int main()
{
	int nums1[] = {1,2,3,0,0,0};
	int nums2[] = {2,5,6};
	int s1 = sizeof(nums1) /sizeof(nums1[0]);
	int s2 = sizeof(nums2) / sizeof(nums2[0]);
	merge(nums1, s1, 3, nums2, s2, 3);
	for (int i = 0; i < s1; i++)
	{
		printf("%d", nums1[i]);
	}
	return 0;
}