//宏定义便于后期的更改
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROWS ROW + 2
//设置11*11的格子防止数组越界。
#define COLS COL + 2
#define ROW 9
#define COL 9
//以下是对函数的声明
void InitMine(char mine[ROWS][COLS], int row, int col, char set);
void SetMine(char mine[ROWS][COLS], int row, int col);
void DisplayMine(char show[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
//设置雷的个数
#define minecount 10