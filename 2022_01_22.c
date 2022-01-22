#define _CRT_SECURE_NO_WARNINGS
/*qsort函数排序结构体*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Stu
{
	char name[20];
	int age;
};
int cmp(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}

void Print(struct Stu a[], int sz)
{//类型用结构体类型 的数组接收 ，切勿写int类型的。
	for (int i = 0; i < sz; i++)
	{
		printf("%s %d",a[i].name, a[i].age);
	}
}
int main()
{
	struct Stu a[3] = { {"zhangsan", 20},{"lisi", 19},{"wangwu", 18} };
	int sz = sizeof(a) / sizeof(a[0]);
	qsort(a, sz, sizeof(a[0]), cmp);
	Print(a, sz);
	return 0;
}

/*strlen函数模拟实现*/
#include<stdio.h>
#include<string.h>
#include<assert.h>
int my_strlen(const char* arr)
{
	assert(arr);
	int count = 0;
	while (*arr)
	{
		count++;
		arr++;
	}
	return count;
}
int main()
{
	char arr[] = "hello";
	printf("%d",my_strlen(arr));
	return 0;
}
/*strcpy函数模拟实现*/
#include<stdio.h>
#include<string.h>
#include<assert.h>
char* my_strcpy(char* arr1, const char* arr2)
{
	char* s = arr2;
	assert(*arr1 && *arr2);
	while (*arr1++ = *arr2++)
	{
		;
	}
	return s;
}
int main()
{
	char arr2[] = "qwer";
	char arr1[] = "helloworld";
	printf("%s", my_strcpy(arr1, arr2));
	return 0;
}
/*strcmp函数模拟*/
#include<stdio.h>
#include<assert.h>
int my_strcmp(const char* arr1, const char* arr2)
{
	assert(arr2 && arr1);//断言指针不为空
	while (*arr1 == *arr2)
	{
		if (*arr1 == *arr2 && *arr1 == 0 && *arr2 ==0)
		{
			return 0;
		}
		arr1++;
		arr2++;
	}
	
	if (*arr1 > *arr2)
	{
		return 1;

	}
	else
	{
		return -1;
	}

}
int main()
{
	char arr1[] = "abc";
	char arr2[] = "abc";
	printf("%d", my_strcmp(arr1, arr2));
	return 0;
}
/*strcat函数模拟实现*/
#include<stdio.h>
#include<assert.h>
char* my_strcat(char* arr1, const char* arr2)
{
	assert(arr1 && arr2);
	char* s = arr1;
	while (*arr1)
	{
		arr1++;
	}
	while (*arr1++ = *arr2++)
	{
		;
	}
	return s;
}
int main()
{
	char arr1[20] = "hello";
	char arr2[] = "world";
	printf("%s", my_strcat(arr1, arr2));
	return 0;
}
/*strstr函数模拟实现*/
#include<stdio.h>
#include<assert.h>
char* my_strstr(const char* arr1, const char* arr2)
{
		assert(arr1 && arr2);
		char* s = arr1;
		while (*s)
		{
			char* s1 = s;
			char* s2 = arr2;
			while (*s1 == *s2 && *s2 && *s1)
			{
				s1++;
				s2++;
			}
			if (*s2 == 0)
			{
				return s;
			}
			s++;
		}
		if (*s == 0)
		{
			printf("没找到");
		}
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "cde";
	printf("%s", my_strstr(arr1, arr2));
	return 0;
}
