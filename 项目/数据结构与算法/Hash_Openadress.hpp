//
//  Hash_Openadress.hpp
//  Data Structures and Algorithm Analysis
//
//  Created by 肖子健  on 2019/8/11.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef Hash_Openadress_hpp
#define Hash_Openadress_hpp

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int Index;
typedef Index Position;
typedef int ElementType;
#define MINTABLESIZE 5

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTbl InitializeTable(int TableSize);
void DestoryTable(HashTable H);
Position Find(ElementType Key, HashTable);
Position Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P, HashTable H);
HashTable ReHash(HashTable H);
int NextPrime(int TableSize);
int IsPrime(int X);
int Hash(ElementType Key, int TableSize);


enum KindOfEntry{Lehitimate/*正当的*/, Empty, Deleted };
struct HashEntry
{
    ElementType Element;
    enum KindOfEntry Info;
};
typedef struct HashEntry Cell/*单元*/;
struct HashTbl
{
    int TableSize;
    Cell *TheCells;
};



#endif /* Hash_Openadress_hpp */
