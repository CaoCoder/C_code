#define _CRT_SECURE_NO_WARNINGS
/*�����غ���Ч*/
#include<stdio.h>
#include<string.h>
#include<windows.h>
int main()
{
	char arr1[] = "cao shuai qi zhen shuai";
	char arr2[] = "                       ";
	int left = 0;
	int right = strlen(arr1) - 1;
	while (left <= right)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
		Sleep(400);
		system("cls");
		left++;
		right--;
	}
	return 0;
}