#define _CRT_SECURE_NO_WARNINGS
/*·´×ªÁ´±í*/
#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
	int data;
	struct ListNode* next;
};
struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	struct ListNode* cur = head;
	struct ListNode* new = NULL;
	while (cur != NULL)
	{
		struct ListNode* next = cur->next;
		cur->next = new;
		new = cur;
		cur = next;
	}
	return new;
}
int main()
{
	struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;
	node5->data = 5;
	reverseList(node1);
	return 0;
}
