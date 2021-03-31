//
//  Hash_Openadress.cpp
//  Data Structures and Algorithm Analysis
//
//  Created by 肖子健  on 2019/8/11.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "Hash_Openadress.hpp"
HashTable initializeTable(int TableSize)
{
    HashTable Table;
    if(TableSize<MINTABLESIZE)
    {
        printf("Table size is too small!!");
        exit(-1);
    }
    Table=new HashTbl;
    if(Table==NULL)
    {
        printf("out of pace!!");
        exit(-1);
    }
    Table->TableSize=NextPrime(TableSize);
    Table->TheCells=new Cell[TableSize];
    if(Table->TheCells==NULL)
    {
        printf("out of pace!!");
        exit(-1);
    }
    for(int i=0;i<Table->TableSize;++i)
    {
        Table->TheCells[i].Info=Empty;
    }
    return Table;
}

Position
Find(ElementType Key, HashTable H)
{
    Position CurrentPos;
    int CollisionNum=0;//冲突的个数
    
    CurrentPos=Hash(Key,H->TableSize);
    while(H->TheCells[CurrentPos].Info!=Empty&&H->TheCells[CurrentPos].Element!=Key)//如果有Key但是先找到了Empty怎么办
    {//平方探测
        CurrentPos+=2*++CollisionNum-1;
        if(CurrentPos>=H->TableSize)
            CurrentPos-=H->TableSize;
    }
    return CurrentPos;
}

void insert(ElementType Key, HashTable H)
{
    Position Pos;
    Pos=Find(Key,H);
    if(H->TheCells[Pos].Info!=Lehitimate)
    {
        H->TheCells[Pos].Info=Lehitimate;
        H->TheCells[Pos].Element=Key;
    }
}

HashTable ReHash(HashTable H)
{
    int i, OldSize;
    Cell *OldCells;
    
    OldCells=H->TheCells;
    OldSize=H->TableSize;
    
    H=initializeTable(2*OldSize);
    for(i=0;i<OldSize;++i)
    {
        if(OldCells[i].Info==Lehitimate)
            insert(OldCells[i].Element, H);
    }
    free(OldCells);
    return H;
}

int Delete(ElementType Key, HashTable H)
{
    Position Pos;
    Pos=Find(Key,H);
    if(H->TheCells[Pos].Info==Empty)
        return 0;
    else
    {
        H->TheCells[Pos].Info=Deleted;
        return 1;
    }
}

int isPrime(int x)
{
    int i;
    for(i=2;i*i<=x;i++)
    {
        if(x%i==0)
            return 0;
    }
    return 1;
}

int nextPrime(int tableSize)
{
    while(1)
    {
        if(isPrime(tableSize))
            return tableSize;
        else
            tableSize++;
    }
}

int Hash(ElementType Key, int TableSize)
{
    return Key%TableSize;
}
