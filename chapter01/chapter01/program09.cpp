//
//  program09.cpp
//  chapter01
//
//  Created by chenyijun on 2017/01/21.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

int main()
{
    int sum = 0;
    int i = 50;
    while(i <= 100)
    {
        sum = sum  + i;
        ++i;
    }
    
    std::cout << "sum =======" << sum;
    
    return 0;
}
