#define _CRT_SECURE_NO_WARNINGS
/*������ַ���*/
//int main()
//{
//	int i = 0;
//	char arr1[200] = {0};
//	char arr[5][100] = { 0 };
//	for (i = 0; i <= 4; i++)
//	{
//		gets(arr[i]);//��5���ַ��ֱ����5�С�gets�����Զ�����
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
/*ɾ���ո�*/
//int main()
//{
//	int i = 0;
//	char arr[100] = "";
//	char arr1[100] = "";
//	printf("�����룺");
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