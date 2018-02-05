#include <stdio.h>
#include "seqstack.h"
#include "debug.h"

int main(int argc, const char *argv[])
{
	//创建空的顺序栈
	seqstack_t s = seqstack_create();
	if(s == NULL)
	{
		DEBUG_CUSTOMERR("malloc error");
		return -1;
	}

	//特点：先进后出
	//入栈、出栈
	int i=0;
	for(i=0; i<10; i++)
	{
		seqstack_push(s,i);
	}
	seqstack_traverse(s);
	seqstack_push(s,11);
	seqstack_traverse(s);

	//取栈顶元素
	printf("top of stack is %d\n",seqstack_top(s));

	datatype data;
	for(i=0; i<10; i++)
	{
		data = seqstack_pop(s);
		printf("%d pop out\n",data);
	}

	if(seqstack_is_empty(s))
	{
		printf("stack is empty\n");
	}

	seqstack_destroy(s);
	s = NULL;
	
	return 0;
}
