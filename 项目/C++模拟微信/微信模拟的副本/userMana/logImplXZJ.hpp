//
//  logImplXZJ.hpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef logImplXZJ_hpp
#define logImplXZJ_hpp
#include <iostream>
#include "Files.hpp"
#include "QQDataXZJ.hpp"
#include "WBDataXZJ.hpp"
#include "WCDataXZJ.hpp"
class logImplXZJ
{
public:
    explicit logImplXZJ(const std::shared_ptr<Files>& _pF)    //调用文件写入QQ，微信，微博数据
    {
        pF=(_pF);
        _pQ=(pF->QQ());
        _pWC=(pF->WC());
        _pWB=(pF->WB());
    }
    
    const std::shared_ptr<QQDataXZJ> logQQ(long accnum);
    const std::shared_ptr<WBDataXZJ> logWB(long accnum);
    const std::shared_ptr<WCDataXZJ> logWC(long accnum);
    
    const std::shared_ptr<QQDataXZJ> nopasswordlogQQ(long accnum);
    const std::shared_ptr<WBDataXZJ> nopasswordlogWB(long accnum);
    const std::shared_ptr<WCDataXZJ> nopasswordlogWC(long accnum);
    
    const std::shared_ptr<QQDataXZJ> pQD()const{return _pQD;}
    const std::shared_ptr<WBDataXZJ> pWBD()const{return _pWBD;}
    const std::shared_ptr<WCDataXZJ> pWCD()const{return _pWCD;}
    ~logImplXZJ(){}
private:
    std::shared_ptr<Files> pF=nullptr;
    std::shared_ptr<QQXZJ> _pQ=nullptr;
    std::shared_ptr<WBXZJ> _pWB=nullptr;
    std::shared_ptr<WCXZJ> _pWC=nullptr;
    std::shared_ptr<QQDataXZJ> _pQD=nullptr;
    std::shared_ptr<WBDataXZJ> _pWBD=nullptr;
    std::shared_ptr<WCDataXZJ> _pWCD=nullptr;
    const std::shared_ptr<QQDataXZJ> findQQperson(long accnum)const;
    const std::shared_ptr<WBDataXZJ> findWBperson(long accnum)const;
    std::__wrap_iter<const std::shared_ptr<WCDataXZJ> *> extracted() const;
    
    const std::shared_ptr<WCDataXZJ> findWCperson(long accnum)const;
};
#endif /* logImplXZJ_hpp */
