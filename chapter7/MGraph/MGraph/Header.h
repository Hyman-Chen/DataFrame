//
//  Header.h
//  MGraph
//
//  Created by Hyman on 2024/2/26.
//

#ifndef Header_h
#define Header_h
#define MaxVertexNum 3
#include <stdlib.h>




// 用邻接矩阵表示图
// 邻接矩阵表示的图适用于存放稠密图，定义图结点时，结构体内有四个数据元素，分别为当前边的条数ne、当前结点数量nv、结点一维数组data和边的二维数组G。
typedef int Vertex;
typedef int DataType;
typedef int WeightType;
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;/* 顶点数 */
    int Ne;/* 边数  */
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data[MaxVertexNum]; /* 存顶点的数据 */
};

typedef PtrToGNode MGraph; /* 以邻接矩阵存储的图类型 */

MGraph CreateGraph(int VertexNum)
{   Vertex V,W;
    MGraph Graph;
    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    /* 注意：这里默认顶点编号从0开始，到9Graph->Nv-1 */
    for (V=0; V<Graph->Nv; V++)
        for (W=0; W<Graph->Nv; W++)
            Graph->G[V][W] = 0;/* 或INFINITY */
    return Graph;
}

// 定义边
typedef struct ENode *PtrToENode;
struct ENode {
    Vertex V1, V2;/* 有向边 */
    WeightType Weight;/* 权重 */
};
typedef PtrToENode Edge;
void InsertEdge( MGraph Graph, Edge E )
{
    Graph->G[E->V1][E->V2] = E->Weight;
    /* 若是无向图，还要插入边<V2,V1> */
    Graph->G[E->V2][E->V1] = E->Weight;
}
/* 输入格式：
 Nv Ne
 V1 V2 Weight
 ......
 */
MGraph BuildGraph(void)
{   MGraph Graph;
    Edge E;
    Vertex V;
    int nv, i;
    Vertex Nv,Ne;
    
    scanf("%d", &Nv);
    Graph = CreateGraph(Nv);
    scanf("%d", &Ne);
    if (Graph->Ne != 0){
        E = (Edge)malloc(sizeof(struct ENode));
        for (i=0;i<Graph->Ne;i++){
            scanf("%d %d %d", &E->V1,&E->V2,&E->Weight);
            InsertEdge(Graph, E);
        }
    }
    
    /* 如果顶点有数据的话，读入数据 */
    for (V=0; V<Graph->Nv;V++)
        scanf(" %d", &(Graph->Data[V]));
    
    return Graph;
    
}

/* 快速建立图的方法
int G[MAXN][MAXN], Nv, Ne;
void Buildgraph()
{
     int i, j, v1, v2, w;
     scanf("%d", &Nv);
     for (i=0;i<Nv;i++)
        for (j=0; j<Nv; j++)
            G[i][j] = 0;
     scanf("%d", &Ne);
     for (i=0; i<Ne; i++){
        scanf('%d %d %d", &v1, &v2, &w);
        G[v1][v2] = w;
        G[v2][v1] = w;
     }
 }
 */




#endif /* Header_h */
