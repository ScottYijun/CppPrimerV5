//
//  program13.cpp
//  chapter01
//
//  Created by chenyijun on 2017/01/21.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

int main()
{
    int sum = 0;
    for(int val = 1; val <= 10; ++val)
    {
        sum += val;
    }
    
    std::cout << "sum of 1 to 10 inclusive is " << sum << std::endl;
    
    return 0;
}
