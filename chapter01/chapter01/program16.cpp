//
//  program16.cpp
//  chapter01
//
//  Created by chenyijun on 2017/01/21.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

int main()
{
    
    int value;
    int sum = 0;
    std::cout << "请输入value的值:" << std::endl;
    while(std::cin >> value)
    {
        sum += value;
    }
    
    std::cout << "sum ======================== " << sum << std::endl;
    
    return 0;
}



