#define _CRT_SECURE_NO_WARNINGS
/*模拟strstr函数*/
//#include<stdio.h>
//#include<assert.h>
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	char* cp = str1;
//	char* s1 = 0;
//	char* s2 = 0;
//	while (*cp != '\0')
//	{
//		s1 = cp;
//		s2 = str2;
//		while (*s2 != '\0' && *s1 != '\0' && *s2 == *s1)
//		{
//			s1++;
//			s2++;
//			if (!*s2)
//			{
//				return cp;
//			}
//		}
//		cp++;
//	}
//	return NULL;
//
//}
//int main()
//{
//	char arr[] = "hworld";
//	char arr1[] = "";
//	char* p = my_strstr(arr, arr1);
//	printf("%s", p);
//	return 0;
//}
/* strtok example */
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char str[] = "- This, a sample string.";
//	char* pch;
//	printf("Splitting string \"%s\" into tokens:\n", str);
//	pch = strtok(str, " ,.-");
//	while (pch != NULL)
//	{
//		printf("%s\n", pch);
//		pch = strtok(NULL, " ,.-");
//	}
//	return 0;
//}
/*关于char类型的截断的问题*/
//#include<stdio.h>
//int main()
//{
//    char a[1000] = { 0 };
//    int i = 0;
//    for (i = 0; i < 1000; i++)
//    {
//        a[i] = -254 - i;
//    }
//    printf("%d", strlen(a));
//    return 0;
//}
//110000 0000
//101111 1111
//110000 0000
/*猜凶手*/
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 'a'; i <= 'd'; i++)
//	{
//		if ((i != 'a') + (i == 'c') + (i == 'd') + (i != 'd') == 3)
//		{
//			printf("%c", i);
//		}
//	}
//	return 0;
//}
/*LeetCode.88合并两个有序数组*/
#include<stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) 
{
	int* p1 = nums1 + m - 1;
	int* p2 = nums2 + n - 1;
	int* tail = nums1 + nums1Size - 1;
	while (p2 >= nums2 && p1 >= nums1)
	{
		if (*p1 <= *p2)
		{
			*tail = *p2;
			p2--;
			tail--;
		}
		else
		{
			*tail = *p1;
			p1--;
			tail--;
		}
	}
	while (p2 >= nums2)
	{
		*tail = *p2;
		p2--;
		tail--;
	}
}
int main()
{
	int nums1[] = { 7,8,9,0,0,0 };
	int nums2[] = { 2,5,6 };
	int sz1 = sizeof(nums1) / sizeof(nums1[0]);
	int sz2 = sizeof(nums2) / sizeof(nums2[0]);
	merge(nums1, sz1, 3, nums2, sz2, 3);
	return 0;
}
