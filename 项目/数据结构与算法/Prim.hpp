//
//  Prim.hpp
//  Data Structures and Algorithm Analysis
//
//  Created by 肖子健  on 2019/9/17.
//  Copyright © 2019 肖子健 . All rights reserved.
//


//最小生成树，通过从指定点寻找相连的边为最小权值的邻接点
#ifndef Prim_hpp
#define Prim_hpp
#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXWEIGHT 100


typedef struct
{
    int tail;
    int head;
}Edge;//边


typedef struct
{
    int adjvex;//邻接点
    int weight;//权值
}CloseEdge;//最近边


class Graph
{
public:
    Graph(int numV);//建图
    void creatGraph(int numE);
    ~Graph();
    
    void Prim(int);
    int minEdgeVEx(CloseEdge*, bool*);
    void updateCloseEdge(CloseEdge*, bool*, int);
    
    void printAdjacentMatrix();//打印邻接矩阵
    bool check(int, int, int);//检查输入
    
    
private:
    int numV;//顶点数
    int numE;//边数
    int **matrix;//邻接矩阵
};

#endif /* Prim_hpp */
