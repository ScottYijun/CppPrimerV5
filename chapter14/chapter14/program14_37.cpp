//
//  文件名：program14_37.cpp
//  工程名：chapter14
//  简介：
//  创建日期：Created by chenyijun on 2017/8/9.
//  版权：Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>        //istringstream 必须包含这个头文件
#include <vector>

using namespace std;

class IntCompare
{
public:
    IntCompare(int v): val(v) { }
    bool operator()(int v)
    {
        return val == v;
    }

private:
    int val;
};

int main()
{
    vector<int> vec = {1, 2, 3, 2, 1};
    const int oldValue = 2;
    const int newValue = 200;
    IntCompare icmp(oldValue);
    std::replace_if(vec.begin(), vec.end(), icmp, newValue);
    cout << "icmp==================" << icmp.operator ()(2) << endl;
    cout << "Hello World!" << endl;
    return 0;
}

