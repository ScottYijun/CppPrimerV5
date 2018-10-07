//
//  program16.cpp
//  chapter02
//
//  Created by chenyijun on 17/1/25.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

int main()
{
    
    int i = 0, &r1 = i;
    double d = 0, &r2 = d;
    r2 = 3.14159;
    r2 = r1;
    i = r2;
    r1 = d;
    std::cout << "r2============" << r2 << std::endl;
    return 0;
}