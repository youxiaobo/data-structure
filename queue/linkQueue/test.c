#include <stdio.h>
#include "linkqueue.h"
#include "debug.h"

int main(int argc, const char *argv[])
{
	//创建空的链式队列
	linkqueue_t lq = NULL;
	lq = linkqueue_create();
	if(lq == NULL)
	{
		DEBUG_CUSTOMERR("linkqueue create fail");
		return -1;
	}

	//判断链式队列是否为空
	if(linkqueue_is_empty(lq))
	{
		printf("linkqueue is empty\n");
	}

	//求链式队列长度
	printf("linkqueue_length is %d\n",linkqueue_length(lq));

	//入队
	linkqueue_in(lq,10);
	linkqueue_in(lq,20);
	linkqueue_in(lq,30);
	linkqueue_in(lq,40);
	linkqueue_in(lq,50);

	printf("linkqueue_length is %d\n",linkqueue_length(lq));
	
	//链表的遍历
	linkqueue_traverse(lq);

	//出队
	printf("%d is out\n",linkqueue_out(lq));
	linkqueue_traverse(lq);
	printf("%d is out\n",linkqueue_out(lq));
	linkqueue_traverse(lq);
	printf("%d is out\n",linkqueue_out(lq));
	linkqueue_traverse(lq);
	printf("%d is out\n",linkqueue_out(lq));
	linkqueue_traverse(lq);
	printf("%d is out\n",linkqueue_out(lq));
	linkqueue_traverse(lq);


	//清空链表
	linkqueue_clear(lq);
	printf("linkqueue_length is %d\n",linkqueue_length(lq));


	//销毁链表
	linkqueue_destroy(lq);

	//注意这里要置NULL，在函数内置NULL并不能影响实参
	lq = NULL;

	return 0;
}
