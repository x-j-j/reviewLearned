//
//  queue.hpp
//  Data Structures and Algorithm Analysis
//
//  Created by 肖子健  on 2019/8/9.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef queue_hpp
#define queue_hpp

#include <stdlib.h>
#include <stdio.h>
struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef int ElementType;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);



#define MinQueueSize 5

struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};


static int
Succ(int Value, Queue Q)//环形队列判断
{
    if(++Value==Q->Capacity)
        Value=0;
    return Value;
}

#endif /* queue_hpp */
