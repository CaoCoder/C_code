#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int val;
	struct Node* next;
	struct Node* random;
};
//struct ListNode* BuynewNode(int x)
//{
//	struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
//	if (newNode == NULL)
//	{
//		printf("malloc fail");
//		exit(-1);
//	}
//	newNode->next = NULL;
//	newNode->random = NULL;
//	newNode->val = x;
//	return newNode;
//}
//struct ListNode* copyRandomList(struct ListNode* head)
//{
//	struct ListNode* cur = head;
//	struct ListNode* newNode = NULL;
//	//顺藤摸瓜迭代链接。
//	while (cur)
//	{
//		newNode = BuynewNode(cur->val);
//		struct ListNode* next = cur->next;
//		cur->next = newNode;
//		newNode->next = next;
//		if (cur->random == NULL)
//		{
//			newNode->random = NULL;
//		}
//		else
//		{
//			newNode->random = cur->random->next;
//		}
//		cur = next;
//	}
//	//断开链接。
//
//
//}
struct Node* copyRandomList(struct Node* head)
{
	struct Node* cur = head;
	if (cur == NULL)
	{
		return;
	}
	//1.拷贝节点连接在原节点后面
	while (cur)
	{
		struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
		if (copy == NULL)
		{
			
			exit(-1);
		}
		copy->val = cur->val;

		copy->next = cur->next;
		cur->next = copy;

		cur = cur->next->next;
	}
	//2.更新拷贝节点的random
	cur = head;
	while (cur)
	{
		struct Node* copy = cur->next;
		if (cur->random == NULL)
		{
			copy->random = NULL;
		}
		else
		{
			copy->random = cur->random->next;
		}
		cur = copy->next;
	}
	//3.拷贝节点解下来，连接到一起
	cur = head;

	struct Node* copyhead = cur->next;
	while (cur)
	{
		struct Node* copy = cur->next;
		struct Node* next = copy->next;
		if (next == NULL)
		{
			copy->next = NULL;
		}
		else
		{
			copy->next = next->next;
		}
		cur = next;
	}
	return copyhead;
}

int main()
{
	struct Node* node1 = malloc(sizeof(struct Node));
	if (node1 == NULL)
	{
		printf("fail");
		return;
	}
	struct Node* node2 = malloc(sizeof(struct Node));
	if (node2 == NULL)
	{
		printf("fail");
		return;
	}
	struct Node* node3 = malloc(sizeof(struct Node));
	if (node3 == NULL)
	{
		printf("fail");
		return;
	}
	struct Node* node4 = malloc(sizeof(struct Node));
	if (node4 == NULL)
	{
		printf("fail");
		return;
	}
	struct Node* node5 = malloc(sizeof(struct Node));
	if (node5 == NULL)
	{
		printf("fail");
		return;
	}

	node1->val = 7;
	node2->val = 13;
	node3->val = 11;
	node4->val = 10;
	node5->val = 1;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next =NULL;

	node1->random = NULL;
	node2->random = node1;
	node3->random = node5;
	node4->random = node3;
	node5->random = node1;


	struct Node* p = copyRandomList(node1);
	return 0;
}