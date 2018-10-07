//
//  program20.cpp
//  chapter01
//
//  Created by chenyijun on 2017/01/21.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include "Sales_item.h"
#include <iostream>

int main()
{
    
    Sales_item book;
    std::cout << "请输入销售记录：" << std::endl;
    //读入ISBN号、售出的册数以及销售价格
    
    while(std::cin >> book)
    {
        std::cout <<  "ISBN、售出本数、销售额和平均售价为 " << book << std::endl;
    }
    
    return 0;
}
