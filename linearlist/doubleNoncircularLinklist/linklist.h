#ifndef _LINKLIST_H_
#define _LINKLIST_H_

//线性表的链式存储
//双向不循环链表
//和单向不循环链表的区别：创建时要多一个指针
//插入要操作4个指针
//删除要操作2个指针
//查询/访问可以向前，也可以向后

typedef int datatype;//定义数据的类型

typedef struct node{
	datatype data;//结点的数据域
	struct node *next,*prior;//结点的指针域，指向后继和前趋
}linknode,*linknode_t;

linknode_t linklist_create();
int linklist_is_empty(linknode_t h);
int linklist_length(linknode_t h);
int linklist_insert(linknode_t h,datatype value);
int linklist_delete(linknode_t h);
int linklist_traverse(linknode_t h);
int linklist_insert_by_pos(linknode_t h,datatype value,int pos);
int linklist_delete_by_pos(linknode_t h,int pos);
#endif
