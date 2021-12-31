#define _CRT_SECURE_NO_WARNINGS
int main()
{
	int arr[] = { 5,4,3,2,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int j = 0;
	int t = 0;
	for (i = 0; i < len - 1; i++)
	{
		int flag = 1;
		for (j = 0; j < len - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
	for (i = 0; i < len; i++)
	{
		printf("%d", arr[i]);
	}
	return 0;
}