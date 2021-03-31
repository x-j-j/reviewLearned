//
//  Hash_Separate.cpp
//  Data Structures and Algorithm Analysis
//
//  Created by 肖子健  on 2019/8/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "Hash_Separate.hpp"
int isPrime(int x);
int NextPrime(int tableSize)
{
    while(1)
    {
        if(isPrime(tableSize))
            return tableSize;
        else
            tableSize++;
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


int Hash(ElementType key,int tableSize)
{
    return key%tableSize;
}


HashTable
InitializeTable(int TableSize)
{
    HashTable H;
    int i;
    if(TableSize<MinTableSize)
    {
        printf("Table sine too small");
        return NULL;
    }
    H=new HashTbl;
    if(H==NULL)
    {
        printf("out of pace!!");
        return NULL;
    }
    H->TableSize=NextPrime(TableSize);
    H->TheLists=new List[TableSize];
    if(H->TheLists==NULL)
    {
        printf("out of space!!");
        return NULL;
    }
    for(i=0;i<H->TableSize;++i)
    {
        H->TheLists[i]=new ListNode;
        if(H->TheLists[i]==NULL)
        {
            printf("out of space!!");
            return NULL;
        }
        else
            H->TheLists[i]->Next=NULL;
    }
    return H;
}

Position
Find(ElementType Key, HashTable H)
{
    Position P;
    List L;
    
    L=H->TheLists[Hash(Key, H->TableSize)];
    P=L->Next;
    while(P)
    {
        if(P->Element==Key)
            return P;
        P=P->Next;
    }
    return NULL;
}

void insert(ElementType Key, HashTable H)
{
    Position Pos,NewCell;
    List L;
    Pos=Find(Key, H);
    if(Pos==NULL)//always true
    {
        NewCell=new ListNode;
        if(NewCell==NULL)
        {
            printf("out of space");
            exit(-1);
        }
        else
        {
            L=H->TheLists[Hash(Key, H->TableSize)];
            NewCell->Next=L->Next;
            NewCell->Element=Key;
            L->Next=NewCell;
        }
    }
}

int Delete(ElementType Key, HashTable H)
{
    Position Pos,h,L;
    L=H->TheLists[Hash(Key, H->TableSize)];
    h=L->Next;
    while(h!=NULL&&h->Next&&h->Next->Element!=Key)
        h=h->Next;
    if(h==NULL)
    {
        printf("Can not find tne key!");
        return 0;
    }
    else
    {
        Pos=h->Next;
        h->Next=Pos->Next;
        delete Pos;
        return 1;
    }
}

void DestoryTable(HashTable H)
{
    Position h,P,Q;
    for(int i=0;i<H->TableSize;++i)
    {
        h=H->TheLists[i];
        P=h->Next;
        while(P)
        {
            Q=P->Next;
            if(!Q)
            {
                delete P;
                P=NULL;
            }
            else
            {
                delete P;
                P=Q;
            }
        }
    }
}
