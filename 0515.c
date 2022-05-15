//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include <errno.h>
//int main()
//{
//	FILE* pf = fopen("学生信息.txt", "w"); //以只写的方式打开文件
//	if (pf == NULL) //打开文件失败
//	{
//		printf("保存最高得分记录失败\n");
//		exit(0);
//	}
//	fwrite(&grade, sizeof(int), 1, pf); //将本局游戏得分写入文件当中
//
//	fclose(pf); 
//	pf = NULL; 
//	return 0;
//}