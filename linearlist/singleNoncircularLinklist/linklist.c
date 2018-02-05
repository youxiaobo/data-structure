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
	h->next = NULL;//规定链表尾指向NULL
	return h;
}
/*
 * 判断链表是否为空
 * (注意：链表不判断是否满)
 * 空为1，不空为0
 */
int linklist_is_empty(linknode_t h)
{
	return h->next == NULL;
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
	p->next = h->next;
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

	//删除数据
	free(tmp);
	tmp = NULL;
	return 0;
}

/*
 * 查找某个数据是否存在于链表中
 * 查到返回位置，位置从0开始计算，失败返回-1
 * 注意：也可以查到返回0，链表并不是很关心位置
 * */
int linklist_query(linknode_t h,datatype value)
{
	int i = 0;
	linknode_t p = h->next;
	while(p != NULL)
	{
		if(p->data == value)
		{
			return i;
		}
		p = p->next;
		i++;
	}
	DEBUG_CUSTOMERR("no such data");
	return -1;
}

/*
 * 修改链表中某个元素的值
 * 成功返回0，失败返回-1
 * */
int linklist_modify(linknode_t h,datatype oldVaule,datatype newValue)
{
	linknode_t p = h->next;
	while(p != NULL)
	{
		if(p->data == oldVaule)
		{
			p->data = newValue;
			return 0;
		}
		p = p->next;
	}
	DEBUG_CUSTOMERR("no such data");
	return -1;
}
/*
 * 清空链表
 * */
int linklist_clear(linknode_t h)
{
	//h->next = NULL
	//不能这么写，需要释放各个结点的空间

	while(h->next != NULL)
	{
		linklist_delete(h);
	}

	return 0;

}
/*
 * 销毁链表
 * */
int linklist_destroy(linknode_t h)
{
	//先清空链表
	linklist_clear(h);

	//释放头结点空间
	free(h);
	h = NULL;
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

/****************扩展*********************/
/*
 * 按位置插入某个数据到链表中
 * 插入到第pos个位置上,pos的取值范围为0-表长
 * 成功返回0，失败返回-1
 * */
int linklist_insert_by_pos(linknode_t h,datatype value,int pos)
{
	linknode_t p = h;
	linknode_t q = NULL;
	
	if(pos < 0 || pos > linklist_length(h))//可以查在表长位置上，尾插，大于表长则不可以
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
	q->data = value;
	q->next = p->next;
	p->next = q;
	return 0;
}

/*
 * 按值删除链表中的某一数据
 * 成功返回0，失败返回-1
 * */
int linklist_delete_by_value(linknode_t h,datatype value)
{
	//找到待删除数据的前一位置
	linknode_t p = h;
	linknode_t tmp = NULL;
	while(p->next != NULL)
	{
		if(p->next->data == value)
		{

			//记录待删除的位置
			tmp = p->next;

			//再使用和头删法类似的步骤
			p->next = tmp->next;
			free(tmp);
			tmp = NULL;
			return 0;
		}
		p = p->next;
	}
	DEBUG_CUSTOMERR("no such data");
	return -1;
}
