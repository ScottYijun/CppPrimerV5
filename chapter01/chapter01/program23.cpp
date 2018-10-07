//
//  program23.cpp
//  chapter01
//
//  Created by chenyijun on 2017/01/22.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include "Sales_item.h"


int main()
{
    Sales_item trans1, trans2;
    int num = 1;
    std::cout << "请输入若干销售记录：" << std::endl;
    
    if(std::cin >> trans1)
    {
        while(std::cin >> trans2)
        {
            if(compareIsbn(trans1, trans2))
            {
                num++;
            }
            else  //ISBN不同
            {
                std::cout << trans1.isbn() << "共有" << num << "条销售记录"  << std::endl;
                trans1 = trans2;
                num = 1;
            }
            std::cout << trans1.isbn() << "共有" << num << "条销售记录" << std::endl;
        }
    }
    else
    {
        std::cout << "没有数据" << std::endl;
        return -1;
    }
}




