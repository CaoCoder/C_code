#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	printf("请输入一个数：");
//	scanf("%d", &n);
//	printf("%d小时%d分钟", n / 60, n % 60);
//	return 0;
//}
/*递归调用*/
//#include<stdio.h>
//int f(unsigned int n) 
//{
//    if (n == 0 || n == 1)
//        return 1;
//    else
//        return n * f(n - 1);
//}
//int main()
//{
//    int ret = f(3);
//    printf("%d", ret);
//    return 0;
//}
/*消失的数字*/
//int missingNumber(int* nums, int numsSize)
//{
//	int i = 0;
//	int sum = 0;
//	int sum1 = 0;
//	for (i = 0; i < numsSize; i++)
//	{
//		
//		sum = sum + nums[i];
//		sum1 = sum1 + i;
//	}
//	sum1 = sum1 + i;
//	return sum1 - sum;
//}
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 9,6,4,2,3,5,7,0,1 };
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	missingNumber(arr, sz);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	scanf("%d%d%d", &a, &b, &c);
//	if (a+b>c || a+c>b || b+c>a)
//	{
//		if (a == b &&b == c)
//		{
//			printf("构成等边");
//		}
//		else if (a == b &&a != c || a == c && a!= b || b == c &&b != a)
//		{
//			printf("等腰");
//		}
//		else
//		{
//			printf("普通");
//		}
//
//	}
//	return 0;
//}
/*剑指offer56. 数组中数字出现的次数*/
 //Note: The returned array must be malloced, assume caller calls free
//int* singleNumbers(int* nums, int numsSize, int* returnSize)
//{
//	int sum = 0;
//	int sum1 = 0;
//	int i = 0;
//	for ( i = 0; i < numsSize; i++)
//	{
//		sum = sum ^ nums[i];
//	}
//	for (i = 0; i < numsSize; i++)
//	{
//		nums[i]+
//	}
//}
//#include<stdio.h>
//int main()
//{
//	int nums[] = { 4,1,4,6 };
//	int numsSize = sizeof(nums) / sizeof(nums[0]);
//	singleNumbers(nums, numsSize, )
//	return 0;
//}
/*模拟strlen函数*/
//#include<stdio.h>
//#include<string.h>
//int my_strlen(const char* arr)
//{
//	char* p= arr;
//	while (*arr != '\0')
//	{
//		arr++;
//	}
//	return arr - p;
//}
//int main()
//{
//	char arr[] = "hello";
//	int sz = my_strlen(arr);
//	printf("%d", sz);
//	return 0;
//}
/*strcpy函数的模拟*/
//#include<stdio.h>
//#include<assert.h>
//char* my_strcpy(char* arr, const char* arr1)
//{
//	assert(arr && arr1);
//	char* p = arr;
//	while (*arr1 != '\0')
//	{
//		*arr = *arr1;
//		arr++;
//		arr1++;
//	}
//	return p;
//}
//
//int main()
//{
//	char arr[] = "hello";
//	char arr1[] = "world";
//	printf("%s", my_strcpy(arr, arr1) );
//	return;
//}
/*模拟strcmp*/
//#include<stdio.h>
//#include<assert.h>
//int my_strcmp(const char* arr,const char* arr1)
//{
//	assert(arr && arr1);
//	while (*arr && *arr1)
//	{
//		if (*arr > *arr1)
//		{
//			return 1;
//		}
//		else if (*arr < *arr1)
//		{
//			return -1;
//		}
//		else
//		{
//			arr++;
//			arr1++;
//		}
//	}
//	if (*arr == *arr1 && arr == 0)
//	{
//		return 0;
//	}
//}
//int main()
//{
//	char arr[] = "bbcd";
//	char arr1[] = "bcd";
//	printf("%d", my_strcmp(arr, arr1));
//	return 0;
//}
/*模拟strcat函数*/
//#include<stdio.h>
//#include<assert.h>
//
//char* my_strcat(char* arr, const char* arr1)
//{
//	assert(arr && arr1);
//	char* p = arr;
//	while (*arr)
//	{
//		arr++;
//	}
//	while (*arr1)
//	{
//		*arr++ = *arr1++;
//	}
//	return p;
//}
//int main()
//{
//	char arr[20] = "bbcd";
//	char arr1[] = "bcd";
//	printf("%s", my_strcat(arr, arr1));
//	return 0;
//}
