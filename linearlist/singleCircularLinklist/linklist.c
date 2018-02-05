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
	h->next = h;//规定链表尾指向h,循环列表
	return h;
}
/*
 * 判断链表是否为空
 * (注意：链表不判断是否满)
 * 空为1，不空为0
 */
int linklist_is_empty(linknode_t h)
{
	return h->next == h;
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

	while(p != h)
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
	while(p != h)
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

	while(p != h)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
	return 0;
}

/*
 * 求表尾数据所在的位置（指针）
 * 注意这里要得到这个指针，不能返回函数内的局部变量
 * 因此在函数内改变h的位置进行返回
 * 注意1：h在函数内变化后并不影响函数外的h，因为函数内是变量副本
 * 注意2：因为这里要移动h，所以用h->next是否等于h将退不出while循环，需要先使用局部变量记录h的初始位置
 */
linknode_t linklist_rearP(linknode_t h)
{
	linknode_t p = h;//记录h的初始位置
	if(h->next == p)
	{

		return h;
	}
	while(h->next != p)
	{
		h = h->next;
	}
	return h;
}

/*
 * 两条单向循环链表的简单合并
 * */
int linklist_union(linknode_t a_r,linknode_t b_r)
{

	linknode_t p = NULL;
	p = b_r->next;//记录b的头指针位置
	b_r->next = a_r->next;//b的尾指针指向a的头指针
	a_r->next = p->next;//a的尾指针指向b链头指针的下一个位置，即数据开始的地方
	free(p);//删除b链的头指针
	return 0;

}
