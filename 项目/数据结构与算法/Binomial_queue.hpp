//
//  Binomial_queue.hpp
//  Data Structures and Algorithm Analysis
//
//  Created by 肖子健  on 2019/8/11.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef Binomial_queue_hpp
#define Binomial_queue_hpp
typedef int ElementType;
extern  ElementType const ILLEGAL_VALUE;
extern  ElementType const INT_MIN;

typedef struct BinNode *Position, *BinTree;
typedef struct Collection *BinQueue;
#define MaxTrees 100
#define Capacity 200

int IsEmpty(BinQueue H);
BinQueue Initialize();
BinTree CombineTrees(BinTree T1, BinTree T2);
BinQueue Merge(BinQueue H1, BinQueue H2);
ElementType DeleteMin(BinQueue H);

struct BinNode
{
    ElementType Element;
    Position LeftChild;//第一个孩子
    Position NextSibling;//右兄弟
};

struct Collection
{
    int CurrentSize;
    BinTree TheTrees[MaxTrees];
};





#endif /* Binomial_queue_hpp */
