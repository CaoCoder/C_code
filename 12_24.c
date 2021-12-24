#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<time.h>
#define U 0.1
#define V 0.053
#define PI  3.141592653589793238462643383279502884197
void SetColor(unsigned short ForeColor, unsigned short BackGroundColor)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, (ForeColor % 16) | (BackGroundColor % 16 * 16));
}
float sx, sy;
float sdCircle(float px, float py, float r)
{
	float dx = px - sx, dy = py - sy;
	return sqrtf(dx * dx + dy * dy) - r;
}
float opUnion(float d1, float d2)
{
	return d1 < d2 ? d1 : d2;
}
#define T px + scale * r * cosf(theta), py + scale * r * sin(theta)
float f(float px, float py, float theta, float scale, int n)
{
	float d = 0.0f;
	for (float r = 0.0f; r < 0.8f; r += 0.02f)
		d = opUnion(d, sdCircle(T, 0.05f * scale * (0.95f - r)));
	if (n > 0)
		for (int t = -1; t <= 1; t += 2)
		{
			float tt = theta + t * 1.8f;
			float ss = scale * 0.9f;
			for (float r = 0.2f; r < 0.8f; r += 0.1f)
			{
				d = opUnion(d, f(T, tt, ss * 0.5f, n - 1));
				ss *= 0.8f;
			}
		}
	return d;
}
int circle()
{
	float x = (fmodf(sy, 0.1f) / 0.1f - 0.5f) * 0.5f;
	return sx >= x - 0.05f && sx <= x + 0.05f;
}
int main(int argc, char* argv[])
{
	printf("\n");
	printf("                            河南牧业经济学院\n");

	printf("                         大学生社团发展服务中心\n");
	printf("                                  YYDS!\n");
	int n = argc > 1 ? atoi(argv[1]) : 3;
	float zoom = argc > 2 ? atof(argv[2]) : 1.0f;
	for (sy = 0.8f; sy > 0.0f; sy -= 0.02f / zoom, putchar('\n'))
		for (sx = -0.35f; sx < 0.35f; sx += 0.01f / zoom)
		{
			if (f(0, 0, PI * 0.5f, 1.0f, n) < 0.0f)
			{
				if (sy < 0.1f)
					putchar('!');
				else
				{
					if (circle())
						putchar('+');
					else
						putchar("***..........**..........***#sj&o"[rand() % 33]);
				}
			}
			else
				putchar(' ');
		}
	Sleep(1000);
	system("cls");
	int i, s = 0, t, a = 10, b = 11, c = 12, d = 13, e = 14;
	int z[] = { 32,32,-55,-25,-63,-86,-59,-93,-79,-58,-93,-95,33,32,32 };
	float x, y;
	srand(time(NULL));
	for (y = 1.3; y >= -1.1; y -= U)
	{
		for (x = -2; x < 1.4; x += V)
		{
			if ((((x * x + y * y - 1) * (x * x + y * y - 1) * (x * x + y * y - 1) - x * x * y * y * y) <= 0))
			{
				if (y >= 1.3 - 10 * U || y <= 1.3 - 11 * U)
				{
					s++;
					if (s % 4 == 1) { SetColor(a, 0); printf("l"); }
					if (s % 4 == 2) { SetColor(e, 0); printf("o"); }
					if (s % 4 == 3) { SetColor(c, 0); printf("v"); }
					if (s % 4 == 0) { SetColor(d, 0); printf("e"); }
				}
				else
				{
					for (i = 0; i < 42; i++)
					{
						if (i <= 14 || i >= 28)
						{
							s++;
							if (s % 4 == 1) { SetColor(a, 0); printf("l"); }
							if (s % 4 == 2) { SetColor(e, 0); printf("o"); }
							if (s % 4 == 3) { SetColor(c, 0); printf("v"); }
							if (s % 4 == 0) { SetColor(d, 0); printf("e"); }
						}
						else
						{
							SetColor(b, 0);
							printf("%c", z[i - 15]);
							Sleep(50);
						}
					}
					break;
				}
			}
			else
				printf(" ");
			Sleep(1);
		}
		printf("\n");
	}
	printf("                      河南牧业经济学院大学生社团发展服务中心！");
	getchar();
	while (1)
	{
		system("cls");
		t = a; a = b; b = c; c = d; d = e; e = t;
		for (y = 1.3; y >= -1.1; y -= U)
		{
			for (x = -2; x < 1.4; x += V)
			{
				if ((((x * x + y * y - 1) * (x * x + y * y - 1) * (x * x + y * y - 1) - x * x * y * y * y) <= 0))
				{
					if (y >= 1.3 - 10 * U || y <= 1.3 - 11 * U)
					{
						s++;
						if (s % 4 == 1) { SetColor(a, 0); printf("l"); }
						if (s % 4 == 2) { SetColor(b, 0); printf("o"); }
						if (s % 4 == 3) { SetColor(c, 0); printf("v"); }
						if (s % 4 == 0) { SetColor(d, 0); printf("e"); }
					}
					else
					{
						for (i = 0; i < 42; i++)
						{
							if (i <= 14 || i >= 28)
							{
								s++;
								if (s % 4 == 1) { SetColor(a, 0); printf("l"); }
								if (s % 4 == 2) { SetColor(b, 0); printf("o"); }
								if (s % 4 == 3) { SetColor(c, 0); printf("v"); }
								if (s % 4 == 0) { SetColor(d, 0); printf("e"); }
							}
							else
							{
								SetColor(e, 0);
								printf("%c", z[i - 15]);
							}
						}
						break;
					}
				}
				else
					printf(" ");
			}
			printf("\n");
		}
		Sleep(1000);
		system("cls");

	}
}

#include<stdio.h>
int main()
{
	printf("%c%c%c%c%c%c%c%c", -50,-46, -49, -78, -69, -74, -60, -29);
	return 0;//我喜欢你}
}
11010010//206
10110010//-原码-50
11001101//反码
11001110//补码
计算机中存储的是补码，但正数的补码原码相同，所以正数的原码就是补码，负数的原码不是补码


/*计算空格隔开的一句话多长*/
#include<stdio.h>
int main()
{
	char arr[100] = { 0 };
	int brr[100] = { 0 };
	int i = 0;
	int j = 0;
	int a = 0;
	while (1)
	{
		scanf("%c", &arr[i]);
		if (arr[i] == '.')
		{
			break;
		}
		i++;
	}
	i = 0;
	while (arr[i] != '.')
	{
		if (arr[i] != ' ')
		{
			i++;
			a++;
		}
		else
		{
			brr[j] = a;
			i++;
			j++;
			a = 0;
		}
	}
	brr[j] = a;
	for (i = 0; i < j + 1; i++)
	{
		printf("%d ", brr[i]);
	}
	return 0;
}
#include<stdio.h>
int main()
{
    char ch;
    int count = 0;
    while (1)
    {
        int a = 0;
        scanf("%c", &ch);
        while (ch != '\n' && ch != ' ' && ch != '.')
        {
            a++;
            scanf("%c", &ch);
        }
        if (a != 0)
        {
            count++;
            if (count == 1)printf("%d", a);
            else
                printf(" %d", a);
        }
        if (ch == '.')break;
    }
}
#define _CRT_SECURE_NO_WARNINGS
/*选择排序*/
#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	int n = 0;
	int arr[100] = { 0 };
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < n-1; i++)
	{
		for (j = i; j < n-1;j++)
		{
			int t = 0;
			if (arr[i] > arr[j + 1])
			{
				t = arr[i];
				arr[i] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf(" %d", arr[i]);
	}
	return 0;
}
1 2 3 4
给1234排序
2 1 3 4  4 2 1 3  4 3 2 1
3 1 2 4  4 3 1 2
4 1 2 3
/*计算一个汉字的ASCII码值是多少*/
#include<stdio.h>
int main()
{
	char str[] = "社联牛逼！";
	int i = 0;
	while (str[i] != '\0')
	{
		printf("%d ", str[i]);
		i++;
	}
	printf("\n");
	return 0;
}