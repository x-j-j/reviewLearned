//
//  Heap.cpp
//  Data Structures and Algorithm Analysis
//
//  Created by 肖子健  on 2019/8/11.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "Heap.hpp"
PriorityQueue MakeEmpty(PriorityQueue H)
{
    if(H==NULL){
        cout<<"the Heap is empty";
        return NULL;
    }else{
        H->Capacity=0;
        H->Size=0;
        H->Elements=0;
    }
    return NULL;
}
int IsEmpty(PriorityQueue H)
{
    return H->Size==0;
}
int IsFull(PriorityQueue H)
{
    return H->Size==H->Capacity;
}
PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue H;
    if(MaxElements<MinPQSize)
    {
        printf("Priority queue size is too small");
    }
    H=new HeapStruct;
    if(H==NULL)
    {
        printf("out of pace!!");
        exit(-1);
    }
    H->Elements=new ElementType[MaxElements+1];
    if(H->Elements==NULL)
    {
        printf("out of pace!!");
        exit(-1);
    }
    H->Capacity=MaxElements;
    H->Size=0;
    H->Elements[0]=MinData;
    return H;
}

void Insert(ElementType X, PriorityQueue H)
{
    int i;
    if(IsFull(H))
    {
        printf("Priority queue is full!!");
        return;
    }
    for(i=++H->Size;H->Elements[i/2]>X;i/=2)
        H->Elements[i]=H->Elements[i/2];
    H->Elements[i]=X;
}

ElementType
DeleteMin(PriorityQueue H)
{
    int i, Child;
    ElementType MinElement, LastElement;
    if(IsEmpty(H))
    {
        printf("Priority queue is empty!!");
        return H->Elements[0];
    }
    MinElement=H->Elements[1];
    LastElement=H->Elements[--H->Size];
    for(i=1;i*2<=H->Size;i=Child)
    {
        Child=i*2;
        if(Child!=H->Size&&H->Elements[Child+1]<H->Elements[Child])
        {
            ++Child;
        }
        if(LastElement>H->Elements[Child])
            H->Elements[i]=H->Elements[Child];
        else
            break;
    }
    H->Elements[i]=LastElement;
    return MinElement;
}
