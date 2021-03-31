//
//  userManaXZJ.hpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef userManaXZJ_hpp
#define userManaXZJ_hpp
#include <iostream>
#include "Files.hpp"
#include "QQDataXZJ.hpp"
#include "WCDataXZJ.hpp"
#include "WBDataXZJ.hpp"
#include "creatAccXZJ.hpp"
#include "logXZJ.hpp"
#include "groupManaXZJ.hpp"
#include "friendManaXZJ.hpp"
enum type{qq, wc, wb};
class userManaXZJ
{
public:
    explicit userManaXZJ();//调用文件写入QQ，微信，微博数据
    ~userManaXZJ(){}
private:
    type _t;
    void CreatAccount();
    void Log();
    void ManageGroup();
    void ManageFriends();
    void mainOperation();
    std::shared_ptr<QQDataXZJ> pQD=nullptr;//当前登录状态
    std::shared_ptr<WCDataXZJ> pWCD=nullptr;//当前登录状态
    std::shared_ptr<WBDataXZJ> pWBD=nullptr;//当前登录状态
    std::shared_ptr<QQXZJ> pQ=nullptr;
    std::shared_ptr<WCXZJ> pWC=nullptr;
    std::shared_ptr<WBXZJ> pWB=nullptr;
    std::shared_ptr<Files> pF=nullptr;
    std::shared_ptr<creatAccXZJ> pcA=nullptr;//管理创建账户
    std::shared_ptr<logXZJ> pl=nullptr;//管理登录
    std::shared_ptr<groupManaXZJ> pgM=nullptr;//管理群
    std::shared_ptr<friendManaXZJ> pfM=nullptr;//管理好友
};
#endif /* userManaXZJ_hpp */
