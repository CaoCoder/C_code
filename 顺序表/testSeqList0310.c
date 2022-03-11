#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"
int main()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, -1);
	SeqListPrint(&s);


	SeqListInsert(&s, 2, 5);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListErease(&s, 2);
	SeqListPrint(&s);
	
	SeqListDestroy(&s);
	return 0;
}
