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


	//头插法
	linklist_insert(h,10);
	linklist_insert(h,20);
	linklist_insert(h,30);
	linklist_insert(h,40);
	linklist_insert(h,50);
	
	//链表的遍历
	linklist_traverse(h);

	//按位置插入某个数据到链表中
	linklist_insert_by_pos(h,500,4);
	linklist_insert_by_pos(h,300,2);
	linklist_traverse(h);

	//头删法
	linklist_delete(h);
	linklist_traverse(h);
	linklist_delete(h);
	linklist_traverse(h);	

	//按位置删除链表中的某一数据
	linklist_delete_by_pos(h,2);
	linklist_traverse(h);
	linklist_delete_by_pos(h,3);
	linklist_traverse(h);


		return 0;
}
