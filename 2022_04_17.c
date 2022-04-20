//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct BTNodeTree
//{
//	struct BTNodeTree* left;
//	struct BTNodeTree* right;
//	char val;
//}BTNode;
//BTNode* CreateTree(char* a, int n, int* pi)
//{
//	while (*pi < n)
//	{
//		if (a[*pi] == '#')
//		{
//			(*pi)++;
//			return NULL;
//		}
//		BTNode* node = (BTNode*)malloc(sizeof(BTNode));
//		node->val = a[(*pi)++];
//		node->left = CreateTree(a, n, pi);
//		node->right = CreateTree(a, n, pi);
//
//		return node;
//	}
//}
//void inorder(BTNode* root)
//{
//	if (root == NULL)
//		return;
//	inorder(root->left);
//	printf("%c ", root->val);
//
//	inorder(root->right);
//}
//int main()
//{
//	int a[100];
//	scanf("%s", a);
//	int i = 0;
//	int n = strlen(a);
//	BTNode* tree = CreateTree(a, n, &i);
//	inorder(tree);
//	return 0;
//}