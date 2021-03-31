//
//  logImplXZJ.cpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "logImplXZJ.hpp"
const std::shared_ptr<QQDataXZJ> logImplXZJ::logQQ(long accnum)
{
    while(1){
        for(auto i=(_pQ->people())->cbegin(); i!=(_pQ->people())->cend(); ++i)
        {
            if((*i)->qqNum()==accnum)
            {
                long j=0;
                do {
                    std::cout<<"输入密码__";
                    std::cin>>j;
                    std::cout<<std::endl;
                    if(j!=(*i)->password())
                        std::cout<<"密码错误";
                }while(j!=(*i)->password());
                if((*i)->wb()!=0)
                    _pWBD=findWBperson((*i)->wb());
                if((*i)->wc()!=0)
                    _pWCD=findWCperson((*i)->wc());
                return *i;
            }
        }
        std::cout<<"没找到用户, 重新输入账户";
        std::cin>>accnum;
    }
}
const std::shared_ptr<WBDataXZJ> logImplXZJ::logWB(long accnum)
{
    while(1){
        for(auto i=(_pWB->people())->cbegin(); i!=(_pWB->people())->cend(); ++i)
        {
            if((*i)->wbNum()==accnum)
            {
                long j=0;
                do {
                    std::cout<<"输入密码:";
                    std::cin>>j;
                    std::cout<<std::endl;
                }while(j!=(*i)->password());
                if((*i)->qq()!=0)
                    _pQD=findQQperson((*i)->qq());
                if((*i)->wc()!=0)
                    _pWCD=findWCperson((*i)->wc());
                return *i;
            }
        }
        std::cout<<"没找到用户, 重新输入账户";
        std::cin>>accnum;
    }
    
    return nullptr;
}
const std::shared_ptr<WCDataXZJ> logImplXZJ::logWC(long accnum)
{
    while(1){
        for(auto i=(_pWC->people())->cbegin(); i!=(_pWC->people())->cend(); ++i)
        {
            if((*i)->ID()==accnum)
            {
                long j=0;
                do {
                    std::cout<<"输入密码:";
                    std::cin>>j;
                    std::cout<<std::endl;
                }while(j!=(*i)->password());
                if((*i)->qq()!=0)
                    _pQD=findQQperson((*i)->qq());
                if((*i)->wb()!=0)
                    _pWBD=findWBperson((*i)->wb());
                return *i;
            }
        }
        std::cout<<"没找到用户, 重新输入账户";
        std::cin>>accnum;
    }
    return nullptr;
}
const std::shared_ptr<QQDataXZJ> logImplXZJ::findQQperson(long accnum)const
{
    for(auto i=(_pQ->people())->cbegin(); i!=(_pQ->people())->cend(); ++i)
    {
        if((*i)->qqNum()==accnum)
            return *i;
        if((*i)->ID()==accnum)
            return *i;
    }
    std::cout<<"没有这个QQ号/ID";
    return nullptr;
}
const std::shared_ptr<WBDataXZJ> logImplXZJ::findWBperson(long accnum)const
{
    for(auto i=(_pWB->people())->cbegin(); i!=(_pWB->people())->cend(); ++i)
    {
        if((*i)->wbNum()==accnum)
            return *i;
        if((*i)->ID()==accnum)
            return *i;
    }
    std::cout<<"没有这个微博号/ID";
    return nullptr;
}
const std::shared_ptr<WCDataXZJ> logImplXZJ::findWCperson(long accnum)const
{
    for(auto i=(_pWC->people())->cbegin(); i!=(_pWC->people())->cend(); ++i)
        if((*i)->ID()==accnum)
            return *i;
    std::cout<<"没有这个微信ID";
    return nullptr;
}
const std::shared_ptr<QQDataXZJ> logImplXZJ::nopasswordlogQQ(long accnum)
{
    for(auto i=(_pQ->people())->cbegin(); i!=(_pQ->people())->cend(); ++i)
    {
        if((*i)->qqNum()==accnum)
        {
            
            if((*i)->wb()!=0)
                _pWBD=findWBperson((*i)->wb());
            if((*i)->wc()!=0)
                _pWCD=findWCperson((*i)->wc());
            return *i;
        }
    }
    return nullptr;
}
const std::shared_ptr<WBDataXZJ> logImplXZJ::nopasswordlogWB(long accnum)
{
    for(auto i=(_pWB->people())->cbegin(); i!=(_pWB->people())->cend(); ++i)
    {
        if((*i)->wbNum()==accnum)
        {
            if((*i)->qq()!=0)
                _pQD=findQQperson((*i)->qq());
            if((*i)->wc()!=0)
                _pWCD=findWCperson((*i)->wc());
            return *i;
        }
    }
    std::cout<<"没找到这个人";
    return nullptr;
}
const std::shared_ptr<WCDataXZJ> logImplXZJ::nopasswordlogWC(long accnum)
{
    for(auto i=(_pWC->people())->cbegin(); i!=(_pWC->people())->cend(); ++i)
    {
        if((*i)->ID()==accnum)
        {
            if((*i)->qq()!=0)
                _pQD=findQQperson((*i)->qq());
            if((*i)->wb()!=0)
                _pWBD=findWBperson((*i)->wb());
            return *i;
        }
    }
    return nullptr;
}
