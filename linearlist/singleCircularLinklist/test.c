#include <stdio.h>
#include "linklist.h"
#include "debug.h"

int main(int argc, const char *argv[])
{
	//创建空的链表
	linknode_t h = NULL;
	h = linklist_create();
	if(h == NULL)
	{
		DEBUG_CUSTOMERR("linklist create fail");
		return -1;
	}

	//判断链表是否为空
	if(linklist_is_empty(h))
	{
		printf("linklist is empty\n");
	}

	//求链表长
	printf("linklist_length is %d\n",linklist_length(h));

	//头插法
	linklist_insert(h,10);
	linklist_insert(h,20);
	linklist_insert(h,30);
	linklist_insert(h,40);
	linklist_insert(h,50);

	printf("linklist_length is %d\n",linklist_length(h));
	
	//链表的遍历
	linklist_traverse(h);

	//头删法
	linklist_delete(h);
	linklist_traverse(h);
	linklist_delete(h);
	linklist_traverse(h);

	//查找某个数据是否存在于链表中
	printf("value 50 pos %d\n",linklist_query(h,50));
	printf("value 10 pos %d\n",linklist_query(h,10));

	//尾插
	/*
	linklist_insert_by_pos(h,10,linklist_length(h));
	linklist_insert_by_pos(h,20,linklist_length(h));
	linklist_insert_by_pos(h,30,linklist_length(h));
	linklist_insert_by_pos(h,40,linklist_length(h));
	linklist_insert_by_pos(h,50,linklist_length(h));
	*/

	//尾插
	linknode_t r = NULL;
	r = linklist_rearP(h);//获取表尾位置
	linklist_insert(r,100);
	r = linklist_rearP(h);//获取表尾位置
	linklist_insert(r,200);
	linklist_traverse(h);

	//使用尾指针访问数据
	printf("h->next->data=%d\n",h->next->data);
	r = linklist_rearP(h);//获取表尾位置
	printf("r->next->next->data=%d\n",r->next->next->data);

	//创建空的链表
	linknode_t h1 = NULL;
	h1 = linklist_create();
	if(h1 == NULL)
	{
		DEBUG_CUSTOMERR("linklist create fail");
		return -1;
	}
	//头插法
	linklist_insert(h1,1);
	linklist_insert(h1,2);
	linklist_insert(h1,3);
	linklist_insert(h1,4);
	linklist_insert(h1,5);

	//两条单向循环链表的简单合并
	linklist_traverse(h);
	linklist_traverse(h1);
	r = linklist_rearP(h);
	linknode_t r1 = linklist_rearP(h1);
	linklist_union(r,r1);
	linklist_traverse(h);

	return 0;
}
