#define _CRT_SECURE_NO_WARNINGS
//LeetCode��ָoffer�ҵ���
//#include<stdio.h>
//#include<stdlib.h>
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//void singleNumbers(int* nums, int numsSize) 
//{
//	int num = 0;
//	for (int i = 0; i < numsSize; i++)
//	{
//		num = num ^ nums[i];
//	}
//	int k = 1;
//	while ((num & k) == 0)
//	{
//		k = k << 1;
//	}
//
//	int j = 0;
//	int* a = (int*)malloc(sizeof(int) * 2);
//	if (a == NULL)
//	{
//		return;
//	}
//	a[0] = 0;
//	a[1] = 0;
//	for (j = 0; j < numsSize; j++)
//	{
//		if ((k & nums[j]) == 0)
//		{
//			a[0] = a[0] ^ nums[j];
//		}
//		else
//		{
//			a[1] = a[1] ^ nums[j];
//		}
//	}
//	printf("%d %d", a[0], a[1]);
//}
//
//int main()
//{
//	int nums[] = {1,2,5,2};
//	int sz = sizeof(nums) / sizeof(nums[0]);
//	singleNumbers(nums, sz);
//	return 0;
//}
//LeetCode   203. �Ƴ�����Ԫ��
//#include<stdio.h>
//#include<stdlib.h>
//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//};
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* prev = NULL;
//	struct ListNode* cur = head;
//	while (cur)
//	{
//		if (cur->val != val)
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//		else
//		{
//			if (prev == NULL)
//			{
//				struct ListNode* n = cur->next;
//				free(cur);
//				cur = n;
//				head = n;
//			}
//			else
//			{
//				prev->next = cur->next;
//				free(cur);
//				cur= NULL;
//				cur = prev->next;
//			}
//		}
//	}
//	return head;
//}
//int main()
//{
//	struct ListNode* node1 = malloc(sizeof(struct ListNode));
//	struct ListNode* node2 = malloc(sizeof(struct ListNode));
//	struct ListNode* node3 = malloc(sizeof(struct ListNode));
//	struct ListNode* node4 = malloc(sizeof(struct ListNode));
//	struct ListNode* node5 = malloc(sizeof(struct ListNode));
//	struct ListNode* node6 = malloc(sizeof(struct ListNode));
//	struct ListNode* node7 = malloc(sizeof(struct ListNode));
//
//	node1->val = 6;
//	node2->val = 6;
//	node3->val = 6;
//	node4->val = 3;
//	node5->val = 4;
//	node6->val = 5;
//	node7->val = 6;
//
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = node5;
//	node5->next = node6;
//	node6->next = node7;
//	node7->next = NULL;
//	struct ListNode* p = removeElements(node1, 6);
//	return 0;
//}
//206. ��ת����
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//#include<stdio.h>
//#include<stdlib.h>
//struct ListNode
//{
//	int val;
//	struct ListNode* next;
//};
//struct ListNode* reverseList(struct ListNode* head)
//{
//    if (head == NULL || head->next == NULL)
//    {
//        return head;
//    }
//    struct ListNode* n1, * n2, * n3;
//    n1 = head;
//    n2 = n1->next;
//    n3 = n2->next;
//    n1->next = NULL;
//    //�м�ڵ㲻Ϊ�գ������޸�ָ��
//    while (n2)
//    {
//        //�м�ڵ�ָ��ת
//        n2->next = n1;
//        //�������������Ľڵ�
//        n1 = n2;
//        n2 = n3;
//        if (n3)
//        {
//            n3 = n3->next;
//        }
//    }
//    //�����µ�ͷ
//    return n1;
//}
//int main()
//{
//	struct ListNode* node1 = (struct LsitNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* node2 = (struct LsitNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* node3 = (struct LsitNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* node4 = (struct LsitNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* node5 = (struct LsitNode*)malloc(sizeof(struct ListNode));
//
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = NULL;
//
//	node1->val = 1;
//	node2->val = 2;
//	node3->val = 3;
//
//
//	struct ListNode* p = reverseList(node1);
//
//	return 0;
//}
