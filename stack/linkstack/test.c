#include <stdio.h>
#include "linkstack.h"
#include "debug.h"

int main(int argc, const char *argv[])
{
	//创建空的链栈
	linknode_t s = NULL;
	s = linkstack_create();
	if(s == NULL)
	{
		DEBUG_CUSTOMERR("linkstack create fail");
		return -1;
	}

	//判断链栈是否为空
	if(linkstack_is_empty(s))
	{
		printf("linkstack is empty\n");
	}

	//求链栈长
	printf("linkstack_length is %d\n",linkstack_length(s));

	//入栈
	linkstack_push(s,10);
	linkstack_push(s,20);
	linkstack_push(s,30);
	linkstack_push(s,40);
	linkstack_push(s,50);

	printf("linkstack_length is %d\n",linkstack_length(s));
	
	//链栈的遍历
	linkstack_traverse(s);

	//出栈
	printf("%d pop out\n",linkstack_pop(s));
	printf("%d pop out\n",linkstack_pop(s));

	//取栈顶元素
	printf("top of stack is %d\n",linkstack_top(s));
 
	//清空链栈
	linkstack_clear(s);
	
	//链栈的遍历
	linkstack_traverse(s);


	//销毁链栈
	linkstack_destroy(s);

	//注意这里要置NULL，在函数内置NULL并不能影响实参
	s = NULL;
	return 0;
}
