#include "cirqueue.h"
#include "debug.h"
#include <stdlib.h>

/*
 * 创建空的循环队列
 * 返回循环队列指针
 */
cirqueue_t cirqueue_create()
{
	cirqueue_t p = NULL;
	//为指针动态分配空间
	p = (cirqueue_t)malloc(sizeof(cirqueue));
	if(p == NULL)
	{
		DEBUG_CUSTOMERR("malloc error");
		return NULL;
	}
	p->front = p->rear = 0;//队头和队尾初始化为0
	
	int i;
	for(i=0; i<N; i++)
	{
		p->data[i] = -1;//为了打印时区分没有赋值的空间，这里初始化一下数据
	}
	return p;
}
/*
 * 清空循环队列 
 */
int cirqueue_clear(cirqueue_t p)
{
	p->rear = p->front = 0;
	
	int i;
	for(i=0; i<N; i++)
	{
		p->data[i] = -1;//同样这里都重新赋值为-1
	}

	return 0;
}

/*
 * 销毁循环队列
 */
 int cirqueue_destroy(cirqueue_t p)
{
	free(p);
	p = NULL;
	return 0;
}
/*
 * 判断表是否为空
 * 空为1，不空为0 
 */
int cirqueue_is_empty(cirqueue_t p)
{
	return p->rear == p->front;
}

/*
 * 判断表是否满,采用求余的方式
 * 满为1，不满为0
 */
int cirqueue_is_full(cirqueue_t p)
{
	return (p->rear+1)%N == p->front;
}

/*
 * 求循环队列长
 * 如果rear>front 长度为rear-front
 * 如果rear<front 长度为N-front+rear
 * 所以采用求余的方式
 */
int cirqueue_length(cirqueue_t p)
{
	return (p->rear-p->front+N)%N;
}

/*
 * 入队，浪费头结点，即头结点不放数据（插在队尾）
 * 成功返回0，失败返回-1
 */
int cirqueue_in(cirqueue_t p,datatype x)
{
	int i;
	if(cirqueue_is_full(p))
	{
		DEBUG_CUSTOMERR("cirqueue is full");
		return -1;
	}
	
	//p->rear++;不能这么写，因为是循环队列，满了之后，需要置rear为0
	p->rear = (p->rear+1)%N;//队尾下标移动
	p->data[p->rear] = x;
	return 0;

}

/*
 * 出队，浪费头结点（删除队头）
 * 成功返回数据，失败暂时返回-1，应按照实际数据类型返回
 */
datatype cirqueue_out(cirqueue_t p)
{
	int i;
	if(cirqueue_is_empty(p))
	{
		DEBUG_CUSTOMERR("cirqueue has no data");
		return -1;
	}

	p->front = (p->front+1)%N;//队头下标移动
	datatype data = p->data[p->front];
	p->data[p->front] = -1;//我自己加的，其实这里所谓的删除，原来的数据还在，因为是数组。因此这里置为-1，区分一下。
	return data;

}

/*
 * 入队，浪费尾结点，即尾结点不放数据（插在队尾）
 * 成功返回0，失败返回-1
 */
int cirqueue_in1(cirqueue_t p,datatype x)
{
	int i;
	if(cirqueue_is_full(p))
	{
		DEBUG_CUSTOMERR("cirqueue is full");
		return -1;
	}
	
	
	p->data[p->rear] = x;//先赋值
	p->rear = (p->rear+1)%N;//再队尾下标移动
	return 0;

}

/*
 * 出队，浪费尾结点（删除队头）
 * 成功返回数据，失败暂时返回-1，应按照实际数据类型返回
 */
datatype cirqueue_out1(cirqueue_t p)
{
	int i;
	if(cirqueue_is_empty(p))
	{
		DEBUG_CUSTOMERR("cirqueue has no data");
		return -1;
	}

	datatype data = p->data[p->front];//先取值
	
	p->data[p->front] = -1;//我自己加的，要出队的位置置-1
	
	p->front = (p->front+1)%N;//再队头下标移动
	return data;

}

/*
 * 循环队列的遍历
 */
int cirqueue_traverse(cirqueue_t p)
{
	int i;
	if(cirqueue_is_empty(p))
	{
		DEBUG_CUSTOMERR("cirqueue has no data");
		return -1;
	}
	for(i=0; i<N; i++)//打印整个队列的空间
	{
		printf("%d ",p->data[i]);
	}
	printf("\n");
	return 0;
}


