//
//  program11.cpp
//  chapter01
//
//  Created by chenyijun on 2017/01/21.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

int main()
{
    int param1 = 0;
    int param2 = 0;
    std::cout << "请输入param1和param2的值：" << std::endl;
    std::cin >> param1 >> param2;
    std::cout << "param1 到 param2之间的整数为：" << std::endl;
    if(param1 > param2)
    {
        while(param1 >= param2)
        {
            std::cout << param1 << std::endl;
            param1--;
        }
    }
    else
    {
        while(param1 <= param2)
        {
            std::cout << param1 << std::endl;
            param1++;
        }
    }
    
    return 0;
}

