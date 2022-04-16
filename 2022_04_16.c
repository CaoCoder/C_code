#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;

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
// 二叉树第k层节点个数
//int BinaryTreeLevelKSize(BTNode* root, int k)
//{
//	assert(k >= 1);
//	if (root == NULL)
//	{
//		return 0;
//	}
//	if (k == 1)
//	{
//		return 1;
//	}
//	return BinaryTreeLevelKSize(root->left, k - 1) +
//		BinaryTreeLevelKSize(root->right, k - 1);
//}
// 二叉树查找值为x的节点
//BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
//{
//	//如果root为空,则返回
//	if (root == NULL)
//		return NULL;
//	if (root->data == x)
//		return root;
//	BTNode* ret1 = BinaryTreeFind(root->left, x);
//	if (ret1)
//		return ret1;
//
//	BTNode* ret2 = BinaryTreeFind(root->right, x);
//	if (ret2)
//		return ret2;
//	return NULL;
//}
//求树的高度
//int BTreeDepth(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	int leftdepth = BTreeDepth(root->left);
//	int rightdepth = BTreeDepth(root->right);
//
//	return leftdepth > rightdepth ? 
//		leftdepth + 1 : rightdepth + 1;
//
//}
//二叉树前序遍历
//void prevtree(BTNode* root)
//{
//	if (root == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//	printf("%d ", root->data);
//	prevtree(root->left);
//	prevtree(root->right);
//}
// 二叉树销毁
//void BinaryTreeDestory(BTNode* root)
//{
//	if (root == NULL)
//		return;
//	BinaryTreeDestory(root->left);
//	BinaryTreeDestory(root->right);
//	free(root);
//}
int main()
{
	BTNode* tree = CreatBinaryTree();
	
	return 0;
}
