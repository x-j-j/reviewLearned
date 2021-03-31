//
//  groupManaImplXZJ.cpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "groupManaImplXZJ.hpp"
groupManaImplXZJ::groupManaImplXZJ(const std::shared_ptr<Files>& _pF, const std::shared_ptr<QQDataXZJ>& user):
pF(_pF),
pQ(std::make_shared<QQXZJ>(pF->QQ())),
pWC(std::make_shared<WCXZJ>(pF->WC())),
pWB(std::make_shared<WBXZJ>(pF->WB())),
pQD(user),
_qqGro(std::make_shared<groupXZJ>())
{
    _t=qq;
}
groupManaImplXZJ::groupManaImplXZJ(const std::shared_ptr<Files>& _pF, const std::shared_ptr<WCDataXZJ>& user):
pF(_pF),
pQ(std::make_shared<QQXZJ>(pF->QQ())),
pWC(std::make_shared<WCXZJ>(pF->WC())),
pWB(std::make_shared<WBXZJ>(pF->WB())),
pWCD(user),
_wcGro(std::make_shared<groupXZJ>())
{
    _t=wc;
}
groupManaImplXZJ::groupManaImplXZJ(const std::shared_ptr<Files>& _pF, const std::shared_ptr<WBDataXZJ>& user):
pF(_pF),
pQ(std::make_shared<QQXZJ>(pF->QQ())),
pWC(std::make_shared<WCXZJ>(pF->WC())),
pWB(std::make_shared<WBXZJ>(pF->WB())),
pWBD(user),
_wbGro(std::make_shared<groupXZJ>())
{
    _t=wb;
}
void groupManaImplXZJ::ModeOne()
{
    std::cout<<"选择你的操作  1.创建群  2.申请加群  3.退出群  4.进入群";
    //群管理1.踢人(群主，管理员)  2.解散群（群主）  3.同意网友进群或者拒绝(群主，管理员)  4.设置管理员(群主)  5.(设置临时讨论组)
    long i;
    
    do {
        std::cin>>i;
        switch (i) {
            case 1:
            {
                creatGro();
                break;
            }
            case 2:
            {
                int judge=0;
                showAllGroNum();
                std::cout<<"想加哪个群";
                long u;
                
                switch (_t) {
                    case qq:
                    {
                        do {
                            judge=0;
                            std::cin>>u;
                            for(auto ii=(pQ->groupMana())->begin(); ii!=(pQ->groupMana())->end(); ++ii)
                                if((*ii)->groupNum()==u)
                                {
                                    judge=1;
                                    ((*ii)->askJoinQQGroList())->push_back(pQD);
                                }
                            if(judge==0)
                                std::cout<<"没有这个群"<<std::endl;
                        }while(judge==0);
                        break;
                    }
                    case wb:
                    {
                        do {
                            judge=0;
                            std::cin>>u;
                            for(auto ii=(pWB->groupMana())->begin(); ii!=(pWB->groupMana())->end(); ++ii)
                                if((*ii)->groupNum()==u)
                                {
                                    judge=1;
                                    ((*ii)->askJoinWBGroList())->push_back(pWBD);
                                }
                            if(judge==0)
                                std::cout<<"没有这个群"<<std::endl;
                        }while(judge==0);
                        break;
                    }
                    case wc:
                    {
                        do {
                            judge=0;
                            std::cin>>u;
                            for(auto ii=(pWC->groupMana())->begin(); ii!=(pWC->groupMana())->end(); ++ii)
                                if((*ii)->groupNum()==u)
                                {
                                    judge=1;
                                    ((*ii)->askJoinWCGroList())->push_back(pWCD);
                                }
                            if(judge==0)
                                std::cout<<"没有这个群"<<std::endl;
                        }while(judge==0);
                        break;
                    }
                }
                break;
            }
            case 3:
            {
                std::cout<<"你有这些群:"<<std::endl;
                showGroNum();
                std::cout<<"你有这些临时讨论组"<<std::endl;
                showtempGroNum();
                std::cout<<"输入要退出的群号;"<<std::endl;
                long gron;
                std::cin>>gron;
                switch (_t) {
                    case qq:
                        exitGro(gron, pQD);
                        break;
                    case wb:
                        exitGro(gron, pWCD);
                        break;
                    case wc:
                        exitGro(gron, pWBD);
                        break;
                }
                break;
            }
            case 4:
            {
                int judge=1;
                std::cout<<"群"<<std::endl;
                showGroNum();
                std::cout<<"讨论组"<<std::endl;
                showtempGroNum();
                std::cout<<"输入你要进入的群号";
                long num;
                std::cin>>num;
                
                int ju=inGro(num);
                if(ju==1)
                {
                    std::cout<<"你可以有下面的操作  1.管理群  2.搜索群成员__  3.设置临时讨论组";
                    int choose;
                    do {
                        std::cin>>choose;
                        switch (choose) {
                            case 1:
                            {
                                if(_mt==normal)
                                    std::cout<<"你不是群主或者管理员哦"<<std::endl;
                                else
                                {
                                    if(isOwner())//群主
                                    {
                                        std::cout<<"你是群主"<<std::endl;
                                        std::cout<<"群管理  1.踢人  2.解散群  3.同意网友进群或者拒绝  4.设置管理员";
                                        long cho;
                                        
                                        do {
                                            std::cin>>cho;
                                            switch (cho) {
                                                case 1:
                                                {
                                                    std::vector<std::shared_ptr<std::vector<std::shared_ptr<QQDataXZJ>>>>::size_type count=0;
                                                    searchMem();
                                                    switch (_t) {
                                                        case qq:
                                                            count=(_qqGro->qqGro()->size());
                                                            break;
                                                        case wc:
                                                            count=(_wcGro->wcGro())->size();
                                                            break;
                                                        case wb:
                                                            count=(_wbGro->wbGro())->size();
                                                            break;
                                                    }
                                                    std::cout<<"输入你要踢出的人的编号";
                                                    while(1)
                                                    {
                                                        long bh;
                                                        std::cin>>bh;
                                                        if(bh<=0||bh>count)
                                                        {
                                                            std::cout<<"没有这个人";
                                                            std::cin>>bh;
                                                        }
                                                        else
                                                            Kickmem(bh-1);
                                                    }
                                                    break;
                                                }
                                                case 2:
                                                {
                                                    disSolvedGro();
                                                    break;
                                                }
                                                case 3:
                                                {
                                                    addMem();
                                                    break;
                                                }
                                                case 4:
                                                {
                                                    searchMem();
                                                    std::cout<<"输入你要设置的人的编号";
                                                    long bh;
                                                    std::cin>>bh;
                                                    setAdministrator(bh-1);
                                                    break;
                                                }
                                                default:
                                                {
                                                    std::cout<<"只能输入1～4哦";
                                                    cho=0;
                                                    break;
                                                }
                                            }
                                        }while(cho==0);
                                    }
                                    else if(isAdministrator())
                                    {
                                        std::cout<<"你是管理员"<<std::endl;
                                        std::cout<<"群管理  1.踢人  2.同意网友进群或者拒绝";
                                        long cho;
                                        
                                        do {
                                            std::cin>>cho;
                                            switch (cho) {
                                                case 1:
                                                {
                                                    searchMem();
                                                    std::cout<<"输入你要踢出的人的编号";
                                                    long bh;
                                                    std::cin>>bh;
                                                    Kickmem(bh-1);
                                                    break;
                                                }
                                                case 2:
                                                {
                                                    addMem();
                                                    break;
                                                }
                                                default:
                                                {
                                                    std::cout<<"只能输入1～2哦";
                                                    cho=0;
                                                    break;
                                                }
                                            }
                                        }while(cho==0);
                                    }
                                }
                                break;
                            }
                            case 2:
                            {
                                manageSearchMem();
                                break;
                            }
                            case 3:
                            {
                                settempdisgro();
                                break;
                            }
                            default:
                            {
                                std::cout<<"只能输入1或者2哦";
                                judge=0;
                                break;
                            }
                        }
                    }while(judge==0);
                    break;
                }
            }
            
        }
    }while(i==0);
}
void groupManaImplXZJ::ModeTwo()
{
    std::cout<<"选择你的操作  1.创建群  2.推荐加群  3.退出群  4.进入群";
    //管理群:1.踢人(群主)  2.解散群(群主)  3.同意网友进群或者拒绝(群主)
    long i;
    do {
        std::cin>>i;
        switch (i) {
            case 1:
            {
                creatGro();
                break;
            }
            case 2:
            {
                srand(static_cast<unsigned>(time(0)));
                switch (_t) {
                    case qq:
                    {
                        long count=0;
                        long select;
                        std::vector<long> groname;
                        for(auto i=(pQ->groupMana())->cbegin(); i!=(pQ->groupMana())->cend(); ++i)
                        {
                            ++count;
                            groname.push_back((*i)->groupNum());
                        }
                        
                        long j=0;
                        do {
                            select=rand()%count;
                            for(auto i=(pQD->groNum()).cbegin(); i!=(pQD->groNum()).cend(); ++i)
                                if(*i==groname[select])
                                    j=1;
                        }while(j);
                        
                        std::cout<<"推荐你加群"<<select<<std::endl
                        <<"1.加群  2.不加群";
                        long k;
                        do {
                            std::cin>>k;
                            switch (k) {
                                case 1:
                                    for(auto i=(pQ->groupMana())->begin(); i!=(pQ->groupMana())->end(); ++i)
                                        if((*i)->groupNum()==groname[select])
                                            ((*i)->askJoinQQGroList())->push_back(pQD);
                                    break;
                                case 2:
                                    break;
                                default:
                                    std::cout<<"只能输入1或者2哦";
                                    k=0;
                                    break;
                            }
                        }while(k==0);
                        break;
                    }
                    case wb:
                    {
                        long count=0;
                        long select;
                        std::vector<long> groname;
                        for(auto i=(pWB->groupMana())->cbegin(); i!=(pWB->groupMana())->cend(); ++i)
                        {
                            ++count;
                            groname.push_back((*i)->groupNum());
                        }
                        
                        long j=0;
                        do {
                            select=rand()%count;
                            for(auto i=(pWBD->groNum()).cbegin(); i!=(pWBD->groNum()).cend(); ++i)
                                if(*i==groname[select])
                                    j=1;
                        }while(j);
                        
                        std::cout<<"推荐你加群"<<select<<std::endl
                        <<"1.加群  2.不加群";
                        long k;
                        do {
                            std::cin>>k;
                            switch (k) {
                                case 1:
                                    for(auto i=(pWB->groupMana())->begin(); i!=(pWB->groupMana())->end(); ++i)
                                        if((*i)->groupNum()==groname[select])
                                            ((*i)->askJoinWBGroList())->push_back(pWBD);
                                    break;
                                case 2:
                                    break;
                                default:
                                    std::cout<<"只能输入1或者2哦";
                                    k=0;
                                    break;
                            }
                        }while(k==0);
                        break;
                    }
                    case wc:
                    {
                        long count=0;
                        long select;
                        std::vector<long> groname;
                        for(auto i=(pWC->groupMana())->cbegin(); i!=(pWC->groupMana())->cend(); ++i)
                        {
                            ++count;
                            groname.push_back((*i)->groupNum());
                        }
                        
                        long j=0;
                        do {
                            select=rand()%count;
                            for(auto i=(pWCD->groNum()).cbegin(); i!=(pWCD->groNum()).cend(); ++i)
                                if(*i==groname[select])
                                    j=1;
                        }while(j);
                        
                        std::cout<<"推荐你加群"<<select<<std::endl
                        <<"1.加群  2.不加群";
                        long k;
                        do {
                            std::cin>>k;
                            switch (k) {
                                case 1:
                                    for(auto i=(pWC->groupMana())->begin(); i!=(pWC->groupMana())->end(); ++i)
                                        if((*i)->groupNum()==groname[select])
                                            ((*i)->askJoinWCGroList())->push_back(pWCD);
                                    break;
                                case 2:
                                    break;
                                default:
                                    std::cout<<"只能输入1或者2哦";
                                    k=0;
                                    break;
                            }
                        }while(k==0);
                        break;
                    }
                }
                break;
            }
            case 3:
            {
                std::cout<<"你有这些群:"<<std::endl;
                showGroNum();
                std::cout<<"你有这些临时讨论组"<<std::endl;
                showtempGroNum();
                std::cout<<"输入要退出的群号;";
                long gron;
                std::cin>>gron;
                switch (_t) {
                    case qq:
                        exitGro(gron, pQD);
                        break;
                    case wb:
                        exitGro(gron, pWCD);
                        break;
                    case wc:
                        exitGro(gron, pWBD);
                        break;
                }
                break;
            }
            case 4:
            {
                int judge=1;
                std::cout<<"群"<<std::endl;
                showGroNum();
                std::cout<<"讨论组"<<std::endl;
                showtempGroNum();
                long num;
                std::cin>>num;
                inGro(num);
                std::cout<<"你可以有下面的操作  1.管理群  2.搜索群成员";
                int choose;
                do{
                    std::cin>>choose;
                    switch (choose) {
                        case 1:
                        {
                            if(!isOwner())
                                std::cout<<"你不是群主哦";
                            else
                            {
                                std::cout<<"你是群主"<<std::endl;
                                std::cout<<"管理群:  1.踢人  2.解散群  3.同意网友进群或者拒绝";
                                long cho;
                                std::cin>>cho;
                                do {
                                    switch (cho) {
                                        case 1:
                                        {
                                            searchMem();
                                            std::cout<<"输入你要踢出的人的编号";
                                            long bh;
                                            std::cin>>bh;
                                            Kickmem(bh-1);
                                            break;
                                        }
                                        case 2:
                                        {
                                            disSolvedGro();
                                            break;
                                        }
                                        case 3:
                                        {
                                            addMem();
                                            break;
                                        }
                                        default:
                                        {
                                            std::cout<<"只能输入1～3哦";
                                            cho=0;
                                            break;
                                        }
                                    }
                                }while(cho==0);
                            }
                            break;
                        }
                        case 2:
                            manageSearchMem();
                            break;
                        default:
                        {
                            std::cout<<"只能输入1或者2哦";
                            judge=0;
                            break;
                        }
                    }
                }while(judge==0);
                break;
            }
            default:
            {
                std::cout<<"只能输入1～4哦";
                i=0;
                break;
            }
        }
    }while(i==0);
}
void groupManaImplXZJ::creatGro()
{
    std::cout<<"你想创建的群号是多少__"<<std::endl;
    long gronum;
    int judge;
    switch (_t) {
        case qq:
            do
            {
                judge=0;
                std::cin>>gronum;
                for(auto i=(pQ->groupMana())->cbegin(); i!=(pQ->groupMana())->cend(); ++i)
                    if((*i)->groupNum()==gronum)
                    {
                        std::cout<<"群号重复";
                        judge=1;
                    }
                if(judge==0)
                {
                    _qqGro=std::make_shared<groupXZJ>(gronum);
                    (_qqGro->qqGro())->push_back(pQD);
                    (pQD->groNum()).push_back(gronum);
                    (pQ->groupMana())->push_back(_qqGro);//qq里面增加一个群
                }
            }while(judge==1);
            break;
        case wb:
            do
            {
                judge=0;
                std::cin>>gronum;
                for(auto i=(pWB->groupMana())->cbegin(); i!=(pWB->groupMana())->cend(); ++i)
                    if((*i)->groupNum()==gronum)
                    {
                        std::cout<<"群号重复";
                        judge=1;
                    }
                if(judge==0)
                {
                    _wbGro=std::make_shared<groupXZJ>(gronum);
                    (_wbGro->wbGro())->push_back(pWBD);
                    (pWBD->groNum()).push_back(gronum);
                    (pWB->groupMana())->push_back(_wbGro);//qq里面增加一个群
                }
            }while(judge==1);
            break;
        case wc:
            do
            {
                judge=0;
                std::cin>>gronum;
                for(auto i=(pWC->groupMana())->cbegin(); i!=(pWC->groupMana())->cend(); ++i)
                    if((*i)->groupNum()==gronum)
                    {
                        std::cout<<"群号重复";
                        judge=1;
                    }
                if(judge==0)
                {
                    _wcGro=std::make_shared<groupXZJ>(gronum);
                    (_wcGro->wcGro())->push_back(pWCD);
                    (pWCD->groNum()).push_back(gronum);
                    (pWC->groupMana())->push_back(_wcGro);//qq里面增加一个群
                }
            }while(judge==1);
            break;
    }
    std::cout<<"**创建成功**"<<std::endl;
}
int groupManaImplXZJ::inGro(long num)
{
    long judge=0;
    switch (_t) {
        case qq:
        {
            do
            {
                if(!(pQD->groNum()).empty())
                {
                    for(auto i=(pQD->groNum()).cbegin(); i!=(pQD->groNum()).cend(); ++i)
                        if(*i==num)
                        {
                            for(auto j=(pQ->groupMana())->cbegin(); j!=(pQ->groupMana())->cend(); ++j)
                                if(num==(*j)->groupNum())
                                {
                                    _qqGro=*j;
                                    return 1;
                                }
                            
                            judge=1;
                        }
                    for(auto i=(pQD->tempgroNum()).cbegin(); i!=(pQD->tempgroNum()).cend(); ++i)
                        if(*i==num)
                        {
                            
                            for(auto j=(pQ->tempdisgro())->cbegin(); j!=(pQ->tempdisgro())->cend(); ++j)
                                if(num==(*j)->groupNum())
                                {
                                    
                                    _qqGro=*j;
                                    return 1;
                                }
                            judge=1;
                        }
                    if(judge==0)
                    {
                        std::cout<<"没有这个群号";
                        std::cin>>num;
                    }
                }
                else
                    return 0;
            }while(judge==0);
            
            break;
        }
        case wb:
        {
            do
            {
                if(!(pWBD->groNum()).empty())
                {
                    for(auto i=(pWBD->groNum()).cbegin(); i!=(pWBD->groNum()).cend(); ++i)
                        if(*i==num)
                        {
                            for(auto j=(pWB->groupMana())->cbegin(); j!=(pWB->groupMana())->cend(); ++j)
                                if(num==(*j)->groupNum())
                                {
                                    _wbGro=*j;
                                    return 1;
                                }
                            judge=1;
                        }
                    for(auto i=(pWBD->tempgroNum()).cbegin(); i!=(pWBD->tempgroNum()).cend(); ++i)
                        if(*i==num)
                        {
                            for(auto j=(pWB->tempdisgro())->cbegin(); j!=(pWB->tempdisgro())->cend(); ++j)
                                if(num==(*j)->groupNum())
                                {
                                    _wbGro=*j;
                                    return 1;
                                }
                            judge=1;
                        }
                    if(judge==0)
                    {
                        std::cout<<"没有这个群号";
                        std::cin>>num;
                    }
                }
                else
                    return 0;
            }while(judge==0);
            break;
        }
        case wc:
        {
            do
            {
                if(!(pWCD->groNum()).empty())
                {
                    for(auto i=(pWCD->groNum()).cbegin(); i!=(pWCD->groNum()).cend(); ++i)
                        if(*i==num)
                        {
                            for(auto j=(pWC->groupMana())->cbegin(); j!=(pWC->groupMana())->cend(); ++j)
                                if(num==(*j)->groupNum())
                                {
                                    _wcGro=*j;
                                    return 1;
                                }
                            judge=1;
                        }
                    for(auto i=(pWCD->tempgroNum()).cbegin(); i!=(pWCD->tempgroNum()).cend(); ++i)
                        if(*i==num)
                        {
                            for(auto j=(pWC->tempdisgro())->cbegin(); j!=(pWC->tempdisgro())->cend(); ++j)
                                if(num==(*j)->groupNum())
                                {
                                    _wcGro=*j;
                                    return 1;
                                }
                            judge=1;
                        }
                    if(judge==0)
                    {
                        std::cout<<"没有这个群号";
                        std::cin>>num;
                    }
                }
                else
                    return 0;
            }while(judge==0);
            break;
        }
    }
    return 0;
}


void groupManaImplXZJ::exitGro(long& i, std::shared_ptr<QQDataXZJ> pqd)
{
    long k;
    do {
        k=1;
        for(auto j=(pqd->groNum()).begin(); j!=(pqd->groNum()).end(); ++j)//从人里面删除组号
            if(*j==i)
            {
                j=(pQD->groNum()).erase(j);
                k=0;
                break;
            }
        if(k==0)
        {
            for(auto j=(pQ->groupMana())->begin(); j!=(pQ->groupMana())->end(); ++j)//从组里面删除人
                if((*j)->groupNum()==i)
                    for(auto l=((*j)->qqGro())->begin(); l!=((*j)->qqGro())->end(); ++l)
                        if(**l==*pqd)
                        {
                            l=((*j)->qqGro())->erase(l);
                            break;
                        }
            for(auto j=(pQ->tempdisgro())->begin(); j!=(pQ->tempdisgro())->end(); ++j)
                if((*j)->groupNum()==i)
                    for(auto l=((*j)->tempqqGro())->begin(); l!=((*j)->tempqqGro())->end(); ++l)
                        if(**l==*pqd)
                        {
                            l=((*j)->tempqqGro())->erase(l);
                            break;
                        }
        }
        
        if(k)
        {
            std::cout<<"没有这个群号哦，重新输入叭__";
            std::cin>>i;
        }
    }while(k);
}
void groupManaImplXZJ::exitGro(long& i, std::shared_ptr<WCDataXZJ> pwcd)
{
    long k;
    do {
        k=1;
        for(auto j=(pwcd->groNum()).begin(); j!=(pwcd->groNum()).end(); ++j)//从人里面删除组号
            if(*j==i)
            {
                j=(pWCD->groNum()).erase(j);
                k=0;
                break;
            }
        if(k==0)
        {
            for(auto j=(pWC->groupMana())->begin(); j!=(pWC->groupMana())->end(); ++j)//从组里面删除人
                if((*j)->groupNum()==i)
                    for(auto l=((*j)->wcGro())->begin(); l!=((*j)->wcGro())->end(); ++l)
                        if(**l==*pwcd)
                        {
                            l=((*j)->wcGro())->erase(l);
                            break;
                        }
            for(auto j=(pWC->tempdisgro())->begin(); j!=(pWC->tempdisgro())->end(); ++j)
                if((*j)->groupNum()==i)
                    for(auto l=((*j)->tempwcGro())->begin(); l!=((*j)->tempwcGro())->end(); ++l)
                        if(**l==*pwcd)
                        {
                            l=((*j)->tempwcGro())->erase(l);
                            break;
                        }
        }
        if(k)
        {
            std::cout<<"没有这个群号哦，重新输入叭__";
            std::cin>>i;
        }
    }while(k);
}
void groupManaImplXZJ::exitGro(long& i, std::shared_ptr<WBDataXZJ> pwbd)
{
    long k;
    do {
        k=1;
        for(auto j=(pwbd->groNum()).begin(); j!=(pwbd->groNum()).end(); ++j)//从人里面删除组号
            if(*j==i)
            {
                j=(pWBD->groNum()).erase(j);
                k=0;
                break;
            }
        if(k==0)
        {
            for(auto j=(pWB->groupMana())->begin(); j!=(pWB->groupMana())->end(); ++j)//从组里面删除人
                if((*j)->groupNum()==i)
                    for(auto l=((*j)->wbGro())->begin(); l!=((*j)->wbGro())->end(); ++l)
                        if(**l==*pwbd)
                        {
                            l=((*j)->wbGro())->erase(l);
                            break;
                        }
            for(auto j=(pWB->tempdisgro())->begin(); j!=(pWB->tempdisgro())->end(); ++j)
                if((*j)->groupNum()==i)
                    for(auto l=((*j)->tempwbGro())->begin(); l!=((*j)->tempwbGro())->end(); ++l)
                        if(**l==*pwbd)
                        {
                            l=((*j)->tempwbGro())->erase(l);
                            break;
                        }
        }
        if(k)
        {
            std::cout<<"没有这个群号哦，重新输入叭__";
            std::cin>>i;
        }
    }while(k);
}

void groupManaImplXZJ::showAllGroNum()
{
    switch (_t) {
        case qq:
            for(auto j=(pQ->groupMana())->cbegin(); j!=(pQ->groupMana())->cend(); ++j)
                std::cout<<(*j)->groupNum()<<std::endl;
            break;
        case wc:
            for(auto j=(pWC->groupMana())->cbegin(); j!=(pWC->groupMana())->cend(); ++j)
                std::cout<<(*j)->groupNum()<<std::endl;
            break;
        case wb:
            for(auto j=(pWB->groupMana())->cbegin(); j!=(pWB->groupMana())->cend(); ++j)
                std::cout<<(*j)->groupNum()<<std::endl;
            break;
    }
}
void groupManaImplXZJ::showGroNum()
{
    switch (_t) {
        case qq:
            for(auto j=(pQD->groNum()).cbegin(); j!=(pQD->groNum()).cend(); ++j)
                std::cout<<(*j)<<std::endl;
            break;
        case wc:
            for(auto j=(pWCD->groNum()).cbegin(); j!=(pWCD->groNum()).cend(); ++j)
                std::cout<<(*j)<<std::endl;
            break;
        case wb:
            for(auto j=(pWBD->groNum()).cbegin(); j!=(pWBD->groNum()).cend(); ++j)
                std::cout<<(*j)<<std::endl;
            break;
    }
}
void groupManaImplXZJ::showtempGroNum()
{
    switch (_t) {
        case qq:
            for(auto j=(pQD->tempgroNum()).cbegin(); j!=(pQD->tempgroNum()).cend(); ++j)
                std::cout<<(*j)<<std::endl;
            break;
        case wc:
            for(auto j=(pWCD->tempgroNum()).cbegin(); j!=(pWCD->tempgroNum()).cend(); ++j)
                std::cout<<(*j)<<std::endl;
            break;
        case wb:
            for(auto j=(pWBD->tempgroNum()).cbegin(); j!=(pWBD->tempgroNum()).cend(); ++j)
                std::cout<<(*j)<<std::endl;
            break;
    }
}
void groupManaImplXZJ::showperson(const std::__wrap_iter<std::shared_ptr<QQDataXZJ> *>& p)const
{
    std::cout
    <<"名字:"<<(p->get())->name()<<std::endl
    <<"QQ号:"<<(p->get())->qqNum()<<std::endl
    <<"ID:"<<(p->get())->ID()<<std::endl
    <<"家庭住址"<<(p->get())->home()<<std::endl
    <<"生日:"<<(p->get())->birth()<<std::endl
    <<"T龄:"<<(p->get())->t_age()<<std::endl;
}
void groupManaImplXZJ::showperson(const std::__wrap_iter<std::shared_ptr<WBDataXZJ> *>& p)const
{
    std::cout
    <<"名字:"<<(p->get())->name()<<std::endl
    <<"微博号:"<<(p->get())->wbNum()<<std::endl
    <<"ID:"<<(p->get())->ID()<<std::endl
    <<"家庭住址"<<(p->get())->home()<<std::endl
    <<"生日:"<<(p->get())->birth()<<std::endl
    <<"T龄:"<<(p->get())->t_age()<<std::endl;
}
void groupManaImplXZJ::showperson(const std::__wrap_iter<std::shared_ptr<WCDataXZJ> *>& p)const
{
    std::cout
    <<"名字:"<<(p->get())->name()<<std::endl
    <<"ID:"<<(p->get())->ID()<<std::endl
    <<"家庭住址"<<(p->get())->home()<<std::endl
    <<"生日:"<<(p->get())->birth()<<std::endl
    <<"T龄:"<<(p->get())->t_age()<<std::endl;
}
void groupManaImplXZJ::showperson(const std::shared_ptr<std::vector<std::shared_ptr<QQDataXZJ>>>& p)const
{
    long j=0;
    for(auto i=p->cbegin(); i!=p->cend(); ++i)
    {
        std::cout<<++j<<"."<<std::endl;
        std::cout
        <<"名字:"<<(*i)->name()<<std::endl
        <<"QQ号:"<<(*i)->qqNum()<<std::endl
        <<"ID:"<<(*i)->ID()<<std::endl
        <<"家庭住址"<<(*i)->home()<<std::endl
        <<"生日:"<<(*i)->birth()<<std::endl
        <<"T龄:"<<(*i)->t_age()<<std::endl;
        
    }
}
void groupManaImplXZJ::showperson(const std::shared_ptr<std::vector<std::shared_ptr<WCDataXZJ>>>& p)const
{
    long j=0;
    for(auto i=p->cbegin(); i!=p->cend(); ++i)
    {
        std::cout<<++j<<"."<<std::endl;
        std::cout
        <<"名字:"<<(*i)->name()<<std::endl
        <<"微信ID:"<<(*i)->ID()<<std::endl
        <<"家庭住址"<<(*i)->home()<<std::endl
        <<"生日:"<<(*i)->birth()<<std::endl
        <<"T龄:"<<(*i)->t_age()<<std::endl;
        
    }
}
void groupManaImplXZJ::showperson(const std::shared_ptr<std::vector<std::shared_ptr<WBDataXZJ>>>& p)const
{
    long j=0;
    for(auto i=p->cbegin(); i!=p->cend(); ++i)
    {
        std::cout<<++j<<"."<<std::endl;
        std::cout
        <<"名字:"<<(*i)->name()<<std::endl
        <<"微博号:"<<(*i)->wbNum()<<std::endl
        <<"ID:"<<(*i)->ID()<<std::endl
        <<"家庭住址"<<(*i)->home()<<std::endl
        <<"生日:"<<(*i)->birth()<<std::endl
        <<"T龄:"<<(*i)->t_age()<<std::endl;
        
    }
}
void groupManaImplXZJ::searchMem()const
{
    long j=0;
    switch (_t) {
        case qq:
            for(auto i=(_qqGro->qqGro())->begin(); i!=(_qqGro->qqGro())->end(); ++i)
            {
                std::cout<<(*i)->name();
                std::cout<<++j<<"."<<std::endl;
                showperson(i);
            }
            break;
        case wb:
            for(auto i=(_wbGro->wbGro())->begin(); i!=(_wbGro->wbGro())->end(); ++i)
            {
                std::cout<<++j<<"."<<std::endl;
                showperson(i);
            }
            break;
        case wc:
            for(auto i=(_wcGro->wcGro())->begin(); i!=(_wcGro->wcGro())->end(); ++i)
            {
                std::cout<<++j<<"."<<std::endl;
                showperson(i);
            }
            break;
    }
}
void groupManaImplXZJ::searchMem(const std::string& name)const
{
    switch (_t) {
        case qq:
            for(auto i=(_qqGro->qqGro())->begin(); i!=(_qqGro->qqGro())->end(); ++i)
                if((*i)->name()==name)
                {
                    showperson(i);
                    break;
                }
            break;
        case wb:
            for(auto i=(_wbGro->wbGro())->begin(); i!=(_wbGro->wbGro())->end(); ++i)
                if((*i)->name()==name)
                {
                    showperson(i);
                    break;
                }
            break;
        case wc:
            for(auto i=(_wcGro->wcGro())->begin(); i!=(_wcGro->wcGro())->end(); ++i)
                if((*i)->name()==name)
                {
                    showperson(i);
                    break;
                }
            break;
    }
}
void groupManaImplXZJ::searchMem(const long id)const
{
    switch (_t) {
        case qq:
            for(auto i=(_qqGro->qqGro())->begin(); i!=(_qqGro->qqGro())->end(); ++i)
                if((*i)->ID()==id)
                {
                    showperson(i);
                    break;
                }
            break;
        case wb:
            for(auto i=(_wbGro->wbGro())->begin(); i!=(_wbGro->wbGro())->end(); ++i)
                if((*i)->ID()==id)
                {
                    showperson(i);
                    break;
                }
            break;
        case wc:
            for(auto i=(_wcGro->wcGro())->begin(); i!=(_wcGro->wcGro())->end(); ++i)
                if((*i)->ID()==id)
                {
                    showperson(i);
                    break;
                }
            break;
    }
}

void groupManaImplXZJ::manageSearchMem()
{
    std::cout<<"可以  1.名字搜索  2.ID搜索  3.展示所有的人";
    long s, judge=0;
    do {
        std::cin>>s;
        judge=0;
        switch (s) {
            case 1:
            {
                std::cout<<"输入名字__";
                std::string name;
                std::cin>>name;
                searchMem(name);
                break;
            }
            case 2:
            {
                std::cout<<"输入ID__";
                long id;
                std::cin>>id;
                searchMem(id);
                break;
            }
            case 3:
            {
                searchMem();
                break;
            }
            default:
            {
                std::cout<<"只能输入1，2，3哦";
                std::cin>>s;
                judge=1;
                break;
            }
        }
    }while(judge);
}


void groupManaImplXZJ::settempdisgro()
{
    std::cout<<"设置临时讨论组的组号__";
    long gron;
    std::cin>>gron;
    std::shared_ptr<groupXZJ> tempGro=std::make_shared<groupXZJ>(gron);//建立讨论组
    
    searchMem();
    std::cout<<"选择你要邀请的人，输入8888结束";
    long i;
    
    switch (_t) {
        case qq:
        {
            do {
                std::cin>>i;//push_back---------std::shared_ptr<QQDataXZJ>
                if(i!=8888)
                    ((tempGro.get())->tempqqGro())->push_back((*(_qqGro->tempqqGro()))[i-1]);
            }while(i!=8888);
            (pQ->tempdisgro())->push_back(tempGro);
            break;
        }
        case wb:
        {
            do {
                std::cin>>i;
                if(i!=8888)
                    ((tempGro.get())->tempwbGro())->push_back((*(_wbGro->tempwbGro()))[i-1]);
            }while(i!=8888);
            (pWB->tempdisgro())->push_back(tempGro);
            break;
        }
        case wc:
        {
            do {
                std::cin>>i;
                if(i!=8888)
                    ((tempGro.get())->tempwcGro())->push_back((*(_wcGro->tempwcGro()))[i-1]);
            }while(i!=8888);
            (pWC->tempdisgro())->push_back(tempGro);
            break;
        }
    }
}
bool groupManaImplXZJ::isOwner()
{
    switch (_t) {
        case qq:
            if(*((_qqGro->qqGro())->front())==*pQD)
                return true;
            else
                return false;
            break;
        case wb:
            if(*((_wbGro->wbGro())->front())==*pWBD)
                return true;
            else
                return false;
            break;
        case wc:
            if(*((_wcGro->wcGro())->front())==*pWCD)
                return true;
            else
                return false;
            break;
    }
}
bool groupManaImplXZJ::isAdministrator()
{
    switch (_t) {
        case qq:
        {
            for(auto i=(_qqGro->qqGroAdministrators())->cbegin(); i!=(_qqGro->qqGroAdministrators())->cend(); ++i)
                if(**i==*pQD)
                    return true;
            return false;
            break;
        }
        case wb:
        {
            for(auto i=(_wbGro->wbGroAdministrators())->cbegin(); i!=(_wbGro->wbGroAdministrators())->cend(); ++i)
                if(**i==*pWBD)
                    return true;
            return false;
            break;
        }
        case wc:
        {
            for(auto i=(_wcGro->wcGroAdministrators())->cbegin(); i!=(_wcGro->wcGroAdministrators())->cend(); ++i)
                if(**i==*pWCD)
                    return true;
            return false;
            break;
        }
    }
}



void groupManaImplXZJ::confirmPosition()
{
    if(isOwner())
        _mt=Owner;
    else if(isAdministrator())
        _mt=administrator;
    else
        _mt=normal;
    
    switch (_mt) {
        case Owner:
            std::cout<<"你是本群的群主哦";
            break;
        case administrator:
            std::cout<<"你是本群的管理员哦";
            break;
        case normal:
            std::cout<<"你是本群的普通成员哦";
            break;
    }
}
void groupManaImplXZJ::Kickmem(long number)//number是人在组中的序号
{
    switch (_t) {
        case qq:
        {
            //把人中的组号移除
            for(auto i=((*((_qqGro->qqGro())->begin()+number))->groNum()).begin(); i!=((*((_qqGro->qqGro())->begin()+number))->groNum()).end(); ++i)
                if(*i==_qqGro->groupNum())
                {
                    ((*((_qqGro->qqGro())->begin()+number))->groNum()).erase(i);
                    break;
                }
            //把人从组中移除
            auto i=_qqGro->qqGro()->begin()+number;
            (_qqGro->qqGro())->erase(i);
            break;
        }
        case wb:
        {
            //把人中的组号移除
            for(auto i=((*((_wbGro->wbGro())->begin()+number))->groNum()).begin(); i!=((*((_wbGro->wbGro())->begin()+number))->groNum()).end(); ++i)
                if(*i==_wbGro->groupNum())
                {
                    ((*((_wbGro->wbGro())->begin()+number))->groNum()).erase(i);
                    break;
                }
            //把人从组中移除
            auto i=_wbGro->wbGro()->begin()+number;
            (_wbGro->wbGro())->erase(i);
            break;
        }
        case wc:
        {
            //把人中的组号移除
            for(auto i=((*((_wcGro->wcGro())->begin()+number))->groNum()).begin(); i!=((*((_wcGro->wcGro())->begin()+number))->groNum()).end(); ++i)
                if(*i==_wcGro->groupNum())
                {
                    ((*((_wcGro->wcGro())->begin()+number))->groNum()).erase(i);
                    break;
                }
            //把人从组中移除
            auto i=_wcGro->wcGro()->begin()+number;
            (_wcGro->wcGro())->erase(i);
            break;
        }
    }
}
void groupManaImplXZJ::disSolvedGro()
{
    switch (_t) {
        case qq:
        {
            //先从人中删除组号,然后从容器末尾向前删除成员
            for(auto i=(_qqGro->qqGro())->rbegin();i!=(_qqGro->qqGro())->rend(); ++i)
            {
                for(auto j=((*i)->groNum()).begin(); j!=((*i)->groNum()).end(); ++j)
                {
                    if(*j==_qqGro->groupNum())
                    {
                        ((*i)->groNum()).erase(j);//先从人中删除组号
                        break;
                    }
                }
            }
            while((_qqGro->qqGro())->size()!=0)
                (_qqGro->qqGro())->pop_back();
            break;
        }
        case wb:
        {
            for(auto i=(_wbGro->wbGro())->rbegin();i!=(_wbGro->wbGro())->rend(); ++i)
            {
                for(auto j=((*i)->groNum()).begin(); j!=((*i)->groNum()).end(); ++j)
                {
                    if(*j==_wbGro->groupNum())
                    {
                        ((*i)->groNum()).erase(j);//先从人中删除组号
                        break;
                    }
                }
            }
            while((_wbGro->wbGro())->size()!=0)
                (_wbGro->wbGro())->pop_back();
            break;
        }
        case wc:
        {
            for(auto i=(_wcGro->wcGro())->rbegin();i!=(_wcGro->wcGro())->rend(); ++i)
            {
                for(auto j=((*i)->groNum()).begin(); j!=((*i)->groNum()).end(); ++j)
                {
                    if(*j==_wcGro->groupNum())
                    {
                        ((*i)->groNum()).erase(j);//先从人中删除组号
                        break;
                    }
                }
            }
            while((_wcGro->wcGro())->size()!=0)
                (_wcGro->wcGro())->pop_back();
            break;
        }
    }
}
void groupManaImplXZJ::addMem()
{
    switch (_t) {
        case qq:
        {
            std::cout<<"有这些人想要加入你管理的群"<<std::endl;
            showperson(_qqGro->askJoinQQGroList());
            std::cout<<"输入你同意加入的人的序号,输入-1结束"<<std::endl<<std::endl<<std::endl;
            long xh;
            std::cin>>xh;
            while(xh!=-1||!(_qqGro->askJoinQQGroList())->empty())
            {
                xh-=1;
                (_qqGro->qqGro())->push_back(*((_qqGro->askJoinQQGroList())->begin()+xh));
                
                auto i=(_qqGro->askJoinQQGroList())->begin()+xh;
                
                (_qqGro->askJoinQQGroList())->erase(i);
                
                if((_qqGro->askJoinQQGroList())->empty())
                    break;
                else
                {
                    showperson(_qqGro->askJoinQQGroList());
                    std::cout<<"继续输入你同意加入的人的序号,输入-1结束"<<std::endl<<std::endl<<std::endl;
                    std::cin>>xh;
                }
            }
            break;
        }
        case wb:
        {
            std::cout<<"有这些人想要加入你管理的群";
            showperson(_wbGro->askJoinWBGroList());
            std::cout<<"输入你同意加入的人的序号,输入-1结束"<<std::endl<<std::endl<<std::endl;
            long xh;
            std::cin>>xh;
            while(xh!=-1||!(_wbGro->askJoinWBGroList())->empty())
            {
                xh-=1;
                (_wbGro->wbGro())->push_back(*((_wbGro->askJoinWBGroList())->begin()+xh));
                auto i=(_wbGro->askJoinWBGroList())->begin()+xh;
                (_wbGro->askJoinWBGroList())->erase(i);
                
                if((_wbGro->askJoinWBGroList())->empty())
                    break;
                else
                {
                    showperson(_wbGro->askJoinWBGroList());
                    std::cout<<"继续输入你同意加入的人的序号,输入-1结束"<<std::endl<<std::endl<<std::endl;
                    std::cin>>xh;
                }
            }
            break;
        }
        case wc:
        {
            std::cout<<"有这些人想要加入你管理的群";
            showperson(_wcGro->askJoinWCGroList());
            std::cout<<"输入你同意加入的人的序号,输入-1结束"<<std::endl<<std::endl<<std::endl;
            long xh;
            std::cin>>xh;
            while(xh!=-1||!(_wcGro->askJoinWCGroList())->empty())
            {
                xh-=1;
                (_wcGro->wcGro())->push_back(*((_wcGro->askJoinWCGroList())->begin()+xh));
                auto i=(_wcGro->askJoinWCGroList())->begin()+xh;
                (_wcGro->askJoinWCGroList())->erase(i);
                if((_wcGro->askJoinWCGroList())->empty())
                    break;
                else
                {
                    showperson(_wcGro->askJoinWCGroList());
                    std::cout<<"继续输入你同意加入的人的序号,输入-1结束"<<std::endl<<std::endl<<std::endl;
                    std::cin>>xh;
                }
            }
            break;
        }
    }
}
void groupManaImplXZJ::setAdministrator(long number)
{
    switch (_t) {
        case qq:
        {
            std::cout<<"你的群里有这些人:"<<std::endl;
            showperson(_qqGro->qqGro());
            std::cout<<"输入你想设置为管理员的号码";
            long hm;
            std::cin>>hm;
            (_qqGro->qqGroAdministrators())->push_back(*((_qqGro->qqGro())->begin()+hm-1));
            break;
        }
        case wb:
        {
            std::cout<<"你的群里有这些人:"<<std::endl;
            showperson(_wbGro->wbGro());
            std::cout<<"输入你想设置为管理员的号码";
            long hm;
            std::cin>>hm;
            (_wbGro->wbGroAdministrators())->push_back(*((_wbGro->wbGro())->begin()+hm-1));
            break;
        }
        case wc:
        {
            std::cout<<"你的群里有这些人:"<<std::endl;
            showperson(_wcGro->wcGro());
            std::cout<<"输入你想设置为管理员的号码";
            long hm;
            std::cin>>hm;
            (_wcGro->wcGroAdministrators())->push_back(*((_wcGro->wcGro())->begin()+hm-1));
            break;
        }
    }
}



