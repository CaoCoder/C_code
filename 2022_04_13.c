#define _CRT_SECURE_NO_WARNINGS
////
////#include <stdio.h>
////#include <stdlib.h>
////#include <assert.h>
////#include <stdbool.h>
////typedef int BTDataType;
////
////typedef struct BinaryTreeNode
////{
////	struct BinaryTreeNode* left;
////	struct BinaryTreeNode* right;
////	BTDataType data;
////}BTNode;
////
////BTNode* BuyBTNode(BTDataType x)
////{
////	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
////	if (node == NULL)
////	{
////		printf("malloc fail\n");
////		exit(-1);
////	}
////	node->data = x;
////	node->left = NULL;
////	node->right = NULL;
////	return node;
////}
////
////BTNode* CreatBinaryTree()
////{
////	BTNode* node1 = BuyBTNode(1);
////	BTNode* node2 = BuyBTNode(2);
////	BTNode* node3 = BuyBTNode(3);
////	BTNode* node4 = BuyBTNode(4);
////	BTNode* node5 = BuyBTNode(5);
////	BTNode* node6 = BuyBTNode(6);
////	node1->left = node2;
////	node1->right = node4;
////	node2->left = node3;
////	node4->left = node5;
////	node4->right = node6;
////
////	return node1;
////}
////
////// 二叉树节点个数
//////int BinaryTreeSize(BTNode* root)
//////{
//////	if (root == NULL)
//////	{
//////		return 0;
//////	}
//////	return BinaryTreeSize(root->left)
//////		+ BinaryTreeSize(root->right) + 1;
//////}
////// 二叉树叶子节点个数
//////int BinaryTreeLeafSize(BTNode* root)
//////{
//////	if (root == NULL)
//////	{
//////		return 0;
//////	}
//////	if (root->left == NULL && root->right == NULL)
//////	{
//////		return 1;
//////	}
//////	return BinaryTreeLeafSize(root->left) 
//////		+ BinaryTreeLeafSize(root->right);
//////}
////int main()
////{
////	BTNode* tree = CreatBinaryTree();
////	int size = BinaryTreeLeafSize(tree);
////	printf("%d ", size);
////	return 0;
////}
//#include<stdio.h>
//#include<stdlib.h>
//struct TreeNode
//{
//	struct TreeNode* left;
//	struct TreeNode* right;
//	char val;
//};
//
//struct TreeNode* CreateTree(char* str, int* pi)
//{
//	if (str[*pi] == '#')
//	{
//		(*pi)++;
//		return NULL;
//	}
//
//	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//	root->val = str[(*pi)++];
//	root->left = CreateTree(str, pi);
//	root->right = CreateTree(str, pi);
//
//	return root;
//}
//
//void InOrder(struct TreeNode* root)
//{
//	if (root == NULL)
//		return;
//
//	InOrder(root->left);
//	printf("%c ", root->val);
//	InOrder(root->right);
//}
//
//int main()
//{
//	char str[100];
//	scanf("%s", str);
//	int i = 0;
//	struct TreeNode* root = CreateTree(str, &i);
//	InOrder(root);
//
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct tree {
    struct tree* lchild, * rchild;
    char date;
} tree, * ntree;
char ch[100];
int i = 0;
int creat(ntree p) {
    while (i <= strlen(ch)) {
        if (p->date == '#') return 0;
        else
        {
            p->date = ch[i];
            creat(p->lchild);
            creat(p->rchild);
        }
        i++;
        p = (ntree)malloc(sizeof(tree));
    }
}
int main() {
    gets(ch);
    ntree p, head;
    p = head = (ntree)malloc(sizeof(tree));
    if (p) {
        printf("初始化成功");
        creat(p);
    }
}

