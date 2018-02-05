#include "linklist.h"
#include "debug.h"
#include <stdlib.h>

/*
 * 创建空的链表
 * 返回链表的头结点
 */
linknode_t linklist_create()
{
	linknode_t h = NULL;
	h = (linknode_t)malloc(sizeof(linknode));
	if(h == NULL)
	{
		DEBUG_CUSTOMERR("malloc error");
		return NULL;
	}
	h->next = NULL;//初始化后继
	h->prior = NULL;//初始化前趋

	return h;
}
/*
 * 判断链表是否为空
 * (注意：链表不判断是否满)
 * 空为1，不空为0
 */
int linklist_is_empty(linknode_t h)
{
	return h->next == NULL && h->prior == NULL;
}

/*
 * 求链表长
 * 链表空时，长度为0
 * */
int linklist_length(linknode_t h)
{
	int i = 0;
	linknode_t p = h->next;
	if(linklist_is_empty(h))
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
 * 链表头插法
 * 成功返回0，失败返回-1
 * 注意：在头部插入的原因是：知道头结点的位置，而尾结点的位置需要遍历后才能获取
 * */
int linklist_insert(linknode_t h,datatype value)
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
	//操作3个指针
	p->next = h->next;
	p->prior = h;
	//h->next->prior = p;//注意，这里不能写，因为h->next是NULL
	h->next = p;
	return 0;
}

/*
 * 链表头删法
 * 成功返回0，失败返回-1
 * */
int linklist_delete(linknode_t h)
{
	if(linklist_is_empty(h))
	{
		DEBUG_CUSTOMERR("linklist is empty");
		return -1;
	}

	//记录要删除的位置
	linknode_t tmp = h->next;

	//改变指针连接
	h->next = tmp->next;
	tmp->next->prior = h;

	//删除数据
	free(tmp);
	tmp = NULL;
	return 0;
}



/*
 * 链表的遍历
 * */
int linklist_traverse(linknode_t h)
{
	linknode_t p = h->next;
	if(linklist_is_empty(h))
	{
		DEBUG_CUSTOMERR("linklist is empty");
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

/*
 * 按位置插入某个数据到链表中
 * 成功返回0，失败返回-1
 * */
int linklist_insert_by_pos(linknode_t h,datatype value,int pos)
{
	linknode_t p = h;
	linknode_t q = NULL;
	
	if(pos < 0 || pos > linklist_length(h)-1)//这里只讨论在中间插入，操作4个指针，不管在表尾插入
	{
		DEBUG_CUSTOMERR("pos error");
		return -1;
	}

	int i = 0;
	//移动指针到插入位置的前一个位置，相当于头插法的head
	for(i=0; i<pos; i++)
	{
		p = p->next;
	}
	//此时再使用头插法
	q = (linknode_t)malloc(sizeof(linknode));
	if(q == NULL)
	{
		DEBUG_CUSTOMERR("malloc error");
		return -1;
	}

	//数据域填充数据
	q->data = value;

	//结点指针连接
	//操作四个指针
	//先操作新增结点的前趋和后继
	//再操作新增结点后继的前趋
	//最后操作新增结点前趋的后继
	q->next = p->next;
	q->prior = p;
	p->next->prior = q;
	p->next = q;
	return 0;
}

/*
 * 按位置删除链表中的某一数据
 * 成功返回0，失败返回-1
 * */
int linklist_delete_by_pos(linknode_t h,int pos)
{
	if(pos < 0 || pos > linklist_length(h)-2)//这里只讨论在中间删除，操作2个指针，不删除最后一个元素
	{
		DEBUG_CUSTOMERR("pos error");
		return -1;
	}

	//找到待删除数据的前一位置
	linknode_t p = h;
	linknode_t tmp = NULL;

	int i;
	for(i=0; i<pos; i++)
	{
		p = p->next;
	}

	//再使用和头删法类似的步骤
	//记录要删除的位置
	tmp = p->next;

	//改变两个指针
	p->next = tmp->next;
	tmp->next->prior = p;

	free(tmp);
	tmp = NULL;
	return 0;
}
