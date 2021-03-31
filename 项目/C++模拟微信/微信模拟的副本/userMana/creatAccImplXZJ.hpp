//
//  creatAccImplXZJ.hpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef creatAccImplXZJ_hpp
#define creatAccImplXZJ_hpp
#include <iostream>
#include <ctime>
#include "Files.hpp"
#include "ConnectXZJ.hpp"
#include "QQDataXZJ.hpp"
#include "WBDataXZJ.hpp"
#include "WCDataXZJ.hpp"
enum choose{qq, wechet, webo};
class creatAccImplXZJ
{
public:
    creatAccImplXZJ(const std::shared_ptr<Files>& pF);
    
    const std::shared_ptr<QQDataXZJ> creatQQAcc();
    const std::shared_ptr<WBDataXZJ> creatWBAcc();
    const std::shared_ptr<WCDataXZJ> creatWCAcc();
    ~creatAccImplXZJ(){}
private:
    time_t rawtime;
    struct tm *ptminfo;
    std::shared_ptr<Files> _pF=nullptr;
    std::shared_ptr<QQXZJ> _pQ=nullptr;
    std::shared_ptr<WBXZJ> _pWB=nullptr;
    std::shared_ptr<WCXZJ> _pWC=nullptr;
};
#endif /* creatAccImplXZJ_hpp */
