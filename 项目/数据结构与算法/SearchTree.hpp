//
//  tree.hpp
//  Data Structures and Algorithm Analysis
//
//  Created by 肖子健  on 2019/8/9.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef tree_hpp
#define tree_hpp

#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMIn(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);










#endif /* tree_hpp */
