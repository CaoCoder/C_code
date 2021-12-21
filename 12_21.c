#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int my_strlen(char* s)
{
	int count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return count;
}
/*指针写法*/
void reverse_string(char* str)//str存放的是首元素的地址。*str 代表a，str代表地址。
{
	char* left = str;//将a放在指针left里。
	char* right = my_strlen(str) + str - 1;
	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}

}
/*参数写法*/
void reverse_string(char arr[])
{
	int left = 0;
	int right = my_strlen(arr) - 1;
	while (left < right)
	{
		char temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;
		right--;
	}
}
/*递归版本*/
void reverse_string(char* arr)
{
	int len = my_strlen(arr);
	char temp = *arr;
	*arr = *(arr + len - 1);//解引用
	*(arr + len - 1) = '\0';
	if (my_strlen(arr + 1) > 1)
		reverse_string(arr + 1);
	*(arr + len - 1) = temp;
}
int main()
{

	char arr[] = "abcdef";//abcdef\0
	reverse_string(arr);
	printf("%s\n", arr);
	return 0;
}
/*求两个数二进制中不同位的个数*/
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	int c = 0;
	int d = 0;
	int n = 0;
	c = a ^ b;
	int count = 32;
	while (count > 0)
	{
		d = c & 1;
		if (1 == d)
		{
			n++;
		}
		count--;
		c = c >> 1;
	}
	printf("%d", n);
	return 0;
}
/*求二进制中奇数位和偶数位*/
int main()
{
	int a = 2;
	int b = 0;
	int c = 0;
	int count = 16;
	while (count > 0)
	{
		b = a & 1;
		printf("%d", b);
		b = b >> 1;
		count--;
	}
	printf("\0");
	int coun = 16;
	while (coun > 0)
	{
		a = a >> 1;
		b = a & 1;
		printf("%d", b);
		coun--;
	}
	return 0;
}
/*输入一个整数 n ，输出该数32位二进制表示中1的个数。其中负数用补码表示。 */
int main()
{
	int count = 0;
	int n = 0;
	scanf("%d", &n);
	int b = 0;
	int i = 0;
	for (i = 1; i <= 32; i++)
	{
		b = n & 1;
		if (1 == b)
		{
			count++;
		}
		n = n >> 1;

	}
	printf("%d", count);
	return 0;
}
/*交换两个变量（不创建临时变量）*/
int main()
{
	int a = 10;
	int b = 5;
	b = a + b;
	a = b - a;
	b = b - a;
	printf("%d %d", a, b);
}
int main()
{
	int a = 10;
	int b = 5;
	a = a ^ b;
	b = a ^ b;//a^b^b
	a = a ^ b;
	printf("%d %d", a, b);
}
