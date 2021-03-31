//
//  ConnectXZJ.cpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "ConnectXZJ.hpp"
long ConnectQQ(const method me, long digital)
{
    std::shared_ptr<Connect> con=std::make_shared<Connect>();
    std::string mee("ID");
    do{
        switch (me) {
            case ID:
                while(!con->searchQQID(digital))
                {
                    std::cout<<"没有这个QQID，重输:";
                    std::cin>>digital;
                }
                return digital;
                break;
            case number:
                while(!con->searchQQNum(digital))
                {
                    std::cout<<"没有这个QQ号，重输:";
                    std::cin>>digital;
                }
                return digital;
            default:
                std::cout<<"只能选择输入ID或者number"<<std::endl
                <<"重输:";
                std::cin>>mee;
                break;
        }
    }while(mee!="ID"||mee!="number");
    return 0;
}
long ConnectWC(const method me, long digital)
{
    std::shared_ptr<Connect> con=std::make_shared<Connect>();
    std::string mee("ID");
    do{
        switch (me) {
            case ID:
                while(!con->searchWCID(digital))
                {
                    std::cout<<"没有这个微信ID，重输:";
                    std::cin>>digital;
                }
                return digital;
                break;
            case number:
            default:
                std::cout<<"只能选择输入ID"<<std::endl
                <<"重输:";
                std::cin>>mee;
                break;
        }
    }while(mee!="ID");
    return 0;
}
long ConnectWB(const method me, long digital)
{
    std::shared_ptr<Connect> con=std::make_shared<Connect>();
    std::string mee("ID");
    do{
        switch (me) {
            case ID:
                while(!con->searchWBID(digital))
                {
                    std::cout<<"没有这个微博ID，重输:";
                    std::cin>>digital;
                }
                return digital;
                break;
            case number:
                while(!con->searchWBNum(digital))
                {
                    std::cout<<"没有这个微博号，重输:";
                    std::cin>>digital;
                }
                return digital;
            default:
                std::cout<<"只能选择输入ID或者number"<<std::endl
                <<"重输:";
                std::cin>>mee;
                break;
        }
    }while(mee!="ID"||mee!="number");
    return 0;
}
const bool Connect::searchQQID(const long id)
{
    for(auto each=(pQ->people())->cbegin(); each!=(pQ->people())->cend(); ++each)
        if((each->get())->ID()==id)
            return 1;
    return 0;
}
const bool Connect::searchWBID(const long id)
{
    for(auto each=(pWB->people())->cbegin(); each!=(pWB->people())->cend(); ++each)
        if((each->get())->ID()==id)
            return 1;
    return 0;
}
const bool Connect::searchWCID(const long id)
{
    for(auto each: *pWB->people())
        if(each->ID()==id)
            return 1;
    return 0;
}
const bool Connect::searchQQNum(const long num)
{
    for(auto each: *pQ->people())
        if(each->qqNum()==num)
            return 1;
    return 0;
}
const bool Connect::searchWBNum(const long num)
{
    for(auto each: *pWB->people())
        if(each->wbNum()==num)
            return 1;
    return 0;
}
