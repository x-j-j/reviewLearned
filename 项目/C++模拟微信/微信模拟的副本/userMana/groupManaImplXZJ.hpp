//
//  groupManaImplXZJ.hpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef groupManaImplXZJ_hpp
#define groupManaImplXZJ_hpp
#include <iostream>
#include <ctime>
#include "Files.hpp"
#include "BasicDataXZJ.hpp"
#include "QQDataXZJ.hpp"
#include "WBDataXZJ.hpp"
#include "WCDataXZJ.hpp"
enum type{ qq, wc, wb};
enum managertype{ Owner, administrator, normal};
class groupManaImplXZJ
{
public:       //调用文件写入QQ，微信，微博数据
    explicit groupManaImplXZJ(const std::shared_ptr<Files>& _pF);
    explicit groupManaImplXZJ(const std::shared_ptr<Files>& _pF, const std::shared_ptr<QQDataXZJ>& user);
    explicit groupManaImplXZJ(const std::shared_ptr<Files>& _pF, const std::shared_ptr<WCDataXZJ>& user);
    explicit groupManaImplXZJ(const std::shared_ptr<Files>& _pF, const std::shared_ptr<WBDataXZJ>& user);
    
    void ModeOne();//群可以申请加入，可以设置临时讨论组，群主和管理员一起管理群
    void ModeTwo();//群只能推荐加入，不可以设置临时讨论组，群主管理群
    ~groupManaImplXZJ(){}
    
private://加群没有单独函数，因为加群的理念不一样，不会涉及到代码重复
    
    //应用里面操作
    void creatGro();
    
    int inGro(long i);
    
    
    void exitGro(long& i, std::shared_ptr<QQDataXZJ>);//给出这个人的 位置 和 这个人 退出群
    void exitGro(long& i, std::shared_ptr<WCDataXZJ>);
    void exitGro(long& i, std::shared_ptr<WBDataXZJ>);
    void showAllGroNum();
    void showGroNum();
    void showtempGroNum();
    
    //在你进入的群里面操作
    void showperson(const std::__wrap_iter<std::shared_ptr<QQDataXZJ> *>& p)const;//展示一个人
    void showperson(const std::__wrap_iter<std::shared_ptr<WCDataXZJ> *>& p)const;
    void showperson(const std::__wrap_iter<std::shared_ptr<WBDataXZJ> *>& p)const;
    void showperson(const std::shared_ptr<std::vector<std::shared_ptr<QQDataXZJ>>>& p)const;//展示一群人
    void showperson(const std::shared_ptr<std::vector<std::shared_ptr<WCDataXZJ>>>& p)const;
    void showperson(const std::shared_ptr<std::vector<std::shared_ptr<WBDataXZJ>>>& p)const;
    
    
    void searchMem()const;//直接展示所有成员
    void searchMem(const std::string& name)const;//查询成员，名字查询
    void searchMem(const long id)const;//ID查询
    void manageSearchMem();
    
    void settempdisgro();
    
    
    //群主和管理员的功能函数
    bool isOwner();
    bool isAdministrator();
    void confirmPosition();
    
    void Kickmem(long number);
    void disSolvedGro();
    void addMem();
    void setAdministrator(long number);
    
    
    type _t;//登录的种类
    managertype _mt;//群中的地位
    std::shared_ptr<QQDataXZJ> pQD=nullptr;//当前使用的人
    std::shared_ptr<WCDataXZJ> pWCD=nullptr;
    std::shared_ptr<WBDataXZJ> pWBD=nullptr;
    
    std::shared_ptr<Files> pF=nullptr;
    std::shared_ptr<QQXZJ> pQ=nullptr;//里面有群
    std::shared_ptr<WBXZJ> pWB=nullptr;
    std::shared_ptr<WCXZJ> pWC=nullptr;
    std::shared_ptr<groupXZJ> _qqGro=nullptr;//当前登录的群
    std::shared_ptr<groupXZJ> _wbGro=nullptr;
    std::shared_ptr<groupXZJ> _wcGro=nullptr;
};
#endif /* groupManaImplXZJ_hpp */
