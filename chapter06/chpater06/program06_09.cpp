//
//  program06_09.cpp
//  chpater06
//
//  Created by chenyijun on 17/2/26.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include "program06_08.h"
#include <iostream>
#include <cmath>

using namespace std;

int fact(int val)
{
    if(val < 0)
        return -1;
    int ret = 1;
    for(int i = 1; i != val + 1; ++i)
        ret *= i;
    
    return ret;
}

void myABS(int &a)
{
    if(a < 0)
        a = -a;
}

int myABS2(int b)
{
    if(b < 0)
        return -b;
    else
        return b;
}

int main()
{
    int num;
    cout << "请输入第一个整数:" << endl;
    cin >> num;
    myABS(num);
    cout << num << "的阶数是：" << fact(num) << endl;
    cout << "请输入第2个整数:" << endl;
    cin >> num;
    num = myABS2(num);
    cout << num << "的阶数是：" << fact(num) << endl;
    return 0;
}