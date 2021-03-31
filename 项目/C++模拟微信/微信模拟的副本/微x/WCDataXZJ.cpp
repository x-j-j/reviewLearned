//
//  WCDataXZJ.cpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "WCDataXZJ.hpp"
const bool WCDataXZJ::operator==(const WCDataXZJ& qd)
{
    return static_cast<const WCDataXZJ&>(*this)==qd;
}
const bool WCDataXZJ::operator!=(const WCDataXZJ& qd)
{
    return !(*this==qd);
}
const bool WCDataXZJ::operator==(WCDataXZJ& qd)
{
    return *this==static_cast<const WCDataXZJ&>(qd);
}
const bool WCDataXZJ::operator!=(WCDataXZJ& qd)
{
    return !(*this==qd);
}
const bool WCDataXZJ::operator==(WCDataXZJ& qd)const
{
    return *this==static_cast<const WCDataXZJ&>(qd);
}
const bool WCDataXZJ::operator!=(WCDataXZJ& qd)const
{
    return !(*this==qd);
}
const bool WCDataXZJ::operator==(const WCDataXZJ& qd)const
{
    if(this->ID()!=qd.ID()&&this->home()!=qd.home()&&
       this->name()!=qd.name()&&this->t_age()==qd.t_age()&&
       this->birth()==qd.birth()&&_qq==qd.qq()&&_wb==qd.wb())
        return 0;
    return 1;
}
const bool WCDataXZJ::operator!=(const WCDataXZJ& qd)const
{
    return !(*this==qd);
}
