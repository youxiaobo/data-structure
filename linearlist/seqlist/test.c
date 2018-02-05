#include <stdio.h>
#include "seqlist.h"
#include "debug.h"

int main(int argc, const char *argv[])
{
	
	//创建空的顺序表
	seqlist_t p = NULL;
	p = seqlist_create();
	if(p == NULL)
	{
		DEBUG_CUSTOMERR("seqlist_create fail");
		return -1;
	}
	
	//判断表是否为空
	if(seqlist_is_empty(p))
	{
		printf("seqlist is empty\n");
	}

	//顺序的在表尾插入
	seqlist_insert(p,1,0);
	seqlist_insert(p,2,1);
	seqlist_insert(p,3,2);
	seqlist_insert(p,4,3);
	seqlist_insert(p,5,4);

	seqlist_traverse(p);

	//判断表是否为满
	if(seqlist_is_full(p))
	{
		printf("seqlist is full\n");
	}
	else
	{
		printf("seqlist length is %d\n",seqlist_length(p));
	}

	//在位置2插入数据
	seqlist_insert(p,12,2);

	seqlist_traverse(p);

	//在位置8插入数据
	//seqlist_insert(p,23,8);
	
	seqlist_insert(p,22,6);
	seqlist_insert(p,33,7);
	seqlist_insert(p,44,8);
	seqlist_insert(p,55,9);
	//seqlist_insert(p,66,10);

	seqlist_traverse(p);
	
	//seqlist_delete(p,10);
	seqlist_delete(p,9);
	seqlist_delete(p,2);
	
	seqlist_traverse(p);

	//取出某个位置的数据
	printf("pos 2 value %d\n",seqlist_query_value(p,2));
	printf("pos 9 value %d\n",seqlist_query_value(p,9));
		
	//修改某个位置的数据
	seqlist_modify_by_pos(p,2,88);
	seqlist_modify_by_pos(p,9,100);

	seqlist_traverse(p);
	
	//查找某个数据的位置
	printf("value 33 pos %d\n",seqlist_query_pos(p,33));
	printf("value 77 pos %d\n",seqlist_query_pos(p,77));

	//修改某个数据
	seqlist_modify_by_value(p,33,66);
	seqlist_modify_by_value(p,6,9);

	seqlist_traverse(p);
	
	//销毁表
    seqlist_destroy(p);

	//为了避免函数外继续访问，这里必须置NULL
	p = NULL;
	//printf("%p\n",p);
	//printf("p->data[2]=%d\n",p->data[2]);

	return 0;
}
