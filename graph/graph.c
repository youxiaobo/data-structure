#include <stdlib.h>
#include "graph.h"
#include "debug.h"
#include "linkqueue.h"
/* 使用示例
  [0 1]
  [0 2]
  [1 3]
  [1 5]
  [2 6]
  [2 7]
  [3 4]
  [4 5]
  [4 8]
  [6 7]
  #
 * */
int flag[MAXN] = {0};//标记顶点是否访问数组
/*
 * 创建图
 * 邻接矩阵表示法
 * */
graph_t graph_create()
{
	int i,j,m,n;
	graph_t g = NULL;

	//动态申请空间
	g = (graph_t)malloc(sizeof(graph));
	if(g == NULL)
	{
		DEBUG_CUSTOMERR("malloc error");
		return NULL;
	}

	//输入邻接矩阵，这里是无向图，最后输入一个字符即可结束
	while(scanf("[%d %d]",&m,&n) == 2)
	{
		getchar();//吃掉回车符
		g->A[m][n] = 1;
		g->A[n][m] = 1;//无向图对称，有向图该句可以省略

	}

	//为剩下的位置赋值
	for(i=0; i<MAXN; i++)
	{
		for(j=0; j<MAXN; j++)
		{
			if(g->A[i][j] != 1)
			{
				g->A[i][j] = 0;
			}
		}
	}

	//为顶点赋初值
	for(i=0; i<MAXN; i++)
	{
		g->V[i] = 'a'+i;
	}
	return g;
}

/*
 * 图的邻接矩阵打印
 * */
int graph_adjmatrix_print(graph_t g)
{
	int i,j;
	for(i=0; i<MAXN; i++)
	{
		for(j=0; j<MAXN; j++)
		{
			printf("%d ",g->A[i][j]);
		}
		printf("\n");
	}
	return 0;
}

/*
 * 找下一个邻接点
 * 输入参数是顶点的下标位置
 * */
int find_next_adj(graph_t g,int v)
{
	int i;

	for(i=v+1; i<MAXN; i++)
	{
		//如果存在关系，且没有被访问过，返回邻结点的位置
		if(g->A[v][i] == 1 && flag[i] == 0)
		{
			return i;
		}
	}

	//没有找到返回-1
	return -1;
	
}

/*
 * 深度优先搜索遍历
 * 需要输入从哪个结点开始搜索
 * 其中注释的打印信息可帮助理解程序运行流程
 * */
int graph_traverse_DFS(graph_t g,int v)
{

	//访问结点
	printf("%d %c \n",v,g->V[v]);

	//标记已经访问
	flag[v] = 1;
	
	vtype u,tmp;
	//找到该结点的邻接点
	u = find_next_adj(g,v);
	//printf("u = %d\n",u);

	//如果找到了邻接点
	while(u >= 0)
	{
		//递归使用DFS：访问结点并搜索邻结点
		graph_traverse_DFS(g,u);
	
		//寻找该结点的其他未访问的邻结点，输入参数是v,输出参数是u，再根据u的值循环
		//递归进去后一层一层出来，刚好保留了结点的位置，这里的关键就是使用v和u
	//	printf("v=%d\n",v);
		u = find_next_adj(g,v);
	//	printf("u = %d\n",u);
		
	}
	return 0;

}



/*
 * 广度优先搜索遍历
 * 使用队列入队和出队
 * */
int graph_traverse_BFS(graph_t g,int v)
{
	linkqueue_t lq = NULL;	
	datatype data;
	int u;

	//创建队列
	lq = linkqueue_create();
	if(lq == NULL)
	{
		DEBUG_CUSTOMERR("linkqueue create error");
		return -1;
	}

	//顶点下标入队
	linkqueue_in(lq,v);

	//标记即将访问
	flag[v] = 1;

	//如果队列不为空
	while(!linkqueue_is_empty(lq))
	{
		//顶点下标出队
		data = linkqueue_out(lq);

		//访问该顶点
		printf("%d %c\n",data,g->V[data]);

		//找出出队顶点的所有未访问的邻结点
		while((u = find_next_adj(g,data)) != -1)
		{
			//顶点下标入队
			linkqueue_in(lq,u);
			//标记即将访问，在这里标记上，避免下一次找邻结点由于未标记又找到重复的邻结点
			flag[u] = 1;
		}
	}
	return 0;
}
