#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
////int main()
////{
////	int arr1[2][3] = { 0 };
////	int arr2[3][2] = { 0 };
////	int arrsum[2][2] = { 0 };
////	int i = 0;
////	int j = 0;
////	int k = 0;
////	int m = 0;
////	int n = 0;
////	for (i = 0; i < 2; i++)
////	{
////		for (j = 0; j < 3; j++)
////		{
////			scanf("%d", &arr1[i][j]);
////		}
////	}
////	for (i = 0; i < 3; i++)
////	{
////		for (j = 0; j < 2; j++)
////		{
////			scanf("%d", &arr2[i][j]);
////		}
////	}
////	int a = 0;
////	for (a = 0; a < 2; a++)
////	{
////		int b = 0, c = 0, d = 0;
////		for (b = 0; b < 2; b++)
////		{
////			for (j = 0; j < 3; j++)
////			{
////				arrsum[a][b] = arrsum[a][b] + arr1[a][j] * arr2[j][b];
////			}
////			printf("%d ", arrsum[a][b]);
////		}
////		printf("\n");
////	}
////	return 0;
////}
//int main()
//{
//	int i = 0;
//	int j = 2;
//	int k = 1;
//	do
//	{
//		for (i = 2; i < 4; i++)
//		{
//			k = k + i;//��һ��forѭ��kΪ3���ڶ���forѭ��kΪ6
//			
//
//		}
//		if (k > 6)//k������6�����Բ�����ѭ������ʼ����ڶ���whileѭ����
//		{
//			break;//��ʱ��k��2���ټ�3��
//			//��ʱ��k��11��Ȼ�����6������ѭ��
//		}
//	} while (j--);
//	printf("%d", k);
//}
#include<stdio.h>


//��һ���г����еĿ����ԣ�ÿ������2�ֿ������
//���������1��������Ϊ0��
#include<stdio.h>
int main()
{
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    for (a = 0; a <= 1; a++)
    {
        for (b = 0; b <= 1; b++)
        {
            for (c = 0; c <= 1; c++)
            {
                for (d = 0; d <= 1; d++)
                {
                    for (e = 0; e <= 1; e++)
                    {
                        if (a && b)
                        {
                            if (b && c || (b == 0 && c == 0))
                            {
                                if (c || d)
                                {
                                    if (d == 0 && e || d && e == 0)
                                    {
                                        if (e)
                                        {
                                            a == 1;
                                            d == 1;
                                            printf("a=%db=%dc=%dd=%de=%d", a, b, c, d, e);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}