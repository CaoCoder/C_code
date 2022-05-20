#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

#define Init_SZ 4

typedef int DataType;
//构建学生的属性信息
typedef struct StudentInfo
{
	int number;//学号
	char name[10];
	char sex[10];
	int score;
}StuInfo;

//构建存放学生个体的容器
typedef struct Student
{
	StuInfo* a;//相当于数组用于存放数据
	int sz;//记录有效的学生信息个数
	int capacity;//记录当前学生信息表的最大容量
}Stu;
//初始化学生信息表
void InitStu(Stu* ps);
//销毁学生信息表
void DestoryStu(Stu* ps);
//增加学生到信息表
void AddStu(Stu* ps);
//展示信息表
void ShowStu(Stu* ps);
//将信息表的数据写入文件
void SaveStu(Stu* ps);
//排序信息表
void SortStu(Stu* ps);
//将女生 和 男生分开
int SeparateStu(Stu* ps);
//女生合格率
void GirlPass(Stu* ps);
//男生合格率
void ManPass(Stu* ps);
//总的平均分
void TotalScore(Stu* ps);