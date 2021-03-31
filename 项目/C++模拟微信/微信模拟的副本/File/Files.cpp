//
//  Files.cpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/11.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "Files.hpp"
Files::Files()
{
    OutFileQQ();
    OutFileWB();
    OutFileWC();
}

void Files::Save(const std::shared_ptr<QQDataXZJ>& save)
{
    std::stringstream ss;
    ss<<save->ID();
    std::string filename="QQ"+ss.str()+".txt";
    try {
        ifperson.open(filename);
        if(!ifperson.is_open())
            throw 1;
        ifperson<<save->ID()<<std::endl
        <<save->qqNum()<<std::endl
        <<save->password()<<std::endl
        <<save->name()<<std::endl
        <<save->home()<<std::endl;
        
        if(!(save->groNum()).empty())
            for(auto i=(save->groNum()).cbegin(); i!=(save->groNum()).cend(); ++i)
            {
                
                ifperson<<*i<<" ";
            }
        else
            ifperson<<"0";
        ifperson<<std::endl;
        if(!(save->tempgroNum()).empty())
            for(auto i=(save->tempgroNum()).cbegin(); i!=(save->tempgroNum()).cend(); ++i)
            {
                
                ifperson<<*i<<" ";
            }
        else
            ifperson<<"0";
        ifperson<<std::endl;
        ifperson<<(save->birth()).year()<<" "<<(save->birth()).month()<<" "<<(save->birth()).day()<<std::endl
        <<(save->t_age()).year()<<" "<<(save->t_age()).month()<<" "<<(save->t_age()).day()<<" "<<std::endl
        <<save->wc()<<std::endl
        <<save->wb()<<std::endl;
//        <<"好友们的ID是:";
        
        if(!(save->friendList()).empty())
            for(auto i=(save->friendList()).cbegin(); i!=(save->friendList()).cend(); ++i)
                ifperson<<(*i)->ID()<<" ";
        else
            ifperson<<"0";
        ifperson<<std::endl;
//        ifperosn<<"要添加你为好友的用户的ID是:";
        if(!(save->askfriendList()).empty())
            for(auto i=(save->askfriendList()).cbegin(); i!=(save->askfriendList()).cend(); ++i)
                ifperson<<(*i)->ID()<<" ";
        else
            ifperson<<"0";
        ifperson.close();
    } catch (...) {
        std::cout<<"打开文件失败";
    }
}
void Files::Save(const std::shared_ptr<WBDataXZJ>& save)
{
    std::stringstream ss;
    ss<<save->ID();
    std::string filename="WB"+ss.str()+".txt";
    try {
        ifperson.open(filename);//隐含截断文件
        if(!ifperson.is_open())
            throw 1;
        ifperson<<save->ID()<<std::endl
        <<save->wbNum()<<std::endl
        <<save->password()<<std::endl
        <<save->name()<<std::endl
        <<save->home()<<std::endl;
//        <<"加入的群号:";
        if(!(save->groNum()).empty())
            for(auto i=(save->groNum()).cbegin(); i!=(save->groNum()).cend(); ++i)
                ifperson<<*i<<" ";
        else
            ifperson<<"0";
        ifperson<<std::endl;
        if(!(save->tempgroNum()).empty())
            for(auto i=(save->tempgroNum()).cbegin(); i!=(save->tempgroNum()).cend(); ++i)
                ifperson<<*i<<" ";
        else
            ifperson<<"0";
        ifperson<<std::endl;
        ifperson<<(save->birth()).year()<<" "<<(save->birth()).month()<<" "<<(save->birth()).day()<<" "<<std::endl
        <<(save->t_age()).year()<<" "<<(save->t_age()).month()<<" "<<(save->t_age()).day()<<" "<<std::endl
        <<save->wc()<<std::endl
        <<save->qq()<<std::endl;
//        <<"好友们的ID是:";
        if(!(save->friendList()).empty())
            for(auto i=(save->friendList()).cbegin(); i!=(save->friendList()).cend(); ++i)
                ifperson<<(*i)->ID()<<" ";
        else
            ifperson<<"0";
        ifperson<<std::endl;
        //        ifperson<<"要添加你为好友的用户的ID是:";
        if(!(save->askfriendList()).empty())
            for(auto i=(save->askfriendList()).cbegin(); i!=(save->askfriendList()).cend(); ++i)
                ifperson<<(*i)->ID()<<" ";
        else
            ifperson<<"0";
        ifperson.close();
    } catch (long a) {
        std::cout<<"打开文件失败";
    }
    
    
}
void Files::Save(const std::shared_ptr<WCDataXZJ>& save)
{
    std::stringstream ss;
    ss<<save->ID();
    std::string filename="WC"+ss.str()+".txt";
    try {
        ifperson.open(filename);//隐含截断文件
        if(!ifperson.is_open())
            throw 1;
        ifperson<<save->ID()<<std::endl
        <<save->password()<<std::endl
        <<save->name()<<std::endl
        <<save->home()<<std::endl;
//        <<"加入的群号:";
        if(!(save->groNum()).empty())
            for(auto i=(save->groNum()).cbegin(); i!=(save->groNum()).cend(); ++i)
                ifperson<<*i<<" ";
        else
            ifperson<<"0";
        ifperson<<std::endl;
        if(!(save->tempgroNum()).empty())
            for(auto i=(save->tempgroNum()).cbegin(); i!=(save->tempgroNum()).cend(); ++i)
                ifperson<<*i<<" ";
        else
            ifperson<<"0";
        ifperson<<std::endl;
        ifperson<<(save->birth()).year()<<" "<<(save->birth()).month()<<" "<<(save->birth()).day()<<" "<<std::endl
        <<(save->t_age()).year()<<" "<<(save->t_age()).month()<<" "<<(save->t_age()).day()<<" "<<std::endl
        <<save->qq()<<std::endl
        <<save->wb()<<std::endl;
//        <<"好友们的ID是:";
        if(!(save->friendList()).empty())
            for(auto i=(save->friendList()).cbegin(); i!=(save->friendList()).cend(); ++i)
                ifperson<<(*i)->ID()<<" ";
        else
            ifperson<<"0";
        ifperson<<std::endl;
        //        ifperson<<"要添加你为好友的用户的ID是:";
        if(!(save->askfriendList()).empty())
            for(auto i=(save->askfriendList()).cbegin(); i!=(save->askfriendList()).cend(); ++i)
                ifperson<<(*i)->ID()<<" ";
        else
            ifperson<<"0";
        ifperson.close();
    } catch (long a) {
        std::cout<<"打开文件失败";
    }
    
}
void Files::SaveQQGro(const std::shared_ptr<groupXZJ>& save)
{
    std::stringstream ss;
    ss<<save->groupNum();
    std::string filename("QQGro"+ss.str()+".txt");
    try {
        ifqq.open(filename);
        if(!ifqq.is_open())
            throw 1;
//        <<"群中成员们的ID号是:";
        if(!(save->qqGro())->empty())
            for(auto i=(save->qqGro())->cbegin(); i!=(save->qqGro())->cend(); ++i)
                ifqq<<(*i)->ID()<<" ";
        ifqq<<std::endl;
        if(!(save->askJoinQQGroList())->empty())
            for(auto i=(save->askJoinQQGroList())->cbegin(); i!=(save->askJoinQQGroList())->cend(); ++i)
            {
                ifqq<<(*i)->ID()<<" ";
            }
        ifqq.close();
    } catch (...) {
        std::cout<<"打开文件失败";
    }
}
void Files::SaveWBGro(const std::shared_ptr<groupXZJ>& save)
{
    std::stringstream ss;
    ss<<save->groupNum();
    std::string filename("WBGro"+ss.str()+".txt");
    try {
        ifwb.open(filename);
        if(!ifwb.is_open())
            throw 1;
//        <<"群中成员们的ID号是:";
        if(!(save->wbGro())->empty())
            for(auto i=(save->wbGro())->cbegin(); i!=(save->wbGro())->cend(); ++i)
                ifwb<<(*i)->ID()<<" ";
        ifwb<<std::endl;
        if(!(save->askJoinWBGroList())->empty())
            for(auto i=(save->askJoinWBGroList())->cbegin(); i!=(save->askJoinWBGroList())->cend(); ++i)
                ifwb<<(*i)->ID()<<" ";
        ifwb.close();
    } catch (...) {
        std::cout<<"打开文件失败";
    }
}
void Files::SaveWCGro(const std::shared_ptr<groupXZJ>& save)
{
    std::stringstream ss;
    ss<<save->groupNum();
    std::string filename("WCGro"+ss.str()+".txt");
    try {
        ifwc.open(filename);
        if(!ifwc.is_open())
            throw 1;
//        <<"群中成员们的ID号是:";
        if(!(save->wcGro())->empty())
            for(auto i=(save->wcGro())->cbegin(); i!=(save->wcGro())->cend(); ++i)
                ifwc<<(*i)->ID()<<" ";
        ifwc<<std::endl;
        if(!(save->askJoinWCGroList())->empty())
            for(auto i=(save->askJoinWCGroList())->cbegin(); i!=(save->askJoinWCGroList())->cend(); ++i)
                ifwc<<(*i)->ID()<<" ";
        ifwc.close();
    } catch (long a) {
        std::cout<<"打开文件失败";
    }
}
void Files::SaveQQtempGro(const std::shared_ptr<groupXZJ>& save)
{
    std::stringstream ss;
    ss<<save->groupNum();
    
    std::string filename("QQtempGro"+ss.str()+".txt");
    try {
        ifqq.open(filename);
        if(!ifqq.is_open())
            throw 1;
//        <<"群中成员们的ID号是:";
        if(!(save->tempqqGro())->empty())
            for(auto i=(save->tempqqGro())->cbegin(); i!=(save->tempqqGro())->cend(); ++i)
                ifqq<<(*i)->ID()<<" ";
        ifqq<<std::endl;
        if(!(save->askJointempQQGroList())->empty())
            for(auto i=(save->askJointempQQGroList())->cbegin(); i!=(save->askJointempQQGroList())->cend(); ++i)
                ifqq<<(*i)->ID()<<" ";
        ifqq.close();
    } catch (long a) {
        std::cout<<"打开文件失败";
    }
}
void Files::SaveWBtempGro(const std::shared_ptr<groupXZJ>& save)
{
    std::stringstream ss;
    ss<<save->groupNum();
    std::string filename("WBtempGro"+ss.str()+".txt");
    try {
        ifwb.open(filename);
        if(!ifwb.is_open())
            throw 1;
//        <<"群中成员们的ID号是:";
        if(!(save->tempwbGro())->empty())
            for(auto i=(save->tempwbGro())->cbegin(); i!=(save->tempwbGro())->cend(); ++i)
                ifwb<<(*i)->ID()<<" ";
        ifwb<<std::endl;
        if(!(save->askJointempWBGroList())->empty())
            for(auto i=(save->askJointempWBGroList())->cbegin(); i!=(save->askJointempWBGroList())->cend(); ++i)
                ifwb<<(*i)->ID()<<" ";
        ifwb.close();
    } catch (long a) {
        std::cout<<"打开文件失败";
    }
}
void Files::SaveWCtempGro(const std::shared_ptr<groupXZJ>& save)
{
    std::stringstream ss;
    ss<<save->groupNum();
    std::string filename("WCtempGro"+ss.str()+".txt");
    try {
        ifwc.open(filename);
        if(!ifwc.is_open())
            throw 1;
//        <<"群中成员们的ID号是:";
        if(!(save->tempwcGro())->empty())
            for(auto i=(save->tempwcGro())->cbegin(); i!=(save->tempwcGro())->cend(); ++i)
                ifwc<<(*i)->ID()<<" ";
        ifwc<<std::endl;
        if(!(save->askJointempWCGroList())->empty())
            for(auto i=(save->askJointempWCGroList())->cbegin(); i!=(save->askJointempWCGroList())->cend(); ++i)
                ifwc<<(*i)->ID()<<" ";
        ifwc.close();
    } catch (long a) {
        std::cout<<"打开文件失败";
    }
}
void Files::Save(const std::shared_ptr<QQXZJ>& save)
{
    try{
        infile.open("QQ.txt");
        if(!infile.is_open())
            throw 1;
//        infile<<"所有人的ID:";
        if(!(save->people())->empty())
            for(auto i=(save->people())->cbegin(); i!=(save->people())->cend(); ++i)
            {
                Save(*i);
                infile<<(*i)->ID()<<"  ";
            }
        infile<<std::endl;
        for(auto i=(save->groupMana())->cbegin(); i!=(save->groupMana())->cend(); ++i)
        {
            SaveQQGro(*i);
            infile<<(*i)->groupNum()<<"  ";
        }
        infile<<std::endl;
        for(auto i=(save->tempdisgro())->cbegin(); i!=(save->tempdisgro())->cend(); ++i)
        {
            
            SaveQQtempGro(*i);
            infile<<(*i)->groupNum()<<"  ";
        }
    }
    catch(long a){
        std::cout<<"打开文件失败";
    }
}
void Files::Save(const std::shared_ptr<WBXZJ>& save)
{
    try{
        infile.open("WB.txt");
        if(!infile.is_open())
            throw 1;
//        infile<<"所有人的ID:";
        if(!(save->people())->empty())
            for(auto i=(save->people())->cbegin(); i!=(save->people())->cend(); ++i)
            {
                
                Save(*i);
                infile<<(*i)->ID()<<"  ";
            }
        infile<<std::endl;
//        infile<<std::endl<<"所有群号:";
        for(auto i=(save->groupMana())->cbegin(); i!=(save->groupMana())->cend(); ++i)
        {
            SaveWBGro((*i));
            infile<<(*i)->groupNum()<<"  ";
        }
        infile<<std::endl;
//        infile<<std::endl<<"所有临时讨论组号:";
        for(auto i=(save->tempdisgro())->cbegin(); i!=(save->tempdisgro())->cend(); ++i)
        {
            SaveWBtempGro(*i);
            infile<<(*i)->groupNum()<<"  ";
        }
    }catch(long a){
        std::cout<<"打开文件失败";
    }
}
void Files::Save(const std::shared_ptr<WCXZJ>& save)
{
    try {
        infile.open("WC.txt");
        if(!infile.is_open())
            throw 1;
//        infile<<"所有人的ID:";
        if(!(save->people())->empty())
            for(auto i=(save->people())->cbegin(); i!=(save->people())->cend(); ++i)
            {
                Save(*i);
                infile<<(*i)->ID()<<"  ";
            }
//        infile<<std::endl<<"所有群号:";
        for(auto i=(save->groupMana())->cbegin(); i!=(save->groupMana())->cend(); ++i)
        {
            SaveWCGro(*i);
            infile<<(*i)->groupNum()<<"  ";
        }
//        infile<<std::endl<<"所有临时讨论组号:";
        for(auto i=(save->tempdisgro())->cbegin(); i!=(save->tempdisgro())->cend(); ++i)
        {
            SaveWCtempGro(*i);
            infile<<(*i)->groupNum()<<"  ";
        }
    } catch (long a) {
        std::cout<<"打开文件失败";
    }
}
void Files::OutFileQQ()
{
    try {
        _pQ=std::make_shared<QQXZJ>();
        qq.open("QQ.txt");
        if(!qq.is_open())
            throw 1;
        std::stringstream qqss, wcss,wbss;
        std::string qqs, wcs, wbs;
        std::vector<long> gronum, tempgronum, personid;
        
        //人
        long id,  year, month, day, tyear, tmonth, tday, wcid, wbnum, fid, askfid;
        long password, number;
        std::vector<long> friendid, askfriendid;
        std::string name, home;
        
        long a;
        
        getline(qq,qqs);
        
        qqss<<qqs;
        while(qqss>>a)//人的ID
        {
            personid.push_back(a);
        }
        for(auto i=personid.begin(); i!=personid.end(); ++i)
        {
            qqss.clear();
            qqss.str("");
            qqss<<*i;
            qqs="QQ"+qqss.str()+".txt";
            outfile.open(qqs);
            friendid.clear();;getline(outfile, qqs);
            
            qqss.clear();
            qqss.str("");
            qqss<<qqs;
            qqss>>id;
            
            
            qqss.clear();
            qqss.str("");
            friendid.clear();;getline(outfile, qqs);
            qqss<<qqs;
            qqss>>number;
            
            
            qqss.clear();
            qqss.str("");
            friendid.clear();;getline(outfile, qqs);
            qqss<<qqs;
            qqss>>password;
            
            
            qqss.clear();
            qqss.str("");
            friendid.clear();;getline(outfile, qqs);
            qqss<<qqs;
            qqss>>name;
            
            
            qqss.clear();
            qqss.str("");
            friendid.clear();;getline(outfile, qqs);
            qqss<<qqs;
            qqss>>home;
            
            
            qqss.clear();
            qqss.str("");
            friendid.clear();;getline(outfile, qqs);
            qqss<<qqs;
            long a;
            gronum.clear();
            while(qqss>>a)
            {
                
                gronum.push_back(a);
            }
            qqss.clear();
            qqss.str("");
            friendid.clear();;getline(outfile, qqs);
            qqss<<qqs;
            tempgronum.clear();
            while(qqss>>a)
            {
                
                tempgronum.push_back(a);
            }
            qqss.clear();
            qqss.str("");
            friendid.clear();;getline(outfile, qqs);
            qqss<<qqs;
            qqss>>year>>month>>day;
            
            qqss.clear();
            qqss.str("");
            friendid.clear();;getline(outfile, qqs);
            qqss<<qqs;
            qqss>>tyear>>tmonth>>tday;
            
            qqss.clear();
            qqss.str("");
            friendid.clear();;getline(outfile, qqs);
            qqss<<qqs;
            qqss>>wcid;
            
            qqss.clear();
            qqss.str("");
            friendid.clear();;getline(outfile, qqs);
            qqss<<qqs;
            qqss>>wbnum;
            
            qqss.clear();
            qqss.str("");
            friendid.clear();;getline(outfile, qqs);
            qqss<<qqs;
            qqss>>fid;
            friendid.clear();
            if(fid!=0)
            {
                friendid.push_back(fid);
                while(qqss>>fid)
                {
                    
                    friendid.push_back(fid);
                }
            }
            qqss.clear();
            qqss.str("");
            friendid.clear();
            getline(outfile, qqs);
            qqss<<qqs;
            qqss>>askfid;
            askfriendid.clear();
            if(askfid!=0)
            {
                askfriendid.push_back(askfid);
                while(qqss>>askfid)
                {
                    
                    askfriendid.push_back(askfid);
                }
            }
            qqss.clear();
            qqss.str("");
            std::shared_ptr<QQDataXZJ> person=std::make_shared<QQDataXZJ>(name, home, Time(Year(year), Month(month), Day(day)), Time(Year(tyear), Month(tmonth), Day(tday)), id, password, wcid, wbnum, number);
            person->groNum()=gronum;//friendlist和askfriendlist等所有人都构建完之后在写入
            person->tempgroNum()=tempgronum;
            (person->friendlistnum())=friendid;
            (person->askfriendlistnum())=askfriendid;
            person->wc()=wcid;
            person->wb()=wbnum;
            (_pQ->people())->push_back(person);
            outfile.close();
        }//现在所有的人都齐了
        
        
        for(auto i=(_pQ->people())->begin(); i!=(_pQ->people())->end(); ++i)//把friendlistnum和sakfriendlistnum的人都找到
        {
            if(!((*i)->askfriendlistnum()).empty())
                for(auto num=((*i)->askfriendlistnum()).cbegin(); num!=((*i)->askfriendlistnum()).cend(); ++num)
                    for(auto j=(_pQ->people())->begin(); j!=(_pQ->people())->end(); ++j)
                        if((*j)->ID()==*num)
                            ((*i)->askfriendList()).push_back(*j);
            if(!((*i)->friendlistnum()).empty())
                for(auto num=((*i)->friendlistnum()).cbegin(); num!=((*i)->friendlistnum()).cend(); ++num)
                    for(auto j=(_pQ->people())->begin(); j!=(_pQ->people())->end(); ++j)
                        if((*j)->ID()==*num)
                            ((*i)->friendList()).push_back(*j);
                            
        }
        
        
        
        
        
        
        getline(qq,qqs);
        qqss.clear();
        qqss.str("");
        qqss<<qqs;
        while(qqss>>a)//组号
        {
            
            (_pQ->groupMana())->push_back(std::make_shared<groupXZJ>(a));
        }
        
        
        for(auto i=(_pQ->groupMana())->begin(); i!=(_pQ->groupMana())->end(); ++i)//对于QQ中的每一个群
        {
            long j=(*i)->groupNum();
            qqss.clear();
            qqss.str("");
            qqss<<j;
            qqs="QQGro"+qqss.str()+".txt";//群号
            outfile.open(qqs);//根据群号打开文件
            getline(outfile, qqs);
            qqss.clear();
            qqss.str("");
            qqss<<qqs;
            std::vector<long>().swap(personid);
            while(qqss>>a)//群里每个人的ID
            {
                
                personid.push_back(a);
            }
            if(!personid.empty())
            {
                for(auto j=personid.begin(); j!=personid.end(); ++j)
                {//根据这个群中每个人的ID去QQ里面找然后压入这个群的人里面
                    for(auto k=(_pQ->people())->begin(); k!=(_pQ->people())->end(); ++k)
                        if(*j==(*k)->ID())
                        {
                            ((*i)->qqGro())->push_back(*k);
                            break;
                        }
                }
            }
            qqs="";
            friendid.clear();;getline(outfile, qqs);
            
            qqss.clear();
            qqss.str("");
            
            qqss<<qqs;
            
            std::vector<long>().swap(personid);
            while(qqss>>a)//群里每个人的ID
            {
                
                personid.push_back(a);
            }
            if(!personid.empty())
            {
                for(auto j=personid.begin(); j!=personid.end(); ++j)
                {//根据这个群中每个人的ID去QQ里面找然后压入这个群的人里面
                    for(auto k=(_pQ->people())->begin(); k!=(_pQ->people())->end(); ++k)
                        if(*j==(*k)->ID())
                        {
                            
                            ((*i)->askJoinQQGroList())->push_back(*k);
                            break;
                        }
                }
            }
            outfile.close();
        }
        
        
        
        
        
        
        
        getline(qq,qqs);
        qqss.clear();
        qqss.str("");
        qqss<<qqs;
        while(qqss>>a)//临时讨论组号
        {
            
            (_pQ->tempdisgro())->push_back(std::make_shared<groupXZJ>(a));
        }
        for(auto i=(_pQ->tempdisgro())->begin(); i!=(_pQ->tempdisgro())->end(); ++i)//对于QQ中的每一个临时群
        {
            long j=(*i)->groupNum();
            qqss.clear();
            qqss.str("");
            qqss<<j;
            qqs="QQGro"+qqss.str()+".txt";//群号
            outfile.open(qqs);//根据群号打开文件
            
            getline(outfile, qqs);
            qqss.clear();
            qqss.str("");
            qqss<<qqs;
            std::vector<long>().swap(personid);
            while(qqss>>a)
            {
                
                personid.push_back(a);
            }
            if(!personid.empty())
            {
                for(auto j=personid.begin(); j!=personid.end(); ++j)
                {//根据这个群中每个人的ID去QQ群里面找然后压入这个群的人里面
                    for(auto k=(_pQ->people())->begin(); k!=(_pQ->people())->end(); ++k)
                        if(*j==(*k)->ID())
                        {
                            ((*i)->tempqqGro())->push_back(*k);
                            break;
                        }
                }
            }
            
            
            getline(outfile, qqs);
            qqss.clear();
            qqss.str("");
            qqss<<qqs;
            std::vector<long>().swap(personid);
            while(qqss>>a)
            {
                
                personid.push_back(a);
            }
            if(!personid.empty())
            {
                for(auto j=personid.begin(); j!=personid.end(); ++j)
                {//根据这个群中每个人的ID去QQ群里面找然后压入这个群的人里面
                    for(auto k=(_pQ->people())->begin(); k!=(_pQ->people())->end(); ++k)
                        if(*j==(*k)->ID())
                        {
                            ((*i)->askJointempQQGroList())->push_back(*k);
                            break;
                        }
                }
            }
            outfile.close();
        }
        qq.close();
    } catch (long a) {
        std::cout<<"打开文件失败";
    }
}
void Files::OutFileWC()
{
    try {
        _pWC=std::make_shared<WCXZJ>();
        wc.open("WC.txt");
        if(!wc.is_open())
            throw 1;
        std::stringstream qqss, wcss,wbss;
        std::string qqs, wcs, wbs;
        std::vector<long> gronum, tempgronum, personid;
        
        //人
        long id, year, month, day, tyear, tmonth, tday, qqnum, wbnum, fid, askfid;
        long password, number;
        std::vector<long> friendid, askfriendid;
        std::string name, home;
        
        long a;
        
        getline(wc,wcs);
        
        wcss<<wcs;
        while(wcss>>a)//人的ID
        {
            personid.push_back(a);
        }
        for(auto i=personid.begin(); i!=personid.end(); ++i)//先写到变量里
        {
            wcss.clear();
            wcss.str("");
            wcss<<*i;
            wcs="QQ"+wcss.str()+".txt";
            outfile.open(wcs);
            getline(outfile, wcs);
            
            wcss.clear();
            wcss.str("");
            wcss<<wcs;
            wcss>>id;
            
            
            getline(outfile, wcs);
            wcss.clear();
            wcss.str("");
            wcss<<wcs;
            wcss>>number;
            
            
            getline(outfile, wcs);
            wcss.clear();
            wcss.str("");
            wcss<<wcs;
            wcss>>password;
            
            
            getline(outfile, wcs);
            wcss.clear();
            wcss.str("");
            wcss<<wcs;
            wcss>>name;
             
            
            getline(outfile, wcs);
            wcss.clear();
            wcss.str("");
            wcss<<wcs;
            wcss>>home;
            
            
            getline(outfile, wcs);
            wcss.clear();
            wcss.str("");
            wcss<<wcs;
            long a;
            gronum.clear();
            while(wcss>>a)
            {
                
                gronum.push_back(a);
            }
            
            wcss.clear();
            wcss.str("");
            getline(outfile, wcs);
            wcss<<wcs;
            tempgronum.clear();
            while(wcss>>a)
            {
                
                tempgronum.push_back(a);
            }
            
            getline(outfile, wcs);
            wcss.clear();
            wcss.str("");
            wcss<<wcs;
            wcss>>year>>month>>day;
            
            
            getline(outfile, wcs);
            wcss.clear();
            wcss.str("");
            wcss<<wcs;
            wcss>>tyear>>tmonth>>tday;
            
            
            getline(outfile, wcs);
            wcss.clear();
            wcss.str("");
            wcss<<wcs;
            wcss>>qqnum;
            
            
            getline(outfile, wcs);
            wcss.clear();
            wcss.str("");
            wcss<<wcs;
            wcss>>wbnum;
            
            
            getline(outfile, wcs);
            wcss.clear();
            wcss.str("");
            wcss<<wcs;
            wcss>>fid;
            
            friendid.resize(0);
            if(fid!=0)
            {
                friendid.push_back(fid);
                while(wcss>>fid)
                {
                    
                    friendid.push_back(fid);
                }
            }
           
            getline(outfile, wcs);
            wcss.clear();
            wcss.str("");
            wcss<<wcs;
            wcss>>askfid;
            askfriendid.resize(0);
            if(askfid!=0)
            {
                askfriendid.push_back(askfid);
                while(wcss>>askfid)
                {
                    askfriendid.push_back(askfid);
                }
            }
            
            std::shared_ptr<WCDataXZJ> person=std::make_shared<WCDataXZJ>(name, home, Time(Year(year), Month(month), Day(day)), Time(Year(tyear), Month(tmonth), Day(tday)), id, password, qqnum, wbnum);
            person->groNum()=gronum;//friendlist和askfriendlist等所有人都构建完之后在写入
            person->tempgroNum()=tempgronum;
            (person->friendlistnum())=friendid;
            (person->askfriendlistnum())=askfriendid;
            person->qq()=qqnum;
            person->wb()=wbnum;
            (_pWC->people())->push_back(person);
            outfile.close();
        }//现在所有的人都齐了
        for(auto i=(_pWC->people())->begin(); i!=(_pWC->people())->end(); ++i)//把friendlistnum和sakfriendlistnum的人都找到
        {
            if(!((*i)->askfriendlistnum()).empty())
                for(auto num=((*i)->askfriendlistnum()).cbegin(); num!=((*i)->askfriendlistnum()).cend(); ++num)
                    for(auto j=(_pWC->people())->begin(); j!=(_pWC->people())->end(); ++j)
                        if((*j)->ID()==*num)
                            ((*i)->askfriendList()).push_back(*j);
            if(!((*i)->friendlistnum()).empty())
                for(auto num=((*i)->friendlistnum()).cbegin(); num!=((*i)->friendlistnum()).cend(); ++num)
                    for(auto j=(_pWC->people())->begin(); j!=(_pWC->people())->end(); ++j)
                        if((*j)->ID()==*num)
                            ((*i)->friendList()).push_back(*j);
        }
        
        
        getline(wc,wcs);
        wcss.clear();
        wcss.str("");
        wcss<<wcs;
        while(wcss>>a)//组号
        {
            
            (_pWC->groupMana())->push_back(std::make_shared<groupXZJ>(a));
        }
        
        for(auto i=(_pWC->groupMana())->begin(); i!=(_pWC->groupMana())->end(); ++i)//对于微信中的每一个群
        {
            long j=(*i)->groupNum();
            wcss.clear();
            wcss.str("");
            wcss<<j;
            wcs="WCGro"+wcss.str()+".txt";//群号
            outfile.open(wcs);//根据群号打开文件
            getline(outfile, wcs);
            wcss.clear();
            wcss.str("");
            wcss<<wcs;
            std::vector<long>().swap(personid);
            while(wcss>>a)
            {
                personid.push_back(a);
            }
            if(!personid.empty())
            {
                for(auto j=personid.begin(); j!=personid.end(); ++j)
                {//根据这个群中每个人的ID去QQ群里面找然后压入这个群的人里面
                    for(auto k=(_pWC->people())->begin(); k!=(_pWC->people())->end(); ++k)
                        if(*j==(*k)->ID())
                        {
                            ((*i)->wcGro())->push_back(*k);
                            break;
                        }
                }
            }
            
            getline(outfile, wcs);
            wcss.clear();
            wcss.str("");
            wcss<<wcs;
            std::vector<long>().swap(personid);
            while(wcss>>a)
            {
                
                personid.push_back(a);
            }
            if(!personid.empty())
            {
                for(auto j=personid.begin(); j!=personid.end(); ++j)
                {//根据这个群中每个人的ID去QQ群里面找然后压入这个群的人里面
                    for(auto k=(_pWC->people())->begin(); k!=(_pWC->people())->end(); ++k)
                        if(*j==(*k)->ID())
                        {
                            ((*i)->askJoinWCGroList())->push_back(*k);
                            break;
                        }
                }
            }
            outfile.close();
        }
        
        
        getline(wc,wcs);
        wcss.clear();
        wcss.str("");
        wcss<<wcs;
        while(wcss>>a)//临时讨论组号
        {
             
            (_pWC->tempdisgro())->push_back(std::make_shared<groupXZJ>(a));
        }
        for(auto i=(_pWC->tempdisgro())->begin(); i!=(_pWC->tempdisgro())->end(); ++i)//对于微信中的每一个临时群
        {
            long j=(*i)->groupNum();
            wcss.clear();
            wcss.str("");
            wcss<<j;
            wcs="WCGro"+wcss.str()+".txt";//群号
            outfile.open(wcs);//根据群号打开文件
            getline(outfile, wcs);
            wcss.clear();
            wcss.str("");
            wcss<<wcs;
            std::vector<long>().swap(personid);
            while(wcss>>a)
            {
                
                personid.push_back(a);
            }
            if(!personid.empty())
            {
                for(auto j=personid.begin(); j!=personid.end(); ++j)
                {//根据这个群中每个人的ID去QQ群里面找然后压入这个群的人里面
                    for(auto k=(_pWC->people())->begin(); k!=(_pWC->people())->end(); ++k)
                        if(*j==(*k)->ID())
                        {
                            ((*i)->tempwcGro())->push_back(*k);
                            break;
                        }
                }
            }
            
            
            getline(outfile, wcs);
            wcss.clear();
            wcss.str("");
            wcss<<wcs;
            std::vector<long>().swap(personid);
            while(wcss>>a)
            {
                
                personid.push_back(a);
            }
            if(!personid.empty())
            {
                for(auto j=personid.begin(); j!=personid.end(); ++j)
                {//根据这个群中每个人的ID去QQ群里面找然后压入这个群的人里面
                    for(auto k=(_pWC->people())->begin(); k!=(_pWC->people())->end(); ++k)
                        if(*j==(*k)->ID())
                        {
                            ((*i)->askJointempWCGroList())->push_back(*k);
                            break;
                        }
                }
            }
            outfile.close();
        }
        wc.close();
    } catch (long a) {
        std::cout<<"打开文件失败";
    }
}
void Files::OutFileWB()
{
    try {
        _pWB=std::make_shared<WBXZJ>();
        wb.open("WB.txt");
        if(!wb.is_open())
            throw 1;
        std::stringstream qqss, wcss,wbss;
        std::string qqs, wcs, wbs;
        std::vector<long> gronum, tempgronum, personid;
        
        //人
        long id, password, number, year, month, day, tyear, tmonth, tday, wcid, qqnum, fid, askfid;
        std::vector<long> friendid, askfriendid;
        std::string name, home;
        
        long a;
        
        getline(wb,wbs);
        
        wbss<<wbs;
        while(wbss>>a)//人的ID
        {
            
            personid.push_back(a);
        }
        for(auto i=personid.begin(); i!=personid.end(); ++i)
        {
            wbss.clear();
            wbss.str("");
            wbss<<*i;
            wbs="QQ"+wbss.str()+".txt";
            outfile.open(wbs);
            getline(outfile, wbs);
            wbss.clear();
            wbss.str("");
            wbss<<wbs;
            wbss>>id;
            
            
            getline(outfile, wbs);
            wbss.clear();
            wbss.str("");
            wbss<<wbs;
            wbss>>number;
            
            
            getline(outfile, wbs);
            wbss.clear();
            wbss.str("");
            wbss<<wbs;
            wbss>>password;
            
            
            getline(outfile, wbs);
            wbss.clear();
            wbss.str("");
            wbss<<wbs;
            wbss>>name;
            
            
            getline(outfile, wbs);
            wbss.clear();
            wbss.str("");
            wbss<<wbs;
            wbss>>home;
            
            
            getline(outfile, wbs);
            wbss.clear();
            wbss.str("");
            wbss<<wbs;
            long a;
            gronum.clear();
            while(wbss>>a)
            {
                
                gronum.push_back(a);
            }
          
            wbss.clear();
            wbss.str("");
            getline(outfile, wbs);
            wbss<<wbs;
            tempgronum.clear();
            while(wbss>>a)
            {
             
                tempgronum.push_back(a);
            }
            getline(outfile, wbs);
            wbss.clear();
            wbss.str("");
            wbss<<wbs;
            wbss>>year>>month>>day;
            
            
            getline(outfile, wbs);
            wbss.clear();
            wbss.str("");
            wbss<<wbs;
            wbss>>tyear>>tmonth>>tday;
          
            
            getline(outfile, wbs);
            wbss.clear();
            wbss.str("");
            wbss<<wbs;
            wbss>>wcid;
            
            
            getline(outfile, wbs);
            wbss.clear();
            wbss.str("");
            wbss<<wbs;
            wbss>>qqnum;
            
            
            getline(outfile, wbs);
            wbss.clear();
            wbss.str("");
            wbss<<wbs;
            wbss>>fid;
            
            friendid.clear();
            if(fid!=0)
            {
                friendid.push_back(fid);
                while(wbss>>fid)
                {
                   
                    friendid.push_back(fid);
                }
            }
            getline(outfile, wbs);
            wbss.clear();
            wbss.str("");
            wbss<<wbs;
            wbss>>askfid;
            
            askfriendid.clear();
            if(askfid!=0)
            {
                askfriendid.push_back(askfid);
                while(wbss>>askfid)
                {
                    
                    askfriendid.push_back(askfid);
                }
            }
            std::shared_ptr<WBDataXZJ> person=std::make_shared<WBDataXZJ>(name, home, Time(Year(year), Month(month), Day(day)), Time(Year(tyear), Month(tmonth), Day(tday)), id, password, qqnum, wcid, number);
            person->groNum()=gronum;//friendlist和askfriendlist等所有人都构建完之后在写入
            person->tempgroNum()=tempgronum;
            (person->friendlistnum())=friendid;
            (person->askfriendlistnum())=askfriendid;
            person->qq()=qqnum;
            person->wc()=wcid;
            (_pWB->people())->push_back(person);
            outfile.close();
        }//现在所有的人都齐了
        for(auto i=(_pWB->people())->begin(); i!=(_pWB->people())->end(); ++i)//把friendlistnum和sakfriendlistnum的人都找到
        {
            if(!((*i)->askfriendlistnum()).empty())
                for(auto num=((*i)->askfriendlistnum()).cbegin(); num!=((*i)->askfriendlistnum()).cend(); ++num)
                    for(auto j=(_pWB->people())->begin(); j!=(_pWB->people())->end(); ++j)
                        if((*j)->ID()==*num)
                            ((*i)->askfriendList()).push_back(*j);
            if(!((*i)->friendlistnum()).empty())
                for(auto num=((*i)->friendlistnum()).cbegin(); num!=((*i)->friendlistnum()).cend(); ++num)
                    for(auto j=(_pWB->people())->begin(); j!=(_pWB->people())->end(); ++j)
                        if((*j)->ID()==*num)
                            ((*i)->friendList()).push_back(*j);
        }
        
        
        getline(wb,wbs);
        wbss.clear();
        wbss.str("");
        wbss<<wbs;
        while(wbss>>a)//组号
        {
            
            (_pWB->groupMana())->push_back(std::make_shared<groupXZJ>(a));
        }
        for(auto i=(_pWB->groupMana())->begin(); i!=(_pWB->groupMana())->end(); ++i)//对于微博中的每一个群
        {
            long j=(*i)->groupNum();
            wbss.clear();
            wbss.str("");
            wbss<<j;
            wbs="WBGro"+wbss.str()+".txt";//群号
            outfile.open(wbs);//根据群号打开文件
            getline(outfile, wbs);
            wbss.clear();
            wbss.str("");
            wbss<<wbs;
            std::vector<long>().swap(personid);
            while(wbss>>a)
            {
                
                personid.push_back(a);
            }
            if(!personid.empty())
            {
                for(auto j=personid.begin(); j!=personid.end(); ++j)
                {//根据这个群中每个人的ID去QQ群里面找然后压入这个群的人里面
                    for(auto k=(_pWB->people())->begin(); k!=(_pWB->people())->end(); ++k)
                        if(*j==(*k)->ID())
                        {
                            ((*i)->wbGro())->push_back(*k);
                            break;
                        }
                }
            }
            
            
            getline(outfile, wbs);
            wbss.clear();
            wbss.str("");
            wbss<<wbs;
            std::vector<long>().swap(personid);
            while(wbss>>a)
            {
                
                personid.push_back(a);
            }
            if(!personid.empty())
            {
                for(auto j=personid.begin(); j!=personid.end(); ++j)
                {//根据这个群中每个人的ID去QQ群里面找然后压入这个群的人里面
                    for(auto k=(_pWB->people())->begin(); k!=(_pWB->people())->end(); ++k)
                        if(*j==(*k)->ID())
                        {
                            ((*i)->askJoinWBGroList())->push_back(*k);
                            break;
                        }
                }
            }
            outfile.close();
        }
        
        
        getline(wb,wbs);
        wbss.clear();
        wbss.str("");
        wbss<<wbs;
        while(wbss>>a)//临时讨论组号
        {
            
            (_pWB->tempdisgro())->push_back(std::make_shared<groupXZJ>(a));
        }
        for(auto i=(_pWB->tempdisgro())->begin(); i!=(_pWB->tempdisgro())->end(); ++i)//对于微博中的每一个群
        {
            long j=(*i)->groupNum();
            wbss.clear();
            wbss.str("");
            wbss<<j;
            wbs="WBGro"+wbss.str()+".txt";//群号
            outfile.open(wbs);//根据群号打开文件
            getline(outfile, wbs);
            wbss.clear();
            wbss.str("");
            wbss<<wbs;
            std::vector<long>().swap(personid);
            while(wbss>>a)
            {
                
                personid.push_back(a);
            }
            if(!personid.empty())
            {
                for(auto j=personid.begin(); j!=personid.end(); ++j)
                {//根据这个群中每个人的ID去QQ群里面找然后压入这个群的人里面
                    for(auto k=(_pWB->people())->begin(); k!=(_pWB->people())->end(); ++k)
                        if(*j==(*k)->ID())
                        {
                            ((*i)->tempwbGro())->push_back(*k);
                            break;
                        }
                }
            }
            getline(outfile, wbs);
            wbss.clear();
            wbss.str("");
            wbss<<wbs;
            std::vector<long>().swap(personid);
            while(wbss>>a)
            {
                
                personid.push_back(a);
            }
            if(!personid.empty())
            {
                for(auto j=personid.begin(); j!=personid.end(); ++j)
                {//根据这个群中每个人的ID去QQ群里面找然后压入这个群的人里面
                    for(auto k=(_pWB->people())->begin(); k!=(_pWB->people())->end(); ++k)
                        if(*j==(*k)->ID())
                        {
                            ((*i)->askJointempWBGroList())->push_back(*k);
                            break;
                        }
                }
            }
            outfile.close();
        }
        wb.close();
    } catch (long a) {
        std::cout<<"打开文件失败";
    }
}
