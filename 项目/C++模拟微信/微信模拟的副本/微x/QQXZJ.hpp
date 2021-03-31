//
//  QQXZJ.hpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef QQXZJ_hpp
#define QQXZJ_hpp
#include <iostream>
#include <vector>
#include "QQDataXZJ.hpp"
#include "groupXZJ.hpp"
class QQXZJ
{
public:
    QQXZJ():
    _people(std::make_shared<std::vector<std::shared_ptr<QQDataXZJ>>>()),
    _tempdisgro(std::make_shared<std::vector<std::shared_ptr<groupXZJ>>>()),
    _groupMana(std::make_shared<std::vector<std::shared_ptr<groupXZJ>>>())
    {
        
    }
    
    explicit QQXZJ(std::shared_ptr<QQXZJ> pQ):
    _people(pQ->people()),
    _groupMana(pQ->groupMana()),
    _tempdisgro(pQ->tempdisgro()){}
    
    explicit QQXZJ(const QQXZJ& pQ):
    _people(pQ.people()),
    _groupMana(pQ.groupMana()),
    _tempdisgro(pQ.tempdisgro()){}
    
    const std::shared_ptr<std::vector<std::shared_ptr<QQDataXZJ>>>& people()const{return _people;}
    const std::shared_ptr<std::vector<std::shared_ptr<groupXZJ>>>& groupMana()const{return _groupMana;}
    const std::shared_ptr<std::vector<std::shared_ptr<groupXZJ>>>& tempdisgro()const{return _tempdisgro;}
    std::shared_ptr<std::vector<std::shared_ptr<QQDataXZJ>>>& people(){return _people;}
    std::shared_ptr<std::vector<std::shared_ptr<groupXZJ>>>& tempdisgro(){return _tempdisgro;}
    ~QQXZJ(){}
private:
    std::shared_ptr<std::vector<std::shared_ptr<QQDataXZJ>>> _people=nullptr;
    std::shared_ptr<std::vector<std::shared_ptr<groupXZJ>>> _tempdisgro=nullptr;//临时讨论组
    std::shared_ptr<std::vector<std::shared_ptr<groupXZJ>>> _groupMana=nullptr;//初始化时别忘记设置群号
};
#endif /* QQXZJ_hpp */
