#ifndef _SEQLIST_H_
#define _SEQLIST_H_

//线性表的顺序存储

#define N 10 //定义表的最大长度
typedef int datatype; //定义数据的类型，可替换为其他

typedef struct{
	datatype data[N]; //线性表的存储空间，一维数组
	int last; //表尾下标
}seqlist,*seqlist_t;

seqlist_t seqlist_create();
int seqlist_clear(seqlist_t p);
int seqlist_destroy(seqlist_t p);
int seqlist_is_empty(seqlist_t p);
int seqlist_is_full(seqlist_t p);
int seqlist_length(seqlist_t p);
int seqlist_insert(seqlist_t p,datatype x,int pos);
int seqlist_delete(seqlist_t p,int pos);
datatype seqlist_query_value(seqlist_t p,int pos);
int seqlist_modify_by_pos(seqlist_t p,int pos,datatype newValue);
int seqlist_query_pos(seqlist_t p,datatype value);
int seqlist_modify_by_value(seqlist_t p,datatype oldVaule,datatype newValue);
int seqlist_traverse(seqlist_t p);

#endif
