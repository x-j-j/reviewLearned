//
//  friendManaXZJ.hpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef friendManaXZJ_hpp
#define friendManaXZJ_hpp
#include <iostream>
class friendManaImplXZJ;
class QQDataXZJ;
class WBDataXZJ;
class WCDataXZJ;
class Files;
class friendManaXZJ
{
public:
    explicit friendManaXZJ(const std::shared_ptr<Files>& _pF, const std::shared_ptr<QQDataXZJ>& pQD);
    explicit friendManaXZJ(const std::shared_ptr<Files>& _pF, const std::shared_ptr<WBDataXZJ>& pWBD);
    explicit friendManaXZJ(const std::shared_ptr<Files>& _pF, const std::shared_ptr<WCDataXZJ>& pWCD);
    
    void addFriend();
    void addFriend(std::shared_ptr<QQDataXZJ> p);
    void addFriend(std::shared_ptr<WCDataXZJ> p);
    void addFriend(std::shared_ptr<WBDataXZJ> p);
    
    void deleteFriend(std::shared_ptr<QQDataXZJ> p);
    void deleteFriend(std::shared_ptr<WCDataXZJ> p);
    void deleteFriend(std::shared_ptr<WBDataXZJ> p);
    
    void searchFriend()const;//直接展示所有好友
    void searchFriend(const std::string& name)const;//查询好友，名字查询
    void searchFriend(const long id)const;//ID查询
    
    void recoQQFriend();//推荐所有好友
    void recoWBFriend();
    void recoWCFriend();
    
    void agreeFriend();
    
    ~friendManaXZJ(){}
private:
    std::shared_ptr<friendManaImplXZJ> pfMI=nullptr;
};
#endif /* friendManaXZJ_hpp */
