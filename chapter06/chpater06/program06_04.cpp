//
//  program06_04.cpp
//  chpater06
//
//  Created by chenyijun on 17/2/26.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//


#include <iostream>

using namespace std;

int fact(int val)
{
    if(val < 0)
        return -1;
    int ret = 1;
    //从1连乘到val
    for(int i = 1; i != val + 1; ++i)
        ret *= i;
    
    return ret;
}

int main()
{
    int num;
    cout << "请输入一个整数:" << endl;
    cin >> num;
    cout << num << "的阶乘是：" << fact(num) << endl;
    
    return 0;
}