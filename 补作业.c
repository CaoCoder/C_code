#define _CRT_SECURE_NO_WARNINGS
//�ж�˭�����֡�
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
//�����Ρ���ϣ���˼·���
//#include <stdio.h>
//int checkData(int* p)
//
//{
//	int tmp[7] = { 0 }; //��Ǳ�ʵ���ǹ�ϣ���˼·��һ��ʼÿ��Ԫ�ض���0��
//	int i;
//	for (i = 0; i < 5; i++)
//	{
//		if (tmp[p[i]]) //������λ�õı���Ѿ���1��������ظ���ֱ�ӷ���0��
//		{
//			return 0;
//		}
//		tmp[p[i]] = 1; //������ǣ�������λ�ñ��Ϊ1��
//	}
//	return 1; //ȫ��������Ҳû�г����ظ������������OK��
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
//							checkData(p) //���ܲ���
//							)
//						{
//							//ţ�Ƶ������ϵ�
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
 //BC116-С���ָ�����
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
//BC116-С���ָ�����
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
//        //����pow������
//        sum += m * pow(10, i);
//        i++;
//        n /= 10;
//    }
//    printf("%d\n", sum);
//    return 0;
//
//}
// //BC117-С������̨��
//�ݹ�ⷨ��̫����
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