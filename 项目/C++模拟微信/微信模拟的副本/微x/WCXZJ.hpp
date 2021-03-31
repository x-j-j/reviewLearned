//
//  WCXZJ.hpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef WCXZJ_hpp
#define WCXZJ_hpp
#include <iostream>
#include <vector>
#include "WCDataXZJ.hpp"
#include "groupXZJ.hpp"
class WCXZJ
{
public:
    WCXZJ():
    _people(std::make_shared<std::vector<std::shared_ptr<WCDataXZJ>>>()),
    _tempdisgro(std::make_shared<std::vector<std::shared_ptr<groupXZJ>>>()),
    _groupMana(std::make_shared<std::vector<std::shared_ptr<groupXZJ>>>())
    {
        
    }
    
    explicit WCXZJ(std::shared_ptr<WCXZJ> pWC):
    _people(pWC->people()),
    _groupMana(pWC->groupMana()),
    _tempdisgro(pWC->tempdisgro()){}
    
    explicit WCXZJ(const WCXZJ& pWC):
    _people(pWC.people()),
    _groupMana(pWC.groupMana()),
    _tempdisgro(pWC.tempdisgro()){}
    
    const std::shared_ptr<std::vector<std::shared_ptr<WCDataXZJ>>>& people()const{return _people;}
    const std::shared_ptr<std::vector<std::shared_ptr<groupXZJ>>>& groupMana()const{return _groupMana;}
    const std::shared_ptr<std::vector<std::shared_ptr<groupXZJ>>>& tempdisgro()const{return _tempdisgro;}
    std::shared_ptr<std::vector<std::shared_ptr<WCDataXZJ>>>& people(){return _people;}
    std::shared_ptr<std::vector<std::shared_ptr<groupXZJ>>>& tempdisgro(){return _tempdisgro;}
    ~WCXZJ(){}
private:
    std::shared_ptr<std::vector<std::shared_ptr<WCDataXZJ>>> _people=nullptr;
    std::shared_ptr<std::vector<std::shared_ptr<groupXZJ>>> _tempdisgro=nullptr;//临时讨论组
    std::shared_ptr<std::vector<std::shared_ptr<groupXZJ>>> _groupMana=nullptr;//初始化时别忘记设置群号
};
#endif /* WCXZJ_hpp */
