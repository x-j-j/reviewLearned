//
//  BFS.cpp
//  Data Structures and Algorithm Analysis
//
//  Created by 肖子健  on 2019/9/11.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "BFS.hpp"
void BFSTraverse(MGraph G)
{
    int v;
    for(v=0; v<G.vexnum; ++v)
        visited[v]=false;
    Queue *Q=InitQueue();
    for(v=0; v<G.vexnum; ++v)
    {
        if(!visited[v])
        {
            visited[v]=true;
            visitVex(G, v);
            EnQueue(Q, G.vexs[v]);
            while(!QueueEmpty(Q))
            {
                int u;
                DeQueue(Q, &u);
                u=LocateVex(&G, u);
                for(int w=FirstAdjVex(G, u); w>0; w=NextAdjVex(G, u, w))
                {
                    if(!visited[w])
                    {
                        visited[w]=true;
                        visitVex(G, w);
                        EnQueue(Q, G.vexs[w]);
                    }
                }
            }
        }
    }
}
Queue* InitQueue()
{
    Queue* Q=new Queue;
    Q->next=NULL;
    return Q;
}
void EnQueue(Queue *Q,VertexType v)
{
    Queue *element=new Queue;
    element->data=v;
    Queue *temp=Q;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=element;
}

void DeQueue(Queue *Q,int *u)
{
    *u=Q->next->data;
    Queue *temp=Q;
    Q=Q->next;
    delete temp;
}

bool QueueEmpty(Queue *Q)
{
    if(Q->next==NULL)
        return true;
    return false;
}
void visitVex(MGraph G, int v)
{
    cout<<G.vexs[v];
}
int FirstAdjVex(MGraph G,int v)
{
    for(int i=0; i<G.vexnum; ++i)
        if(G.arcs[v][i].adj)
            return i;
    return -1;
}
int NextAdjVex(MGraph G,int v,int w)
{
    for(int i=w+1; i<G.vexnum; ++i)
        if(G.arcs[v][i].adj)
            return i;
    return -1;
}
void CreateDN(MGraph *G){
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));
    for (int i=0; i<G->vexnum; i++) {
        scanf("%d",&(G->vexs[i]));
    }
    for (int i=0; i<G->vexnum; i++) {
        for (int j=0; j<G->vexnum; j++) {
            G->arcs[i][j].adj=0;
            G->arcs[i][j].info=NULL;
        }
    }
    for (int i=0; i<G->arcnum; i++) {
        int v1,v2;
        scanf("%d,%d",&v1,&v2);
        int n=LocateVex(G, v1);
        int m=LocateVex(G, v2);
        if (m==-1 ||n==-1) {
            printf("no this vertex\n");
            return;
        }
        G->arcs[n][m].adj=1;
        G->arcs[m][n].adj=1;//无向图的二阶矩阵沿主对角线对称
    }
}
//根据顶点本身数据，判断出顶点在二维数组中的位置
int LocateVex(MGraph * G,VertexType v){
    int i=0;
    //遍历一维数组，找到变量v
    for (; i<G->vexnum; ++i) {
        if (G->vexs[i]==v) {
            break;
        }
    }
    //如果找不到，输出提示语句，返回-1
    if (i>G->vexnum) {
        printf("no such vertex.\n");
        return -1;
    }
    return i;
}
