#include "linkqueue.h"
#include "debug.h"
#include <stdlib.h>

/*
 * 创建空的链式队列
 * 返回链式队列的指针
 */
linkqueue_t linkqueue_create()
{
	//创建结点
	linknode_t h = NULL;
	h = (linknode_t)malloc(sizeof(linknode));
	if(h == NULL)
	{
		DEBUG_CUSTOMERR("malloc error");
		return NULL;
	}

	//创建队列
	linkqueue_t lq = NULL;
	lq = (linkqueue_t)malloc(sizeof(linkqueue));
	if(lq == NULL)
	{
		free(h);//如果失败，释放结点空间
		DEBUG_CUSTOMERR("malloc error");
		return NULL;
	}
	h->next = NULL;//初始化头结点，注意这个位置，在结点和队列的空间都申请成功后再初始化
	lq->front = h;//初始化队头
	lq->rear = h;//初始化队尾
	
	return lq;
}
/*
 * 判断链式队列是否为空
 * (注意：链式队列不判断是否满)
 * 空为1，不空为0
 */
int linkqueue_is_empty(linkqueue_t lq)
{
	return lq->front ==  lq->rear;
}

/*
 * 求链式队列长
 * 链式队列空时，长度为0
 * */
int linkqueue_length(linkqueue_t lq)
{
	int i = 0;
	linknode_t p = lq->front->next;
	if(linkqueue_is_empty(lq))
	{
		return i;
	}

	while(p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}
/*
 * 入队（在队尾插入）
 * 成功返回0，失败返回-1
 * */
int linkqueue_in(linkqueue_t lq,datatype value)
{
	//为新的结点分配空间
	linknode_t p = NULL;
	p = (linknode_t)malloc(sizeof(linknode));
	if(p == NULL)
	{
		DEBUG_CUSTOMERR("malloc error");
		return -1;
	}

	//结点数据赋值
	p->data = value;

	//结点指针连接
	p->next = lq->rear->next;
	lq->rear->next = p;

	lq->rear = p;//队尾指针向后移动一个位置
	return 0;
}

/*
 * 出队（在队头删除）
 * 成功返回数据，失败暂时返回-1，应按照实际数据类型返回
 * */
datatype linkqueue_out(linkqueue_t lq)
{
	if(linkqueue_is_empty(lq))
	{
		DEBUG_CUSTOMERR("linkqueue is empty");
		return -1;
	}

	//记录要删除的位置
	linknode_t tmp = lq->front->next;
	datatype data = tmp->data;

	//改变指针连接
	lq->front->next = tmp->next;

	//注意：一定要写这句，避免删除最后一个数据时，如果free掉最后一个数据的空间，那么rear指针没有指的地方，成为野指针，所有需要向前移动
	if(lq->rear == tmp)
	{
		lq->rear = lq->front;
	}

	//删除数据
	free(tmp);
	tmp = NULL;

	/* 以上是方法一，释放要删除结点的空间
	 * 方法二，删除头结点的空间，则可以避免忘记将rear指针向前移动
	 * 因为出队，更多关注出队的数据，而至于删除了哪个位置不是很关心
	 * linknode_t tmp = lq->front;
	 * datatype data = lq->front->next->data;
	 * lq->front = lq->front->next;
	 * free(tmp);
	 * tmp = NULL;
	 * return data;
	 * */
	return data;
}

/*
 * 清空链式队列
 * */
int linkqueue_clear(linkqueue_t lq)
{
	//h->next = NULL
	//不能这么写，需要释放各个结点的空间

	while(!linkqueue_is_empty(lq))
	{
		linkqueue_out(lq);
	}

	return 0;

}
/*
 * 销毁链式队列
 * */
int linkqueue_destroy(linkqueue_t lq)
{
	//先清空链式队列
	linkqueue_clear(lq);

	//释放头结点空间(此时front和rear在同一个位置)
	free(lq->front);
	
	lq->front = NULL;
	lq->rear = NULL;

	//lq->front和lq->rear置NULL后才可以释放lq
	free(lq);
	lq =  NULL;
	return 0;
}


/*
 * 链式队列的遍历
 * */
int linkqueue_traverse(linkqueue_t lq)
{
	linknode_t p = lq->front->next;
	if(linkqueue_is_empty(lq))
	{
		DEBUG_CUSTOMERR("linkqueue is empty");
		return -1;
	}

	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
	return 0;
}


