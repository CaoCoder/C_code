#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int checkData(int* p)
{
	int tmp[7] = { 0 }; //标记表，实际是哈希表的思路。一开始每个元素都是0。

	int i;
	for (i = 0; i < 5; i++)
	{
		if (tmp[p[i]]) //如果这个位置的标记已经是1，则代表重复，直接返回0。
		{
			return 0;
		}
		tmp[p[i]] = 1; //如果不是，则给这个位置标记为1。
	}
	return 1; //全部标记完毕也没有出现重复的情况，代表OK。
}
int main()
{
	int p[5]; //0 1 2 3 4分别代表a b c d e

	for (p[0] = 1; p[0] <= 5; p[0]++)
	{
		for (p[1] = 1; p[1] <= 5; p[1]++)
		{
			for (p[2] = 1; p[2] <= 5; p[2]++)
			{
				for (p[3] = 1; p[3] <= 5; p[3]++)
				{
					for (p[4] = 1; p[4] <= 5; p[4]++) //五层循环遍历
					{
						//这里是五个人的描述，由于比较表达式只有0和1两个结果，如果要两个条件有且只有一个为真，则可以用比较表达式的值总和为1的方式直接判定。别忘了还要判定不能并列。
						if ((p[1] == 2) + (p[0] == 3) == 1 && //B第二，我第三
							(p[1] == 2) + (p[4] == 4) == 1 && //我第二，E第四
							(p[2] == 1) + (p[3] == 2) == 1 && //我第一，D第二
							(p[2] == 5) + (p[3] == 3) == 1 && //C最后，我第三
							(p[4] == 4) + (p[0] == 1) == 1 && //我第四，A第一
							checkData(p) //不能并列
							)
						{
							for (int i = 0; i < 5; i++)
							{
								printf("%d ", p[i]);
							}
							putchar('\n');
						}
					}
				}
			}
		}
	}
	return 0;
}
 /*方法二*/
#include <stdio.h>//编译预处理命令 
void sort() {//定义一个无返回值排序函数 
	int A, B, C, D, E;//定义五个整形变量A,B,C,D,E 
	//首先不加条件的情况下每个人的名次都有五种可能 
	for (A = 1; A <= 5; ++A)
	{
		for (B = 1; B <= 5; ++B)
		{
			for (C = 1; C <= 5; ++C)
			{
				for (D = 1; D < 5; ++D)
				{
					for (E = 1; E < 5; ++E)
					{
						if (A * B * C * D * E == 120)//五人名次不同相乘为120，减少筛选范围 
						{
							//以下5人的叙述中都只说对了一半 
							if (((B == 2) + (A == 3) == 1) && //A选手说：B第二，我第三
								((B == 2) + (E == 4) == 1) && //B选手说：我第二，E第四
								((C == 1) + (D == 2) == 1) &&//C选手说：我第一，D第二
								((C == 5) + (D == 3) == 1) &&//D选手说：C最后，我第三
								((E == 4) + (A == 1) == 1))//E选手说：我第四，A第一
							{
								printf("A=%d,B=%d,C=%d,D=%d,E=%d\n", A, B, C, D, E);//输出五人的名次
							}
						}
					}
				}
			}
		}
	}
}

int main() {//定义主函数 
	sort();//调用 sort函数 
	return 0;//函数返回值为0 
}
/*小乐乐排电梯*/
#include<stdio.h>
int main()
{
	int n = 0;
	int c = 0;
	scanf("%d", &n);
	if (n < 12)
	{
		printf("2");
	}
	else
	{
		c = n / 12;
		printf("%d", c * 4 + 2);
	}
	return 0;
}
/*BC107 矩阵转置 */
#include<stdio.h>
int main()
{
	int n = 0;
	int m = 0;
	int a[100][100] = { 0 };
	scanf("%d%d", &n, &m);
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", a[j][i]);
		}
		printf("\n");
	}
	return 0;
}
/*BC98-序列中删除指定数字*/
#include<stdio.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int k = 0;
	int j = 0;
	int arr[100] = { 0 };
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &k);
	for (i = 0; i < n; i++)
	{
		if (arr[i] == k)
		{
			arr[i] = 0;
		}
	}
	while (j < n)
	{
		if (arr[j] != 0)
		{
			printf("%d ", arr[j]);
		}
		j++;
	}
	return 0;
}
#include<stdio.h>
int main()
{
	int a = 0x11223344;
	return 0;
}
#include<stdio.h>
int main()
{
	int a = 10;
	int b = -10;
	return 0;
}
/*BC29 2的n次方计算 不使用累计乘法的基础上，通过移位运算（<<）实现2的n次方的计算*/
#include<stdio.h>
int main()
{
	int a = 1;
	int n = 0;
	int s = 0;
	scanf("%d", &n);
	//00000000 00000000 00000000 0000001
	s = a << n;
	printf("%d", s);
	return 0;
}
/*BC70 空心三角形图案 */
#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	int n = 0;
	int arr[30][30] = { 0 };
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j <= i; j++)
			{
				if (j == 0 || i == j || i == n - 1)
				{
					printf("* ");
				}
				if (i != j && j != 0 && i != n - 1)
				{
					printf("  ");
				}
			}
			printf("\n");
		}
	}
	
	return 0;
}
/*BC76 公务员面试 */
#include<stdio.h>
int main()
{
	int arr[7] = { 0 };
	int i = 0;
	for (i = 0; i < 7; i++)
	{
		scanf("%d", &arr[i]);
	}
	int max = arr[0];
	int min = arr[0];
	for (i = 0; i < 7; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	int sum = 0;
	for (i = 0; i < 7; i++)
	{
		sum = sum + arr[i];
	}
	printf("%.2f", (sum - min - max) / 5.0);
	return 0;
}
/*BC54 获得月份天数 */
#include<stdio.h>
int main()
{
	int year = 0;
	int mon = 0;
	while (scanf("%d%d", &year, &mon) != EOF)
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		{
			if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12)
			{
				printf("31");
			}
			if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
			{
				printf("30");
			}
			if (mon == 2)
			{
				printf("29");
			}
		}
		else
		{
			if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12)
			{
				printf("31");
			}
			if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
			{
				printf("30");
			}
			if (mon ==2)
			{
				printf("28");
			}
		}
		printf("\n");
	}
	return 0;
}
/*BC53 计算一元二次方程 */
#include<stdio.h>
#include<math.h>
int main()
{
	float a = 0;
	float b = 0;
	float c = 0;
	while (scanf("%f%f%f", &a, &b, &c) != EOF)
	{
		float t = 0;
		t = pow(b, 2) - 4 * a * c;
		if (a == 0)
		{
			printf("Not quadratic equation");
		}
		else
		{
			if (t == 0)
			{
				printf("x1=x2=%.2f", (-b + sqrt(t)) / (2 * a));
			}
			else if (t > 0)
			{
				printf("x1=%.2f;x2=%.2f", (-b - sqrt(t)) / (2 * a),(-b + sqrt(t)) / (2 * a));
			}
			else
			{
				printf("x1=%.2f-%.2fi;x2=%.2f+%.2fi\n",
					(-b) / (2 * a), sqrt(-t) / (2 * a),
					(-b) / (2 * a), sqrt(-t) / (2 * a));
			}
		}
		printf("\n");
	}
	return 0;
}
/*用max()函数求两个整数的最大值*/
#include<stdio.h>
int Max(int a, int b)
{
	int max = a > b ? a : b;
	return max;
}
int main()
{
	int a = 0;
	int b = 0;
	int n = 0;
	scanf("%d%d", &a, &b);
	n = Max(a, b);
	printf("%d", n);
	return 0;
}
/*定义一个求n个整数和的函数sum（）*/
#include<stdio.h>
int sum(int n)
{
	int i = 0;
	int a = 0;
	int s = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a);
		s = s + a;
	}
	return s;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d", sum(n));
	return 0;
}
/*计算组合数使用嵌套函数*/
#include<stdio.h>
int mn(m, n)
{
	int a = m - n;
	int s = 1;
	while (a != 1)
	{
		s = s * a;
		a = a - 1;
	}
	return s;
	
}
int nnn(n)
{
	int s = 1;
	while (n != 1)
	{
		 s = s * n;
		 n = n - 1;
	}
	return s;
}
int mmm(m)
{
	int s = 1;
	while (m != 1)
	{
		s = s * m;
		m = m - 1;
	}
	return s;
}
int math(int n,int m)
{
	mmm(m);
	nnn(n);
	mn(m, n);
	return (mmm(m) / nnn(n) * mn(m, n));
}
int main()
{
	int n = 0;
	int m = 0;
	scanf("%d%d", &n, &m);
	printf("%d", math(n, m));
	return 0;
}
/*求两点的距离*/
#include<stdio.h>
#include<math.h>
double dist(double x, double y, double x1, double y1)
{
	double a = sqrt((abs(x - x1)) * abs(x - x1) + abs(y - y1) * abs(y - y1));
	return a;
}
int main()
{
	double x = 0;
	double y = 0;
	double x1 = 0;
	double y1 = 0;
	scanf("%lf%lf%lf%lf", &x, &y, &x1, &y1);
	double b = dist(x, y, x1, y1);
	printf("%.2lf", b);
	return 0;
}
/*计算标准体重*/
#include<stdio.h>
float fun(int h)
{
	return ((h - 100) * 0.9 * 2);
}
int main()
{
	int h = 0;
	float w = 0;
	scanf("%d", &h);
	printf("%.1f", fun(h));
	return 0;
}
/*编写一个函数让数组中每一个数乘以5输出*/
#include<stdio.h>
void fun(int* arr,int n)
{
	int a = 0;
	while (a<n)
	{
		*(arr + a++) *= 5;
	}
}
int main()
{
	int arr[5] = { 1,2,3,4,5 };
	fun(arr,5);
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
/*求阶乘和数*/
#include<stdio.h>
int fun(int m)
{
	while (m)
	{
		int i = 0;
		int arr[3] = { 0 };
		arr[i] = m % 10;
		m = m / 10;
		i++;
	}
	fac()
	if(m==)
}
int main()
{
	int m = 0;
	scanf("%d", &m);
	fun(m);
	return 0;
}