//
//  list.hpp
//  Data Structures and Algorithm Analysis
//
//  Created by 肖子健  on 2019/7/12.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef list_hpp
#define list_hpp

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef int Elementype;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node
{
    Elementype Element;
    Position Next;
};

List MakeEmpty(List L);//初始化
int IsEmpty(List L);//测试链表是否是空表
int IsLast(Position P,List L);//测试当前位置是否是链表末尾
Position Find(Elementype x,List L);//find
void Delete(Elementype x,List L);//delete
Position FindPrevious(Elementype x,List L);//findprevious
void Insert(Elementype x,List L,Position P);//位置P后面插入
void Deletelist(List L);//deletelist
Position Header(List L);//
Position First(List L);
Position Advance(Position P);
Elementype Retrieve(Position P);



#endif /* list_hpp */
