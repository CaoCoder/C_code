#define _CRT_SECURE_NO_WARNINGS
#include "List.h"

int main()
{
	LN* plist = NULL;
	ListNodeInit(&plist);


	ListNodePushBack(plist, 1);
	ListNodePushBack(plist, 2);
	ListNodePushBack(plist, 3);
	ListNodePushBack(plist, 4);
	ListNodePushBack(plist, 5);
	ListNodePrint(plist);
	LN* pos = NULL;
	pos = ListNodeFind(plist, 5);
	ListNodeInsert(plist, pos, 6);
	pos = ListNodeFind(plist, 1);
	ListNodeInsert(plist, pos, 7);
	ListNodePrint(plist);

	pos = ListNodeFind(plist, 5);
	ListNodeInsertBack(plist, pos, 8);
	ListNodePrint(plist);

	pos = ListNodeFind(plist, 5);
	ListNodeInsertBack(plist, pos, 9);
	ListNodePrint(plist);


	pos = ListNodeFind(plist, 9);
	ListNodeErease(plist, pos);
	pos = ListNodeFind(plist, 8);
	ListNodeErease(plist, pos);
	pos = ListNodeFind(plist, 7);
	ListNodeErease(plist, pos);
	ListNodePrint(plist);
	pos = ListNodeFind(plist, 1);

	ListNodeErease(plist, pos);
	ListNodePrint(plist);

	pos = ListNodeFind(plist, 2);

	ListNodeErease(plist, pos);
	ListNodePrint(plist);

	ListNodePopBack(plist);
	ListNodePopBack(plist);
	ListNodePopBack(plist);
	ListNodePopBack(plist);
	ListNodePrint(plist);
	ListNodePushFront(plist, 1);
	ListNodePushFront(plist, 1);
	ListNodePushFront(plist, 1);
	ListNodePrint(plist);
	ListNodePopFront(plist);
	ListNodePrint(plist);
	ListNodePopFront(plist);
	ListNodePopFront(plist);
	ListNodePopFront(plist);

	ListNodePrint(plist);

	ListNodeDestroy(plist);

	return 0;
}