//
//  creatAccImplXZJ.cpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "creatAccImplXZJ.hpp"
creatAccImplXZJ::creatAccImplXZJ(const std::shared_ptr<Files>& pF)
{
    _pF=(pF);
    _pQ=(std::make_shared<QQXZJ>(_pF->QQ()));
    _pWC=(std::make_shared<WCXZJ>(_pF->WC()));
    _pWB=(std::make_shared<WBXZJ>(_pF->WB()));
}
const std::shared_ptr<QQDataXZJ> creatAccImplXZJ::creatQQAcc()
{
    time(&rawtime);
    ptminfo = localtime(&rawtime);
    srand(static_cast<unsigned>(time(0)));
//年    ptminfo->tm_year + 1900
//月    ptminfo->tm_mon + 1
//日    ptminfo->tm_mday
    
//    cout << rand() % 100 << endl;
    
    
    long _password, password;
    std::cout<<"设置密码__";std::cin>>_password;
    std::cout<<std::endl;
    std::cout<<"再次输入密码__";std::cin>>password;
    std::cout<<std::endl;
    while(_password!=password)
    {
        std::cout<<"密码有误";
        std::cout<<std::endl;
        std::cout<<"再次输入密码__";std::cin>>password;
        std::cout<<std::endl;
    }
    
    
    std::string _name;
    std::cout<<"输入你想起的名字__";std::cin>>_name;
    std::cout<<std::endl;
    
    
    std::string _home;
    std::cout<<"输入你的家乡__";std::cin>>_home;
    std::cout<<std::endl;
    
    
    long i,j,k;
    std::cout<<"输入你的出生日期: 年__";std::cin>>i;
    Year y(i);
    std::cout<<" 月__";std::cin>>j;
    Month m(j);
    std::cout<<" 日__";std::cin>>k;
    Day d(k);
    Time _birth(y, m, d);
    std::cout<<std::endl;
    
    
    Time _t_age(Year(ptminfo->tm_year + 1900), Month(ptminfo->tm_mon + 1), Day(ptminfo->tm_mday));//根据系统时间
    
    
    long _ID;//随机生成，不能重复
    long _qqNum;//随机生成，不能重复
    long _wb=0, _wc=0;
    std::cout<<"是否想要绑定   是Y/y,  否N/n"<<std::endl;
    char cho;
    long judge1, judge2, judge3, judge4=1;//判断是否输入错误
    long yby=0;//是否继续绑定
    do {
        judge1=1;
        std::cin>>cho;
        switch (cho) {
            case 'Y':
            case 'y':
            {
                do {
                    do {
                        std::cout<<"绑定  a.微博  b.微信__";
                        char ch;std::cin>>ch;
                        judge2=0;
                        switch (ch) {
                            case 'a':
                            {
                                std::cout<<"绑定  a.微博ID  b.微博账号__";
                                char c;
                                std::cin>>c;
                                do {
                                    judge3=0;
                                    switch (c) {
                                        case 'a':
                                            std::cout<<"输入ID号__";
                                            long idNum;
                                            std::cin>>idNum;
                                            _wb=ConnectWB(ID, idNum);
                                            break;
                                        case 'b':
                                            std::cout<<"输入账号__";
                                            long Number;
                                            std::cin>>Number;
                                            _wb=ConnectWB(number, Number);
                                            break;
                                        default:
                                            std::cout<<"只能输入a,b哦"<<std::endl<<"重新输入__";
                                            std::cin>>c;
                                            judge3=1;
                                            break;
                                    }
                                }while(judge3);
                                
                                break;
                            }
                            case 'b':
                            {
                                std::cout<<"输入绑定的微信ID号码__";
                                long id;
                                std::cin>>id;
                                _ID=ConnectWC(ID, id);
                                _wc=_ID;
                                judge4=0;
                                break;
                            }
                            default:
                            {
                                std::cout<<"只能输入a,b哦"<<std::endl<<"重新输入__";
                                std::cin>>ch;
                                judge2=1;
                                break;
                            }
                        }
                    }while(judge2);
                    std::cout<<"还要继续绑定吗  1.要  2.不要";
                    std::cin>>yby;
                }while(yby==1);
                break;
            }
            case 'N':
            case 'n':
                break;
            default:
            {
                std::cout<<"只能输入Y,y,N,n哦";
                judge1=0;
                break;
            }
        }
    }while(judge1==0);
    
    if(judge4!=0)
    {
        _ID=rand()%1000000;
        if(!(_pQ->people()->empty()))
            for(auto i=(_pQ->people())->cbegin(); i!=(_pQ->people())->cend(); ++i){
                if(_ID==(*i)->ID()){
                    do {
                        _ID=rand()%1000000;
                    }while(_ID==(*i)->ID());
                }
            }
    }
    _qqNum=rand()%10000000000;
    if(!(_pQ->people())->empty())
        for(auto i=(_pQ->people())->cbegin(); i!=(_pQ->people())->cend(); ++i){
            if(_qqNum==(*i)->qqNum()){
                do {
                    _qqNum=rand()%10000000000;
                }while(_qqNum==(*i)->qqNum());
            }
        }
    std::cout<<"**创建成功**"<<std::endl;
    std::cout<<"QQ号是:"<<_qqNum<<std::endl;
    
    return std::make_shared<QQDataXZJ>(_name, _home, _birth, _t_age, _ID, password, _wc, _wb, _qqNum);
}





const std::shared_ptr<WBDataXZJ> creatAccImplXZJ::creatWBAcc()
{
    time(&rawtime);
    ptminfo = localtime(&rawtime);
    srand(static_cast<unsigned>(time(0)));
    
    
    long _password, password;
    std::cout<<"设置密码__";std::cin>>_password;
    std::cout<<std::endl;
    std::cout<<"再次输入密码__";std::cin>>password;
    std::cout<<std::endl;
    while(_password!=password)
    {
        std::cout<<"密码有误";
        std::cout<<std::endl;
        std::cout<<"再次输入密码__";std::cin>>password;
        std::cout<<std::endl;
    }
    
    
    std::string _name;
    std::cout<<"输入你想起的名字__";std::cin>>_name;
    std::cout<<std::endl;
    
    
    std::string _home;
    std::cout<<"输入你的家乡__";std::cin>>_home;
    std::cout<<std::endl;
    
    
    long i,j,k;
    std::cout<<"输入你的出生日期: 年__";std::cin>>i;
    Year y(i);
    std::cout<<" 月__";std::cin>>j;
    Month m(j);
    std::cout<<" 日__";std::cin>>k;
    Day d(k);
    Time _birth(y, m, d);
    std::cout<<std::endl;
    
    
    Time _t_age(Year(ptminfo->tm_year + 1900), Month(ptminfo->tm_mon + 1), Day(ptminfo->tm_mday));//根据系统时间
    
    
    long _ID;//随机生成，不能重复
    long _wbNum;//随机生成，不能重复
    long _qq=0, _wc=0;
    std::cout<<"是否想要绑定   是Y/y,  否N/n";
    char cho;
    long judge1=0, judge2=0, judge3=0, judge4=1;//判断是否输入错误
    long yby;//是否继续绑定
    do {
        judge1=0;
        std::cin>>cho;
        switch (cho) {
            case 'Y':
            case 'y':
            {
                do {
                    do {
                        std::cout<<"绑定  a.QQ  b.微信__";
                        char ch;std::cin>>ch;
                        judge2=0;
                        switch (ch) {
                            case 'a':
                                std::cout<<"绑定  a.QQID  b.QQ账号__";
                                char c;
                                std::cin>>c;
                                do {
                                    judge3=0;
                                    switch (c) {
                                        case 'a':
                                            std::cout<<"输入ID号__";
                                            long idNum;
                                            std::cin>>idNum;
                                            _qq=ConnectQQ(ID, idNum);
                                            break;
                                        case 'b':
                                            std::cout<<"输入账号__";
                                            long Number;
                                            std::cin>>Number;
                                            _qq=ConnectQQ(number, Number);
                                            break;
                                        default:
                                            std::cout<<"只能输入a,b哦"<<std::endl<<"重新输入__";
                                            std::cin>>c;
                                            judge3=1;
                                            break;
                                    }
                                }while(judge3);
                                break;
                            case 'b':
                                std::cout<<"输入绑定的微信ID号码__";
                                long id;
                                std::cin>>id;
                                _ID=ConnectWC(ID, id);
                                _wc=_ID;
                                judge4=0;
                                break;
                            default:
                                std::cout<<"只能输入a,b哦"<<std::endl<<"重新输入__";
                                std::cin>>ch;
                                judge2=1;
                                break;
                        }
                    }while(judge2);
                    std::cout<<"还要继续绑定吗  1.要  2.不要";
                    std::cin>>yby;
                }while(yby);
                break;
            }
            case 'N'://直接生成ID和号码
            case 'n':
                break;
            default:
                std::cout<<"只能输入Y,y,N,n哦";
                judge1=1;
                break;
        }
    }while(judge1);
    
    if(judge4!=0)
    {
        _ID=rand()%1000000;
        for(auto i=(_pWB->people())->cbegin(); i!=(_pWB->people())->cend(); ++i){
            if(_ID==(*i)->ID()){
                do {
                    _ID=rand()%1000000;
                }while(_ID==(*i)->ID());
            }
        }
    }
    
    _wbNum=rand()%10000000000;
    for(auto i=(_pWB->people())->cbegin(); i!=(_pWB->people())->cend(); ++i){
        if(_wbNum==(*i)->wbNum()){
            do {
                _wbNum=rand()%10000000000;
            }while(_wbNum==(*i)->wbNum());
        }
    }
    std::cout<<"**创建成功**";
    std::cout<<"微博号是:";
    std::cout<<_wbNum;
    
    return std::make_shared<WBDataXZJ>(_name, _home, _birth, _t_age, _ID, password, _qq, _wc, _wbNum);
}




const std::shared_ptr<WCDataXZJ> creatAccImplXZJ::creatWCAcc()
{
    time(&rawtime);
    ptminfo = localtime(&rawtime);
    srand(static_cast<unsigned>(time(0)));
    
    
    long _password, password;
    std::cout<<"设置密码__";std::cin>>_password;
    std::cout<<std::endl;
    std::cout<<"再次输入密码__";std::cin>>password;
    std::cout<<std::endl;
    while(_password!=password)
    {
        std::cout<<"密码有误";
        std::cout<<std::endl;
        std::cout<<"再次输入密码__";std::cin>>password;
        std::cout<<std::endl;
    }
    
    
    std::string _name;
    std::cout<<"输入你想起的名字__";std::cin>>_name;
    std::cout<<std::endl;
    
    
    std::string _home;
    std::cout<<"输入你的家乡__";std::cin>>_home;
    std::cout<<std::endl;
    
    
    long i,j,k;
    std::cout<<"输入你的出生日期: 年__";std::cin>>i;
    Year y(i);
    std::cout<<" 月__";std::cin>>j;
    Month m(j);
    std::cout<<" 日__";std::cin>>k;
    Day d(k);
    Time _birth(y, m, d);
    std::cout<<std::endl;
    
    
    Time _t_age(Year(ptminfo->tm_year + 1900), Month(ptminfo->tm_mon + 1), Day(ptminfo->tm_mday));//根据系统时间
    
    
    long _ID;//随机生成，不能重复
    long _qq=0, _wb=0;
    std::cout<<"是否想要绑定   是Y/y,  否N/n";
    char cho; std::cin>>cho;
    long judge1=0, judge2=0, judge3=0;//判断是否输入错误
    long yby;//是否继续绑定
    do {
        judge1=0;
        switch (cho) {
            case 'Y':
            case 'y':
            {
                do {
                    do {
                        std::cout<<"绑定  a.QQ  b.微博__";
                        char ch;std::cin>>ch;
                        judge2=0;
                        switch (ch) {
                            case 'a':
                                std::cout<<"绑定  a.QQID  b.QQ账号__";
                                char c;
                                std::cin>>c;
                                do {
                                    judge3=0;
                                    switch (c) {
                                        case 'a':
                                            std::cout<<"输入ID号__";
                                            long idNum;
                                            std::cin>>idNum;
                                            _qq=ConnectQQ(ID, idNum);
                                            break;
                                        case 'b':
                                            std::cout<<"输入账号__";
                                            long Number;
                                            std::cin>>Number;
                                            _qq=ConnectQQ(number, Number);
                                            break;
                                        default:
                                            std::cout<<"只能输入a,b哦"<<std::endl<<"重新输入__";
                                            std::cin>>c;
                                            judge3=1;
                                            break;
                                    }
                                }while(judge3);
                                break;
                            case 'b':
                                std::cout<<"绑定  a.微博ID  b.微博账号__";
                                char cc;
                                std::cin>>cc;
                                do {
                                    judge3=0;
                                    switch (cc) {
                                        case 'a':
                                            std::cout<<"输入ID号__";
                                            long idNum;
                                            std::cin>>idNum;
                                            _wb=ConnectWB(ID, idNum);
                                            break;
                                        case 'b':
                                            std::cout<<"输入账号__";
                                            long Number;
                                            std::cin>>Number;
                                            _wb=ConnectWB(number, Number);
                                            break;
                                        default:
                                            std::cout<<"只能输入a,b哦"<<std::endl<<"重新输入__";
                                            std::cin>>cc;
                                            judge3=1;
                                            break;
                                    }
                                }while(judge3);
                                break;
                            default:
                                std::cout<<"只能输入a,b哦"<<std::endl<<"重新输入__";
                                std::cin>>ch;
                                judge2=1;
                                break;
                        }
                    }while(judge2);
                    std::cout<<"还要继续绑定吗  1.要  2.不要";
                    std::cin>>yby;
                }while(yby);
                break;
            }
            case 'N'://直接生成ID和号码
            case 'n':
                break;
            default:
                std::cout<<"只能输入Y,y,N,n哦";
                judge1=1;
                break;
        }
    }while(judge1);
    
    
    _ID=rand()%1000000;
    for(auto i=(_pQ->people())->cbegin(); i!=(_pQ->people())->cend(); ++i){
        if(_ID==(*i)->ID()){
            do {
                _ID=rand()%1000000;
            }while(_ID==(*i)->ID());
        }
    }
    std::cout<<"**创建成功**";
    std::cout<<"微信ID是:";
    std::cout<<_ID;
    
    return std::make_shared<WCDataXZJ>(_name, _home, _birth, _t_age, _ID, password, _qq, _wb);
}
