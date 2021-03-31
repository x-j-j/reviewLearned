//
//  list.cpp
//  Data Structures and Algorithm Analysis
//
//  Created by 肖子健  on 2019/7/12.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "List.hpp"
List MakeEmpty(List L)
{
    L->Element=0;
    L->Next=0;
    return L;
}
int IsEmpty(List L)
{
    return L->Next==NULL;
}


int IsLast(Position P, List L)
{
    return P->Next==NULL;
}


Position Find(Elementype x, List L)
{
    Position P;
    P=L;
    while(P->Next!=NULL&&P->Element!=x)
        P=P->Next;
    return P;
}


Position FindPrevious(Elementype x, List L)
{
    Position P;
    P=L;
    if(P->Element==x)
        return P;
    else
        while(P->Next->Element!=x&&P->Next!=NULL)
            P=P->Next;
    return P;
}


void Delete(Elementype x, List L)
{
    Position P, TmpCell;
    P=FindPrevious(x, L);
    if(!IsLast(P, L))
    {
        TmpCell=P->Next;
        P->Next=TmpCell->Next;
        free(TmpCell);
    }
}


void insert(Elementype x,List L,Position P)
{
    Position TmpCell;
    TmpCell=new Node;
    if(TmpCell==NULL)
    {
        cout<<"Out of space!!";
        return;
    }
    TmpCell->Element=x;
    TmpCell->Next=P->Next;
    P->Next=TmpCell;
}


void DeleteList(List L)
{
    Position P;
    P=L->Next;
    L->Next=NULL;
    while(P!=NULL)
    {
        free(P);
        P=P->Next;
    }
}


