//
//  BasicDataXZJ.cpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "BasicDataXZJ.hpp"
bool Time::operator==(const Time& time)const
{
    if(this->_y.val!=time._y.val||this->_m.val!=time._m.val||this->_d.val!=time._d.val)
        return 0;
    return 1;
}
bool Time::operator!=(const Time& time)const
{
    return !(*this==time);
}
std::ostream& operator<<(std::ostream& os, const Time& t)
{
    os<<t.year()<<"年"<<t.month()<<"月"<<t.day()<<"日";
    return os;
}
const bool BasicDataXZJ::operator==(const BasicDataXZJ& qd)
{
    return static_cast<const BasicDataXZJ&>(*this)==qd;
}
const bool BasicDataXZJ::operator!=(const BasicDataXZJ& qd)
{
    return !(*this==qd);
}
const bool BasicDataXZJ::operator==(BasicDataXZJ& qd)
{
    return *this==static_cast<const BasicDataXZJ&>(qd);
}
const bool BasicDataXZJ::operator!=(BasicDataXZJ& qd)
{
    return !(*this==qd);
}
const bool BasicDataXZJ::operator==(BasicDataXZJ& qd)const
{
    return *this==static_cast<const BasicDataXZJ&>(qd);
}
const bool BasicDataXZJ::operator!=(BasicDataXZJ& qd)const
{
    return !(*this==qd);
}
const bool BasicDataXZJ::operator==(const BasicDataXZJ& qd)const
{
    if(this->ID()!=qd.ID()&&this->home()!=qd.home()&&this->name()!=qd.name()&&this->t_age()==qd.t_age()&&this->birth()==qd.birth())
        return 0;
    return 1;
}
const bool BasicDataXZJ::operator!=(const BasicDataXZJ& qd)const
{
    return !(*this==qd);
}
