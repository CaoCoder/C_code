#define _CRT_SECURE_NO_WARNINGS
/*%g用来输入实数，三目操作符的调用。*/
#include <stdio.h>
#define Abs(x) ((x) > 0 ? (x) : (x) < 0 ? -(x) : 0)
int main()
{
    int a, b;
    double x, y;
    scanf("%d %lg", &a, &x);
    b = Abs(a);
    y = Abs(x);
    printf("%d %g\n", b, y);
    return 0;
}
/*循环*/
#include <stdio.h>
int main()
{
forever:
    printf("I\3U");
always:
    goto forever;
endless:
    return 0;
}
/*递归求排列组合A（5,3）*/
#include<stdio.h>
double Arg(int x, int y)
{
	if (y != 1 && x != 0 && y!=0)
	{
		return x * Arg(x - 1,y-1);
	}
	else if (x == 0||y == 0)
	{
		return 1;
	}
	else
	{
		return x;
	}
}
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	printf("%.10g\n", Arg(m, n));
	return 0;
}
/*反转字符串*/
#include<stdio.h>
void reverseString(char* s, int sSize)
{
	char* left = s + 0;
	char* right = s + sSize - 1;
	while (left <= right)
	{
		int t = 0;
		t = *left;
		*left = *right;
		*right = t;
		left++;
		right--;
	}
	printf("%s", s);
}
int main()
{
	char arr[40] = {0};
	scanf("%s", arr);
	int sSize = strlen(arr);
	reverseString(arr, sSize);
	return 0;
}
