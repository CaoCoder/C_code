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
/*ָ��д��*/
void reverse_string(char* str)//str��ŵ�����Ԫ�صĵ�ַ��*str ����a��str�����ַ��
{
	char* left = str;//��a����ָ��left�
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
/*����д��*/
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
/*�ݹ�汾*/
void reverse_string(char* arr)
{
	int len = my_strlen(arr);
	char temp = *arr;
	*arr = *(arr + len - 1);//������
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
/*���������������в�ͬλ�ĸ���*/
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
/*�������������λ��ż��λ*/
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
/*����һ������ n ���������32λ�����Ʊ�ʾ��1�ĸ��������и����ò����ʾ�� */
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
/*����������������������ʱ������*/
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
