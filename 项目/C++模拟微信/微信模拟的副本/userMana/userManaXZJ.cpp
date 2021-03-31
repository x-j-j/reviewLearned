//
//  userManaXZJ.cpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "userManaXZJ.hpp"
userManaXZJ::userManaXZJ()
{
    pF=(std::make_shared<Files>());
    pQ=(pF->QQ());
    pWB=(pF->WB());
    pWC=(pF->WC());
    
    std::cout<<"你有两个选择  1.创建账户  2.登录";
    long i, judge1;
    do {
        judge1=1;
        std::cin>>i;
        switch (i) {
            case 1:
            {
                CreatAccount();
                std::cout<<std::endl;
                break;
            }
            case 2:
            {
                Log();
                break;
            }
            default:
            {
                std::cout<<"只能输入1或者2哦";
                judge1=0;
                break;
            }
        }
    }while(judge1==0);
    std::cout<<"好了，登录成功，你现在有这些功能"<<std::endl;
    mainOperation();
    std::cout<<"1.继续操作  2.保存退出"<<std::endl;
    long j;
    do{
        do {
            std::cin>>j;
            judge1=1;
            switch (j) {
                case 1:
                    mainOperation();
                    break;
                case 2:
                {
                    pF->Save(pQ);
                    pF->Save(pWC);
                    pF->Save(pWB);
                    exit(1);
                }
                default:
                {
                    std::cout<<"只能输入1，2哦";
                    judge1=0;
                    break;
                }
            }
        }while(judge1==0);
        std::cout<<"1.继续操作  2.保存退出";
        std::cin>>j;
    }while(1);
}
void userManaXZJ::CreatAccount()
{
    const std::shared_ptr<creatAccXZJ> pcA=std::make_shared<creatAccXZJ>(pF);
    std::cout<<"创建什么账户:  1.qq  2.wechet  3.webo";
    long i,j=0;
    std::cin>>i;
    do {
        j=0;
        switch (i) {
            case 1:
            {
                pQD=pcA->creatQQAcc();
                
                (pQ->people())->push_back(pQD);
                break;
            }
            case 2:
            {
                pWCD=pcA->creatWCAcc();
                
                (pWC->people())->push_back(pWCD);
                break;
            }
            case 3:
            {
                pWBD=pcA->creatWBAcc();
                
                (pWB->people())->push_back(pWBD);
                break;
            }
            default:
                std::cout<<"重新输入:";
                std::cin>>i;
                j=1;
                break;
        }
    }while(j);
    
}
void userManaXZJ::Log()
{
    pl=(std::make_shared<logXZJ>(pF));
    std::cout<<"你要登录  1.QQ  2.微信  3.微博";
    long i, judge;
    do {
        judge=1;
        std::cin>>i;
        switch (i) {
            case 1:
            {
                _t=qq;
                std::cout<<"输入你的QQ号__";
                long j;
                std::cin>>j;
                pQD=pl->logQQ(j);
                break;
            }
            case 2:
            {
                _t=wc;
                std::cout<<"输入你的微信ID__";
                long j;
                std::cin>>j;
                pWCD=pl->logWC(j);
                break;
            }
            case 3:
            {
                _t=wb;
                std::cout<<"输入你的微博号__";
                long k;
                std::cin>>k;
                pWBD=pl->logWB(k);
                break;
            }
            default:
            {
                std::cout<<"只能输入1，2，3，4哦";
                judge=0;
                break;
            }
        }
    }while(judge==0);
}
void userManaXZJ::ManageGroup()
{
    std::cout<<"选择模式啦"<<std::endl<<std::endl
    <<"模式1"<<std::endl
    <<"可以创建群,申请加群,退出群,进入群,搜索群的成员,设置临时讨论组,管理群。而管理群是以群主为核心来进行管理的"<<std::endl<<std::endl
    <<"选择模式2"<<std::endl
    <<"可以创建群,推荐加群,退出群,进入群,搜索群的成员,管理群。而管理群是只有群主是特权账号"<<std::endl<<std::endl
    <<"输入你的选择__";
    switch (_t) {
        case qq:
            pgM=std::make_shared<groupManaXZJ>(pF, pQD);
            break;
        case wc:
            pgM=std::make_shared<groupManaXZJ>(pF, pWCD);
            break;
        case wb:
            pgM=std::make_shared<groupManaXZJ>(pF, pWBD);
            break;
    }
    long i, judge;
    
    do {
        judge=1;
        std::cin>>i;
        switch (i) {
            case 1:
                pgM->ModeOne();
                break;
            case 2:
                pgM->ModeTwo();
                break;
            default:
            {
                std::cout<<"只能选择模式1或者模式2哦";
                judge=0;
                break;
            }
        }
    }while(judge==0);
}
void userManaXZJ::ManageFriends()
{
    long judge1, judge2;
    std::cout<<"你有这些管理好友的功能"<<std::endl
    <<"1.添加好友  2.推荐好友  3.查询好友  4.删除好友  5.同意或者拒绝其他好友添加";
    long i;
    
    switch (_t) {
        case qq:
            pfM=std::make_shared<friendManaXZJ>(pF, pQD);
            break;
        case wc:
            pfM=std::make_shared<friendManaXZJ>(pF, pWCD);
            break;
        case wb:
            pfM=std::make_shared<friendManaXZJ>(pF, pWBD);
            break;
        default:
            break;
    }
    do {
        std::cin>>i;
        judge1=1;
        switch (i) {
            case 1:
            {
                pfM->addFriend();
                break;
            }
            case 2:
            {
                judge2=1;
                std::cout<<"推荐什么好好友  1.QQ  2.微信  3.微博";
                long j;
                do {
                    std::cin>>j;
                    switch (j) {
                        case 1:
                            pfM->recoQQFriend();
                            break;
                        case 2:
                            pfM->recoWCFriend();
                            break;
                        case 3:
                            pfM->recoWBFriend();
                            break;
                        default:
                        {
                            std::cout<<"只能输入1,2,3哦";
                            judge2=0;
                            break;
                        }
                    }
                }while(judge2==0);
                break;
            }
            case 3:
            {
                std::cout<<"查询  1.所有好友  2.按照名字查询  3.ID查询";
                long j;
                
                do {
                    std::cin>>j;
                    judge2=1;
                    switch (j) {
                        case 1:
                            pfM->searchFriend();
                            break;
                        case 2:
                        {
                            std::cout<<"输入好友名字";
                            std::string name;
                            std::cin>>name;
                            pfM->searchFriend(name);
                            break;
                        }
                        case 3:
                        {
                            std::cout<<"输入好友ID";
                            long id;
                            std::cin>>id;
                            pfM->searchFriend(id);
                            break;
                        }
                        default:
                        {
                            std::cout<<"只能输入1,2,3哦";
                            judge2=0;
                            break;
                        }
                    }
                }while(judge2==0);
                break;
            }
            case 4:
            {
                pfM->searchFriend();
                std::cout<<"输入删除哪个好友";
                long hy;
                std::cin>>hy;
                switch (_t) {
                    case qq:
                        pfM->deleteFriend(*((pQD->friendList()).begin()+hy-1));
                        break;
                    case wc:
                        pfM->deleteFriend(*((pWCD->friendList()).begin()+hy-1));
                        break;
                    case wb:
                        pfM->deleteFriend(*((pWBD->friendList()).begin()+hy-1));
                        break;
                }
                break;
            }
            case 5:
            {
                pfM->agreeFriend();
                break;
            }
            default:
            {
                std::cout<<"只能输入1～5哦";
                judge1=0;
                break;
            }
        }
    }while(judge1==0);
}
void userManaXZJ::mainOperation()
{
    long judge2;
    std::cout<<"1.有关群的操作  2.有关好友的操作  3.保存退出";
    long j;
    do {
        judge2=1;
        std::cin>>j;
        switch (j) {
            case 1:
                ManageGroup();
                break;
            case 2:
                
                ManageFriends();
                break;
            case 3:
            {
                pF->Save(pQ);
                pF->Save(pWB);
                pF->Save(pWC);
                exit(1);
                break;
            }
            default:
            {
                std::cout<<"只能输入1或者2或者3哦";
                judge2=0;
                break;
            }
        }
    }while(judge2==0);
}
