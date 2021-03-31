//
//  friendManaImplXZJ.cpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "friendManaImplXZJ.hpp"

void friendManaImplXZJ::addFriend(std::shared_ptr<QQDataXZJ> p)
{
    (p->askfriendList()).push_back(std::make_shared<QQDataXZJ>(*pQD.get()));
}
void friendManaImplXZJ::addFriend(std::shared_ptr<WCDataXZJ> p)
{
    (p->askfriendList()).push_back(std::make_shared<WCDataXZJ>(*pWCD.get()));
}
void friendManaImplXZJ::addFriend(std::shared_ptr<WBDataXZJ> p)
{
    (p->askfriendList()).push_back(std::make_shared<WBDataXZJ>(*pWBD.get()));
}

void friendManaImplXZJ::deleteFriend(std::shared_ptr<QQDataXZJ> p)
{
    for(auto j=(p->friendList()).begin(); j!=(p->friendList()).end(); ++j)//从对方把自己删除
        if(*j==pQD)
        {
            std::cout<<(*j)->name();
            j=(p->friendList()).erase(j);
            --j;
        }
    for(auto i=(pQD->friendList()).begin(); i!=(pQD->friendList()).end(); ++i)//从自己把对方删除
        if(*(*i)==*p)
        {
            i=(pQD->friendList()).erase(i);
            --i;
        }
}
void friendManaImplXZJ::deleteFriend(std::shared_ptr<WCDataXZJ> p)
{
    for(auto j=(p->friendList()).begin(); j!=(p->friendList()).end(); ++j)//从对方把自己删除
        if(*j==pWCD)
        {
            j=(p->friendList()).erase(j);
            --j;
        }
    for(auto i=(pWCD->friendList()).begin(); i!=(pWCD->friendList()).end(); ++i)//从自己把对方删除
        if(*(*i)==*p)
        {
            i=(pWCD->friendList()).erase(i);
            --i;
        }
}
void friendManaImplXZJ::deleteFriend(std::shared_ptr<WBDataXZJ> p)
{
    for(auto j=(p->friendList()).begin(); j!=(p->friendList()).end(); ++j)//从对方把自己删除
        if(*j==pWBD)
        {
            j=(p->friendList()).erase(j);
            --j;
        }
    for(auto i=(pWBD->friendList()).begin(); i!=(pWBD->friendList()).end(); ++i)//从自己把对方删除
        if(*(*i)==*p)
        {
            i=(pWBD->friendList()).erase(i);
            --i;
        }
}
void friendManaImplXZJ::searchFriend()const//直接展示所有好友
{
    long j=0;
    switch (uzing) {
        case qq:
            for(auto i=(pQD->friendList()).begin(); i!=(pQD->friendList()).end(); ++i)
            {
                std::cout<<++j;
                showperson(i);
            }
            break;
        case wb:
            for(auto i=(pWBD->friendList()).begin(); i!=(pWBD->friendList()).end(); ++i)
            {
                std::cout<<++j;
                showperson(i);
            }
            break;
        case wc:
            for(auto i=(pWCD->friendList()).begin(); i!=(pWCD->friendList()).end(); ++i)
            {
                std::cout<<++j;
                showperson(i);
            }
            break;
    }
}

void friendManaImplXZJ::searchFriend(const std::string& name)const//查询好友，名字查询
{
    switch (uzing) {
        case qq:
            for(auto i=(pQD->friendList()).begin(); i!=(pQD->friendList()).end(); ++i)
                if((*i)->name()==name)
                    showperson(i);
            break;
        case wb:
            for(auto i=(pWBD->friendList()).begin(); i!=(pWBD->friendList()).end(); ++i)
                if((*i)->name()==name)
                    showperson(i);
            break;
        case wc:
            for(auto i=(pWCD->friendList()).begin(); i!=(pWCD->friendList()).end(); ++i)
                if((*i)->name()==name)
                    showperson(i);
            break;
    }
}
void friendManaImplXZJ::searchFriend(const long id)const//ID查询
{
    switch (uzing) {
        case qq:
            for(auto i=(pQD->friendList()).begin(); i!=(pQD->friendList()).end(); ++i)
                if((*i)->ID()==id)
                    showperson(i);
            break;
        case wb:
            for(auto i=(pWBD->friendList()).begin(); i!=(pWBD->friendList()).end(); ++i)
                if((*i)->ID()==id)
                    showperson(i);
            break;
        case wc:
            for(auto i=(pWCD->friendList()).begin(); i!=(pWCD->friendList()).end(); ++i)
                if((*i)->ID()==id)
                    showperson(i);
            break;
    }
}


void friendManaImplXZJ::showperson(const std::__wrap_iter<std::shared_ptr<QQDataXZJ> *>& p)const
{
    std::cout
    <<"名字:"<<(p->get())->name()<<std::endl
    <<"QQ号:"<<(p->get())->qqNum()<<std::endl
    <<"ID:"<<(p->get())->ID()<<std::endl
    <<"家庭住址"<<(p->get())->home()<<std::endl
    <<"生日:"<<(p->get())->birth()<<std::endl
    <<"T龄:"<<(p->get())->t_age()<<std::endl;
}
void friendManaImplXZJ::showperson(const std::__wrap_iter<std::shared_ptr<WBDataXZJ> *>& p)const
{
    std::cout
    <<"名字:"<<(p->get())->name()<<std::endl
    <<"微博号:"<<(p->get())->wbNum()<<std::endl
    <<"ID:"<<(p->get())->ID()<<std::endl
    <<"家庭住址"<<(p->get())->home()<<std::endl
    <<"生日:"<<(p->get())->birth()<<std::endl
    <<"T龄:"<<(p->get())->t_age()<<std::endl;
}
void friendManaImplXZJ::showperson(const std::__wrap_iter<std::shared_ptr<WCDataXZJ> *>& p)const
{
    std::cout
    <<"名字:"<<(p->get())->name()<<std::endl
    <<"ID:"<<(p->get())->ID()<<std::endl
    <<"家庭住址"<<(p->get())->home()<<std::endl
    <<"生日:"<<(p->get())->birth()<<std::endl
    <<"T龄:"<<(p->get())->t_age()<<std::endl;
}
void friendManaImplXZJ::recoQQFriend()
{
    int judge=1;
    switch (uzing) {
        case wc:
        {
            if(!(pWCD->friendList()).empty())
            {
                for(auto i=(pWCD->friendList()).cbegin(); i!=(pWCD->friendList()).cend(); ++i)
                    if((*i)->qq()!=0)
                    {
                        judge=0;
                        std::cout<<"你的好友"<<(*i)->name()<<"(ID:"<<(*i)->ID()<<")"
                        <<"的QQ号是"<<(*i)->qq()<<"(ID:"<<(*i)->ID()<<")"<<std::endl<<std::endl;
                    }
                if(judge==0)
                {
                    std::cout<<"是否添加为好友，如果是添加的话输入序号，如果不添加输入-1";
                    long i;
                    std::cin>>i;
                    switch (i) {
                        case -1:
                            break;
                        default:
                        {
                            addFriend(*((pWCD->friendList()).begin()+i-1));
                            break;
                        }
                    }
                }
                else
                    std::cout<<"您的微信好友还没有绑定QQ";
                
            }
            else
                std::cout<<"您的微信还没有好友"<<std::endl;
            break;
        }
        case wb:
        {
            if(!(pWBD->friendList()).empty())
            {
                for(auto i=(pWBD->friendList()).cbegin(); i!=(pWBD->friendList()).cend(); ++i)
                    if((*i)->qq()!=0)
                    {
                        judge=0;
                        std::cout<<"你的好友"<<(*i)->name()<<"(ID:"<<(*i)->ID()<<")"
                        <<"的QQ号是"<<(*i)->qq()<<"(ID:"<<(*i)->ID()<<")"<<std::endl<<std::endl;
                    }
                if(judge==0)
                {
                    std::cout<<"是否添加为好友，如果是添加的话输入序号，如果不添加输入-1";
                    long i;
                    std::cin>>i;
                    switch (i) {
                        case -1:
                            break;
                        default:
                        {
                            addFriend(*((pWCD->friendList()).begin()+i-1));
                            break;
                        }
                    }
                }
                else
                    std::cout<<"您的微博好友还没有绑定QQ";
            }
            else
                std::cout<<"您的微博还没有好友"<<std::endl;
            break;
        }
        case qq:
            std::cout<<"您当前登录的就是QQ"<<std::endl;
            break;
    }
}
void friendManaImplXZJ::recoWBFriend()
{
    int judge=1;
    switch (uzing) {
        case qq:
        {
            if(!(pQD->friendList()).empty())
            {
                for(auto i=(pQD->friendList()).cbegin(); i!=(pQD->friendList()).cend(); ++i)
                    if((*i)->wb()!=0)
                    {
                        judge=0;
                        std::cout<<"你的好友"<<(*i)->name()<<"(ID:"<<(*i)->ID()<<")"
                        <<"的微博号是"<<(*i)->wb()<<"(ID:"<<(*i)->ID()<<")"<<std::endl<<std::endl;
                    }
                if(judge==0)
                {
                    std::cout<<"是否添加为好友，如果是添加的话输入序号，如果不添加输入-1";
                    long i;
                    std::cin>>i;
                    switch (i) {
                        case -1:
                            break;
                        default:
                        {
                            addFriend(*((pQD->friendList()).begin()+i-1));
                            break;
                        }
                    }
                }
                else
                    std::cout<<"您的QQ好友还没有绑定微博";
            }
            else
                std::cout<<"您的QQ还没有好友"<<std::endl;
            break;
        }
        case wc:
        {
            if(!(pWCD->friendList()).empty())
            {
                for(auto i=(pWCD->friendList()).cbegin(); i!=(pWCD->friendList()).cend(); ++i)
                    if((*i)->wb()!=0)
                    {
                        judge=0;
                        std::cout<<"你的好友"<<(*i)->name()<<"(ID:"<<(*i)->ID()<<")"
                        <<"的微博号是"<<(*i)->wb()<<"(ID:"<<(*i)->ID()<<")"<<std::endl<<std::endl;
                    }
                if(judge==0)
                {
                    std::cout<<"是否添加为好友，如果是添加的话输入序号，如果不添加输入-1";
                    long i;
                    std::cin>>i;
                    switch (i) {
                        case -1:
                            break;
                        default:
                        {
                            addFriend(*((pWCD->friendList()).begin()+i-1));
                            break;
                        }
                    }
                }
                else
                    std::cout<<"您的微信好友还没有绑定微博";
            }
            else
                std::cout<<"您的微信还没有好友"<<std::endl;
            break;
        }
        case wb:
            std::cout<<"您当前登录的就是微博"<<std::endl;
            break;
    }
}
void friendManaImplXZJ::recoWCFriend()
{
    int judge=1;
    switch (uzing) {
        case qq:
        {
            if(!(pQD->friendList()).empty())
            {
                for(auto i=(pQD->friendList()).cbegin(); i!=(pQD->friendList()).cend(); ++i)
                    if((*i)->wc()!=0)
                    {
                        judge=0;
                        std::cout<<"你的好友"<<(*i)->name()<<"(ID:"<<(*i)->ID()<<")"
                        <<"的微微信ID是"<<(*i)->ID()<<std::endl<<std::endl;
                    }
                if(judge==0)
                {
                    std::cout<<"是否添加为好友，如果是添加的话输入序号，如果不添加输入-1";
                    long i;
                    std::cin>>i;
                    switch (i) {
                        case -1:
                            break;
                        default:
                        {
                            addFriend(*((pQD->friendList()).begin()+i-1));
                            break;
                        }
                    }
                }
                else
                    std::cout<<"您的QQ好友还没有绑定微信";
            }
            else
                std::cout<<"您的QQ还没有好友"<<std::endl;
            break;
        }
        case wb:
        {
            if(!(pWBD->friendList()).empty())
            {
                for(auto i=(pWBD->friendList()).cbegin(); i!=(pWBD->friendList()).cend(); ++i)
                    if((*i)->wc()!=0)
                    {
                        judge=0;
                        std::cout<<"你的好友"<<(*i)->name()<<"(ID:"<<(*i)->ID()<<")"
                        <<"的微微信ID是"<<(*i)->ID()<<std::endl<<std::endl;
                    }
                if(judge==0)
                {
                    std::cout<<"是否添加为好友，如果是添加的话输入序号，如果不添加输入-1";
                    long i;
                    std::cin>>i;
                    switch (i) {
                        case -1:
                            break;
                        default:
                        {
                            addFriend(*((pWBD->friendList()).begin()+i-1));
                            break;
                        }
                    }
                }
                else
                    std::cout<<"您的微博好友还没有绑定微信";
            }
            else
                std::cout<<"您的微博还没有好友"<<std::endl;
            break;
        }
        case wc:
            std::cout<<"您当前登录的就是微信"<<std::endl;
    }
    
}
void friendManaImplXZJ::addFriend()
{
    int j=0;
    switch (uzing) {
        case qq:
        {
            for(auto i=(pQ->people())->begin(); i!=(pQ->people())->end(); ++i)
            {
                std::cout<<++j<<"."<<std::endl;
                showperson(i);
            }
            std::cout<<"是否添加为好友，如果是添加的话输入序号，如果不添加输入-1";
            long i;
            std::cin>>i;
            switch (i) {
                case -1:
                    break;
                default:
                {
                    addFriend(*((pQ->people())->begin()+i-1));
                    break;
                }
            }
            break;
        }
        case wc:
        {
            for(auto i=(pWC->people())->begin(); i!=(pWC->people())->end(); ++i)
            {
                std::cout<<++j<<"."<<std::endl;
                showperson(i);
            }
            std::cout<<"是否添加为好友，如果是添加的话输入序号，如果不添加输入-1";
            long i;
            std::cin>>i;
            switch (i) {
                case -1:
                    break;
                default:
                {
                    addFriend(*((pWC->people())->begin()+i-1));
                    break;
                }
            }
            break;
        }
        case wb:
        {
            for(auto i=(pWB->people())->begin(); i!=(pWB->people())->end(); ++i)
            {
                std::cout<<++j<<"."<<std::endl;
                showperson(i);
            }
            std::cout<<"是否添加为好友，如果是添加的话输入序号，如果不添加输入-1";
            long i;
            std::cin>>i;
            switch (i) {
                case -1:
                    break;
                default:
                {
                    addFriend(*((pWB->people())->begin()+i-1));
                    break;
                }
            }
            break;
        }
    }
}
void friendManaImplXZJ::agreeFriend()
{
    long j=0;
    switch (uzing) {
        case qq:
        {
            if(!(pQD->askfriendList()).empty())
            {
                for(auto i=(pQD->askfriendList()).begin(); i!=(pQD->askfriendList()).end(); ++i)
                {
                    std::cout<<++j<<"."<<std::endl;
                    showperson(i);
                }
                std::cout<<"输入同意的序号__";
                long k;
                std::cin>>k;
                auto i=(pQD->askfriendList()).begin();
                (pQD->friendList()).push_back(*(i+k-1));//自己好友中加他
                ((*(i+k-1))->friendList()).push_back(pQD);//他的好友中加你
                (pQD->askfriendList()).erase(i+k-1);
            }
            else
                std::cout<<"没有好友要添加你"<<std::endl;
            break;
        }
        case wb:
        {
            if(!(pWBD->askfriendList()).empty())
            {
                for(auto i=(pWBD->askfriendList()).begin(); i!=(pWBD->askfriendList()).end(); ++i)
                {
                    std::cout<<++j<<"."<<std::endl;
                    showperson(i);
                }
                std::cout<<"输入同意的序号__";
                long k;
                std::cin>>k;
                auto i=(pWBD->askfriendList()).begin();
                (pWBD->friendList()).push_back(*(i+k-1));//自己好友中加他
                ((*(i+k-1))->friendList()).push_back(pWBD);//他的好友中加你
                (pWBD->askfriendList()).erase(i+k-1);
            }
            else
                std::cout<<"没有好友要添加你"<<std::endl;
            break;
        }
        case wc:
        {
            if(!(pWCD->askfriendList()).empty())
            {
                for(auto i=(pWCD->askfriendList()).begin(); i!=(pWCD->askfriendList()).end(); ++i)
                {
                    std::cout<<++j<<"."<<std::endl;
                    showperson(i);
                }
                std::cout<<"输入同意的序号__";
                long k;
                std::cin>>k;
                auto i=(pWCD->askfriendList()).begin();
                (pWCD->friendList()).push_back(*(i+k-1));//自己好友中加他
                ((*(i+k-1))->friendList()).push_back(pWCD);//他的好友中加你
                (pWCD->askfriendList()).erase(i+k-1);
            }
            else
                std::cout<<"没有好友要添加你"<<std::endl;
            break;
        }
    }
}
