//
//  WBDataXZJ.hpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef WBDataXZJ_hpp
#define WBDataXZJ_hpp
#include <iostream>
#include "BasicDataXZJ.hpp"
class WBDataXZJ:public BasicDataXZJ
{
public:
    WBDataXZJ():BasicDataXZJ(){}
    explicit WBDataXZJ(const std::string& name, const std::string& home,
                       const Time& birth, const Time& t_age,
                       long id, long password, long qq=0, long wc=0, long wbNum=0)
    :BasicDataXZJ(id,password,name,home,birth,t_age),_qq(qq),_wc(wc),_wbNum(wbNum){}
    
    explicit WBDataXZJ(std::__wrap_iter<const std::shared_ptr<WBDataXZJ> *> i):
    BasicDataXZJ((*i)->ID(),
                 (*i)->password(),
                 (*i)->name(),
                 (*i)->home(),
                 (*i)->birth(),
                 (*i)->t_age()),_qq((*i)->qq()),_wc((*i)->wc()),_wbNum((*i)->wbNum()){}
    
    explicit WBDataXZJ(const std::shared_ptr<WBDataXZJ>& i):
    BasicDataXZJ(i->ID(),
                 i->password(),
                 i->name(),
                 i->home(),
                 i->birth(),
                 i->t_age()),_qq(i->qq()),_wc(i->wc()),_wbNum(i->wbNum()){}
    
    explicit WBDataXZJ(const WBDataXZJ& wb)
    :BasicDataXZJ(wb.ID(),wb.password(),wb.name(),wb.home(),wb.birth(),wb.t_age()),_qq(wb.qq()),_wc(wb.wc()),_wbNum(wb.wbNum()){}
    
    explicit WBDataXZJ(const BasicDataXZJ& wb)
    :BasicDataXZJ(wb.ID(),wb.password(),wb.name(),wb.home(),wb.birth(),wb.t_age()),_qq(0),_wc(0),_wbNum(0){}
    
    virtual ~WBDataXZJ(){}
 
    long& qq(){return _qq;}
    long& wc(){return _wc;}
    long& wbNum(){return _wbNum;}
    const long qq()const{return _qq;}
    const long wc()const{return _wc;}
    const long wbNum()const{return _wbNum;}
    
    std::vector<std::shared_ptr<WBDataXZJ>>& friendList(){return _friendList;}
    std::vector<std::shared_ptr<WBDataXZJ>>& askfriendList(){return _askfriendList;}
    std::vector<long>& friendlistnum(){return _friendlistnum;}
    std::vector<long>& askfriendlistnum(){return _askfriendlistnum;}
    
    const bool operator==(const WBDataXZJ& qd);
    const bool operator!=(const WBDataXZJ& qd);
    const bool operator==(WBDataXZJ& qd)const;
    const bool operator!=(WBDataXZJ& qd)const;
    const bool operator==(const WBDataXZJ& qd)const;
    const bool operator!=(const WBDataXZJ& qd)const;
    const bool operator==(WBDataXZJ& qd);
    const bool operator!=(WBDataXZJ& qd);
    
private:
    long _wbNum=0;
    long _qq=0;
    long _wc=0;
    std::vector<std::shared_ptr<WBDataXZJ>> _friendList;
    std::vector<long> _friendlistnum;
    std::vector<std::shared_ptr<WBDataXZJ>> _askfriendList;
    std::vector<long> _askfriendlistnum;
};

#endif /* WBDataXZJ_hpp */
