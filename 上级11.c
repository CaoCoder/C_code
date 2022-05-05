/*不用strlen函数查字符串*/
#include<stdio.h>
#include<string.h>
int main()
{
	char arr[20] = {0};
	gets(arr);//获取键盘上的字符除了'\n'.并将回车键转化为\0
	int i = 0;
	while (arr[i++]);//'\0'ASCII码值为0
	printf("%d", i-1);
	return 0;
}
/*查找指定字符*/
int main()
{
	int i = 0;
	printf("请输入字符串：\n");
	char arr[100] = { 0 };
	gets(arr);//自动换行
	printf("请输入要查找的字符：");
	char ch = getchar();//得到一个字符
	while (arr[i++]!= ch);
	printf("%d", i);
	return 0;
}
/*为字符串加密*/
int main()
{
	int i = 0;
	char arr[100] = { 0 };
	gets(arr);
	while (arr[i])
	{
		if (isalpha(arr[i]) != 0)//isalpha函数如果判断是非字母，返回0，如果是小写字母返回2，如果是大写字母返回1。
		{
			if (arr[i] == 'y')
			{
				arr[i] = 95;//'a'的ASCII码值是97
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
/*查找最长字符串*/
int main()
{
	int i = 0;
	char arr1[200] = {0};
	char arr[5][100] = { 0 };
	for (i = 0; i <= 4; i++)
	{
		gets(arr[i]);//将5串字符分别存入5行。gets函数自动换行
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
/*删除空格*/
int main()
{
	int i = 0;
	char arr[100] = "";
	char arr1[100] = "";
	printf("请输入：");
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