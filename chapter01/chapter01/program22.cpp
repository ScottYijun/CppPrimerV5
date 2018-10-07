//
//  program22.cpp
//  chapter01
//
//  Created by chenyijun on 2017/01/22.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item total, trans;
    std::cout << "请输入几条ＩＳＢＮ 相同的销售记录：" << std::endl;
    if(std::cin >> total)
    {
        while(std::cin >> trans)
        {
            if(compareIsbn(total, trans))  //ISBN相同
            {
                total = total + trans;
            }
            else   //ISBN 不同
            {
                std::cout << "ISBN不同" << std::endl;
                return -1;
            }
            
            std::cout << "汇总信息：ＩＳＢＮ、售出本数、销售额和平均售价为" << total << std::endl;
        }
    }
    else
    {
        std::cout << "没有数据" << std::endl;
        return -1;
    }
    
    return 0;
}

