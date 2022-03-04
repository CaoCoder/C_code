#define _CRT_SECURE_NO_WARNINGS

#include "SeqList.h"
int main()
{
	SL s1;
	SeqListInit(&s1);
	//头插两个数
	SeqListPushFront(&s1, 2);
	SeqListPushFront(&s1, 5);
	SeqListPrint(&s1);

	//尾插3个数
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 7);
	SeqListPushBack(&s1, 2);
	//打印
	SeqListPrint(&s1);

	//头删
	SeqListPopFront(&s1);
	//打印
	SeqListPrint(&s1);

	//尾删
	SeqListPopBack(&s1);
	SeqListPrint(&s1);

	//查有没有某个值
	SeqListFind(&s1, 3);
	SeqListFind(&s1, 5);

	//修改一个位置上的值
	SeqListChange(&s1, 2, 9);
	SeqListPrint(&s1);

	//指定位置前插入一个值
	SeqListInsert(&s1, 1, 1);
	SeqListPrint(&s1);

	//指定位置删除
	SeqListDelete(&s1,2);
	SeqListPrint(&s1);

	//销毁顺序表
	SeqListDestory(&s1);
	return 0;
}