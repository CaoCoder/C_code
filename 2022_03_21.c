#define _CRT_SECURE_NO_WARNINGS
/*�Ƴ�Ԫ��*/
//int removeElement(int* nums, int numsSize, int val)
//{
//	int* fast = nums;
//	int* slow = nums;
//	while (fast != nums + numsSize)
//	{
//		if (*fast != val)
//		{
//			*slow = *fast;
//			slow++;
//			fast++;
//		}
//		else
//		{
//			fast++;
//		}
//	}
//	return slow;
//}
//#include<stdio.h>
//int main()
//{
//	int nums[] = { 3,2,2,3 };
//	int sz = sizeof(nums) / sizeof(nums[0]);
//	removeElement(nums, sz, 3);
//	return 0;
//}
/*26. ɾ�����������е��ظ���*/
//int removeDuplicates(int* nums, int numsSize)
//{
//	int* slow = nums;
//	int* fast = nums + 1;
//	while (fast < nums + numsSize)
//	{
//		if (*slow == *fast)
//		{
//			fast++;
//		}
//		else
//		{
//			slow++;
//			*slow = *fast;
//			fast++;
//		}
//	}
//	return slow+ 1 -nums;
//}
//#include<stdio.h>
//int main()
//{
//	int nums[] = {1,1,2};
//	int sz = sizeof(nums) / sizeof(nums[0]);
//	removeDuplicates(nums, sz);
//	return 0;
//}
/*��ת����*/
//struct ListNode* reverseList(struct ListNode* head)
//{
//	if (head == NULL)
//	{
//		return;
//	}
//	struct ListNode* n1 = NULL;
//	struct ListNode* n2 = head;
//	struct ListNode* n3 = head->next;
//	while (n2)
//	{
//		n2->next = n1;
//		n1 = n2;
//		n2 = n3;
//		if(n3 != NULL)
//		{
//			n3 = n3->next;
//		}
//	}
//	return n1;
//}
/*�������е�n���ڵ�*/
//struct ListNode* middleNode(struct ListNode* head)
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
//	}
//	return slow;
//}

