#ifndef _LINKLIST_H_
#define _LINKLIST_H_

//线性表的链式存储
//单向循环链表
//和单向不循环链表的区别：创建时，h->nxet不是NULL而是h本身
//判断链表是否到达表尾，是p->next==h
//插入删除不变
//查询/访问时，可以不从头指针开始，可以定义一个尾指针，从尾指针开始

typedef int datatype;//定义数据的类型

typedef struct node{
	datatype data;//结点的数据域
	struct node *next;//结点的指针域，指向下一个结点
}linknode,*linknode_t;

linknode_t linklist_create();
int linklist_is_empty(linknode_t h);
int linklist_length(linknode_t h);
int linklist_insert(linknode_t h,datatype value);
int linklist_delete(linknode_t h);
int linklist_query(linknode_t h,datatype value);
int linklist_traverse(linknode_t h);
linknode_t linklist_rearP(linknode_t h);
int linklist_union(linknode_t a_r,linknode_t b_r);
#endif
