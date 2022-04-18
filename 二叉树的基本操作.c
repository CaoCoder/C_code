#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int BTDataType;
//����������ṹ��
typedef struct BinaryTreeNode
{
	int data;//�ڵ�����
	struct BinartTreeNode* left;//������
	struct BinartTreeNode* right;//������

}BTNode;
//����һ�ö�����
BTNode* BuyBTNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyBTNode(1);
	BTNode* node2 = BuyBTNode(2);
	BTNode* node3 = BuyBTNode(3);
	BTNode* node4 = BuyBTNode(4);
	BTNode* node5 = BuyBTNode(5);
	BTNode* node6 = BuyBTNode(6);
	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;

	return node1;
}
// ������ǰ�����
void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	//����Ϊ��ʱ
	if (root == NULL)
		return 0;
	//������Ϊ��ʱ
	return BinaryTreeSize(root->left) +
		BinaryTreeSize(root->right) + 1;
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	//����Ϊ��ʱ
	if (root == NULL)
		return 0;
	//������ �� ����Ϊ��ʱ
	if (root->left == NULL && root->right == NULL)
		return 1;
	/*���򶼵���һ��, ��ζ���������㷵�ص������
	���Լ����ݹ� �������� ��������*/
	return BinaryTreeLeafSize(root->left)+
		BinaryTreeLeafSize(root->right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//����Ϊ��ʱ
	if (root == NULL)
		return 0;
	//��kΪ1ʱ
	if (k == 1)
		return 1;
	//�������ߵ���һ�У�˵������Ϊ�գ�kҲ��Ϊ1.�����ݹ�
	return BinaryTreeLevelKSize(root->left, k-1)+
	BinaryTreeLevelKSize(root->right, k - 1);
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	//����Ϊ��ʱ
	if (root == NULL)
		return NULL;
	//������ֵ����xʱ
	if (root->data == x)
		return root;
	/*�ߵ���һ�У�˵������������������
	��ʼ�ݹ���������������ҵ��ˣ�ֱ��һ��һ�����ط�*/
	BTNode* a = BinaryTreeFind(root->left, x);
	if (a)
	{
		return a;
	}
	BTNode* b = BinaryTreeFind(root->right, x);
	if (b)
	{
		return b;
	}
	//û��x���򷵻ؿ�
	return NULL;
}
// ����������
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}
// �������
//void LevelOrder(BTNode* root)
//{
//	//��ʼ�����У�ע������������� ָ�����͡�
//	Queue q;
//	QueueInit(&q);
//	//�������Ϊ�տ�ʼ���
//	if (root)
//	{
//		QueuePush(&q, root);
//	}
//	//����Ϊ�տ�ʼ����ͷ���ݣ�ͬʱ�������������������ֱ������Ϊ�ա�
//	while (!QueueEmpty(&q))
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//
//		printf("%d ", front->data);
//		//�����������������������ӣ��������
//		if (front->left)
//		{
//			QueuePush(&q, front->left);
//		}
//		if (front->right)
//		{
//			QueuePush(&q, front->right);
//		}
//	}
//	//�ǵ����ٶ���
//	printf("\n");
//	QueueDestory(&q);
//}
//�ж϶������Ƿ�����ȫ������
//bool BTreeComplete(BTNode* root)
//{
//	Queue q;
//	QueueInit(&q);
//
//	if (root)
//		QueuePush(&q, root);
//
//	while (!QueueEmpty(&q))
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//		if (front == NULL)
//			break;
//		QueuePush(&q, front->left);
//		QueuePush(&q, front->right);
//	}
//	while (!QueueEmpty(&q))
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//		//�պ�������ǿգ���˵��������ȫ������
//		if (front)
//			return false;
//	}
//	//��������ȫ������
//	return true;
//}
void swap(BTNode* q, BTNode* p)
{
	if (q == NULL || p == NULL)
	{
		free()
	}
	else
	{
		int t = 0;
		t = q->data;
		q->data = p->data;
		p->data = t;
	}
}
 BTNode* TreeSwap(BTNode* q, BTNode* p)
{
	 swap(q, p);
	if (q->left == NULL && p->right == NULL)
		return;
	TreeSwap(q->left, p->right);
	TreeSwap(q->right, p->left);
}
BTNode* invertTree(BTNode* root)
{
	if (root == NULL)
		return NULL;
	if (root->right == NULL && root->left == NULL)
		return root;

	TreeSwap(root, root);

	return root;
}
int main()
{
	BTNode* root = CreatBinaryTree();
	//// ������ǰ�����
	//PreOrder(root);
	//// �������������
	//InOrder(root);
	//// �������������
	//PostOrder(root);
	// �������ڵ����
	invertTree(root);
	
	return 0;
}