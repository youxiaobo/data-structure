#include <stdio.h>
#include "bitree.h"
#include "debug.h"
//测试用例
//ABC##DE#G##F###
int main(int argc, const char *argv[])
{

	//生成二叉树
	bitree_t root = NULL;
	root = bitree_create();
	if(root == NULL)
	{
		DEBUG_CUSTOMERR("malloc error");
		return -1;
	}

	//前序遍历
	printf("preorder:");
	bitree_traverse_preorder(root);
	printf("\n");

	//中序遍历
	printf("midorder:");
	bitree_traverse_midorder(root);
	printf("\n");

	//后序遍历
	printf("postorder:");
	bitree_traverse_postorder(root);
	printf("\n");

	//层次遍历
	printf("level:");
	bitree_traverse_level(root);
	printf("\n");

	return 0;
}
