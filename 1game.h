//�궨����ں��ڵĸ���
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROWS ROW + 2
//����11*11�ĸ��ӷ�ֹ����Խ�硣
#define COLS COL + 2
#define ROW 9
#define COL 9
//�����ǶԺ���������
void InitMine(char mine[ROWS][COLS], int row, int col, char set);
void SetMine(char mine[ROWS][COLS], int row, int col);
void DisplayMine(char show[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
//�����׵ĸ���
#define minecount 10