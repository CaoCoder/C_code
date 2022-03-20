#define _CRT_SECURE_NO_WARNINGS
/*LeetCode141. 环形链表*/
//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//struct ListNode
//{
//	int data;
//	struct ListNode* next;
//};
//struct ListNode* detectCycle(struct ListNode* head)
//{
//	if (head == NULL)
//	{
//		return NULL;
//	}
//	struct ListNode* slow = head;
//	struct ListNode* fast = head;
//	while (fast && fast->next)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//		if (slow == fast)
//		{
//			return true;
//		}
//	}
//	return false;
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
/*LeetCode.环形链表找入口点*/
//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//struct ListNode
//{
//	int data;
//	struct ListNode* next;
//};
//struct ListNode* detectCycle(struct ListNode* head)
//{
//	if (head == NULL)
//	{
//		return NULL;
//	}
//	struct ListNode* slow = head;
//	struct ListNode* fast = head;
//	while (fast && fast->next)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//		if (slow == fast)
//		{
//			while (slow != head)
//			{
//				slow = slow->next;
//				head = head->next;
//			}
//			return head;
//		}
//	}
//	return NULL;
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
/*牛客分割链表*/
//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//struct ListNode
//{
//	int data;
//	struct ListNode* next;
//};
//struct ListNode* partition(struct ListNode* pHead, int x)
//{
//	struct ListNode* n1 = NULL;
//	struct ListNode* n2 = NULL;
//	struct ListNode* cur = pHead;
//	struct ListNode* head2 = NULL;
//	struct ListNode* head1 = NULL;
//	//分割为两个链表。
//	while (cur)
//	{
//		if (cur->data < x)
//		{
//			if (n1 == NULL)
//			{
//				head1 = cur;
//				n1 = cur;
//				cur = cur->next;
//			}
//			else
//			{
//
//				n1->next = cur;
//				cur = cur->next;
//				n1 = n1->next;
//			}
//		}
//		else
//		{
//			if (n2 == NULL)
//			{
//				head2 = cur;
//				n2 = cur;
//				cur = cur->next;
//			}
//			else
//			{
//				n2->next = cur;
//				cur = cur->next;
//				n2 = n2->next;
//			}
//		}
//	}
//	//连接两个链表。
//	if (n1)
//	{
//		n1->next = head2;
//		if (n2)
//		{
//			n2->next = NULL;
//		}
//		return head1;
//	}
//	else
//	{
//		return head2;
//	}
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
//	node2->data = 5;
//	node3->data = 3;
//	node4->data = 2;
//	node5->data = 4;
//	partition(node1, 3);
//	return 0;
//}
