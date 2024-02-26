//
//  Header.h
//  LGraph
//
//  Created by Hyman on 2024/2/26.
//
#include <stdlib.h>
#ifndef Header_h
#define Header_h
#define MaxVertexNum 10

typedef int DataType;
typedef int Vertex;
typedef int WeightType;
typedef struct VNode *PtrToVNode;

// 链表中结点
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
    Vertex AdjV; /* 邻接点下标 */
    WeightType Weight;
    PtrToAdjVNode Next;
};

// 某个节点在数组中的位置
typedef struct VNode{
    PtrToAdjVNode FirstEdge;// 数组所存储结点所连接的结点形成的链表
    DataType Data;
} AdjList[MaxVertexNum];

// 图结点
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;// 顶点个数
    int Ne;// 边的条数
    AdjList G;// 存图结点的数组
};
typedef PtrToGNode LGraph;

// LGraph 初始化
typedef int Vertex;
LGraph CreateGraph( int VertexNum )
{
    Vertex V, W;
    LGraph Graph;
    Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    
    for (V=0; V<Graph->Nv;V++)
        Graph->G[V].FirstEdge = NULL;
    return Graph;
}

// 创建边
typedef struct ENode{
    Vertex V1,V2;
    WeightType Weight;
}*Edge;
// 插入边
void InsertEdge (LGraph Graph, Edge E)
{
    PtrToAdjVNode NewNode;
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;
    /* 将V2插入V1的表头 */
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;
    
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V1;
    NewNode->Weight = E->Weight;
    /* 将V1插入V2的表头 */
    NewNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;
    
    
}
#endif /* Header_h */
