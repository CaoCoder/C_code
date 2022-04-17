#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void swap(char* left, char* right)
{
	while (left < right)
	{
		char t = 0;
		t = *left;
		*left = *right;
		*right = t;
		left++;
		right--;
	}
}
void reserve(char* a, int lenth)
{
	char* fast = a + 0;
	char* slow = a + 0;
	while (fast < a + lenth)
	{
		while (*fast != ' ')
		{
			fast++;
		}
		//½»»»
		swap(slow, fast - 1);
		while (*fast == ' ')
		{
			fast++;
		}
		slow = fast;
	}
}

int main()
{
	char a[20];
	gets(a);
	int len = strlen(a);
	//·´×ª
	reserve(a, len);

	printf("%s", a);
}