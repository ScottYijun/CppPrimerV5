//
//  program20.cpp
//  chapter02
//
//  Created by chenyijun on 17/1/25.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

int main()
{
    int i = 42;
    int *p1 = &i;
    *p1 = *p1 * *p1;
    std::cout << "*p1========================" << *p1 << std::endl;
    
    return 0;
}
