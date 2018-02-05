#ifndef _BITREE_H_
#define _BITREE_H_

typedef char datatype_t;//注意因为使用了linkqueue.h 这里的类型不能和linkqueue.h里面重复了
typedef struct node_t{//注意因为使用了linkqueue.h 这里的类型不能和linkqueue.h里面重复了
	datatype_t data;
	struct node_t *lchild,*rchild;
}bitree,*bitree_t;


bitree_t bitree_create();
int bitree_traverse_preorder(bitree_t r);
int bitree_traverse_midorder(bitree_t r);
int bitree_traverse_postorder(bitree_t r);
int bitree_traverse_level(bitree_t r);
#endif
