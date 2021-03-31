//
//  LeftHeap.hpp
//  Data Structures and Algorithm Analysis
//
//  Created by 肖子健  on 2019/8/11.
//  Copyright © 2019 肖子健 . All rights reserved.
//
typedef int ElementType;
#ifndef LeftHeap_hpp
#define LeftHeap_hpp


struct TreeNode;
typedef struct TreeNode *PriorityQueue;
PriorityQueue Initialize(void);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);

#define Insert(X, H)(H=Insert1((X), H))

PriorityQueue Insert1(ElementType X, PriorityQueue H);
PriorityQueue DeleteMin(PriorityQueue H);

#endif /* LeftHeap_hpp */
