#include "seqstack.h"
#include "debug.h"
#include <stdlib.h>

/*
 * 创建空的顺序栈
 * 返回顺序栈指针
 */
seqstack_t seqstack_create()
{
	seqstack_t p = NULL;
	//为指针动态分配空间
	p = (seqstack_t)malloc(sizeof(seqstack));
	if(p == NULL)
	{
		DEBUG_CUSTOMERR("malloc error");
		return NULL;
	}
	p->top = -1;//空时下标为-1，插入时+1，正好和数组下标对应
	return p;
}
/*
 * 清空顺序栈 
 */
int seqstack_clear(seqstack_t p)
{
	p->top = -1;
	return 0;
}

/*
 * 销毁顺序栈
 */
 int seqstack_destroy(seqstack_t p)
{
	free(p);
	p = NULL;
	return 0;
}
/*
 * 判断栈是否为空
 * 空为1，不空为0 
 */
int seqstack_is_empty(seqstack_t p)
{
	return p->top == -1;
}

/*
 * 判断栈是否满
 * 满为1，不满为0
 */
int seqstack_is_full(seqstack_t p)
{
	return p->top+1 == N;
}

/*
 * 求顺序栈长
 */
int seqstack_length(seqstack_t p)
{
	return p->top + 1;
}

/*
 * 入栈(相当于在last+1位置插入)
 * 成功返回0，失败返回-1
 */
int seqstack_push(seqstack_t p,datatype x)
{
	int i;
	if(seqstack_is_full(p))
	{
		DEBUG_CUSTOMERR("seqstack is full");
		return -1;
	}
	
	p->data[p->top+1] = x;
	p->top++;
	return 0;
}

/*
 * 出栈（相当于删除last位置的元素）
 * 成功返回栈顶元素，失败暂时返回-1，应按实际类型决定
 */
datatype seqstack_pop(seqstack_t p)
{
	datatype tmp;
	if(seqstack_is_empty(p))
	{
		DEBUG_CUSTOMERR("seqstack has no data");
		return -1;
	}
	
	tmp = p->data[p->top];
	p->top--;
	return tmp;

}

/*
 * 取栈顶元素（查询last位置的元素值）
 * */
datatype seqstack_top(seqstack_t p)
{
	
	if(seqstack_is_empty(p))
	{
		DEBUG_CUSTOMERR("seqstack has no data");
		return -1;
	}
	return p->data[p->top];
}

/*
 * 顺序栈的遍历
 */
int seqstack_traverse(seqstack_t p)
{
	int i;
	if(seqstack_is_empty(p))
	{
		DEBUG_CUSTOMERR("seqstack has no data");
		return -1;
	}
	for(i=0; i<p->top+1; i++)
	{
		printf("%d ",p->data[i]);
	}
	printf("\n");
	return 0;
}


