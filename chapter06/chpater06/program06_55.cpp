//
//  program06_55.cpp
//  chpater06
//
//  Created by chenyijun on 17/3/8.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//加法
int func1(int a, int b)
{
    return a + b;
}

//减法
int func2(int a, int b)
{
    return a - b;
}

//乘法
int func3(int a, int b)
{
    return a * b;
}

//除法
int func4(int a, int b)
{
    return a / b;
}

int main()
{
    decltype(func1) *p1 = func1, *p2 = func2, *p3 = func3, *p4 = func4;
    vector<decltype(func1) *> vF = {p1, p2, p3, p4};
    
    return 0;
}

