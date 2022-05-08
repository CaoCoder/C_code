#define _CRT_SECURE_NO_WARNINGS
#include "Snake.h"
void Game();
int max;
int grade;



int main()
{

	max = 0, grade = 0; //初始化变量
	system("title 贪吃蛇"); //设置cmd窗口的名字
	system("mode con cols=84 lines=23"); //设置cmd窗口的大小
	HideCursor(); //隐藏光标
	ReadGrade(); //从文件读取最高分到max变量
	InitInterface(); //初始化界面
	InitSnake(); //初始化蛇
	srand((unsigned int)time(NULL)); //设置随机数生成起点
	RandFood(); //随机生成食物
	DrawSnake(1); //打印蛇
	Game(); //开始游戏
	return 0;
}

//游戏主体逻辑函数
void Game()
{
	int n = RIGHT; //开始游戏时，默认向后移动
	int tmp = 0; //记录蛇的移动方向
	goto first; //第一次进入循环先向默认方向前进
	while (1)
	{
		n = getch(); //读取键值
		//在执行前，需要对所读取的按键进行调整
		switch (n)
		{
		case UP:
		case DOWN: //如果敲击的是“上”或“下”
			if (tmp != LEFT && tmp != RIGHT) //并且上一次蛇的移动方向不是“左”或“右”
			{
				n = tmp; //那么下一次蛇的移动方向设置为上一次蛇的移动方向
			}
			break;
		case LEFT:
		case RIGHT: //如果敲击的是“左”或“右”
			if (tmp != UP && tmp != DOWN) //并且上一次蛇的移动方向不是“上”或“下”
			{
				n = tmp; //那么下一次蛇的移动方向设置为上一次蛇的移动方向
			}
		case SPACE:
		case ESC:
		case 'r':
		case 'R':
			break; //这四个无需调整
		default:
			n = tmp; //其他键无效，默认为上一次蛇移动的方向
			break;
		}
	first: //第一次进入循环先向默认方向前进
		switch (n)
		{
		case UP: //方向键：上
			run(0, -1); //向上移动（横坐标偏移为0，纵坐标偏移为-1）
			tmp = UP; //记录当前蛇的移动方向
			break;
		case DOWN: //方向键：下
			run(0, 1); //向下移动（横坐标偏移为0，纵坐标偏移为1）
			tmp = DOWN; //记录当前蛇的移动方向
			break;
		case LEFT: //方向键：左
			run(-1, 0); //向左移动（横坐标偏移为-1，纵坐标偏移为0）
			tmp = LEFT; //记录当前蛇的移动方向
			break;
		case RIGHT: //方向键：右
			run(1, 0); //向右移动（横坐标偏移为1，纵坐标偏移为0）
			tmp = RIGHT; //记录当前蛇的移动方向
			break;
		case SPACE: //暂停
			system("pause>nul"); //暂停后按任意键继续
			break;
		case ESC: //退出
			system("cls"); //清空屏幕
			color(7); //颜色设置为白色
			CursorJump(COL - 8, ROW / 2);
			printf("  游戏结束  ");
			CursorJump(COL - 8, ROW / 2 + 2);
			exit(0);
		case 'r':
		case 'R': //重新开始
			system("cls"); //清空屏幕
			main(); //重新执行主函数
		}
	}
}

