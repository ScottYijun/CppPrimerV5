//
//  program06_05.cpp
//  chpater06
//
//  Created by chenyijun on 17/2/26.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;
//第一个函数通过if-else语句计算绝对值
double myABS(double val)
{
    if(val < 0)
        return val * -1;
    else
        return val;
}

//第二个函数调用cmath头文件的abs函数计算绝对值
double myABS2(double val)
{
    return abs(val);
}

//第三个函数直接在前面加－号
double myABS3(double val)
{
    if(val < 0)
        return -val;
    else
        return val;
}

int main()
{
    double num;
    cout << "请输入一个数：" << endl;
    cin >> num;
    cout << num << "的绝对值是：" << myABS(num) << endl;
    cout << num << "的绝对值是：" << myABS2(num) << endl;
    cout << num << "的绝对值是：" << myABS3(num) << endl;
    return 0;
}

