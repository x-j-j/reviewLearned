//
//  logXZJ.hpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef logXZJ_hpp
#define logXZJ_hpp
#include <iostream>
class logImplXZJ;
class QQDataXZJ;
class WBDataXZJ;
class WCDataXZJ;
class Files;
class logXZJ
{
public:
    logXZJ(const std::shared_ptr<Files>& _pF);//调用文件写入QQ，微信，微博数据
    const std::shared_ptr<QQDataXZJ> logQQ(long accnum);//简单确认之后其他自动登录
    const std::shared_ptr<WBDataXZJ> logWB(long accnum);
    const std::shared_ptr<WCDataXZJ> logWC(long accnum);
    
    const std::shared_ptr<QQDataXZJ> nopasswordlogQQ(long accnum);
    const std::shared_ptr<WBDataXZJ> nopasswordlogWB(long accnum);
    const std::shared_ptr<WCDataXZJ> nopasswordlogWC(long accnum);
    
    const std::shared_ptr<QQDataXZJ> pQD()const;
    const std::shared_ptr<WBDataXZJ> pWBD()const;
    const std::shared_ptr<WCDataXZJ> pWCD()const;
    ~logXZJ(){}
private:
    std::shared_ptr<logImplXZJ> plI=nullptr;
};
#endif /* logXZJ_hpp */
