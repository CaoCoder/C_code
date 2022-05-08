#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable:4996) //消除警告
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


#define ROW 22//游戏区行数
#define COL 42//游戏区列数


#define KONG 0//标记空 
#define WALL 1
#define FOOD 2
#define HEAD 3
#define BODY 4

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define ESC 27

//蛇头
struct Snake
{
	int len;
	int x;
	int y;
}snake;
//蛇身
struct Body
{
	int x;
	int y;
}body[ROW*COL];

int face[ROW][COL];//标记游戏区各个位置的状态

//隐藏光标
void HideCursor();
//光标跳转
void CursorJump(int x, int y);
//初始化界面
void InitInterface();
//颜色设置
void color(int c);
//读分数
void ReadGrade();
//更新最高分到文件
void WriteGrade();
//初始化蛇
void InitSnake();
//随机生成食物
void RandFood();
//判断得分与结束
void JudgeFunc(int x, int y);
//打印蛇与覆盖蛇
void DrawSnake(int flag);
//移动蛇
void MoveSnake(int x, int y);
//执行按键
void run(int x, int y);
