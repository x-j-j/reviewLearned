//
//  WBXZJ.hpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef WBXZJ_hpp
#define WBXZJ_hpp
#include <iostream>
#include <vector>
#include "WBDataXZJ.hpp"
#include "groupXZJ.hpp"
class WBXZJ
{
public:
    WBXZJ():
    _people(std::make_shared<std::vector<std::shared_ptr<WBDataXZJ>>>()),
    _tempdisgro(std::make_shared<std::vector<std::shared_ptr<groupXZJ>>>()),
    _groupMana(std::make_shared<std::vector<std::shared_ptr<groupXZJ>>>())
    {
        
    }
    
    explicit WBXZJ(std::shared_ptr<WBXZJ> pWB):
    _people(pWB->people()),
    _groupMana(pWB->groupMana()),
    _tempdisgro(pWB->tempdisgro()){}
    
    explicit WBXZJ(const WBXZJ& pWB):
    _people(pWB.people()),
    _groupMana(pWB.groupMana()),
    _tempdisgro(pWB.tempdisgro()){}
    
    const std::shared_ptr<std::vector<std::shared_ptr<WBDataXZJ>>>& people()const{return _people;}
    const std::shared_ptr<std::vector<std::shared_ptr<groupXZJ>>>& groupMana()const{return _groupMana;}
    const std::shared_ptr<std::vector<std::shared_ptr<groupXZJ>>>& tempdisgro()const{return _tempdisgro;}
    std::shared_ptr<std::vector<std::shared_ptr<WBDataXZJ>>>& people(){return _people;}
    std::shared_ptr<std::vector<std::shared_ptr<groupXZJ>>>& tempdisgro(){return _tempdisgro;}
    ~WBXZJ(){}
private:
    std::shared_ptr<std::vector<std::shared_ptr<WBDataXZJ>>> _people=nullptr;
    std::shared_ptr<std::vector<std::shared_ptr<groupXZJ>>> _tempdisgro=nullptr;//临时讨论组
    std::shared_ptr<std::vector<std::shared_ptr<groupXZJ>>> _groupMana=nullptr;//初始化时别忘记设置群号
};
#endif /* WBXZJ_hpp */
