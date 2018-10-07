//
//  program18.cpp
//  chapter02
//
//  Created by chenyijun on 17/1/25.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>


int main()
{
    
    int param1 = 10;
    int param2 = 20;
    int param3 = 30;
    
    int *p1 = &param1;
    std::cout << "p1====================" << p1 << "   *p1=======" << *p1 << std::endl;
    int *p2 = &param2;
    std::cout << "p2====================" << p2 << "   *p2=======" << *p2 << std::endl;
    p1 = &param3;
    std::cout << "修改p1的值======p1======" << p1 << "   *p1=======" << *p1 << std::endl;
    *p2 = param3;
    std::cout << "修改p2所指对象的值==p2===" << p2 << "   *p2=======" << *p2 << std::endl;
    return 0;
}
