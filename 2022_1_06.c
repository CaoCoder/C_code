#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define Max 100
struct bus
{
	char depart[6];
	char arrived[10];
	int time;
	int tickets;
};
int count(struct bus arr[], int n, int M[]);
int main()
{
	FILE* fp;
	struct bus b[Max];
	int n = 0;
	int total = 0;
	char a_name[10];
	if ((fp = fopen("info.txt", "r")) == NULL)
	{
		printf("Cant find file");
		return 0;
	}
	while (!feof(fp))
	{
		fscanf(fp, "%s%s%d%d", b->depart, b->time, &(b->time), &(b->tickets));
		n++;
	}
	fclose(fp);
	printf("�������յ�վ���ƣ�");
	gets(a_name);
	total = count(b, n, a_name);
	printf("����%s�İ����Ϊ%d", a_name, total);
	return 0;
}
int count(struct bus arr[], int n, char M[])
{
	int i = 0;
	int c = 0;
	for (i = 0; i < n; i++)
	{
		if (strcmp(arr[i].arrived, M))
			c = c + 1;
	}
	return c;
}