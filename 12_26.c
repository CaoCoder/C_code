#define _CRT_SECURE_NO_WARNINGS

//int main()
//{
//	void (*)(int);//����ָ��
//	signal(int, void(*)(int))//���������һ��һ�������Ǻ���ָ������
//	void (*signal(int, void(*)(int)))(int);//�����ĺ���ָ��
//	return 0;
//}
#include<stdio.h>

void    print(char c[][10], int* number, int* total, int* answer, int k)
{
	if (k < 10) {
		for (; answer[k] < total[number[k]] - 1; answer[k]++) {
			print(c, number, total, answer, k + 1);


		}
	}
	if (k == 10)
		for (int i = 0; i < 6; i++) {
			printf("%c", c[number[i]][answer[i]]);
			return;
		}
}
int main()
{
	for (; answer[0] < total[number[0]] - 1; answer[0]++)//���ݸ���ѭ�������Ǳ���ѭ��
	{
		print(c, number, total, answer, 0);

	}
	return 0;
}
int number[6] = { 1,3,2,6,5,4 };
int total[10] = { 0,0,3,3,3,3,3,4,3,4 };
int answer[6] = { 0,0,0,0,0,0 };
char c[10][10] =
{
	"",
	"",
	"ABC",
	"DEF",
	"GHI",
	"JKL",
	"MNO",
	"PQRS",
	"TUV",
	"WXYZ"
};