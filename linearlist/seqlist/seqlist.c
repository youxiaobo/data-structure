#include "seqlist.h"
#include "debug.h"
#include <stdlib.h>

/*
 * 创建空的顺序表
 * 返回顺序表指针
 */
seqlist_t seqlist_create()
{
	seqlist_t p = NULL;
	//为指针动态分配空间
	p = (seqlist_t)malloc(sizeof(seqlist));
	if(p == NULL)
	{
		DEBUG_CUSTOMERR("malloc error");
		return NULL;
	}
	p->last = -1;//空时下标为-1，插入时+1，正好和数组下标对应
	return p;
}
/*
 * 清空顺序表 
 */
int seqlist_clear(seqlist_t p)
{
	p->last = -1;
	return 0;
}

/*
 * 销毁顺序表
 */
 int seqlist_destroy(seqlist_t p)
{
	free(p);
	p = NULL;
	return 0;
}
/*
 * 判断表是否为空
 * 空为1，不空为0 
 */
int seqlist_is_empty(seqlist_t p)
{
	return p->last == -1;
}

/*
 * 判断表是否满
 * 满为1，不满为0
 */
int seqlist_is_full(seqlist_t p)
{
	return p->last+1 == N;
}

/*
 * 求顺序表长
 */
int seqlist_length(seqlist_t p)
{
	return p->last + 1;
}

/*
 * 将元素x插入到表中第pos个元素位置
 * pos的有效范围是0-last+1(包括了在表尾插入的情况)
 * 成功返回0，失败返回-1
 */
int seqlist_insert(seqlist_t p,datatype x,int pos)
{
	int i;
	if(seqlist_is_full(p))
	{
		DEBUG_CUSTOMERR("seqlist is full");
		return -1;
	}
	if(pos < 0 || pos > p->last+1)
	{
		DEBUG_CUSTOMERR("pos error");
		return -1;
	}
	//从后往前，向后移动位置
	for(i = p->last + 1; i > pos; i--)
	{
		p->data[i] = p->data[i-1]; 
	}
	p->data[pos] = x;
	p->last++;
	return 0;
}

/*
 * 删除顺序表中某一个位置数据
 * 成功返回0，失败返回-1
 */
int seqlist_delete(seqlist_t p,int pos)
{
	int i;
	if(seqlist_is_empty(p))
	{
		DEBUG_CUSTOMERR("seqlist has no data");
		return -1;
	}
	if(pos < 0 || pos > p->last)
	{
		DEBUG_CUSTOMERR("pos err");
		return -1;
	}
	//从前往后，向前移动位置
	for(i=pos; i<p->last;i++)
	{
		p->data[i] = p->data[i+1];
	}
	p->last--;
	return 0;

}
/*
 * 查找某个位置的元素值
 * 成功返回datatype的数据值，失败：按实际情况返回，这里暂且写为返回int -1
 */
datatype seqlist_query_value(seqlist_t p,int pos)
{
	if(pos < 0 || pos > p->last)
	{
		DEBUG_CUSTOMERR("pos error");
		return -1;
	}
	return p->data[pos];
}

/*
 * 修改某个位置的元素值
 * 成功返回0，失败返回-1
 */
int seqlist_modify_by_pos(seqlist_t p,int pos,datatype newValue)
{
	if(pos < 0 || pos > p->last)
	{
		DEBUG_CUSTOMERR("pos error");
		return -1;
	}
	p->data[pos] = newValue;
	return 0;
}

/*
 * 查找某个元素所在的位置
 * 成功返回位置，失败返回-1
 */
int seqlist_query_pos(seqlist_t p,datatype value)
{
	int i;
	for(i=0; i<p->last+1; i++)
	{
		if(p->data[i] == value)
		{
			return i;
		}
	}
	DEBUG_CUSTOMERR("no such data");
	return -1;
}
/*
 * 修改某个元素的值
 * 成功返回0，失败返回-1
 */
int seqlist_modify_by_value(seqlist_t p,datatype oldVaule,datatype newValue)
{
	int pos;
	//查找位置
	pos = seqlist_query_pos(p,oldVaule);
	if(pos == -1)
	{
		DEBUG_CUSTOMERR("no such data");
		return -1;
	}
	else
	{
		p->data[pos] = newValue;
		return 0;
	}
}
/*
 * 顺序表的遍历
 */
int seqlist_traverse(seqlist_t p)
{
	int i;
	if(seqlist_is_empty(p))
	{
		DEBUG_CUSTOMERR("seqlist has no data");
		return -1;
	}
	for(i=0; i<p->last+1; i++)
	{
		printf("%d ",p->data[i]);
	}
	printf("\n");
	return 0;
}


