//
//  groupManaXZJ.cpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "groupManaXZJ.hpp"
#include "groupManaImplXZJ.hpp"
groupManaXZJ::groupManaXZJ(const std::shared_ptr<Files>& _pF, const std::shared_ptr<QQDataXZJ>& pQD)//调用文件写入QQ，微信，微博数据
{
    pgMI=(std::make_shared<groupManaImplXZJ>(_pF, pQD));
}
groupManaXZJ::groupManaXZJ(const std::shared_ptr<Files>& _pF, const std::shared_ptr<WCDataXZJ>& pWCD)
{
    pgMI=(std::make_shared<groupManaImplXZJ>(_pF, pWCD));
}
groupManaXZJ::groupManaXZJ(const std::shared_ptr<Files>& _pF, const std::shared_ptr<WBDataXZJ>& pWBD)
{
    pgMI=(std::make_shared<groupManaImplXZJ>(_pF, pWBD));
}
void groupManaXZJ::ModeOne()
{
    pgMI->ModeOne();
}
void groupManaXZJ::ModeTwo()
{
    pgMI->ModeTwo();
}
