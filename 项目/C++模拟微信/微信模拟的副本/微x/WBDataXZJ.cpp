//
//  WBDataXZJ.cpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "WBDataXZJ.hpp"
const bool WBDataXZJ::operator==(const WBDataXZJ& qd)
{
    return static_cast<const WBDataXZJ&>(*this)==qd;
}
const bool WBDataXZJ::operator!=(const WBDataXZJ& qd)
{
    return !(*this==qd);
}
const bool WBDataXZJ::operator==(WBDataXZJ& qd)
{
    return *this==static_cast<const WBDataXZJ&>(qd);
}
const bool WBDataXZJ::operator!=(WBDataXZJ& qd)
{
    return !(*this==qd);
}
const bool WBDataXZJ::operator==(WBDataXZJ& qd)const
{
    return *this==static_cast<const WBDataXZJ&>(qd);
}
const bool WBDataXZJ::operator!=(WBDataXZJ& qd)const
{
    return !(*this==qd);
}
const bool WBDataXZJ::operator==(const WBDataXZJ& qd)const
{
    if(this->ID()!=qd.ID()&&this->home()!=qd.home()&&
       this->name()!=qd.name()&&this->t_age()==qd.t_age()&&
       this->birth()==qd.birth()&&_wbNum==qd.wbNum()&&_qq==qd.qq()&&_wc==qd.wc())
        return 0;
    return 1;
}
const bool WBDataXZJ::operator!=(const WBDataXZJ& qd)const
{
    return !(*this==qd);
}
