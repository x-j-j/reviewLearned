//
//  main.cpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
#include "userManaXZJ.hpp"
#include "Files.hpp"
int main(int argc, const char * argv[]) {
//    //一个人一个文件(QQ+ID号为文件名)或者(WC+ID号为文件名)或者(WB+ID号为文件名)
//    //三个群文件,三个临时讨论组文件,存储群号和每个人的ID号
//    //外加QQ,WC,WB三个文件存储 所有人的ID号(用来识别人的),临时讨论组号,群号
//    //id，账号，密码，名字，家乡，加入的群号，生日，T龄，绑定的微信ID，绑定微博号，好友ID，要加好友ID
//    ofstream qq, wc, wb, qqgro, wbgro, wcgro, qqtempgro, wbtempgro, wctempgro, qqperson, wcperson, wbperson;
//    qq.open("QQ.txt");qq<<123456<<" "<<123123<<endl<<1001<<" "<<1002<<" "<<1003<<" "<<1004<<" "<<1005<<" "<<1006<<endl<<1010<<endl;qq.close();
//    wc.open("WC.txt");wc<<123456<<" "<<123123<<endl<<1001<<" "<<1002<<" "<<1003<<" "<<1004<<" "<<1005<<" "<<1006<<endl<<1010<<endl;wc.close();
//    wb.open("WB.txt");wb<<123456<<" "<<123123<<endl<<1001<<" "<<1002<<" "<<1003<<" "<<1004<<" "<<1005<<" "<<1006<<endl<<1010<<endl;wb.close();
//
//
//    qqperson.open("QQ123456.txt");
//    qqperson<<123456<<endl<<2849771625<<endl<<15542066267100<<endl<<"肖子健"<<endl<<"开原"<<endl
//    <<1001<<endl<<1010<<endl
//    <<2000<<" "<<10<<" "<<12<<endl
//    <<2019<<" "<<10<<" "<<18<<endl
//    <<0<<endl<<0<<endl<<0<<endl<<0<<endl;
//    qqperson.close();
//
//    wcperson.open("WC123456.txt");
//    wcperson<<123456<<endl<<15542066267100<<endl<<"肖子健"<<endl<<"开原"<<endl
//    <<1001<<endl<<1010<<endl
//    <<2000<<" "<<10<<" "<<12<<endl
//    <<2019<<" "<<10<<" "<<18<<endl
//    <<0<<endl<<0<<endl<<0<<endl<<0<<endl;
//    wcperson.close();
//
//    wbperson.open("WB123456.txt");
//    wbperson<<123123<<endl<<2849771625<<endl<<15542066267100<<endl<<"肖子健"<<endl<<"开原"<<endl
//    <<1001<<endl<<1010<<endl
//    <<2000<<" "<<10<<" "<<12<<endl
//    <<2019<<" "<<10<<" "<<18<<endl
//    <<0<<endl<<0<<endl<<0<<endl<<0<<endl;
//    wbperson.close();
//
//    qqperson.open("QQ123123.txt");
//    qqperson<<123123<<endl<<3110957558<<endl<<15542066267100<<endl<<"施运理"<<endl<<"南宁"<<endl
//    <<1002<<endl<<1010<<endl
//    <<2000<<" "<<10<<" "<<12<<endl
//    <<2019<<" "<<10<<" "<<19<<endl
//    <<0<<endl<<0<<endl<<0<<endl<<0<<endl;
//    qqperson.close();
//
//    wcperson.open("WC123123.txt");
//    wcperson<<123123<<endl<<15542066267100<<endl<<"施运理"<<endl<<"南宁"<<endl
//    <<1002<<endl<<1010<<endl
//    <<2000<<" "<<10<<" "<<12<<endl
//    <<2019<<" "<<10<<" "<<19<<endl
//    <<0<<endl<<0<<endl<<0<<endl<<0<<endl;
//    wcperson.close();
//
//    wbperson.open("WB123123.txt");
//    wbperson<<123456<<endl<<3110957558<<endl<<15542066267100<<endl<<"施运理"<<endl<<"南宁"<<endl
//    <<1002<<endl<<1010<<endl
//    <<2000<<" "<<10<<" "<<12<<endl
//    <<2019<<" "<<10<<" "<<19<<endl
//    <<0<<endl<<0<<endl<<0<<endl<<0<<endl;
//    wbperson.close();
//
//    qqgro.open("QQtempGro1010.txt");qqgro<<123456<<" "<<123123<<endl;qqgro.close();
//    wbgro.open("WBtempGro1010.txt");wbgro<<123456<<" "<<123123<<endl;wbgro.close();
//    wcgro.open("WCtempGro1010.txt");wcgro<<123456<<" "<<123123<<endl;wcgro.close();
//
//
//
//    qqtempgro.open("QQGro1001.txt");qqtempgro<<123456<<endl;qqtempgro.close();
//    wbtempgro.open("WBGro1001.txt");wbtempgro<<123456<<endl;wbtempgro.close();
//    wctempgro.open("WCGro1001.txt");wctempgro<<123456<<endl;wctempgro.close();
//
//    qqtempgro.open("QQGro1002.txt");qqtempgro<<123123<<endl;qqtempgro.close();
//    wbtempgro.open("WBGro1002.txt");wbtempgro<<123123<<endl;wbtempgro.close();
//    wctempgro.open("WCGro1002.txt");wctempgro<<123123<<endl;wctempgro.close();
//
//    qqtempgro.open("QQGro1003.txt");qqtempgro.close();
//    wbtempgro.open("WBGro1003.txt");wbtempgro.close();
//    wctempgro.open("WCGro1003.txt");wctempgro.close();
//
//    qqtempgro.open("QQGro1004.txt");qqtempgro.close();
//    wbtempgro.open("WBGro1004.txt");wbtempgro.close();
//    wctempgro.open("WCGro1004.txt");wctempgro.close();
//
//    qqtempgro.open("QQGro1005.txt");qqtempgro.close();
//    wbtempgro.open("WBGro1005.txt");wbtempgro.close();
//    wctempgro.open("WCGro1005.txt");wctempgro.close();
//
//    qqtempgro.open("QQGro1006.txt");qqtempgro.close();
//    wbtempgro.open("WBGro1006.txt");wbtempgro.close();
//    wctempgro.open("WCGro1006.txt");wctempgro.close();
//    userManaXZJ u;
    userManaXZJ u;
    return 0;
}
