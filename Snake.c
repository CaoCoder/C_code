#define _CRT_SECURE_NO_WARNINGS
#include "Snake.h"
extern int max;
extern int grade;

//隐藏光标
void HideCursor()
{
	CONSOLE_CURSOR_INFO curInfo;//定义光标信息
	curInfo.dwSize = 1;//如果没赋值的话，光标隐藏无效
	curInfo.bVisible = FALSE;//将光标设置为不可见
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//获取控制台句柄
	SetConsoleCursorInfo(handle, &curInfo);//设置光标信息
}
//光标跳转
void CursorJump(int x, int y)
{
	COORD pos;//定义光标位置的结构体变量
	pos.X = x;
	pos.Y = y;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//获取控制台句柄
	SetConsoleCursorPosition(handle, pos);//设置光标信息；
}
//初始化界面
void InitInterface()
{
	color(6);//颜色设置为土黄色
	for (int i = 0; i < COL; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (j == 0 || j == COL - 1)
			{
				face[i][j] = WALL;//标记该位置为墙；
				//光标跳转 什么意思？
				CursorJump(2 * j, i);
				printf("■");
			}
			else if (i == 0 || i == ROW - 1)
			{
				face[i][j] = WALL;//标记该位置为墙
				printf("■");

			}
			else
			{
				face[i][j] = KONG;//标记该位置为空
			}
		}
	}
	color(7);//设置为白色
	CursorJump(0, ROW);
	printf("当前得分：%d", grade);
	CursorJump(COL, ROW);
	printf("历史最高得分：%d", max);
}
//颜色设置
void color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);//颜色设置
	//注：SetConsoleTextAttribute是一个API（应用程序编程接口）
}
//从文件读取最高分
void ReadGrade()
{
	FILE* pf = fopen("贪吃蛇最高得分记录.txt", "r");//只读的方式打开文件
	if (pf == NULL)
	{
		pf = fopen("贪吃蛇最高得分纪录.txt", "w");//以只写的方式打开文件
		fwrite(&max, sizeof(int), 1, pf);//将max写入文件（此时max为0），最高得分初始化为0.
	}
	fseek(pf, 0, SEEK_SET);//使文件指针pf指向文件开头
	fread(&max, sizeof(int), 1, pf);//读取文件当中的最高得分到max中
	fclose(pf);//关闭文件
	pf = NULL;//文件指针置空
}
//更新最高分到文件
void WriteGrade()
{
	FILE* pf = fopen("贪吃蛇最高得分纪录.txt", "w");//以只写的方式打开文件
	if (pf == NULL)
	{
		printf("保存最高得分记录失败\n");
		exit(0);
	}
	fwrite(&grade, sizeof(int), 1, pf);//将本局游戏得分写入文件中
	fclose(pf);//关闭文件
	pf = NULL;
}
//初始化蛇
void InitSnake()
{
	snake.len = 2;// 蛇的身体长初始为2
	snake.x = COL / 2;//蛇头位置的横坐标
	snake.y = ROW / 2;//蛇头位置的纵坐标
	//蛇身坐标的初始化
	body[0].x = COL / 2 - 1;
	body[0].y = ROW / 2;
	body[1].x = COL / 2 - 2;
	body[1].y = ROW / 2;
	//将蛇头和蛇身位置进行标记
	face[snake.y][snake.x] = HEAD;
	face[body[0].y][body[0].x] = BODY;
	face[body[1].y][body[1].x] = BODY;

}
//随机生成食物
void RandFood()
{
	int i = 0;
	int j = 0;
	do
	{
		//随机生成食物的横纵坐标
		i = rand() % ROW;
		j = rand() & COL;
	} while (face[i][j] != KONG);
	face[i][j] = FOOD;//将食物位置进行标记
	color(12);//颜色设置为红色
	CursorJump(2 * j, i);//光标跳转到生成的随机位置处
	printf("●");//打印食物
}
//判断得分与结束
void JudgeFunc(int x, int y)
{
	//若蛇头即将到达的位置是食物，则得分
	if (face[snake.y + y][snake.x + x] == FOOD)
	{
		snake.len++;// 蛇身加长
		grade += 10;//更新当前得分
		color(7);//颜色设置为白色
		CursorJump(0, ROW);
		printf("当前得分：%d", grade);//重新打印当前得分
		RandFood();//重新随机生成食物
	}
	//若蛇头即将到达的位置是墙或者蛇身，则游戏结束
	if (face[snake.y + y][snake.x + x] == WALL || WALL || face[snake.y + y][snake.x] == BODY)
	{
		Sleep(1000);//留给玩家反应时间
		system("cls");//清空屏幕
		color(7);//颜色设置为白色
		CursorJump(2 * (COL / 3), ROW / 2 - 3);
		if (grade > max)
		{
			printf("恭喜你打破最高记录，最高记录更新为%d", grade);
			WriteGrade();
		}
		else if (grade == max)
		{
			printf("与最高记录持平，加油再创佳绩%d", grade);
		}
		else
		{
			printf("请继续加油，当前与最高记录相差%d", max - grade);
		}
		CursorJump(2 * (COL / 3), ROW / 2);
		printf("GAME OVER");
		while (1)//询问玩家是否再来一局
		{
			char ch;
			CursorJump(2 * (COL / 3), ROW / 2 + 3);
			printf("再来一局?(y/n):");
			scanf("%c", &ch);
			if (ch == 'y' || ch == 'Y')
			{
				system("cls");
				main();
			}
			else if (ch == 'n' || ch == 'N')
			{
				CursorJump(2 * (COL / 3), ROW / 2 + 5);
				exit(0);
			}
			else
			{
				CursorJump(2 * (COL / 3), ROW / 2 + 5);
				printf("选择错误，请再次选择");
			}
		}
	}
}
//打印蛇与覆盖蛇
void DrawSnake(int flag)
{
	if (flag == 1)//打印蛇
	{
		color(10);//颜色设置为绿色
		CursorJump(2 * snake.x, snake.y);
		printf("■"); //打印蛇头
		for (int i = 0; i < snake.len; i++)
		{
			CursorJump(2 * body[i].x, body[i].y);
			printf("■"); //打印蛇身
		}
	}
	else//覆盖蛇
	{
		if (body[snake.len - 1].x != 0)//防止len++后将(0.0)位置墙覆盖
		{
			//将蛇尾覆盖为空格即可
			CursorJump(2 * body[snake.len - 1].x, body[snake.len - 1].y);
			printf("  ");
		}
	}
	
}
//移动蛇
void MoveSnake(int x, int y)
{
	DrawSnake(0); //先覆盖当前所显示的蛇
	face[body[snake.len - 1].y][body[snake.len - 1].x] = KONG; //蛇移动后蛇尾重新标记为空
	face[snake.y][snake.x] = BODY; //蛇移动后蛇头的位置变为蛇身
	//蛇移动后各个蛇身位置坐标需要更新
	for (int i = snake.len - 1; i > 0; i--)
	{
		body[i].x = body[i - 1].x;
		body[i].y = body[i - 1].y;
	}
	//蛇移动后蛇头位置信息变为第0个蛇身的位置信息
	body[0].x = snake.x;
	body[0].y = snake.y;
	//蛇头的位置更改
	snake.x = snake.x + x;
	snake.y = snake.y + y;
	DrawSnake(1); //打印移动后的蛇
}
//执行按键
void run(int x, int y)
{
	int t = 0;
	while (1)
	{
		if (t == 0)
			t = 3000; //这里t越小，蛇移动速度越快（可以根据次设置游戏难度）
		while (--t)
		{
			if (kbhit() != 0) //若键盘被敲击，则退出循环
				break;
		}
		if (t == 0) //键盘未被敲击
		{
			JudgeFunc(x, y); //判断到达该位置后，是否得分与游戏结束
			MoveSnake(x, y); //移动蛇
		}
		else //键盘被敲击
		{
			break; //返回Game函数读取键值
		}
	}
}