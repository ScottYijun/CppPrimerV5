//
//  program03.cpp
//  chapter02
//
//  Created by chenyijun on 17/1/22.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//


#include <iostream>

int main()
{
    
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;
    
    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;
    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;
    
    return 0;
}

