
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 3
#define COL 3
 

void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void Player_move(char board[ROW][COL], int row, int col);
void Computer_move(char board[ROW][COL], int row, int col);
char is_win(char board[ROW][COL], int row, int col);

//�ж���Ӯ�Ĵ���
//���Ӯ - '*'
//����Ӯ - '#'
//ƽ�� --- 'Q'
//���� ----'C'

