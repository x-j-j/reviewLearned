//
//  Prim.cpp
//  Data Structures and Algorithm Analysis
//
//  Created by 肖子健  on 2019/9/17.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "Prim.hpp"
Graph::Graph(int numV)
{
    while(numV<=0)
    {
        cout<<"输入不对，重输";
        cin>>numV;
    }
    this->numV=numV;
    
}
