#include "linklist.h"
#include "linklist_reverse.h"
#include <stdio.h>
#include <stdlib.h>
#include "debug.h"

/*
 * 链表倒置，方法1
 * 改变指针的指向
 * */
int linklist_reverse(linknode_t h)
{
	if(linklist_is_empty(h))
	{
		DEBUG_CUSTOMERR("linklist is empty");
		return -1;
	}
	//需要两个指针操作
	linknode_t p = h->next;//第一个指针
	linknode_t q = p->next;//第二个指针，指向p的后一个数据
	linknode_t tmp = NULL;
	p->next = NULL;//第一个数据变成最后一个数据，所以next域置NULL
	
	while(q != NULL)
	{
		tmp = q->next;//首先记录下一次要移动到的位置
		q->next = p;//指针反向，指向前一个数据
		p = q;//移动p指针到下一位置，向后移动一个位置
		q = tmp;//移动q指针到下一位置，也是向后移动一个位置
	}
	h->next = p;//头结点的next域指向倒置前的最后一个数据
	return 0;
}

/*
 * 链表尾删法
 * 成功返回删除的数据，失败返回-1
 * */
datatype linklist_delete_rear(linknode_t h)
{
	if(linklist_is_empty(h))
	{
		DEBUG_CUSTOMERR("linklist is empty");
		return -1;
	}
	
	linknode_t p = h;
	int i;
	for(i=0; i<linklist_length(h)-1; i++)
	{
		p = p->next;//指针移动到最后一个数据的前一个位置
	}

	//此后操作类似于头删法
	//记录要删除的位置
	linknode_t tmp = p->next;

	//取出删除位置上的数据
	datatype data = tmp->data;

	//改变指针连接
	p->next = tmp->next;

	//删除数据
	free(tmp);
	tmp = NULL;
	return data;
}
/*
 * 链表倒置，方法2
 * 尾删法挨个删除
 * 再挨个在右边插入
 * */
int linklist_reverse_1(linknode_t h)
{
	int i;
	datatype data;
	for(i=0; i<linklist_length(h); i++)//循环次数为表长次数
	{
		data = linklist_delete_rear(h);//尾删法挨个删除
		
		linklist_insert_by_pos(h,data,i);//挨个插入到第i位置
	}
	return 0;

}

/*
 * 链表头删法
 * 成功返回删除的数据，失败返回-1
 * */
datatype linklist_delete_head(linknode_t h)
{
	if(linklist_is_empty(h))
	{
		DEBUG_CUSTOMERR("linklist is empty");
		return -1;
	}

	//记录要删除的位置
	linknode_t tmp = h->next;
	//记录要删除的数据
	datatype data = tmp->data;

	//改变指针连接
	h->next = tmp->next;

	//删除数据
	free(tmp);
	tmp = NULL;
	return data;
}
/*
 * 链表倒置，方法3
 * 和方法2类似
 * 头删法挨个删除
 * 再挨个插入到第表长-i的位置*/
int linklist_reverse_2(linknode_t h)
{
	int i;
	datatype data;
	for(i=0; i<linklist_length(h); i++)//循环次数为表长次数
	{
		data = linklist_delete_head(h);//头删法
		
		linklist_insert_by_pos(h,data,linklist_length(h)-i);//挨个插入
	}
	return 0;

}

/*
 * 链表倒置，方法4
 * 两个指向一头一尾
 * 交换数据域数据
 * 指针向中间移动*/
int linklist_reverse_3(linknode_t h)
{
	int mid = linklist_length(h)/2;//确定中间位置，即要交换的次数，奇数或偶数个数据均可
	int i = 0;
	int j = 0;
	linknode_t p = h->next;//指针1，初始位置指向第一个数据
	linknode_t q = p;//指针2
	linknode_t tmp = p;
	for(j=1; j<linklist_length(h); j++)//移动次数为表长-1
	{
		q = q->next;//指针2，初始位置指向最后一个数据
	}
	datatype tmpdata;
	for(i=0; i<mid; i++)
	{
		//交换数据
		tmpdata = p->data;
		p->data = q->data;
		q->data = tmpdata;

		//指针1向后移动一个位置
		p = p->next;

		//注意这里指针2，不好确定他的上一个位置，需要遍历找到其上一个位置
		while(tmp->next != q)
		{
			tmp = tmp->next;
		}
		q = tmp;//指针2向前移动一个位置
		tmp = h->next;//临时指针复原，便于下一次移动

	}
	return 0;
}

/*
 * 链表倒置，方法5，最好的方法
 * 使用头插的思想，挨个取出并插入
 * 如果使用插入函数和删除函数会反复的malloc和free，不好
 * */
int linklist_reverse_4(linknode_t h)
{
	linknode_t p = h->next;//每一次要拿的数据，起始位置：第一个元素
	linknode_t q = NULL;//用来记录剩下链表的位置，也就是下一次要拿的位置
	h->next = NULL;//将头变成尾
	while(p != NULL)
	{
		q = p->next;//记录下一次要移动的位置
		p->next = h->next;//头插步骤1
		h->next = p;//头插步骤2
		p = q;//指针移动到下一个位置
	}
	return 0;
}
