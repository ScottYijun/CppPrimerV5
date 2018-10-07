//
//  program14.cpp
//  chapter02
//
//  Created by chenyijun on 17/1/25.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

int main()
{
    int i = 100, sum = 0;
    for(int i = 0; i != 10; ++i)
    {
        sum += i;
    }
    
    std::cout << "i========" << i << "  " << "sum=======" << sum  << std::endl;
    
    return 0;
}
