#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROWS 11
#define COLS 11
#define ROW 9
#define COL 9
void InitMine(char mine[ROWS][COLS], int row, int col, char set);
void SetMine(char mine[ROWS][COLS], int row, int col);
void DisplayMine(char show[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);
#define minecount 10