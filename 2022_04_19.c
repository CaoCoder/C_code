#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	
//	int n = 0;
//	scanf("%d", &n);
//	//���ٿռ䡣
//	char** p = (char**)malloc(sizeof(char*) * n);
//	for (int i = 0; i < n; i++)
//	{
//		p[i] = (char*)malloc(sizeof(char) * 50);
//		scanf("%s", p[i]);
//	}
//
//	for (int k = 0;k < n; k++)
//	{
//		for (int i = 0; i < strlen(p[k]); i++)
//		{
//			if (p[k][i] == 'Z')
//			{
//				printf("A");
//			}
//			else
//			{
//				printf("%c", p[k][i] + 1);
//			}
//		}
//		printf("\n");
//	}
//	
//	//���ͷ�ÿ�е�Ԫ��
//	for (int i = 0; i < n; i++)
//	{
//		free(p[i]);
//	}
//	//����ͷŶ���ָ��
//	free(p);
//	return 0;
//}
//
//
#include<stdio.h>
int main()
{
	int a[2][2] = { {1,2},{3,4} };
	printf("%d", *(*(a + 1) + 1));
	return 0;
}