//
//  creatAccXZJ.hpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef creatAccXZJ_hpp
#define creatAccXZJ_hpp
#include <iostream>
class creatAccImplXZJ;
class QQDataXZJ;
class WBDataXZJ;
class WCDataXZJ;
class Files;
class creatAccXZJ
{
public:
    creatAccXZJ(const std::shared_ptr<Files>& _pF);
    const std::shared_ptr<QQDataXZJ> creatQQAcc();
    const std::shared_ptr<WBDataXZJ> creatWBAcc();
    const std::shared_ptr<WCDataXZJ> creatWCAcc();
    ~creatAccXZJ(){}
private:
    std::shared_ptr<creatAccImplXZJ> pcAI=nullptr;
};
#endif /* creatAccXZJ_hpp */
