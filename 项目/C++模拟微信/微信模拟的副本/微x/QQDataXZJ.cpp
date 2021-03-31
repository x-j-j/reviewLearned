//
//  QQDataXZJ.cpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "QQDataXZJ.hpp"
const bool QQDataXZJ::operator==(const QQDataXZJ& qd)
{
    return static_cast<const QQDataXZJ&>(*this)==qd;
}
const bool QQDataXZJ::operator!=(const QQDataXZJ& qd)
{
    return !(*this==qd);
}
const bool QQDataXZJ::operator==(QQDataXZJ& qd)
{
    return *this==static_cast<const QQDataXZJ&>(qd);
}
const bool QQDataXZJ::operator!=(QQDataXZJ& qd)
{
    return !(*this==qd);
}
const bool QQDataXZJ::operator==(QQDataXZJ& qd)const
{
    return *this==static_cast<const QQDataXZJ&>(qd);
}
const bool QQDataXZJ::operator!=(QQDataXZJ& qd)const
{
    return !(*this==qd);
}
const bool QQDataXZJ::operator==(const QQDataXZJ& qd)const
{
    if(this->ID()!=qd.ID()&&this->home()!=qd.home()&&
       this->name()!=qd.name()&&this->t_age()==qd.t_age()&&
       this->birth()==qd.birth()&&_qqNum==qd.qqNum()&&_wc==qd.wc()&&_wb==qd.wb())
        return 0;
    return 1;
}
const bool QQDataXZJ::operator!=(const QQDataXZJ& qd)const
{
    return !(*this==qd);
}

