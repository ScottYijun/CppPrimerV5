//
//  program38.cpp
//  chapter02
//
//  Created by chenyijun on 17/2/2.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
    int a  = 3;
    auto c1 = a;
    decltype(a) c2 = a;
    decltype((a)) c3 = a;

    const int d = 5;
    auto f1 = d;
    decltype(d) f2 = d;

    std::cout << typeid(c1).name() << std::endl;
    std::cout << typeid(c2).name() << std::endl;
    std::cout << typeid(c3).name() << std::endl;
    std::cout << typeid(f1).name() << std::endl;
    std::cout << typeid(f2).name() << std::endl;

    c1++;
    c2++;
    c3++;
    f1++;
    //f2++;//??:f2?????,????????

    std::cout << a << " " << c1 << " " << c2 << " "
              << c3 << " " << f1 << " " << f2 << std::endl;
    
    return 0;
}

