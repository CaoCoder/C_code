#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

int main()
{
	SListNode* plist = NULL;
	SListNodePushBack(&plist, 1);
	SListNodePushBack(&plist, 2);
	SListNodePushBack(&plist, 3);
	SListNodePushBack(&plist, 4);
	SListNodePushBack(&plist, 1);
	SListNodePushFront(&plist, 0);
	SListNodePushFront(&plist, -1);

	SListNodePopBack(&plist);
	SListNodePopBack(&plist);
	SListNodePopBack(&plist);
	SListNodePopBack(&plist);
	SListNodePopBack(&plist);
	SListNodePopBack(&plist);
	SListNodePopBack(&plist);
	SListNodePopBack(&plist);
	SListNodePopBack(&plist);
	SListNodePushFront(&plist, 0);
	SListNodePushFront(&plist, -1);

	SListNode* pos = SListNodeFind(&plist, 0);
	SListInsert(&plist, pos, 6);

	SListNodePrint(&plist);
	SListNodeDestory(&plist);
	SListNodePrint(&plist);
	return 0;
}

