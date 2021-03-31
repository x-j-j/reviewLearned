//
//  Hash_Separate.hpp
//  Data Structures and Algorithm Analysis
//
//  Created by 肖子健  on 2019/8/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef Hash_Separate_hpp
#define Hash_Separate_hpp

#include <stdio.h>
#include <stdlib.h>
#define MinTableSize 10
struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;
typedef int ElementType;


HashTable InitializeTable(int TableSize);
void DestoryTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P);
int Delete(ElementType Key, HashTable H);
void DestoryTable(HashTable H);



struct ListNode
{
    ElementType Element;
    Position Next;
};

typedef Position List;

struct HashTbl
{
    int TableSize;
    List *TheLists;
};


#endif /* Hash_Separate_hpp */
