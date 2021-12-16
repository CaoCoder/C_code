#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
struct call
{
	char name[10];
	char num[20];
};
int main()
{
	int i = 0;
	char name1[20] = {0};
	scanf("%s", name1);
	struct call arr[5] = { {"Tom","111"},{"Jerry","112"},{"Toey","113"},{"Jack","114"
	},{"Mike","115"} };
	for (i = 0; i < 5; i++)
	{
		if (strcmp(name1, arr[i].name) == 0)
		{
			printf("%s", arr[i].num);
			break;
		}
	}
	if(i==5)
	{
		printf("该用户电话号码不存在!");
	}
	return 0;
}
/*冒泡排序优化*/
#include<stdio.h>
int main()
{
	int arr[5] = { 5,4,3,2,1 };
	int i = 0;
	int j = 0;
	int t = 0;
	for (i = 0; i < 5-1; i++)
	{
		int flag = 0;
		for (j = 0; j < 5 - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
				flag = 1;
			}
		}
		if (0 == flag)
		{
			break;
		}
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
