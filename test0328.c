#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"

int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	

	printf("%d ", QueueSize(&q));
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"
//��ʼ���ṹ��
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
	QNode* new = (QNode*)malloc(sizeof(QNode));
	if (new == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	if (pq->tail == NULL)
	{
		pq->tail = pq->head = new;
		pq->tail->data = x;
	}
	else
	{

		pq->tail->next = new;
		new->data = x;
		pq->tail = new;
	}
}
//����
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	Queue* next = pq->head->next;
	if (pq->head == pq->tail)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		free(pq->head);
		pq->head = NULL;
		pq->head = next;
	}
}
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
//�õ���ͷ��ֵ
QDataType QueueTop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}
//�õ���β��ֵ
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->tail);
	return pq->tail->data;
}
//������еĳ���
int QueueSize(Queue* pq)
{
	assert(pq);
	int s = 0;
	if (pq->head == pq->tail && pq->head == NULL)
	{
		return 0;
	}
	else
	{
		while (pq->head != pq->tail)
		{
			s++;
			pq->head = pq->head->next;
		}
		return s + 1;
	}
}