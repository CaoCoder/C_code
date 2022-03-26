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

//初始化
void QueueInit(Queue* pq);
//入队
void QueuePush(Queue* pq, QDataType x);
//出队
void QueuePop(Queue* pq);
//判断队列是否为空
bool QueueEmpty(Queue* pq);
//访问队头的值
QDataType QueueFront(Queue* pq);
//访问队尾的值
QDataType QueueBack(Queue* pq);
//销毁队列
void QueueDestroy(Queue* pq);





