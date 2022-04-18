#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int BTDataType;
//定义二叉树结构体
typedef struct BinaryTreeNode
{
	int data;//节点数据
	struct BinartTreeNode* left;//左子树
	struct BinartTreeNode* right;//右子树

}BTNode;
//构造一棵二叉树
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
// 二叉树前序遍历
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
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	//当树为空时
	if (root == NULL)
		return 0;
	//当树不为空时
	return BinaryTreeSize(root->left) +
		BinaryTreeSize(root->right) + 1;
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	//当树为空时
	if (root == NULL)
		return 0;
	//当两棵 子 树都为空时
	if (root->left == NULL && root->right == NULL)
		return 1;
	/*程序都到这一行, 意味着树不满足返回的情况，
	所以继续递归 左子树和 右子树。*/
	return BinaryTreeLeafSize(root->left)+
		BinaryTreeLeafSize(root->right);
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//当树为空时
	if (root == NULL)
		return 0;
	//当k为1时
	if (k == 1)
		return 1;
	//程序能走到这一行，说明树不为空，k也不为1.继续递归
	return BinaryTreeLevelKSize(root->left, k-1)+
	BinaryTreeLevelKSize(root->right, k - 1);
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	//当树为空时
	if (root == NULL)
		return NULL;
	//当树的值等于x时
	if (root->data == x)
		return root;
	/*走到这一行，说明不满足以上条件。
	开始递归左右子树，如果找到了，直接一步一步往回返*/
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
	//没有x，则返回空
	return NULL;
}
// 二叉树销毁
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}
// 层序遍历
//void LevelOrder(BTNode* root)
//{
//	//初始化队列，注意队列里面存的是 指针类型。
//	Queue q;
//	QueueInit(&q);
//	//如果树不为空开始入队
//	if (root)
//	{
//		QueuePush(&q, root);
//	}
//	//树不为空开始出对头数据，同时入队左子树和右子树，直到队列为空。
//	while (!QueueEmpty(&q))
//	{
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//
//		printf("%d ", front->data);
//		//如果还有左右子树，继续入队，否则不入队
//		if (front->left)
//		{
//			QueuePush(&q, front->left);
//		}
//		if (front->right)
//		{
//			QueuePush(&q, front->right);
//		}
//	}
//	//记得销毁队列
//	printf("\n");
//	QueueDestory(&q);
//}
//判断二叉树是否是完全二叉树
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
//		//空后面出到非空，那说明不是完全二叉树
//		if (front)
//			return false;
//	}
//	//否则是完全二叉树
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
	//// 二叉树前序遍历
	//PreOrder(root);
	//// 二叉树中序遍历
	//InOrder(root);
	//// 二叉树后序遍历
	//PostOrder(root);
	// 二叉树节点个数
	invertTree(root);
	
	return 0;
}