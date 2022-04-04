#include<stdio.h>
int main()
{
	struct S2
	{
		char c1;
		char c2;
		int i;
	};
	printf("%d\n", sizeof(struct S2));
	return 0;
}
struct S {
	int data[1000];
	int num;
};
struct S s = { {1,2,3,4}, 1000 };
//结构体传参
void print1(struct S s) {
	printf("%d\n", s.num);
}
//结构体地址传参
void print2(struct S* ps) {
	printf("%d\n", ps->num);
}
int main()
{
	print1(s);  //传结构体
	print2(&s); //传地址
	return 0;
}