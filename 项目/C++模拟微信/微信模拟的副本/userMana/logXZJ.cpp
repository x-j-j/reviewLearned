//
//  logXZJ.cpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "logXZJ.hpp"
#include "logImplXZJ.hpp"
logXZJ::logXZJ(const std::shared_ptr<Files>& _pF)
//调用文件写入QQ，微信，微博数据
{
    plI=(std::make_shared<logImplXZJ>(_pF));
}
const std::shared_ptr<QQDataXZJ> logXZJ::logQQ(long accnum)//简单确认之后其他自动登录
{
    return plI->logQQ(accnum);
}
const std::shared_ptr<WBDataXZJ> logXZJ::logWB(long accnum)
{
    return plI->logWB(accnum);
}
const std::shared_ptr<WCDataXZJ> logXZJ::logWC(long accnum)
{
    return plI->logWC(accnum);
}

const std::shared_ptr<QQDataXZJ> logXZJ::pQD()const
{
    return plI->pQD();
}
const std::shared_ptr<WBDataXZJ> logXZJ::pWBD()const
{
    return plI->pWBD();
}
const std::shared_ptr<WCDataXZJ> logXZJ::pWCD()const
{
    return plI->pWCD();
}
const std::shared_ptr<QQDataXZJ> logXZJ::nopasswordlogQQ(long accnum)
{
    return plI->nopasswordlogQQ(accnum);
}
const std::shared_ptr<WBDataXZJ> logXZJ::nopasswordlogWB(long accnum)
{
    return plI->nopasswordlogWB(accnum);
}
const std::shared_ptr<WCDataXZJ> logXZJ::nopasswordlogWC(long accnum)
{
    return plI->nopasswordlogWC(accnum);
}
