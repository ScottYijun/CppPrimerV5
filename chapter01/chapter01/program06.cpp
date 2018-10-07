//
//  program06.cpp
//  chapter01
//
//  Created by chenyijun on 2017/01/20.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

int main()
{
    std::cout << "Enter two  numbers:" << std::endl;
    int param1 = 0;
    int param2 = 0;
    std::cin >> param1 >> param2;
    std::cout << "The sum和 of " << param1
            << " and " << param2
            << " is " << (param1 + param2) << std::endl;

    return 0;
}
