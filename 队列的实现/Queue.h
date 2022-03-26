#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


typedef int QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

//��ʼ��
void QueueInit(Queue* pq);
//���
void QueuePush(Queue* pq, QDataType x);
//����
void QueuePop(Queue* pq);
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);
//���ʶ�ͷ��ֵ
QDataType QueueFront(Queue* pq);
//���ʶ�β��ֵ
QDataType QueueBack(Queue* pq);
//���ٶ���
void QueueDestroy(Queue* pq);





