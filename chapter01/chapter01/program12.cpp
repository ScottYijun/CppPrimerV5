//
//  program12.cpp
//  chapter01
//
//  Created by chenyijun on 2017/01/21.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

int main()
{
    
    int sum = 0;
    for(int i = -100; i <= 100; ++i)
    {
        sum += i;
    }
    std::cout << "sum==========" << sum << std::endl;
    return 0;
}


