//
//  文件名：program14_34.cpp
//  工程名：chapter14
//  简介：
//  创建日期：Created by chenyijun on 2017/8/9.
//  版权：Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>
#include<sstream>        //istringstream 必须包含这个头文件

using namespace std;

class IfElseThen
{
public:
    IfElseThen() { }
    IfElseThen(int i1, int i2, int i3): iVal1(i1), iVal2(i2), iVal3(i3)
    {

    }

    int operator() (int i1, int i2, int i3)
    {
        return i1 ? i2 : i3;
    }

private:
    int iVal1, iVal2, iVal3;
};

int main()
{
    IfElseThen ifelse;

    cout << "ifelse==========" << ifelse(5, 6, 2) << endl;

    cout << "Hello World!" << endl;
    return 0;
}

