#include <stdio.h>
#include "cirqueue.h"
#include "debug.h"

int main(int argc, const char *argv[])
{
	
	//创建空的循环队列
	cirqueue_t p = NULL;
	p = cirqueue_create();
	if(p == NULL)
	{
		DEBUG_CUSTOMERR("cirqueue_create fail");
		return -1;
	}
	
	//判断表是否为空
	if(cirqueue_is_empty(p))
	{
		printf("cirqueue is empty\n");
	}
	cirqueue_traverse(p);

	//入队（浪费头结点）
	cirqueue_in(p,1);
	cirqueue_in(p,2);
	cirqueue_in(p,3);
	cirqueue_in(p,4);
	cirqueue_in(p,5);

	printf("cirqueue length is %d\n",cirqueue_length(p));
	cirqueue_traverse(p);

	//出队（先进先出）
	printf("%d is out\n",cirqueue_out(p));
	printf("%d is out\n",cirqueue_out(p));
	printf("%d is out\n",cirqueue_out(p));

	printf("cirqueue length is %d\n",cirqueue_length(p));
	cirqueue_traverse(p);

	//入队（如果数组后面已满，则会插入到前面）
	cirqueue_in(p,10);
	cirqueue_traverse(p);
	cirqueue_in(p,20);
	cirqueue_traverse(p);
	cirqueue_in(p,30);
	cirqueue_traverse(p);
	cirqueue_in(p,40);
	cirqueue_traverse(p);
	cirqueue_in(p,50);
	cirqueue_traverse(p);
	cirqueue_in(p,60);
	cirqueue_traverse(p);
	cirqueue_in(p,70);
	cirqueue_traverse(p);
	cirqueue_in(p,80);
	cirqueue_traverse(p);
	cirqueue_in(p,90);
	cirqueue_traverse(p);
	cirqueue_in(p,100);

	printf("cirqueue length is %d\n",cirqueue_length(p));
	cirqueue_traverse(p);


	
	//清空循环队列
    cirqueue_clear(p);
	printf("cirqueue length is %d\n",cirqueue_length(p));

	//入队（浪费尾结点）
	cirqueue_in1(p,1);
	cirqueue_in1(p,2);
	cirqueue_in1(p,3);
	cirqueue_in1(p,4);
	cirqueue_in1(p,5);
	cirqueue_traverse(p);

	//出队（先进先出）
	printf("%d is out\n",cirqueue_out1(p));
	cirqueue_traverse(p);
	printf("%d is out\n",cirqueue_out1(p));
	cirqueue_traverse(p);
	printf("%d is out\n",cirqueue_out1(p));
	cirqueue_traverse(p);

	cirqueue_in1(p,10);
	cirqueue_traverse(p);
	cirqueue_in1(p,20);
	cirqueue_traverse(p);
	cirqueue_in1(p,30);
	cirqueue_traverse(p);
	cirqueue_in1(p,40);
	cirqueue_traverse(p);
	cirqueue_in1(p,50);
	cirqueue_traverse(p);
	cirqueue_in1(p,60);
	cirqueue_traverse(p);
	cirqueue_in1(p,70);
	cirqueue_traverse(p);
	cirqueue_in1(p,80);
	cirqueue_traverse(p);
	cirqueue_in1(p,90);
	cirqueue_traverse(p);
	cirqueue_in1(p,100);
	cirqueue_traverse(p);


	printf("cirqueue length is %d\n",cirqueue_length(p));
	cirqueue_traverse(p);
	
	//清空循环队列
    cirqueue_clear(p);
	printf("cirqueue length is %d\n",cirqueue_length(p));
	
	//销毁循环队列
	cirqueue_destroy(p);
	p =  NULL;

	return 0;
}
