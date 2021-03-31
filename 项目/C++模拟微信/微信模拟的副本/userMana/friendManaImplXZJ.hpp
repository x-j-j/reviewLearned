//
//  friendManaImplXZJ.hpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef friendManaImplXZJ_hpp
#define friendManaImplXZJ_hpp
#include <iostream>
#include "Files.hpp"
#include "BasicDataXZJ.hpp"
#include "QQDataXZJ.hpp"//修改，删除，查询
#include "WBDataXZJ.hpp"
#include "WCDataXZJ.hpp"
#include "logXZJ.hpp"//需要自动登录所有微x
#include "Files.hpp"
enum type{qq,wc,wb};
class friendManaImplXZJ
{
public:
    explicit friendManaImplXZJ(const std::shared_ptr<Files>& _pF, const std::shared_ptr<QQDataXZJ>& pqd)
    {
        pF=(_pF);
        pl=(std::make_shared<logXZJ>(_pF));
        pQ=(pF->QQ());
        pWC=(pF->WC());
        pWB=(pF->WB());
        pQD=(pl->nopasswordlogQQ(pqd->qqNum()));//有问题
        pWBD=(pl->pWBD());
        pWCD=(pl->pWCD());
        uzing=(qq);
    }
    
    explicit friendManaImplXZJ(const std::shared_ptr<Files>& _pF, const std::shared_ptr<WBDataXZJ>& pwb)
    {
        pF=(_pF);
        pl=(std::make_shared<logXZJ>(_pF));
        pQ=(pF->QQ());
        pWC=(pF->WC());
        pWB=(pF->WB());
        pWBD=(pl->nopasswordlogWB(pwb->wbNum()));
        pQD=(pl->pQD());
        pWCD=(pl->pWCD());
        uzing=(wb);
    }
    
    explicit friendManaImplXZJ(const std::shared_ptr<Files>& _pF, const std::shared_ptr<WCDataXZJ>& pwc)
    {
        pF=(_pF);
        pl=(std::make_shared<logXZJ>(_pF));
        pQ=(pF->QQ());
        pWC=(pF->WC());
        pWB=(pF->WB());
        pWCD=(pl->nopasswordlogWC(pwc->ID()));
        pWBD=(pl->pWBD());
        pQD=(pl->pQD());
        uzing=(wc);
    }
    
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
    
    void recoQQFriend();//登录除QQ外其他app
    void recoWBFriend();
    void recoWCFriend();
    
    void agreeFriend();
    
    ~friendManaImplXZJ(){}
private:
    type uzing;//正在登录使用的微x
    std::shared_ptr<logXZJ> pl=nullptr;
    std::shared_ptr<Files> pF=nullptr;
    std::shared_ptr<QQDataXZJ> pQD=nullptr;
    std::shared_ptr<WBDataXZJ> pWBD=nullptr;
    std::shared_ptr<WCDataXZJ> pWCD=nullptr;
    std::shared_ptr<QQXZJ> pQ=nullptr;
    std::shared_ptr<WBXZJ> pWB=nullptr;
    std::shared_ptr<WCXZJ> pWC=nullptr;
    void showperson(const std::__wrap_iter<std::shared_ptr<QQDataXZJ> *>& p)const;
    void showperson(const std::__wrap_iter<std::shared_ptr<WBDataXZJ> *>& p)const;
    void showperson(const std::__wrap_iter<std::shared_ptr<WCDataXZJ> *>& p)const;
};
//只有被声明为const的成员函数才能被一个const类对象调用
#endif /* friendManaImplXZJ_hpp */
