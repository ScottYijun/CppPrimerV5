//
//  program04.cpp
//  chapter01
//
//  Created by chenyijun on 2017/01/20.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//
//加，减，乘，除 Addition, subtraction, multiplication and division
//和，差，积，商 sum, difference，product，quotients

#include <iostream>

int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int param1 = 0;
    int param2 = 0;
    std::cin >> param1 >> param2;
    std::cout << "The sum of " << param1 << " and " << param2 << " is " << (param1 + param2)
              << "The difference of " << param1 << " and " << param2 << " is " << (param1 - param2)
              << "The product of " << param1 << " and " << param2 << " is " << (param1 * param2)
              << "The quotients of " << param1 << " and " << param2 << " is " << (param1 / param2) << std::endl;
    std::cout << std::endl;
    return 0;
}
