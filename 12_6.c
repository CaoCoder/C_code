//#define _CRT_SECURE_NO_WARNINGS
///*leetcode删除排序数组中的重复项《快慢指针*/
//#include<stdio.h>
//int semove(int* nums, int a)
//{
//	if (a == 1)
//	{
//		return 1;
//	}
//	int fast = 1;
//	int slow = 1;
//	while (fast < a)
//	{
//		if (nums[fast] != nums[fast - 1])
//		{
//			nums[fast-1] = nums[fast];
//			slow++;
//		}
//		fast++;
//	}
//	return slow;
//}
//int main()
//{
//	int nums[] = {0,0,1,1,1,2,2,3,3,4};
//	int a = sizeof(nums)/sizeof(nums[0]);
//	//strlen只能用于计算字符串的长度
//	int len = semove(nums, a);
//	printf("%d", len);
//	return 0;
//}
///*LeetCode买卖股票的最佳时间《贪心》*/
//#include<stdio.h>
//int maxp(int* prices, int len)
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 1; i < len; i++)
//	{
//		if (prices[i] > prices[i - 1])
//		{
//			 sum += prices[i] - prices[i - 1];
//		}
//	}
//	return sum;
//}
//int main()
//{
//	int prices[] = { 7,1,5,3,6,4 };
//	int len = sizeof(prices) / sizeof(prices[0]);
//	int a = maxp(prices, len);
//	printf("%d", a);
//	return 0;
//}
///*BC8 十六进制转十进制 */
//#include<stdio.h>
//int main()
//{
//	int a = 0xABCDEF;
//	printf("%15d", a);
//	return 0;
//}
///*BC9 printf的返回值 */
//#include<stdio.h>
//int main() 
//{ 
//	int a=printf("Hello world!"); 
//	printf("\n%d",a); 
//	return 0;
//}
///*BC10 成绩输入输出 */
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d%d%d", &a, &b, &c);
//	printf("score1=%d,score2=%d,score3=%d", a, b, c);
//	return 0;
//}
///*BC11 学生基本信息输入输出 */
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	float b = 0;
//	float c = 0;
//	float d = 0;
//	char e = 0;
//	char f = 0;
//	char g = 0;
//	scanf("%d%c%f%c%f%c%f", &a, &e, &b,&f, &c,&g, &d);
//	printf("The each subject score of No. %d is %.2f, %.2f, %.2f.",a,b,c,d);
//	return 0;
//}
///*BC13 ASCII码 */
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 73,32,99,97,110,32,100,111,32,105,116,33};
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		printf("%c", arr[i]);
//	}
//	return 0;
//}
///*BC14 出生日期输入输出 */
//#include<stdio.h>
//int main()
//{
//    int a, b, c;
//    scanf("%4d%2d%2d", &a, &b, &c);
//    printf("year=%d\nmonth=%02d\ndate=%02d\n", a, b, c);
//}
///*BC16 字符转ASCII码 */
//#include<stdio.h>
//int main()
//{
//	char a = 0;
//	scanf("%c", &a);
//	printf("%d", a);
//	return 0;
//}
///*BC20 kiki算数*/
//#include<stdio.h>
//int main()
//{
//    int a = 0;
//    int b = 0;
//    scanf("%d %d", &a, &b);
//    printf("%d\n", (a % 100 + b % 100) % 100);
//    return 0;
//}
///*BC21 浮点数的个位数字 */
//#include<stdio.h>
//int main()
//{
//	float a = 0;
//	scanf("%f", &a);
//	printf("%d", (int)a % 10);
//	return 0;
//}
///*BC22 你能活多少秒 */
//#include<stdio.h>
//int main()
//{
//	long int a = 0;
//	scanf("%ld", &a);
//	printf("%ld", a * 31560000);
//	return 0;
//}
///*BC25 计算体重指数 */
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	float c = a / pow(b * 0.01,2);
//	printf("%.2f", c);
//	return 0;
//}
///*BC26 计算三角形的周长和面积 */
//#include<stdio.h>
//int main()
//{
//	int num = 13;
//	int i = 0;
//	scanf("%d", &num);
//	int count = 0;
//	for (i = 0; i < 32; i++)
//	{
//		int a = num >> i;
//		if (1 & a )
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int c = 0;
//	int a = 0;
//	int n = 0;
//	int sum = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int j = 0;
//	for (i = 2; i < 10000; i++)
//	{
//		for (j = 2; j <= sqrt(i); j++)  
//			if (i % j == 0)           
//			{
//				break;
//			}
//		}
//		if (j > sqrt(i))
//		{
//			a = i;
//			sum += a;
//			if (sum > n)
//			{
//				break;
//			}
//			printf("%d", i);
//			printf("\n");
//			c++;
//		}
//	}
//	printf("%d", c);
//	return 0;
//}
///*小鱼比可爱*/
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int n = 0;
//	int arr[100] = { 0 };
//	int j = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i = 0; i < n; i++)
//	{
//		int c = 0;
//		for (j = 0; j < i; j++)
//		{
//			if (arr[i] > arr[j])
//			{
//				c++;
//			}
//		}
//		printf("%d ", c);
//	}
//	return 0;
//}
///*买铅笔*/
//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int m[3] = { 0 };
//	scanf("%d", &n);
//	int a = 0;
//	int b = 0;
//	int d = 0;
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%d%d", &a, &b);
//		d = n / a;
//		if (n % a != 0)
//		{
//			d = d + 1;
//		}
//		m[i] = d * b;
//	}
//	int min = m[0];
//	for (i = 0; i < 3; i++)
//	{
//		if (m[i] < min)
//		{
//			min = m[i];
//		}
//	}
//	printf("%d", min);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	printf("我爱树莓");
//	return 0;
//}
///*BC34 进制A+B */