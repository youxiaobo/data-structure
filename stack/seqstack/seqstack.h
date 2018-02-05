#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_

//栈的顺序存储
#define N 10
typedef int datatype; //定义数据的类型，可替换为其他

typedef struct{
	datatype data[N]; //栈的存储空间
	int top; //栈顶
}seqstack,*seqstack_t;

seqstack_t seqstack_create();
int seqstack_clear(seqstack_t p);
int seqstack_destroy(seqstack_t p);
int seqstack_is_empty(seqstack_t p);
int seqstack_is_full(seqstack_t p);
int seqstack_length(seqstack_t p);
int seqstack_push(seqstack_t p,datatype x);
datatype seqstack_pop(seqstack_t p);
datatype seqstack_top(seqstack_t p);
int seqstack_traverse(seqstack_t p);

#endif
