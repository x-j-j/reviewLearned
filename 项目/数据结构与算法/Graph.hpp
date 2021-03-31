//
//  Graph.hpp
//  Data Structures and Algorithm Analysis
//
//  Created by 肖子健  on 2019/9/9.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp
#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX_VERtX_NUM 20
#define  MAX_VERTEX_NUM 20
#define VRType int
#define InfoType char
#define VertexType int
typedef enum{DG/*有向图*/, DN/*无向图*/, UDG/*有向网*/, UDN/*无向网*/}Graphkind;
typedef struct
{
    VRType adj;//无权图01代表两点是否相连，有权图代表权值
    InfoType *info;//对弧或者边额外含有的信息指针
}ArcCell, AdjMatrix[MAX_VERtX_NUM][MAX_VERtX_NUM];
typedef struct
{
    VertexType vexs[MAX_VERtX_NUM];
    AdjMatrix arcs;
    int vexnum, arcnum;//定点数，弧的个数
    Graphkind kind;
}MGraph;




typedef struct ArcBox
{
    int tailvex,headvex;//弧尾、弧头对应顶点在数组中的位置下标
    struct ArcBox *hlik,*tlink;//分别指向弧头相同和弧尾相同的下一个弧
    InfoType *info;//存储弧相关信息的指针
}ArcBox;//弧的容器

typedef struct VexNode
{
    VertexType data;//顶点的数据域
    ArcBox *firstin,*firstout;//指向以该顶点为弧头和弧尾的链表首个结点
}VexNode;//顶点

typedef struct
{
    VexNode xlist[MAX_VERTEX_NUM];//存储顶点的一维数组
    int vexnum,arcnum;//记录图的顶点数和弧数
}OLGraph;




int LocateVex(MGraph *G, VertexType v);//根据z数据本身，判断定点在二维数组中的位置
int LocateVex(OLGraph *G, VertexType v);
void CreateDG(MGraph *G);
void CreateDN(MGraph *G);
void CreateUDG(MGraph *G);
void CreateUDN(MGraph *G);
void CreateDG(OLGraph *G);





#endif /* Graph_hpp */
