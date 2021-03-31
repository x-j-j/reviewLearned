//
//  BasicDataXZJ.hpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef BasicDataXZJ_hpp
#define BasicDataXZJ_hpp
#include <iostream>
#include <vector>//一定要包含
struct Day
{
    Day(){}
    explicit Day(long d):val(d){}
    long val;
};
struct Month
{
    Month(){}
    explicit Month(long m):val(m){}
    long val;
};
struct Year
{
    Year(){}
    explicit Year(long y):val(y){}
    long val;
};
class Time
{
public:
    Time(){}
    explicit Time(const Year& y, const Month& m, const Day& d):_y(y),_m(m),_d(d){}
    void show()const{std::cout<<_y.val<<"年"<<_m.val<<"月"<<_d.val<<"日";}
    void year(long y){_y.val=y;}
    void month(long m){_m.val=m;}
    void day(long d){_d.val=d;}
    const long year()const{return _y.val;}
    const long month()const{return _m.val;}
    const long day()const{return _d.val;}
    
    bool operator==(const Time& time)const;
    bool operator!=(const Time& time)const;
private:
    Year _y;
    Month _m;
    Day _d;
};
std::ostream& operator<<(std::ostream& os, const Time& t);

class BasicDataXZJ
{
public:
    BasicDataXZJ(){}
    explicit BasicDataXZJ(const long id, const long password,
                          const std::string& name, const std::string& home,
                          const Time& birth, const Time& t_age)
    :_password(password),_ID(id),_name(name),_home(home),_birth(birth),_t_age(t_age){}
    virtual ~BasicDataXZJ(){}
    
    const long ID()const{return _ID;}
    long ID(){return _ID;}
    const long password()const{return _password;}
    const std::string& name()const{return _name;}
    const std::string& home()const{return _home;}
    const Time& birth()const{return _birth;}
    const Time& t_age()const{return _t_age;}
    
    std::vector<long>& groNum(){return _groNum;}
    std::vector<long>& tempgroNum(){return _tempgroNum;}
    long& changepassword(){return _password;}
    
    const bool operator==(const BasicDataXZJ& qd);
    const bool operator!=(const BasicDataXZJ& qd);
    const bool operator==(BasicDataXZJ& qd)const;
    const bool operator!=(BasicDataXZJ& qd)const;
    const bool operator==(const BasicDataXZJ& qd)const;
    const bool operator!=(const BasicDataXZJ& qd)const;
    const bool operator==(BasicDataXZJ& qd);
    const bool operator!=(BasicDataXZJ& qd);
private:
    long _ID;
    long _password;
    std::string _name;
    std::string _home;
    std::vector<long> _groNum;
    std::vector<long> _tempgroNum;
    Time _birth;
    Time _t_age;
};
#endif /* BasicDataXZJ_hpp */
