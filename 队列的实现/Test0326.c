#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	printf("%d ", QueueFront(&q));
	QueuePop(&q);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	//���Ӵ�ӡ
	while (QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
	//���ٶ���
	QueueDestroy(&q);
}
int main()
{
	TestQueue();
	return 0;
}