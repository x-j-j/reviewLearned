//
//  Heap.hpp
//  Data Structures and Algorithm Analysis
//
//  Created by 肖子健  on 2019/8/11.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef Heap_hpp
#define Heap_hpp

#define MinPQSize 10
#define MinData 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;
typedef int ElementType;


PriorityQueue Initialize(int MaxElements);
void Destory(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
PriorityQueue MakeEmpty(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

#endif /* Heap_hpp */

struct HeapStruct
{
    int Capacity;
    int Size;
    ElementType *Elements;
};
