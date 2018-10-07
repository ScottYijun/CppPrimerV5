//
//  program35.cpp
//  chapter02
//
//  Created by chenyijun on 17/2/2.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <typeinfo>

int main()
{
    const int i = 42;
    auto j = i;
    const auto  &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;
    float aa = 3.12;
    
    std::cout << typeid(i).name() << std::endl;
    std::cout << typeid(j).name() << std::endl;
    std::cout << typeid(k).name() << std::endl;
    std::cout << typeid(p).name() << std::endl;
    std::cout << typeid(j2).name() << std::endl;
    std::cout << typeid(k2).name() << std::endl;
    std::cout << typeid(aa).name() << std::endl;
    
    
    std::cout << "===========================" << std::endl;
    std::cout << typeid(int).name() << std::endl;
    std::cout << typeid(const int).name() << std::endl;
    std::cout << typeid(const int&).name() << std::endl;
    std::cout << typeid(double).name() << std::endl;
    std::cout << typeid(const double).name() << std::endl;
    std::cout << typeid(const double&).name() << std::endl;
    return 0;
}
