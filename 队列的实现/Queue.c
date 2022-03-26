#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"
//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}
//入队
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	if (pq->tail == NULL)
	{
		//断言头指针为空
		assert(pq->head == NULL);
		pq->tail = newNode;
		pq->head = newNode;
	}
	else
	{
		pq->tail->next = newNode;
		pq->tail = pq->tail->next;
	}
}
//出队
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head && pq->tail);
	//只有一个节点时。
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = NULL;
		pq->tail = NULL;
	}
	else
	{
		//注意next是指向节点的。所以用QNode创建
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = NULL;
		pq->head = next;
	}
}
//判断是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	//if (pq->head == NULL)
	//{
	//	return true;
	//}
	//return false;
	//简便写法
	return pq->head != NULL;
}
//访问队头的值
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head && pq->tail);
	return pq->head->data;
}
//访问队尾的值
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head && pq->tail);
	return pq->tail->data;
}
//求队列长度
size_t QueueSize(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	size_t size = 0;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}
//销毁队列
void QueueDestroy(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	QNode* next = NULL;

	while (pq->head)
	{
		next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
	pq->tail = NULL;
}

