#define _CRT_SECURE_NO_WARNINGS
/*查找最长字符串*/
//int main()
//{
//	int i = 0;
//	char arr1[200] = {0};
//	char arr[5][100] = { 0 };
//	for (i = 0; i <= 4; i++)
//	{
//		gets(arr[i]);//将5串字符分别存入5行。gets函数自动换行
//	}
//	int max = strlen(arr[0]);
//	arr1[300] = arr[0];
//	for (i = 0; i <= 4; i++)
//	{
//		if (strlen(arr[i]) > max)
//		{
//			max = strlen(arr[i]);
//			arr1[100] = arr[i];
//		}
//	}
//	printf("%s", arr1);
//	return 0;
//}
/*删除空格*/
//int main()
//{
//	int i = 0;
//	char arr[100] = "";
//	char arr1[100] = "";
//	printf("请输入：");
//	gets(arr);
//	for (i = 0; i < 5; i++)
//	{
//		if (arr[i] != ' ')
//		{
//			arr1[i] = arr[i];
//		}
//	}
//	arr1[i + 1] = '\0';
//	puts(arr1);
//	return 0;
//}