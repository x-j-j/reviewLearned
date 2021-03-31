//
//  QQDataXZJ.hpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef QQDataXZJ_hpp
#define QQDataXZJ_hpp
#include <iostream>
#include "BasicDataXZJ.hpp"
class QQDataXZJ:public BasicDataXZJ
{
public:
    QQDataXZJ():BasicDataXZJ(){}
    explicit QQDataXZJ(const std::string& name, const std::string& home,
                       const Time& birth, const Time& t_age,
                       long id, long password, long wc=0, long wb=0, long qqNum=0)
    :BasicDataXZJ(id,password,name,home,birth,t_age),_wc(wc),_wb(wb),_qqNum(qqNum){}
    
    explicit QQDataXZJ(std::__wrap_iter<const std::shared_ptr<QQDataXZJ> *> i):
    BasicDataXZJ((*i)->ID(),
                 (*i)->password(),
                 (*i)->name(),
                 (*i)->home(),
                 (*i)->birth(),
                 (*i)->t_age()),_wc((*i)->wc()),_wb((*i)->wb()),_qqNum((*i)->qqNum()){}
    
    explicit QQDataXZJ(const std::shared_ptr<QQDataXZJ>& i):
    BasicDataXZJ(i->ID(),
                 i->password(),
                 i->name(),
                 i->home(),
                 i->birth(),
                 i->t_age()),_wc(i->wc()),_wb(i->wb()),_qqNum(i->qqNum()){}
    
    explicit QQDataXZJ(const QQDataXZJ& qd)
    :BasicDataXZJ(qd.ID(),qd.password(),qd.name(),qd.home(),qd.birth(),qd.t_age()),_wc(qd.wc()),_wb(qd.wb()),_qqNum(qd.qqNum()){}
    
    explicit QQDataXZJ(const BasicDataXZJ& qd)
    :BasicDataXZJ(qd.ID(),qd.password(),qd.name(),qd.home(),qd.birth(),qd.t_age()),_wc(0),_wb(0),_qqNum(0){}
    
    virtual ~QQDataXZJ(){}
    
    long& qqNum(){return _qqNum;}
    long& wc(){return _wc;}
    long& wb(){return _wb;}
    const long qqNum()const{return _qqNum;}
    const long wc()const{return _wc;}
    const long wb()const{return _wb;}
    
    std::vector<std::shared_ptr<QQDataXZJ>>& friendList(){return _friendList;}
    std::vector<std::shared_ptr<QQDataXZJ>>& askfriendList(){return _askfriendList;}
    std::vector<long>& friendlistnum(){return _friendlistnum;}
    std::vector<long>& askfriendlistnum(){return _askfriendlistnum;}
    
    const bool operator==(const QQDataXZJ& qd);
    const bool operator!=(const QQDataXZJ& qd);
    const bool operator==(QQDataXZJ& qd)const;
    const bool operator!=(QQDataXZJ& qd)const;
    const bool operator==(const QQDataXZJ& qd)const;
    const bool operator!=(const QQDataXZJ& qd)const;
    const bool operator==(QQDataXZJ& qd);
    const bool operator!=(QQDataXZJ& qd);
    
    
private:
    long _qqNum=0;
    long _wc=0;
    long _wb=0;
    std::vector<std::shared_ptr<QQDataXZJ>> _friendList;
    std::vector<long> _friendlistnum;
    std::vector<std::shared_ptr<QQDataXZJ>> _askfriendList;
    std::vector<long> _askfriendlistnum;
};
#endif /* QQDataXZJ_hpp */
