//
//  program37.cpp
//  chapter02
//
//  Created by chenyijun on 17/2/2.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

int main()
{
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype(a = b) d = a;
    std::cout << "a = " << a << "  b = " << b << "  c = " << c << "  d = " << d << std::endl;
    
    a = 8;
    std::cout << "a = " << a << "  b = " << b << "  c = " << c << "  d = " << d << std::endl;
    
    return 0;
}

