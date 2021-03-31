//
//  Graph.cpp
//  Data Structures and Algorithm Analysis
//
//  Created by 肖子健  on 2019/9/9.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "Graph.hpp"
int LocateVex(MGraph *G, VertexType v)
{
    int i=0;
    for(; i<G->vexnum; ++i)
        if(G->vexs[i]==v)
            break;
    if(i>G->vexnum)
        return -1;
    return i;
}
int LocateVex(OLGraph *G, VertexType v)
{
    int i=0;
    for(; i<G->vexnum; ++i)
        if(G->xlist[i].data==v)
            break;
    if(i>G->vexnum)
        return -1;
    return i;
}
void CreateDG(MGraph *G)
{
    cin>>G->vexnum>>G->arcnum;
    for(int i=0; i<G->vexnum; ++i)
        cin>>G->vexs[i];
    for(int i=0; i<G->vexnum; ++i)
        for(int j=0; j<G->vexnum; ++j)
        {
            G->arcs[i][j].adj=0;
            G->arcs[i][j].info=nullptr;
        }
    for(int i=0; i<G->arcnum; ++i)
    {
        int v1, v2;
        cin>>v1>>v2;//弧尾， 弧头
        int n=LocateVex(G, v1);
        int m=LocateVex(G, v2);
        if(m==-1||n==-1)
            return;
        G->arcs[n][m].adj=1;
    }
}
void CreateDN(MGraph *G)
{
    cin>>G->vexnum>>G->arcnum;
    for(int i=0; i<G->vexnum; ++i)
        cin>>G->vexs[i];
    for(int i=0; i<G->vexnum; ++i)
        for(int j=0; j>G->vexnum; ++j)
        {
            G->arcs[i][j].adj=0;
            G->arcs[i][j].info=nullptr;
        }
    for(int i=0; i<G->arcnum; ++i)
    {
        int v1, v2;
        cin>>v1>>v2;
        int n=LocateVex(G, v1);
        int m=LocateVex(G, v2);
        if(m==-1||n==-1)
            return;
        G->arcs[n][m].adj=1;
        G->arcs[m][n].adj=1;
    }
}
void CreateUDG(MGraph *G)
{
    cin>>G->vexnum>>G->arcnum;
    for(int i=0; i<G->vexnum; ++i)
        cin>>G->vexs[i];
    for(int i=0; i<G->vexnum; ++i)
        for(int j=0; j<G->vexnum; ++j)
        {
            G->arcs[i][j].adj=0;
            G->arcs[i][j].info=nullptr;
        }
    for(int i=0; i<G->arcnum; ++i)
    {
        int v1, v2, w;
        cin>>v1>>v2>>w;//弧尾， 弧头, 权值
        int n=LocateVex(G, v1);
        int m=LocateVex(G, v2);
        if(m==-1||n==-1)
            return;
        G->arcs[n][m].adj=w;
    }
}
void CreateUDN(MGraph *G)
{
    cin>>G->vexnum>>G->arcnum;
    for(int i=0; i<G->vexnum; ++i)
        cin>>G->vexs[i];
    for(int i=0; i<G->vexnum; ++i)
        for(int j=0; j>G->vexnum; ++j)
        {
            G->arcs[i][j].adj=0;
            G->arcs[i][j].info=nullptr;
        }
    for(int i=0; i<G->arcnum; ++i)
    {
        int v1, v2, w;
        cin>>v1>>v2>>w;
        int n=LocateVex(G, v1);
        int m=LocateVex(G, v2);
        if(m==-1||n==-1)
            return;
        G->arcs[n][m].adj=w;
        G->arcs[m][n].adj=w;
    }
}
void CreateGraph(MGraph *G){
    //选择图的类型
    scanf("%d",&(G->kind));
    //根据所选类型，调用不同的函数实现构造图的功能
    switch (G->kind) {
        case DG:
            return CreateDG(G);
            break;
        case DN:
            return CreateDN(G);
            break;
        case UDG:
            return CreateUDG(G);
            break;
        case UDN:
            return CreateUDN(G);
            break;
        default:
            break;
    }
}
//构建十字链表函数
void CreateDG(OLGraph *G){
    //输入有向图的顶点数和弧数
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));
    //使用一维数组存储顶点数据，初始化指针域为NULL
    for (int i=0; i<G->vexnum; i++) {
        scanf("%d",&(G->xlist[i].data));
        G->xlist[i].firstin=NULL;
        G->xlist[i].firstout=NULL;
    }
    //构建十字链表
    for (int k=0;k<G->arcnum; k++) {
        int v1, v2;
        scanf("%d, %d", &v1, &v2);
        //确定v1、v2在数组中的位置下标
        int i=LocateVex(G, v1);
        int j=LocateVex(G, v2);
        //建立弧的结点
        ArcBox * p=(ArcBox*)malloc(sizeof(ArcBox));
        p->tailvex=i;
        p->headvex=j;
        //采用头插法插入新的p结点
        p->hlik=G->xlist[j].firstin;
        p->tlink=G->xlist[i].firstout;
        G->xlist[j].firstin=G->xlist[i].firstout=p;
    }
}
