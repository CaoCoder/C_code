#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
	int data;
	struct ListNode* next;
};
struct ListNode* reverse(struct ListNode* head)
{
    struct ListNode* newhead;
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* next = cur->next;
    newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newhead == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    newhead->next = NULL;
    while (cur)
    {
        newhead->next = cur;
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    free(newhead);
    return newhead->next;
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
	reverse(node1);
	return 0;
}