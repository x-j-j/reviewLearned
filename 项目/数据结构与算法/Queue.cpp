//
//  queue.cpp
//  Data Structures and Algorithm Analysis
//
//  Created by 肖子健  on 2019/8/9.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "Queue.hpp"


int IsEmpty(Queue Q)
{
    return Q->Size==0;
}

void MakeEmpty(Queue Q)
{
    Q->Size=0;
    Q->Front=1;
    Q->Rear=0;
}

int IsFull(Queue Q)
{
    return Q->Capacity==Q->Size;
}

void Enqueue(ElementType X, Queue Q)
{
    if(IsFull(Q))
    {
        printf("Queue is full");
    }
    else
    {
        ++Q->Size;
        Q->Rear=Succ(Q->Rear+1, Q);
        Q->Array[Q->Rear]=X;
    }
}

void Dequeue(Queue Q)
{
    if(Q->Size==0)
    {
        printf("Queue is empty!");
    }
    else
    {
        --Q->Size;
        Q->Front=Succ(Q->Front+1, Q);
    }
}

Queue CreatQueue(int MaxElement)
{
    Queue Q;
    if(MaxElement<MinQueueSize)
    {
        printf("Queue size is too small");
        return NULL;
    }
    Q=new QueueRecord;
    if(Q==NULL)
    {
        printf("out of pace!!");
        return NULL;
    }
    Q->Array=new ElementType[MaxElement];
    if(Q->Array==NULL)
    {
        printf("out of pace!!");
        return NULL;
    }
    Q->Capacity=MaxElement;
    MakeEmpty(Q);
    return Q;
}

void DisposeQueue(Queue Q)
{
    delete Q->Array;
    delete Q;
}
