#include <stdio.h>
#include "linklist.h"
#include "debug.h"
#include "linklist_reverse.h"

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

	//修改链表中某个元素的值
	linklist_modify(h,50,500);
	linklist_traverse(h);
	linklist_modify(h,10,100);
	linklist_traverse(h);

	//清空链表
	linklist_clear(h);

	//尾插
	linklist_insert_by_pos(h,10,linklist_length(h));
	linklist_insert_by_pos(h,20,linklist_length(h));
	linklist_insert_by_pos(h,30,linklist_length(h));
	linklist_insert_by_pos(h,40,linklist_length(h));
	linklist_insert_by_pos(h,50,linklist_length(h));
	
	//按位置插入某个数据到链表中
	linklist_insert_by_pos(h,50,7);

	linklist_traverse(h);

	//按值删除链表中的某一数据
	linklist_delete_by_value(h,55);
	linklist_traverse(h);
	linklist_delete_by_value(h,20);
	linklist_traverse(h);

	//销毁链表
	linklist_destroy(h);

	//注意这里要置NULL，在函数内置NULL并不能影响实参
	h = NULL;
	//linklist_traverse(h);

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
	linklist_traverse(h);

	//链表倒置测试
	linklist_reverse(h);
	linklist_traverse(h);

	linklist_reverse_1(h);
	linklist_traverse(h);

	linklist_reverse_2(h);
	linklist_traverse(h);

	//9个数测试倒置
	linklist_insert_by_pos(h,60,linklist_length(h));
	linklist_insert_by_pos(h,70,linklist_length(h));
	linklist_insert_by_pos(h,80,linklist_length(h));
	linklist_insert_by_pos(h,90,linklist_length(h));
	linklist_traverse(h);
	linklist_reverse_3(h);
	linklist_traverse(h);
	
	//2个数测试倒置
	linklist_delete(h);
	linklist_delete(h);
	linklist_delete(h);
	linklist_delete(h);
	linklist_delete(h);
	linklist_delete(h);
	linklist_delete(h);
	linklist_traverse(h);
	linklist_reverse_3(h);
	linklist_traverse(h);

	//1个数测试倒置
	linklist_delete(h);
	linklist_traverse(h);
	linklist_reverse_3(h);
	linklist_traverse(h);

	linklist_insert_by_pos(h,20,linklist_length(h));
	linklist_insert_by_pos(h,30,linklist_length(h));
	linklist_insert_by_pos(h,40,linklist_length(h));
	linklist_insert_by_pos(h,50,linklist_length(h));
	linklist_traverse(h);
	linklist_reverse_4(h);
	linklist_traverse(h);
	return 0;
}
