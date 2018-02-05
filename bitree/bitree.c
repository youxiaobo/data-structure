#include <stdio.h>
#include <stdlib.h>
#include "bitree.h"
#include "debug.h"
#include "linkqueue.h"
/*
 * 生成二叉树
 * 这里输入字符序列是按照先序输入
 * 根左右
 * */
bitree_t bitree_create()
{
	datatype_t ch;
	scanf("%c",&ch);//这里有输入的缓冲机制，必须要输入正确个数，递归才会结束
	if(ch == '#') //这里认为输入#表示该位置没有数据
	{
		return NULL;
	}

	bitree_t root = NULL;
	root = (bitree_t)malloc(sizeof(bitree));
	if(root == NULL)
	{
		DEBUG_CUSTOMERR("malloc error");
		return NULL;
	}
	root->data = ch;//填充数据
	root->lchild = bitree_create();//递归生成左子树,这里左右孩子是struct node*类型，也是bitree_t类型，所以可以作为bitree_create的返回值
	root->rchild = bitree_create();//递归生成右子树
	return root;

}
/*
 * 先序遍历
 * */
int bitree_traverse_preorder(bitree_t r)
{
	if(r == NULL)
	{
		return -1;
	}
		
	printf("%c",r->data);//根
	bitree_traverse_preorder(r->lchild);//左
	bitree_traverse_preorder(r->rchild);//右
	return 0;

}

/*
 * 中序遍历
 * */
int bitree_traverse_midorder(bitree_t r)
{
	if(r == NULL)
	{
		return -1;
	}
		
	bitree_traverse_midorder(r->lchild);//左
	printf("%c",r->data);//根
	bitree_traverse_midorder(r->rchild);//右
	return 0;

}

/*
 * 后序遍历
 * */
int bitree_traverse_postorder(bitree_t r)
{
	if(r == NULL)
	{
		return -1;
	}
		
	bitree_traverse_postorder(r->lchild);//左
	bitree_traverse_postorder(r->rchild);//右
	printf("%c",r->data);//根
	return 0;

}

/*
 * 层次遍历
 * 利用链式队列
 * 入队出队的数据类型是bitree_t,是指针
 *
 * */
int bitree_traverse_level(bitree_t r)
{
	if(r == NULL)
	{
		return -1;
	}

	//创建队列
	linkqueue_t lq =  NULL;
	lq = linkqueue_create();
	if(lq == NULL)
	{
		DEBUG_CUSTOMERR("malloc error");
		return -1;
	}

	
	//根结点入队
	linkqueue_in(lq,r);

	//队列的结点类型
	datatype bitreeP;

	//队列不为空
	while(!linkqueue_is_empty(lq))
	{
		//出队，得到二叉树的结点指针，这一步是关键！
	    bitreeP = linkqueue_out(lq);
		//出队时访问
		printf("%c",bitreeP->data);


		//出队元素的左孩子如果存在，则入队
		if(bitreeP->lchild != NULL)
		{
			linkqueue_in(lq,bitreeP->lchild);
		}

		//出队元素的右孩子如果存在，则入队
		if(bitreeP->rchild != NULL)
		{
			linkqueue_in(lq,bitreeP->rchild);
		}
	}
	return 0;
}
