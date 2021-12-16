//用邻接矩阵存储图
#include<stdio.h>
#include<stdlib.h>
#define MAX_NODES_NUM 20
#define OVERFLOW -2
typedef char ElemType;
typedef char InfoType;
typedef enum{
	DG,DNG,UDG,UDN//有向图，无向图，有向网，无向网
} GraphType;
typedef struct{
	InfoType* info;//存边相关的信息
	int value;//存权值或者存是否存在的flag
}EdgeMatrix[MAX_NODES_NUM][MAX_NODES_NUM];
typedef struct{
	ElemType nodes[MAX_NODES_NUM];
	EdgeMatrix edges;
	GraphType gt;//图的类型
	int nodes_num,edges_num;//图的当前顶点数和弧数
}Graph;

int locates(Graph* g_add,ElemType e){
	for(int i=0;i<g_add->nodes_num;i++){
		if(g_add->nodes[i]==e){
			return i;
		}
	}
	return -1;
}

//构造一个无向网
void create_udn(Graph* g_add){
	char bc,ec;
	int bi,ei,value;
	
	//为图结构中的每块内存赋初值
	scanf("%d %d",&(g_add->nodes_num),&(g_add->edges_num));
	getchar();
	g_add->gt = UDN;
	for(int i=0;i<g_add->nodes_num;i++){
		scanf("%c",g_add->nodes+i);
		getchar();
	}
	for(int i=0;i<g_add->nodes_num;i++){
		for(int j=0;j<g_add->nodes_num;j++){
			g_add->edges[i][j].value = 0;
			g_add->edges[i][j].info = NULL;
		}
	}
	for(int i=0;i<g_add->edges_num;i++){
		scanf("%c %c %d",&bc,&ec,&value);
		getchar();
		bi = locates(g_add,bc);
		ei = locates(g_add,ec);
		g_add->edges[bi][ei].value = g_add->edges[ei][bi].value = value;//注意一次要给两个位置赋值，无向图的邻接矩阵是对称的
	}
}



void print_graph(Graph* g_add){
	for(int i=0;i<g_add->nodes_num;i++){
		printf("%c\t",g_add->nodes[i]);
	}
	printf("\n");
	for(int i=0;i<g_add->nodes_num;i++){
		for(int j=i+1;j<g_add->nodes_num;j++){
			if(g_add->edges[i][j].value){
				printf("%c---%c:%d\t",g_add->nodes[i],g_add->nodes[j],g_add->edges[i][j].value);
			}
		}
	}
	printf("\n");
}

int main(){
	Graph* g_add = (Graph*)malloc(sizeof(Graph));
	if(!g_add)
		exit(OVERFLOW);
	create_udn(g_add);
	print_graph(g_add);
	return 0;
}







