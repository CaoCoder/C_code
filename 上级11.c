/*����strlen�������ַ���*/
#include<stdio.h>
#include<string.h>
int main()
{
	char arr[20] = {0};
	gets(arr);//��ȡ�����ϵ��ַ�����'\n'.�����س���ת��Ϊ\0
	int i = 0;
	while (arr[i++]);//'\0'ASCII��ֵΪ0
	printf("%d", i-1);
	return 0;
}
/*����ָ���ַ�*/
int main()
{
	int i = 0;
	printf("�������ַ�����\n");
	char arr[100] = { 0 };
	gets(arr);//�Զ�����
	printf("������Ҫ���ҵ��ַ���");
	char ch = getchar();//�õ�һ���ַ�
	while (arr[i++]!= ch);
	printf("%d", i);
	return 0;
}
/*Ϊ�ַ�������*/
int main()
{
	int i = 0;
	char arr[100] = { 0 };
	gets(arr);
	while (arr[i])
	{
		if (isalpha(arr[i]) != 0)//isalpha��������ж��Ƿ���ĸ������0�������Сд��ĸ����2������Ǵ�д��ĸ����1��
		{
			if (arr[i] == 'y')
			{
				arr[i] = 95;//'a'��ASCII��ֵ��97
			}
			else if (arr[i] == 'z')
			{
				arr[i] = 96;
			}
			arr[i] = arr[i] + 2;
		}
		++i;
	}
	puts(arr);
	return 0;
}
/*������ַ���*/
int main()
{
	int i = 0;
	char arr1[200] = {0};
	char arr[5][100] = { 0 };
	for (i = 0; i <= 4; i++)
	{
		gets(arr[i]);//��5���ַ��ֱ����5�С�gets�����Զ�����
	}
	int max = strlen(arr[0]);
	arr1[300] = arr[0];
	for (i = 0; i <= 4; i++)
	{
		if (strlen(arr[i]) > max)
		{
			max = strlen(arr[i]);
			arr1[100] = arr[i];
		}
	}
	printf("%s", arr1);
	return 0;
}
/*ɾ���ո�*/
int main()
{
	int i = 0;
	char arr[100] = "";
	char arr1[100] = "";
	printf("�����룺");
	gets(arr);
	for (i = 0; i < 5; i++)
	{
		if (arr[i] != ' ')
		{
			arr1[i] = arr[i];
		}
	}
	arr1[i + 1] = '\0';
	puts(arr1);
	return 0;
}