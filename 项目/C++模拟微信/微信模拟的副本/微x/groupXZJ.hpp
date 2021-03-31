//
//  groupXZJ.hpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/11.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef groupXZJ_hpp
#define groupXZJ_hpp
#include <iostream>
#include <vector>
#include "QQDataXZJ.hpp"
#include "WBDataXZJ.hpp"
#include "WCDataXZJ.hpp"
class groupXZJ
{
public:
    groupXZJ():
    _tempqqGro(std::make_shared<std::vector<std::shared_ptr<QQDataXZJ>>>()),
    _tempwcGro(std::make_shared<std::vector<std::shared_ptr<WCDataXZJ>>>()),
    _tempwbGro(std::make_shared<std::vector<std::shared_ptr<WBDataXZJ>>>()),
    _qqGro(std::make_shared<std::vector<std::shared_ptr<QQDataXZJ>>>()),
    _wcGro(std::make_shared<std::vector<std::shared_ptr<WCDataXZJ>>>()),
    _wbGro(std::make_shared<std::vector<std::shared_ptr<WBDataXZJ>>>()),
    _askJoinQQGro(std::make_shared<std::vector<std::shared_ptr<QQDataXZJ>>>()),
    _askJoinWCGro(std::make_shared<std::vector<std::shared_ptr<WCDataXZJ>>>()),
    _askJoinWBGro(std::make_shared<std::vector<std::shared_ptr<WBDataXZJ>>>()),
    _askJointempQQGro(std::make_shared<std::vector<std::shared_ptr<QQDataXZJ>>>()),
    _askJointempWCGro(std::make_shared<std::vector<std::shared_ptr<WCDataXZJ>>>()),
    _askJointempWBGro(std::make_shared<std::vector<std::shared_ptr<WBDataXZJ>>>()),
    _qqGroAdministrators(std::make_shared<std::vector<std::shared_ptr<QQDataXZJ>>>()),
    _wcGroAdministrators(std::make_shared<std::vector<std::shared_ptr<WCDataXZJ>>>()),
    _wbGroAdministrators(std::make_shared<std::vector<std::shared_ptr<WBDataXZJ>>>()){}
    explicit groupXZJ(long i):
    _groupNum(i),
    _tempqqGro(std::make_shared<std::vector<std::shared_ptr<QQDataXZJ>>>()),
    _tempwcGro(std::make_shared<std::vector<std::shared_ptr<WCDataXZJ>>>()),
    _tempwbGro(std::make_shared<std::vector<std::shared_ptr<WBDataXZJ>>>()),
    _qqGro(std::make_shared<std::vector<std::shared_ptr<QQDataXZJ>>>()),
    _wcGro(std::make_shared<std::vector<std::shared_ptr<WCDataXZJ>>>()),
    _wbGro(std::make_shared<std::vector<std::shared_ptr<WBDataXZJ>>>()),
    _askJoinQQGro(std::make_shared<std::vector<std::shared_ptr<QQDataXZJ>>>()),
    _askJoinWCGro(std::make_shared<std::vector<std::shared_ptr<WCDataXZJ>>>()),
    _askJoinWBGro(std::make_shared<std::vector<std::shared_ptr<WBDataXZJ>>>()),
    _askJointempQQGro(std::make_shared<std::vector<std::shared_ptr<QQDataXZJ>>>()),
    _askJointempWCGro(std::make_shared<std::vector<std::shared_ptr<WCDataXZJ>>>()),
    _askJointempWBGro(std::make_shared<std::vector<std::shared_ptr<WBDataXZJ>>>()),
    _qqGroAdministrators(std::make_shared<std::vector<std::shared_ptr<QQDataXZJ>>>()),
    _wcGroAdministrators(std::make_shared<std::vector<std::shared_ptr<WCDataXZJ>>>()),
    _wbGroAdministrators(std::make_shared<std::vector<std::shared_ptr<WBDataXZJ>>>()){}
    
    const long groupNum()const{return _groupNum;}
    long& groupNum(){return _groupNum;}
    
    const std::shared_ptr<std::vector<std::shared_ptr<QQDataXZJ>>>& qqGro()const{return _qqGro;}
    const std::shared_ptr<std::vector<std::shared_ptr<WBDataXZJ>>>& wbGro()const{return _wbGro;}
    const std::shared_ptr<std::vector<std::shared_ptr<WCDataXZJ>>>& wcGro()const{return _wcGro;}
    std::shared_ptr<std::vector<std::shared_ptr<QQDataXZJ>>>& qqGro(){return _qqGro;}
    std::shared_ptr<std::vector<std::shared_ptr<WBDataXZJ>>>& wbGro(){return _wbGro;}
    std::shared_ptr<std::vector<std::shared_ptr<WCDataXZJ>>>& wcGro(){return _wcGro;}
    
    std::shared_ptr<std::vector<std::shared_ptr<QQDataXZJ>>>& tempqqGro(){return _tempqqGro;}
    std::shared_ptr<std::vector<std::shared_ptr<WBDataXZJ>>>& tempwbGro(){return _tempwbGro;}
    std::shared_ptr<std::vector<std::shared_ptr<WCDataXZJ>>>& tempwcGro(){return _tempwcGro;}
    
    std::shared_ptr<std::vector<std::shared_ptr<QQDataXZJ>>>& askJoinQQGroList(){return _askJoinQQGro;}
    std::shared_ptr<std::vector<std::shared_ptr<WBDataXZJ>>>& askJoinWBGroList(){return _askJoinWBGro;}
    std::shared_ptr<std::vector<std::shared_ptr<WCDataXZJ>>>& askJoinWCGroList(){return _askJoinWCGro;}
    
    std::shared_ptr<std::vector<std::shared_ptr<QQDataXZJ>>>& askJointempQQGroList(){return _askJointempQQGro;}
    std::shared_ptr<std::vector<std::shared_ptr<WBDataXZJ>>>& askJointempWBGroList(){return _askJointempWBGro;}
    std::shared_ptr<std::vector<std::shared_ptr<WCDataXZJ>>>& askJointempWCGroList(){return _askJointempWCGro;}
    
    std::shared_ptr<std::vector<std::shared_ptr<QQDataXZJ>>>& qqGroAdministrators(){return _qqGroAdministrators;}
    std::shared_ptr<std::vector<std::shared_ptr<WBDataXZJ>>>& wbGroAdministrators(){return _wbGroAdministrators;}
    std::shared_ptr<std::vector<std::shared_ptr<WCDataXZJ>>>& wcGroAdministrators(){return _wcGroAdministrators;}
    ~groupXZJ(){}
    
private:
    long _groupNum;
    std::shared_ptr<std::vector<std::shared_ptr<QQDataXZJ>>> _tempqqGro;
    std::shared_ptr<std::vector<std::shared_ptr<QQDataXZJ>>> _qqGro;
    std::shared_ptr<std::vector<std::shared_ptr<QQDataXZJ>>> _askJoinQQGro;
    std::shared_ptr<std::vector<std::shared_ptr<QQDataXZJ>>> _askJointempQQGro;
    std::shared_ptr<std::vector<std::shared_ptr<QQDataXZJ>>> _qqGroAdministrators;
    
    std::shared_ptr<std::vector<std::shared_ptr<WBDataXZJ>>> _tempwbGro;
    std::shared_ptr<std::vector<std::shared_ptr<WBDataXZJ>>> _wbGro;
    std::shared_ptr<std::vector<std::shared_ptr<WBDataXZJ>>> _askJoinWBGro;
    std::shared_ptr<std::vector<std::shared_ptr<WBDataXZJ>>> _askJointempWBGro;
    std::shared_ptr<std::vector<std::shared_ptr<WBDataXZJ>>> _wbGroAdministrators;
    
    std::shared_ptr<std::vector<std::shared_ptr<WCDataXZJ>>> _tempwcGro;
    std::shared_ptr<std::vector<std::shared_ptr<WCDataXZJ>>> _wcGro;
    std::shared_ptr<std::vector<std::shared_ptr<WCDataXZJ>>> _askJoinWCGro;
    std::shared_ptr<std::vector<std::shared_ptr<WCDataXZJ>>> _askJointempWCGro;
    std::shared_ptr<std::vector<std::shared_ptr<WCDataXZJ>>> _wcGroAdministrators;
};
#endif /* groupXZJ_hpp */
