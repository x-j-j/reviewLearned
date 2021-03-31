//
//  stack.cpp
//  Data Structures and Algorithm Analysis
//
//  Created by 肖子健  on 2019/7/12.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "Stack.hpp"//感觉栈的顶端有一个盖子

int IsEmpty(Stack S)
{
    return S->Next==NULL;
}


Stack CreateStack(void)
{
    Stack S;
    S=new Node;
    if(S==NULL)
    {
        printf("Out of pace!!");
        return NULL;
    }
    S->Next=NULL;
    MakeEmpty(S);
    return S;
}

void MakeEmpty(Stack S)
{
    if(S==NULL)
    {
        printf("must creat first");
        return;
    }
    else
        while(!IsEmpty(S))
            Pop(S);
}

void Pop(Stack S)
{
    PtrToNode FirstCell;
    if(IsEmpty(S))
        printf("Empty stack");
    else
    {
        FirstCell=S->Next;
        S->Next=S->Next->Next;
        free(FirstCell);
    }
}

void Push(ElementType X, Stack S)
{
    PtrToNode TmpCell;
    TmpCell=new Node;
    if(TmpCell==NULL)
    {
        printf("must creat first");
        return;
    }
    else
    {
        TmpCell->Element=X;
        TmpCell->Next=S->Next;
        S->Next=TmpCell;
    }
}

ElementType Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Next->Element;
    printf("Empty stack");
    return 0;
}
