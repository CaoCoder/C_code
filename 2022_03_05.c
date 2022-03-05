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
//			k = k + i;//第一次for循环k为3，第二次for循环k为6
//			
//
//		}
//		if (k > 6)//k不大于6，所以不跳出循环。开始进入第二轮while循环。
//		{
//			break;//这时候k加2，再加3；
//			//这时候k是11，然后大于6，跳出循环
//		}
//	} while (j--);
//	printf("%d", k);
//}
#include<stdio.h>


//第一步列出所有的可能性，每个人有2种可能情况
//假设参赛是1，不参赛为0；
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