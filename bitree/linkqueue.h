#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_
#include "bitree.h"
//队列的链式存储

typedef bitree_t datatype;//定义数据的类型，这里结点类型为二叉树指针

typedef struct node{
	datatype data;//结点的数据域
	struct node *next;//结点的指针域，指向下一个结点
}linknode,*linknode_t;

typedef struct {
	linknode_t front;//队头元素前面的指针
	linknode_t rear;//队尾指针
}linkqueue,*linkqueue_t;//定义链式队列

linkqueue_t linkqueue_create();
int linkqueue_is_empty(linkqueue_t lq);
int linkqueue_length(linkqueue_t lq);
int linkqueue_in(linkqueue_t lq,datatype value);
datatype linkqueue_out(linkqueue_t lq);
int linkqueue_clear(linkqueue_t lq);
int linkqueue_destroy(linkqueue_t lq);
int linkqueue_traverse(linkqueue_t lq);
#endif
