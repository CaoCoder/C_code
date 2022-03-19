#define _CRT_SECURE_NO_WARNINGS
/*反转链表*/
//#include<stdio.h>
//#include<stdlib.h>
//struct ListNode
//{
//	int data;
//	struct ListNode* next;
//};
//struct ListNode* reverseList(struct ListNode* head)
//{
//	if (head == NULL)
//	{
//		return NULL;
//	}
//	struct ListNode* cur = head;
//	struct ListNode* prev = NULL;
//	struct ListNode* next = cur->next;
//	while (cur)
//	{
//		cur->next = prev;
//		prev = cur;
//		cur = next;
//		if (cur)
//		{
//			next = cur->next;
//		}
//	}
//	return prev;
//}
//int main()
//{
//	struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = node5;
//	node5->next = NULL;
//	node1->data = 1;
//	node2->data = 2;
//	node3->data = 3;
//	node4->data = 4;
//	node5->data = 5;
//	reverseList(node1);
//	return 0;
//}
/*876.链表的中间结点*/
//#include<stdio.h>
//#include<stdlib.h>
//struct ListNode
//{
//	int data;
//	struct ListNode* next;
//};
//struct ListNode* middleNode(struct ListNode* head)
//{
//	if (head == NULL)
//	{
//		return NULL;
//	}
//	struct ListNode* slow = head;
//	struct ListNode* fast = head;
//	//必须先判断fast不为空，才能继续判断fast->next,
//	//否则会出现/*NULL -> NULL*/出现报错。
//	while (fast != NULL&& fast->next != NULL)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//	return slow;
//}
//int main()
//{
//	struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = node5;
//	node5->next = NULL;
//	node1->data = 1;
//	node2->data = 2;
//	node3->data = 3;
//	node4->data = 4;
//	node5->data = 5;
//	middleNode(node1);
//	return 0;
//}
/*牛客 链表倒数第k个节点*/
//#include<stdio.h>
//#include<stdlib.h>
//struct ListNode
//{
//	int data;
//	struct ListNode* next;
//};
//struct ListNode* FindKthToTail(struct ListNode* pListHead, unsigned int k)
//{
//	struct ListNode* pHead = pListHead;
//	int n = 0;
//	while (pHead)
//	{
//		pHead = pHead->next;
//		n++;
//	}
//	if (k > n)
//	{
//		return NULL;
//	}
//	if (pListHead == NULL)
//	{
//		return NULL;
//	}
//	struct ListNode* slow = pListHead;
//	struct ListNode* fast = pListHead;
//	while (k)
//	{
//		fast = fast->next;
//		k--;
//	}
//	while (fast)
//	{
//		slow = slow->next;
//		fast = fast->next;
//	}
//	return slow;
//}
//int main()
//{
//	struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = node5;
//	node5->next = NULL;
//	node1->data = 1;
//	node2->data = 2;
//	node3->data = 3;
//	node4->data = 4;
//	node5->data = 5;
//	FindKthToTail(node1, 1);
//	return 0;
//}
/*	LeetCode21.合并两个有序链表*/
//#include<stdio.h>
//#include<stdlib.h>
//struct ListNode
//{
//	int data;
//	struct ListNode* next;
//};
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
//{
//	if (list1 == NULL)
//	{
//		return list2;
//	}
//	if (list2 == NULL)
//	{
//		return list1;
//	}
//	struct ListNode* n1 = list1;
//	struct ListNode* n2 = list2;
//	struct ListNode* head = NULL;
//	struct ListNode* prev = NULL;
//	while (n1 && n2)
//	{
//		if (n1->data <= n2->data)
//		{
//			if (head == NULL)
//			{
//				head = n1;
//				prev = n1;
//				n1 = n1->next;
//			}
//			else
//			{
//				prev->next= n1;
//				prev = n1;
//				n1 = n1->next;
//			}
//		}
//		else
//		{
//			if (head == NULL)
//			{
//				head = n2;
//				prev = n2;
//				n2 = n2->next;
//			}
//			else
//			{
//				prev->next= n2;
//				prev= n2;
//				n2 = n2->next;
//			}
//		}
//	}
//	if (n1 == NULL)
//	{
//		prev->next = n2;
//	}
//	if (n2 == NULL)
//	{
//		prev->next= n1;
//	}
//	return head;
//}
//int main()
//{
//	struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* node6 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = NULL;
//	node4->next = node5;
//	node5->next = node6;
//	node6->next = NULL;
//
//	node1->data = 1;
//	node2->data = 2;
//	node3->data = 4;
//	node4->data = 1;
//	node5->data = 3;
//	node6->data = 4;
//
//	mergeTwoLists(node1, node4);
//	return 0;
//}

/*OR36 链表的回文结构*/
//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//struct ListNode
//{
//	int data;
//	struct ListNode* next;
//};
//bool chkPalindrome(struct ListNode* A) 
//{
//	//找出中间节点时间复杂度O（0.5n）
//	struct ListNode* slow = A;
//	struct ListNode* fast = A;
//	while (fast && fast->next)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//	//反转中间节点后面的链表(o0.5n)
//	struct ListNode* cur = slow;
//	struct ListNode* prev = NULL;
//	struct ListNode* next = NULL;
//	while (cur)
//	{
//		next = cur->next;
//		cur->next = prev;
//		prev = cur;
//		cur = next;
//	}
//	//比较两个链表的data值是否相等。o(0.5n)
//	while (prev)
//	{
//		if (prev->data == A->data)
//		{
//			prev = prev->next;
//			A = A->next;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	return true;
//}
//int main()
//{
//	struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	if (node1 == NULL)
//	{
//		return;
//	}
//	struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	if (node2 == NULL)
//	{
//		return;
//	}
//	struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	if (node3 == NULL)
//	{
//		return;
//	}
//	struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	if (node4 == NULL)
//	{
//		return;
//	}
//	struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	if (node5 == NULL)
//	{
//		return;
//	}
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = node5;
//	node5->next = NULL;
//	node1->data = 1;
//	node2->data = 2;
//	node3->data = 3;
//	node4->data = 4;
//	node5->data = 5;
//	reverseList(node1);
//	return 0;
//}
/*160. 相交链表*/
//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//struct ListNode
//{
//	int data;
//	struct ListNode* next;
//};
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
//{
//	if (headA == NULL || headB == NULL)
//	{
//		return NULL;
//	}
//	//判断两个链表是否相交，并计算链表的长度。O(2n)
//	struct ListNode* n1 = headA;
//	struct ListNode* n2 = headB;
//	int a = 1;
//	int b = 1;
//	while (n1->next)
//	{
//		n1 = n1->next;
//		a++;
//	}
//	while (n2->next)
//	{
//		n2 = n2->next;
//		b++;
//	}
//	if (n1 != n2)
//	{
//		return NULL;
//	}
//	//算出两个链表的长度之差，使从同一个地方开始走。
//	struct ListNode* a1 = headA;
//	struct ListNode* a2 = headB;
//	int k = 0;
//	if (b > a)
//	{
//		k = b - a;
//		while (k)
//		{
//			a2 = a2->next;
//			k--;
//		}
//	}
//	else
//	{
//		k = a - b;
//		while (k)
//		{
//			a1 = a1->next;
//			k--;
//		}
//	}
//	//找到第一个节点相同的位置。O(n)
//	while (a1 != a2)
//	{
//		a1 = a1->next;
//		a2 = a2->next;
//	}
//	return a1;
//}
//int main()
//{
//	struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	if (node1 == NULL)
//	{
//		return;
//	}
//	struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	if (node2 == NULL)
//	{
//		return;
//	}
//	struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	if (node3 == NULL)
//	{
//		return;
//	}
//	struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	if (node4 == NULL)
//	{
//		return;
//	}
//	struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	if (node5 == NULL)
//	{
//		return;
//	}
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = node5;
//	node5->next = NULL;
//	node1->data = 1;
//	node2->data = 2;
//	node3->data = 3;
//	node4->data = 4;
//	node5->data = 5;
//	reverseList(node1);
//	return 0;
//}
/**/