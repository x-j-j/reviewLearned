//
//  groupManaXZJ.hpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef groupManaXZJ_hpp
#define groupManaXZJ_hpp
#include <iostream>
class groupManaImplXZJ;
class QQDataXZJ;
class WCDataXZJ;
class WBDataXZJ;
class Files;
class groupManaXZJ
{
public:
    explicit groupManaXZJ(const std::shared_ptr<Files>& _pF, const std::shared_ptr<QQDataXZJ>& pQD);//调用文件写入QQ，微信，微博数据
    explicit groupManaXZJ(const std::shared_ptr<Files>& _pF, const std::shared_ptr<WCDataXZJ>& pWCD);
    explicit groupManaXZJ(const std::shared_ptr<Files>& _pF, const std::shared_ptr<WBDataXZJ>& pWBD);
    void ModeOne();
    void ModeTwo();
    ~groupManaXZJ(){}
    
private:
    std::shared_ptr<groupManaImplXZJ> pgMI=nullptr;
};
#endif /* groupManaXZJ_hpp */
