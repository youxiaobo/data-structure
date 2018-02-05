#include "linkstack.h"
#include "debug.h"
#include <stdlib.h>

/*
 * 创建空的链栈
 * 返回链栈的头结点
 */
linknode_t linkstack_create()
{
	linknode_t h = NULL;
	h = (linknode_t)malloc(sizeof(linknode));
	if(h == NULL)
	{
		DEBUG_CUSTOMERR("malloc error");
		return NULL;
	}
	h->next = NULL;//规定链栈尾指向NULL
	return h;
}
/*
 * 判断链栈是否为空
 * (注意：链栈不判断是否满)
 * 空为1，不空为0
 */
int linkstack_is_empty(linknode_t h)
{
	return h->next == NULL;
}

/*
 * 求链栈长
 * 链栈空时，长度为0
 * */
int linkstack_length(linknode_t h)
{
	int i = 0;
	linknode_t p = h->next;
	if(linkstack_is_empty(h))
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
 * 入栈(线性表的头插)
 * 成功返回0，失败返回-1
 * */
int linkstack_push(linknode_t h,datatype value)
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
	p->next = h->next;
	h->next = p;
	return 0;
}

/*
 * 出栈（线性表的头删）
 * 成功返回栈顶元素，失败暂时返回-1，应根据实际数据类型返回
 * */
datatype linkstack_pop(linknode_t h)
{
	if(linkstack_is_empty(h))
	{
		DEBUG_CUSTOMERR("linkstack is empty");
		return -1;
	}

	//记录要删除的位置和数据
	linknode_t tmp = h->next;
	datatype data = tmp->data;

	//改变指针连接
	h->next = tmp->next;

	//删除数据
	free(tmp);
	tmp = NULL;
	return data;
}

/*
 * 取栈顶元素（线性表的查询某个位置的元素值，这里位置为第一个元素）
 * 成功返回栈顶元素，失败暂时返回-1，应按照实际数据类型返回
 * */
datatype linkstack_top(linknode_t h)
{
	if(linkstack_is_empty(h))
	{
		DEBUG_CUSTOMERR("linkstack is empty");
		return -1;
	}
	return h->next->data;
}

/*
 * 清空链栈
 * */
int linkstack_clear(linknode_t h)
{
	//h->next = NULL
	//不能这么写，需要释放各个结点的空间

	while(h->next != NULL)
	{
		linkstack_pop(h);
	}

	return 0;

}
/*
 * 销毁链栈
 * */
int linkstack_destroy(linknode_t h)
{
	//先清空链栈
	linkstack_clear(h);

	//释放头结点空间
	free(h);
	h = NULL;
	return 0;
}


/*
 * 链栈的遍历
 * */
int linkstack_traverse(linknode_t h)
{
	linknode_t p = h->next;
	if(linkstack_is_empty(h))
	{
		DEBUG_CUSTOMERR("linkstack is empty");
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


