//
//  BFS.hpp
//  Data Structures and Algorithm Analysis
//
//  Created by 肖子健  on 2019/9/11.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef BFS_hpp
#define BFS_hpp
#include <iostream>
#include <stdio.h>

using namespace std;
#define MAX_VERtEX_NUM 20                   //顶点的最大个数
#define VRType int                          //表示顶点之间的关系的变量类型
#define InfoType char                       //存储弧或者边额外信息的指针变量类型
#define VertexType int                      //图中顶点的数据类型
bool visited[MAX_VERtEX_NUM];               //设置全局数组，记录标记顶点是否被访问过
typedef struct Queue
{
    VertexType data;
    struct Queue *next;
}Queue;
typedef struct {
    VRType adj;                             //对于无权图，用1或0表示是否相邻；对于带权图，直接为权值。
    InfoType * info;                        //弧或边额外含有的信息指针
}ArcCell,AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];
typedef struct {
    VertexType vexs[MAX_VERtEX_NUM];        //存储图中顶点数据
    AdjMatrix arcs;                         //二维数组，记录顶点之间的关系
    int vexnum,arcnum;                      //记录图的顶点数和弧（边）数
}MGraph;


void BFSTraverse(MGraph G);
void visitVex(MGraph G, int v);
int NextAdjVex(MGraph G,int v,int w);
int FirstAdjVex(MGraph G,int v);
void CreateDN(MGraph *G);
int LocateVex(MGraph * G,VertexType v);
Queue *InitQueue();//初始化队列
void EnQueue(Queue *Q,VertexType v);//顶点元素v进队列
void DeQueue(Queue *Q,int *u);//队头元素出队列
bool QueueEmpty(Queue *Q);//判断队列是否为空



#endif /* BFS_hpp */
