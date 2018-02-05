#include <stdio.h>
#include "graph.h"
#include "debug.h"
extern int flag[MAXN];
int main(int argc, const char *argv[])
{
	//创建图
	graph_t g = NULL;
	g = graph_create();
	if(g == NULL)
	{
		DEBUG_CUSTOMERR("malloc error");
		return -1;
	}

	//邻接矩阵打印
	graph_adjmatrix_print(g);

	//深度优先搜索遍历
	graph_traverse_DFS(g,0);
	printf("\n");

	//清空一下标记数组
	//memset(flag,0,MAXN)这样写是错误的
	memset(flag,0,sizeof(flag));
	
	//广度优先搜索遍历
	graph_traverse_BFS(g,0);
	printf("\n");

	return 0;
}
