//
//  LeftHeap.cpp
//  Data Structures and Algorithm Analysis
//
//  Created by 肖子健  on 2019/8/11.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "LeftHeap.hpp"
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    ElementType Element;
    PriorityQueue Left;
    PriorityQueue Right;
    int Npl;
};

PriorityQueue Intialize(void)
{
    return NULL;
}

int IsEmpty(PriorityQueue H)
{
    return H==NULL;
}

ElementType FindMin(PriorityQueue H)
{
    if(IsEmpty(H))
    {
        printf("Priority queue is empty!!");
        return -1;
    }
    return H->Element;
}

void SwapChildren(PriorityQueue H)
{
    PriorityQueue tmp;
    tmp=H->Left;
    H->Left=H->Right;
    H->Right=tmp;
}

static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2);

PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2)//Merge和Merge1不是很理解
{
    if(H1==NULL)
        return H2;
    if(H2==NULL)
        return H1;
    if(H1->Element<H2->Element)
        return Merge1(H1, H2);
    else
        return Merge1(H2, H1);
}

static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2)
{
    if(H1->Left==NULL)
        H1->Left=H2;
    else
    {
        H1->Right=Merge(H1->Right, H2);
        if(H1->Left->Npl<H1->Right->Npl)
            SwapChildren(H1);
        H1->Npl=H1->Right->Npl+1;
    }
    return H1;
}

PriorityQueue Insert1(ElementType X, PriorityQueue H)
{
    PriorityQueue SingleNode;
    SingleNode=new TreeNode;
    if(SingleNode==NULL)
    {
        printf("out of pace!!");
        exit(-1);
    }
    else
    {
        SingleNode->Element=X;
        SingleNode->Npl=0;
        SingleNode->Left=SingleNode->Right=NULL;
        H=Merge(SingleNode, H);
    }
    return H;
}

PriorityQueue DeleteMin(PriorityQueue H)
{
    PriorityQueue LeftHeap, RightHeap;
    if(IsEmpty(H))
    {
        printf("Priority queue is empty!");
        return H;
    }
    LeftHeap=H->Left;
    RightHeap=H->Right;
    delete H;
    return Merge(LeftHeap, RightHeap);
}
