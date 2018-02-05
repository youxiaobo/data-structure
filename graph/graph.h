#ifndef _GRAPH_H_
#define _GRAPH_H_

#define MAXN 9 //最大顶点数
typedef int vtype;//顶点数据类型
typedef char adjtype;//邻接矩阵数据类型
typedef struct{
	vtype V[MAXN];//顶点存储空间
	adjtype A[MAXN][MAXN]; //邻接矩阵存储空间
}graph,*graph_t;

graph_t graph_create();
int graph_adjmatrix_print(graph_t g);
int find_next_adj(graph_t g,int v);
int graph_traverse_DFS(graph_t g,int v);
int graph_traverse_BFS(graph_t g,int v);
#endif
