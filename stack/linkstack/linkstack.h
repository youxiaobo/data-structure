#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

//栈的链式存储

typedef int datatype;//定义数据的类型

typedef struct node{
	datatype data;//结点的数据域
	struct node *next;//结点的指针域，指向下一个结点
}linknode,*linknode_t;

linknode_t linkstack_create();
int linkstack_is_empty(linknode_t h);
int linkstack_length(linknode_t h);
int linkstack_push(linknode_t h,datatype value);
datatype linkstack_pop(linknode_t h);
datatype linkstack_top(linknode_t h);
int linkstack_clear(linknode_t h);
int linkstack_destroy(linknode_t h);
int linkstack_traverse(linknode_t h);
#endif
