//
//  friendManaXZJ.cpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "friendManaXZJ.hpp"
#include "friendManaImplXZJ.hpp"
friendManaXZJ::friendManaXZJ(const std::shared_ptr<Files>& _pF, const std::shared_ptr<QQDataXZJ>& pQD)
{
    pfMI=(std::make_shared<friendManaImplXZJ>(_pF, pQD));
}
friendManaXZJ::friendManaXZJ(const std::shared_ptr<Files>& _pF, const std::shared_ptr<WBDataXZJ>& pWBD)
{
    pfMI=(std::make_shared<friendManaImplXZJ>(_pF, pWBD));
}
friendManaXZJ::friendManaXZJ(const std::shared_ptr<Files>& _pF, const std::shared_ptr<WCDataXZJ>& pWCD)
{
    pfMI=(std::make_shared<friendManaImplXZJ>(_pF, pWCD));
}
void friendManaXZJ::addFriend()
{
    pfMI->addFriend();
}
void friendManaXZJ::addFriend(std::shared_ptr<QQDataXZJ> p)
{
    pfMI->addFriend(p);
}
void friendManaXZJ::addFriend(std::shared_ptr<WCDataXZJ> p)
{
    pfMI->addFriend(p);
}
void friendManaXZJ::addFriend(std::shared_ptr<WBDataXZJ> p)
{
    pfMI->addFriend(p);
}

void friendManaXZJ::deleteFriend(std::shared_ptr<QQDataXZJ> p)
{
    pfMI->deleteFriend(p);
}
void friendManaXZJ::deleteFriend(std::shared_ptr<WCDataXZJ> p)
{
    pfMI->deleteFriend(p);
}
void friendManaXZJ::deleteFriend(std::shared_ptr<WBDataXZJ> p)
{
    pfMI->deleteFriend(p);
}

void friendManaXZJ::searchFriend()const//直接展示所有好友
{
    pfMI->searchFriend();
}
void friendManaXZJ::searchFriend(const std::string& name)const//查询好友，名字查询
{
    pfMI->searchFriend(name);
}
void friendManaXZJ::searchFriend(const long id)const//ID查询
{
    pfMI->searchFriend(id);
}

void friendManaXZJ::recoQQFriend()//推荐所有好友
{
    pfMI->recoQQFriend();
}
void friendManaXZJ::recoWBFriend()
{
    pfMI->recoWBFriend();
}
void friendManaXZJ::recoWCFriend()
{
    pfMI->recoWCFriend();
}
void friendManaXZJ::agreeFriend()
{
    pfMI->agreeFriend();
}
