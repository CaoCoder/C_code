#define _CRT_SECURE_NO_WARNINGS
#define WIDTH 30
#define HEIGHT 30
#define SPEED 100
#define FOODSCORE 1
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include <Windows.h>
#include <stdio.h>
/***************************************model****************************************/
/*ʵ������Ϸ���ߣ����꣬ʳ�ǽ��ͷ��βɾ*/
typedef struct Point {
	int x;
	int y;
}Point;

typedef struct Node {
	Point pos;
	struct Node* next;
}Node;

typedef enum Direction {
	UP, DOWN, LEFT, RIGHT
}Direction;

typedef struct Snake {
	Node* pHead;
	Direction dir;
}Snake;

typedef struct Game {
	Snake snake;
	Point food;
	int score;
	int scorePerFood;
	int interval;
	int width;
	int height;
}Game;
/***************************************view****************************************/
/*
�����ƣ��õ���׼��������
�����������飺��ʳ����ߣ���Ƥ��;���ֻ������ߣ�ÿ��ѭ���ֲ�ˢ�£��������ߣ��ƶ���������
Dos���mode���ƴ����С
*/
typedef struct UI {
	int gameZoneWidth;
	int gameZoneHeight;
	int blockWidth;
	char* wallBlock;
	char* snakeBlock;
	char* foodBlock;
	int marginLeft;
	int marginTop;
}UI;

void InitUI(UI* pUI, int width, int height)
{
	assert(pUI);
	pUI->blockWidth = 2;
	pUI->foodBlock = "��";
	pUI->wallBlock = "�~";
	pUI->snakeBlock = "��";
	pUI->marginLeft = 2;
	pUI->marginTop = 1;
	pUI->gameZoneHeight = height;
	pUI->gameZoneWidth = width;

	char mode[1024] = "";
	sprintf(mode, "mode con cols=%d lines=%d", (pUI->gameZoneWidth) * 2 + 20, pUI->gameZoneHeight + 10);
	system(mode);
}

void DestroyUI()
{
}
//���ù���ӡλ��
void SetCursorPosition(int x, int y)
{
	//��׼����ľ�����൱���ļ�ָ��
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(handle, coord);
}
void DisplayWall(const UI* pUI)
{
	assert(pUI);
	//������
	int x, y;
	int i = 0;
	//�ϱ߽�
	for (i = 0; i < pUI->gameZoneWidth + 2; i++) {
		x = pUI->marginLeft + i * (pUI->blockWidth);
		y = pUI->marginTop;
		SetCursorPosition(x, y);
		printf("%s", pUI->wallBlock);
	}
	for (i = 0; i < pUI->gameZoneWidth + 2; i++) {
		x = pUI->marginLeft + i * (pUI->blockWidth);
		y = pUI->marginTop + pUI->gameZoneHeight + 1;
		SetCursorPosition(x, y);
		printf("%s", pUI->wallBlock);
	}
	for (i = 0; i < pUI->gameZoneHeight + 2; i++) {
		x = pUI->marginLeft;
		y = pUI->marginTop + i;
		SetCursorPosition(x, y);
		printf("%s", pUI->wallBlock);
	}
	for (i = 0; i < pUI->gameZoneHeight + 2; i++) {
		x = pUI->marginLeft + (pUI->gameZoneWidth + 1) * (pUI->blockWidth);
		y = pUI->marginTop + i;
		SetCursorPosition(x, y);
		printf("%s", pUI->wallBlock);
	}

}

void DisplaySnakeBlockAtXY(const UI* pUI, int gameZoneX, int gameZoneY)
{
	SetCursorPosition((gameZoneX + 1) * (pUI->blockWidth) + pUI->marginLeft, gameZoneY + pUI->marginTop + 1);
	printf("%s", pUI->snakeBlock);
}
void CleanSnakeBlockAtXY(const UI* pUI, int gameZoneX, int gameZoneY)
{
	SetCursorPosition((gameZoneX + 1) * (pUI->blockWidth) + pUI->marginLeft, gameZoneY + pUI->marginTop + 1);
	printf(" ");
}
void DisplayFoodBlockAtXY(const UI* pUI, int gameZoneX, int gameZoneY)
{
	SetCursorPosition((gameZoneX + 1) * (pUI->blockWidth) + pUI->marginLeft, gameZoneY + pUI->marginTop + 1);
	printf("%s", pUI->foodBlock);
}
void DisplaySnake(const Snake* pSnake, UI* pUI)
{
	Node* pCur = pSnake->pHead;
	while (pCur) {
		DisplaySnakeBlockAtXY(pUI, pCur->pos.x, pCur->pos.y);
		pCur = pCur->next;
	}
}

void DisplayWizard(const UI* pUI)
{
	char* msg = "��ӭ����̰����";
	//���ô����С��������λ��
	int x = ((pUI->gameZoneWidth) * 2 + 20) / 2 - strlen(msg) / 2;
	int y = (pUI->gameZoneHeight + 10) / 2;
	SetCursorPosition(x, y);
	printf(msg);
	SetCursorPosition(x + 4, y + 2);
	system("pause");
	system("cls");
}

void DisplayOver(const UI* pUI)
{
	char* msg = "��������������";
	int x = ((pUI->gameZoneWidth) * 2) / 2 - strlen(msg) / 2;
	int y = (pUI->gameZoneHeight) / 2;
	SetCursorPosition(x, y);
	printf(msg);
	SetCursorPosition(x + 4, y + 2);
	while (1) {
		getch();
	}
	system("pause");
}

void DisplayScore(const UI* pUI, Game* pGame)
{
	int x = (pUI->gameZoneWidth) * 2 + 2;
	int y = 10;
	SetCursorPosition(x, y);
	SetCursorPosition(x + 4, y + 2);
	printf("�����%2d��", pGame->score);
}
/***************************************control****************************************/
/*�߻��ƶ���ͷ��βɾ��
�߳Զ�����ͷ�壬������ʳ��ӷ֡�
ײǽ��ײ�Լ��������ж�˳��
�������:ͬ��/�첽��׽������
��ʼ��/���١�
*/
void _InitSnake(Snake* pSnake)
{
	assert(pSnake);
	pSnake->pHead = NULL;
	//��ʼ���������ȵ���,ͷ��

	int i;
	for (i = 0; i < 3; i++) {
		Node* pNew = (Node*)malloc(sizeof(Node));
		if (NULL == pNew) {
			exit(EXIT_FAILURE);
		}
		pNew->next = pSnake->pHead;
		pSnake->pHead = pNew;
		pNew->pos.x = 5 + i;
		pNew->pos.y = 5;
	}
	pSnake->dir = RIGHT;
}

int _IsOverlapSnake(int x, int y, const Snake* pSnake)
{
	assert(pSnake);
	Node* pCur = pSnake->pHead;
	while (pCur) {
		if (x == pCur->pos.x && y == pCur->pos.y) {
			return 1;
		}
		pCur = pCur->next;
	}
	return 0;
}

void _GenerateFood(int width, int height, const Snake* pSnake, Point* pFood)
{
	assert(pSnake && pFood);
	int x, y;
	do {
		x = rand() % width;
		y = rand() % height;

	} while (_IsOverlapSnake(x, y, pSnake));
	//���ɲ������ص��ĺϷ�����
	pFood->x = x;
	pFood->y = y;
}

void InitGame(Game* pGame)
{
	pGame->score = 0;
	pGame->width = WIDTH;
	pGame->height = HEIGHT;
	pGame->interval = SPEED;
	pGame->scorePerFood = FOODSCORE;
	_InitSnake(&pGame->snake);
	_GenerateFood(pGame->width, pGame->height, &pGame->snake, &pGame->food);
}

void DestroyGame(Game* pGame)
{
	assert(pGame);
	//��snake�ﶯ̬�����ڴ��ˣ�Ҫ����
	Node* pCur = pGame->snake.pHead;
	while (pCur) {
		Node* pDel = pCur;
		pCur = pCur->next;
		free(pDel);
	}
}

Point GetNextPoint(const Snake* pSnake)
{
	assert(pSnake);
	Point tmp = pSnake->pHead->pos;
	//�����ߵķ��������һ��λ��
	switch (pSnake->dir)
	{
	case UP:tmp.y -= 1; break;
	case DOWN:tmp.y += 1; break;
	case LEFT:tmp.x -= 1; break;
	case RIGHT:tmp.x += 1; break;
	default:
		break;
	}
	return tmp;
}

int IsFood(Point food, Point NextPos)
{
	return food.x == NextPos.x && food.y == NextPos.y;
}

void AddHead(const UI* pUI, Snake* pSnake, Point nextPos)
{
	assert(pSnake);
	Node* pNew = (Node*)malloc(sizeof(Node));
	if (NULL == pNew) {
		exit(EXIT_FAILURE);
	}
	pNew->pos = nextPos;
	pNew->next = pSnake->pHead;
	pSnake->pHead = pNew;
	DisplaySnakeBlockAtXY(pUI, pNew->pos.x, pNew->pos.y);
}

void PopTail(const UI* pUI, Snake* pSnake)
{
	assert(pSnake);
	Node* pCur = pSnake->pHead;
	while (pCur->next->next) {
		pCur = pCur->next;
	}
	CleanSnakeBlockAtXY(pUI, (pCur->next->pos).x, (pCur->next->pos).y);
	free(pCur->next);
	pCur->next = NULL;
}

int IsWall(Point nextPos, int width, int height)
{
	if (nextPos.x < 0 || nextPos.y < 0 || nextPos.x >= width || nextPos.y >= height) {
		return 1;
	}
	return 0;
}

int IsSelf(const Snake* pSnake, Point nextPos)
{
	assert(pSnake);
	//����������һ�������ж���ײ��
	Node* pCur = pSnake->pHead->next;
	while (pCur) {
		if (pCur->pos.x == nextPos.x && nextPos.y == pCur->pos.y) {
			return 1;
		}
		pCur = pCur->next;
	}
	return 0;
}
int main()
{
	srand((unsigned int)time(NULL));
	Game game;
	UI ui;

	InitGame(&game);
	InitUI(&ui, game.width, game.height);
	DisplayWizard(&ui);

	DisplayWall(&ui);
	DisplayFoodBlockAtXY(&ui, game.food.x, game.food.y);
	DisplaySnake(&game.snake, &ui);
	SetCursorPosition(0, 20);
	Point nextPos = { 8,5 };
	while (1) {
		//��ȡ���̰���
		if (GetAsyncKeyState(VK_UP)) {
			//�����߻�ͷ·
			if (game.snake.dir != DOWN) {
				game.snake.dir = UP;
			}
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			if (game.snake.dir != UP) {
				game.snake.dir = DOWN;
			}
		}
		if (GetAsyncKeyState(VK_LEFT)) {
			if (game.snake.dir != RIGHT) {
				game.snake.dir = LEFT;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			if (game.snake.dir != LEFT) {
				game.snake.dir = RIGHT;
			}
		}
		//�ж���һ��λ��
		nextPos = GetNextPoint(&game.snake);
		if (IsFood(game.food, nextPos)) {
			//��ʳ��
			AddHead(&ui, &game.snake, nextPos);
			_GenerateFood(game.width, game.height, &game.snake, &game.food);
			DisplayFoodBlockAtXY(&ui, game.food.x, game.food.y);
			game.score += game.scorePerFood;
			DisplayScore(&ui, &game);
		}
		else {
			//������һ��
			AddHead(&ui, &game.snake, nextPos);
			PopTail(&ui, &game.snake);
		}
		if (IsWall(nextPos, game.width, game.height)) {
			break;
		}
		if (IsSelf(&game.snake, nextPos)) {
			break;
		}

		Sleep(game.interval);
	}

	DisplayOver(&ui);
	DestroyUI();
	DestroyGame(&game);
}
