//
//  program06_51.cpp
//  chpater06
//
//  Created by chenyijun on 17/3/8.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

void f()
{
    cout << "该函数无须参数" << endl;
}

void f(int)
{
    cout << "该函数有一个整型参数" << endl;
}

void f(int, int)
{
    cout << "该函数有两个整型参数" << endl;
}

void f(double a, double b = 3.14)
{
    cout << "该函数有两个双精度浮点型参数" << endl;
}

int main()
{
    //f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    
    return 0;
}



