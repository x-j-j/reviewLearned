//
//  ConnectXZJ.hpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef ConnectXZJ_hpp
#define ConnectXZJ_hpp
#include <iostream>
#include "Files.hpp"//确保ID或者号码存在
enum method{ID, number};
class Connect//微博ID连接QQID，微信ID连接QQ号码，微信ID连接微博ID
{
public:
    Connect():
    pF(std::make_shared<Files>()),
    pQ(std::make_shared<QQXZJ>(pF->QQ())),
    pWC(std::make_shared<WCXZJ>(pF->WC())),
    pWB(std::make_shared<WBXZJ>(pF->WB())){}
    ~Connect(){}
    friend long ConnectQQ(const method me, const long digital);//连接的种类和相应的号码
    friend long ConnectWC(const method me, const long digital);
    friend long ConnectWB(const method me, const long digital);
private:
    const bool searchQQID(const long id);
    const bool searchWBID(const long id);
    const bool searchWCID(const long id);
    const bool searchQQNum(const long num);
    const bool searchWBNum(const long num);
    std::shared_ptr<Files> pF=nullptr;
    std::shared_ptr<QQXZJ> pQ=nullptr;
    std::shared_ptr<WCXZJ> pWC=nullptr;
    std::shared_ptr<WBXZJ> pWB=nullptr;
    
};
long ConnectQQ(const method me, const long digital);
long ConnectWC(const method me, const long digital);
long ConnectWB(const method me, const long digital);
#endif /* ConnectXZJ_hpp */
