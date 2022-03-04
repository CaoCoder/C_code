#define _CRT_SECURE_NO_WARNINGS

#include "SeqList.h"
int main()
{
	SL s1;
	SeqListInit(&s1);
	//ͷ��������
	SeqListPushFront(&s1, 2);
	SeqListPushFront(&s1, 5);
	SeqListPrint(&s1);

	//β��3����
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 7);
	SeqListPushBack(&s1, 2);
	//��ӡ
	SeqListPrint(&s1);

	//ͷɾ
	SeqListPopFront(&s1);
	//��ӡ
	SeqListPrint(&s1);

	//βɾ
	SeqListPopBack(&s1);
	SeqListPrint(&s1);

	//����û��ĳ��ֵ
	SeqListFind(&s1, 3);
	SeqListFind(&s1, 5);

	//�޸�һ��λ���ϵ�ֵ
	SeqListChange(&s1, 2, 9);
	SeqListPrint(&s1);

	//ָ��λ��ǰ����һ��ֵ
	SeqListInsert(&s1, 1, 1);
	SeqListPrint(&s1);

	//ָ��λ��ɾ��
	SeqListDelete(&s1,2);
	SeqListPrint(&s1);

	//����˳���
	SeqListDestory(&s1);
	return 0;
}