//
//  WCDataXZJ.hpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef WCDataXZJ_hpp
#define WCDataXZJ_hpp
#include <iostream>
#include "BasicDataXZJ.hpp"
class WCDataXZJ:public BasicDataXZJ
{
public:
    WCDataXZJ():BasicDataXZJ(){}
    explicit WCDataXZJ(const std::string& name, const std::string& home,
                       const Time& birth, const Time& t_age,
                       long id, long password, long qq=0, long wb=0)
    :BasicDataXZJ(id,password,name,home,birth,t_age),_qq(qq),_wb(wb){}
    
    explicit WCDataXZJ(std::__wrap_iter<const std::shared_ptr<WCDataXZJ> *> i):
    BasicDataXZJ((*i)->ID(),
                 (*i)->password(),
                 (*i)->name(),
                 (*i)->home(),
                 (*i)->birth(),
                 (*i)->t_age()),_qq((*i)->qq()),_wb((*i)->wb()){}
    
    explicit WCDataXZJ(const std::shared_ptr<WCDataXZJ>& i):
    BasicDataXZJ(i->ID(),
                 i->password(),
                 i->name(),
                 i->home(),
                 i->birth(),
                 i->t_age()),_qq(i->qq()),_wb(i->wb()){}
    
    explicit WCDataXZJ(const WCDataXZJ& wc)
    :BasicDataXZJ(wc.ID(),wc.password(),wc.name(),wc.home(),wc.birth(),wc.t_age()),_qq(wc.qq()),_wb(wc.wb()){}
    
    explicit WCDataXZJ(const BasicDataXZJ& wc)
    :BasicDataXZJ(wc.ID(),wc.password(),wc.name(),wc.home(),wc.birth(),wc.t_age()),_qq(0),_wb(0){}
    
    virtual ~WCDataXZJ(){}
    
    long& qq(){return _qq;}
    long& wb(){return _wb;}
    const long qq()const{return _qq;}
    const long wb()const{return _wb;}
    std::vector<std::shared_ptr<WCDataXZJ>>& friendList(){return _friendList;}
    std::vector<std::shared_ptr<WCDataXZJ>>& askfriendList(){return _askfriendList;}
    std::vector<long>& friendlistnum(){return _friendlistnum;}
    std::vector<long>& askfriendlistnum(){return _askfriendlistnum;}
    
    const bool operator==(const WCDataXZJ& qd);
    const bool operator!=(const WCDataXZJ& qd);
    const bool operator==(WCDataXZJ& qd)const;
    const bool operator!=(WCDataXZJ& qd)const;
    const bool operator==(const WCDataXZJ& qd)const;
    const bool operator!=(const WCDataXZJ& qd)const;
    const bool operator==(WCDataXZJ& qd);
    const bool operator!=(WCDataXZJ& qd);
private:
    long _qq=0;
    long _wb=0;
    std::vector<std::shared_ptr<WCDataXZJ>> _friendList;
    std::vector<long> _friendlistnum;
    std::vector<std::shared_ptr<WCDataXZJ>> _askfriendList;
    std::vector<long> _askfriendlistnum;
};
#endif /* WCDataXZJ_hpp */
