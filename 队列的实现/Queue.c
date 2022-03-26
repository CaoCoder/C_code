#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"
//��ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}
//���
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
		//����ͷָ��Ϊ��
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
//����
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head && pq->tail);
	//ֻ��һ���ڵ�ʱ��
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = NULL;
		pq->tail = NULL;
	}
	else
	{
		//ע��next��ָ��ڵ�ġ�������QNode����
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = NULL;
		pq->head = next;
	}
}
//�ж��Ƿ�Ϊ��
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	//if (pq->head == NULL)
	//{
	//	return true;
	//}
	//return false;
	//���д��
	return pq->head != NULL;
}
//���ʶ�ͷ��ֵ
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head && pq->tail);
	return pq->head->data;
}
//���ʶ�β��ֵ
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head && pq->tail);
	return pq->tail->data;
}
//����г���
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
//���ٶ���
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

