//
//  stack.hpp
//  Data Structures and Algorithm Analysis
//
//  Created by 肖子健  on 2019/7/12.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;


int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

#endif /* stack_hpp */
struct Node
{
    ElementType Element;
    PtrToNode Next;
};
