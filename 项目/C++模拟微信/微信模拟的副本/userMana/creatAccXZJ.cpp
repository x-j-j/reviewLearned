//
//  creatAccXZJ.cpp
//  Five-Days
//
//  Created by 肖子健  on 2019/10/10.
//  Copyright © 2019 肖子健 . All rights reserved.
//

#include "creatAccXZJ.hpp"
#include "creatAccImplXZJ.hpp"
creatAccXZJ::creatAccXZJ(const std::shared_ptr<Files>& _pF)
{
    pcAI=(std::make_shared<creatAccImplXZJ>(_pF));
}
const std::shared_ptr<QQDataXZJ> creatAccXZJ::creatQQAcc()
{
    return pcAI->creatQQAcc();
}
const std::shared_ptr<WCDataXZJ> creatAccXZJ::creatWCAcc()
{
    return pcAI->creatWCAcc();
}
const std::shared_ptr<WBDataXZJ> creatAccXZJ::creatWBAcc()
{
    return pcAI->creatWBAcc();
}
