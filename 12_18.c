#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct student
{
	int ID;
	char name[10];
	float score;
}S;
int main()
{
	S STU[5];
	int i;
	for (i = 0; i <= 4; i++)
	{
		scanf("%d%s%f", &STU[i].ID, &STU[i].name, &STU[i].score);
		printf("%d号学生信息为：学号：%d,姓名：%s,成绩：%.1f", i + 1, STU[i].ID, STU[i].name, STU[i].score);
	}
	return 0;
}
