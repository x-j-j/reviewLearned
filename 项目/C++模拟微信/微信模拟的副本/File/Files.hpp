//
//  Files.hpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/11.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#ifndef Files_hpp
#define Files_hpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "QQXZJ.hpp"
#include "WBXZJ.hpp"
#include "WCXZJ.hpp"
//一个人一个文件(QQ+ID号为文件名)或者(WC+ID号为文件名)或者(WB+ID号为文件名)
//18个群文件,18个临时讨论组文件,存储群号和每个人的ID号
//外加QQ,WC,WB三个文件存储 所有人的ID号(用来识别人的),临时讨论组号,群号

class Files
{
public:
    Files();
    //save时清空文件，重新写入
    
    void Save(const std::shared_ptr<QQXZJ>& save);//保存QQ信息，顺便保存群的信息
    void Save(const std::shared_ptr<WBXZJ>& save);//保存微博信息，顺便保存群的信息
    void Save(const std::shared_ptr<WCXZJ>& save);//保存微信信息，顺便保存群的信息
    
    const std::shared_ptr<QQXZJ>& QQ(){return _pQ;}
    const std::shared_ptr<WBXZJ>& WB(){return _pWB;}
    const std::shared_ptr<WCXZJ>& WC(){return _pWC;}
    ~Files(){}
private:
    void Save(const std::shared_ptr<QQDataXZJ>& save);//保存一个人的信息
    void Save(const std::shared_ptr<WBDataXZJ>& save);//保存一个人的信息
    void Save(const std::shared_ptr<WCDataXZJ>& save);//保存一个人的信息
    void SaveQQGro(const std::shared_ptr<groupXZJ>& save);
    void SaveWBGro(const std::shared_ptr<groupXZJ>& save);
    void SaveWCGro(const std::shared_ptr<groupXZJ>& save);
    void SaveQQtempGro(const std::shared_ptr<groupXZJ>& save);
    void SaveWBtempGro(const std::shared_ptr<groupXZJ>& save);
    void SaveWCtempGro(const std::shared_ptr<groupXZJ>& save);
    
    void OutFileQQ();
    void OutFileWC();
    void OutFileWB();
    std::ifstream outfile, qq, wc, wb;
    std::ofstream infile, ifqq, ifwc, ifwb, ifperson;
    std::istringstream instrstream;
    std::ostringstream outstrstream;
    
    std::shared_ptr<QQXZJ> _pQ=nullptr;
    std::shared_ptr<WBXZJ> _pWB=nullptr;
    std::shared_ptr<WCXZJ> _pWC=nullptr;
};
#endif /* Files_hpp */
