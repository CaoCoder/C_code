#define _CRT_SECURE_NO_WARNINGS
//判断谁是凶手。
//#include <stdio.h>
//int main()
//{
//	char i = 0;
//	for (char i = 'A'; i <= 'D'; i++)
//	{
//		if (((i != 'A') + (i == 'C') + (i == 'D') + (i != 'D')) == 3)
//		{
//			printf("%c ", i);
//		}
//	}
//	return 0;
//}
//猜名次。哈希表的思路很妙。
//#include <stdio.h>
//int checkData(int* p)
//
//{
//	int tmp[7] = { 0 }; //标记表，实际是哈希表的思路。一开始每个元素都是0。
//	int i;
//	for (i = 0; i < 5; i++)
//	{
//		if (tmp[p[i]]) //如果这个位置的标记已经是1，则代表重复，直接返回0。
//		{
//			return 0;
//		}
//		tmp[p[i]] = 1; //如果不是，则给这个位置标记为1。
//	}
//	return 1; //全部标记完毕也没有出现重复的情况，代表OK。
//}
//int main()
//{
//	int p[5];
//
//	for (p[0] = 1; p[0] <= 5; p[0]++)
//	{
//		for (p[1] = 1; p[1] <= 5; p[1]++)
//		{
//			for (p[2] = 1; p[2] <= 5; p[2]++)
//			{
//				for (p[3] = 1; p[3] <= 5; p[3]++)
//				{
//					for (p[4] = 1; p[4] <= 5; p[4]++)
//					{
//						
//						if ((p[1] == 2) + (p[0] == 3) == 1 &&
//							(p[1] == 2) + (p[4] == 4) == 1 &&
//							(p[2] == 1) + (p[3] == 2) == 1 &&
//							(p[2] == 5) + (p[3] == 3) == 1 &&
//							(p[4] == 4) + (p[0] == 1) == 1&&
//							checkData(p) //不能并列
//							)
//						{
//							//牛逼的条件断点
//						/*	if (p[0] == 3 && p[1] == 1 &&
//								p[2] == 5 && p[3] == 2 &&
//								p[4] == 4)
//							{
//								;
//							}*/
//							for (int i = 0; i < 5; i++)
//
//							{
//
//								printf("%d ", p[i]);
//
//							}
//							putchar('\n');
//						}
//						
//					}
//				}
//			}
//		}
//	}
//}
 //BC116-小乐乐改数字
//#include <stdio.h>
//int main()
//{
//    int a[10] = { 0 };
//    int b = 0;
//    int i = 9;
//    int t = 0;
//    scanf("%d", &b);
//    while (b > 0)
//    {
//        t = b % 10;
//        if (t % 2 == 0)
//        {
//            a[i--] = 0;
//        }
//        else
//        {
//            a[i--] = 1;
//        }
//        b = b / 10;
//    }
//    int j = 0;
//    while (a[j] == '\0'&& j <=9)
//    {
//        j++;
//    }
//    if (j == 10)
//    {
//        printf("%d", 0);
//    }
//    else
//    {
//        for (int k = j; k <= 9; k++)
//        {
//            printf("%d", a[k]);
//        }
//    }
//
//    return 0;
//}
//BC116-小乐乐改数字
//#include <stdio.h>
//#include <math.h>
//int main()
//
//{
//    int n = 0;
//    int sum = 0;
//    scanf("%d", &n);
//    int i = 0;
//    while (n)
//    {
//        int m = n % 10;
//        if (m % 2 == 1)
//            m = 1;
//        else
//            m = 0;
//        //巧用pow函数。
//        sum += m * pow(10, i);
//        i++;
//        n /= 10;
//    }
//    printf("%d\n", sum);
//    return 0;
//
//}
// //BC117-小乐乐走台阶
//递归解法，太妙了
//#include <stdio.h>
//int fib(int n)
//{
//    if (n <= 2)
//        return n;
//    else
//        return fib(n - 1) + fib(n - 2);
//}
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    printf("%d\n", fib(n));
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	int a[10000] = {0};
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//
//	return 0;
//}