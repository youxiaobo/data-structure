#ifndef _LINKLIST_H_
#define _LINKLIST_H_

//线性表的链式存储

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
int linklist_modify(linknode_t h,datatype oldVaule,datatype newValue);
int linklist_clear(linknode_t h);
int linklist_destroy(linknode_t h);
int linklist_traverse(linknode_t h);
int linklist_insert_by_pos(linknode_t h,datatype value,int pos);
int linklist_delete_by_value(linknode_t h,datatype value);
#endif
