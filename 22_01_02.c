#define _CRT_SECURE_NO_WARNINGS
int maxProfit(int* prices, int pricesSize) 
{
    /*int* p = (int*)malloc((sizeof) * pricesSize);*/
    int sum = 0;
    int n = 0;
    while (n < pricesSize - 1)
    {
        for (n = 0; n < pricesSize - 1; n++)
            if (prices[n + 1] - prices[n] > 0)
            {
                sum += prices[n + 1] - prices[n];
            }
    }
    return sum;
}
#include<stdio.h>
int main()
{
    int prices[] = {7,6,4,3,1 };
    int priceSize = sizeof(prices) / sizeof(prices[0]);
    int ret = maxProfit(prices, priceSize);
    printf("%d", ret);
    return 0;
}

