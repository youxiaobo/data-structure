#ifndef _CIRQUEUE_H_
#define _CIRQUEUE_H_

//循环队列
//头尾相连的顺序存储队列

#define N 10 //定义队列的最大长度
typedef int datatype; //定义数据的类型，可替换为其他

typedef struct{
	datatype data[N]; //队列的存储空间，一维数组
	int front,rear;//队头、队尾下标 
}cirqueue,*cirqueue_t;

cirqueue_t cirqueue_create();
int cirqueue_clear(cirqueue_t p);
int cirqueue_destroy(cirqueue_t p);
int cirqueue_is_empty(cirqueue_t p);
int cirqueue_is_full(cirqueue_t p);
int cirqueue_length(cirqueue_t p);
int cirqueue_in(cirqueue_t p,datatype x);
datatype cirqueue_out(cirqueue_t p);
int cirqueue_in1(cirqueue_t p,datatype x);
datatype cirqueue_out1(cirqueue_t p);
int cirqueue_traverse(cirqueue_t p);

#endif
