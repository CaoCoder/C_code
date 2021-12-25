#define _CRT_SECURE_NO_WARNINGS
/*��������������*/
#include<stdio.h>
#include<stdlib.h>
int buble_sort(const void* e1, const void* e2)
{
	return *((int*)e2) - *((int*)e1);
	//e1-e2 >0 ���ش���0����
	//e1-e2 = 0 ����0
	//e1-e2 < 0 ����С��0����
}
int main()
{
	int arr[] = {0,1,2,3,4,5,6,7,8,9 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), buble_sort);//int (*p)(const void*, const void*)
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
/*��������ṹ������*/
#include<stdio.h>
#include<stdlib.h>
struct Stu
{
	char name[20];
	int age;
};
int age_sort(const void* e1, const void* e2)
{
	//e1��e2�ǽṹ��ָ��
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
//����ָ��
//int (*cmp)(void*, void*)
int main()
{
	struct Stu s[] = { {"zhangsan", 20},{"lisi", 40}, {"wangwu", 30} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), age_sort);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", s[i].age);
	}
	return 0;         
}
/*��������ṹ������*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stu
{
	char name[20];
	int age;
};
int name_sort(const void* e1, const void* e2)
{
	//������ָ��ǿ��ת��Ϊ�ṹ��ָ��
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
int main()
{
	//strcmp���ַ����ǰ����ַ��Ƚϣ��Ƚϵ���ÿ���ַ���ASCII��ֵ��
	struct Stu s[] = { {"zhangsan", 20},{"aisi", 40},{"bangwu", 30} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), name_sort);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%s ", s[i].name);
	}
	return 0;
}

/*���ݿ�������ʵ��ģ��ð������*/
#include<stdio.h>
#include<string.h>
int cmp_int(const void* e1, const void* e2)
{
	return *(char*)e1-*(char*)e2;
}
void swap(char* e1, char* e2, int width)
{
	һ���ֽ�һ���ֽڵĽ���
	int i = 0;
	for (i = 0; i < width; i++)
	{
		int t = 0;
		t = *e1;
		*e1 = *e2;
		*e2 = t;
		e1++;
		e2++;
	}
}
bubble_sort(void* base,int sum,int width,int (*cmp)(const void*, const void*))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sum - 1; i++)
	{
		for (j = 0; j < sum - i - 1; j++)
		{
			if (cmp_int((char*)base + j*width, (char*)base +(j + 1)*width)>0)
			{
				swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
			}
		}
	}
}
void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
void test()
{
	int arr[] = {1,3,5,7,2,4,6,8,0};
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	print(arr, sz);
}
int main()
{
	test();
	return 0;
}
