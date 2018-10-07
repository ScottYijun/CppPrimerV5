//
//  文件名：program14_44.cpp
//  工程名：chapter14
//  简介：
//  创建日期：Created by chenyijun on 2017/8/14.
//  版权：Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

map<string, function<int (int, int) >> binOps = {
    {"+", plus<int>()},
    {"-", minus<int>()},
    {"*", multiplies<int>()},
    {"/", divides<int>()},
    {"%", modulus<int>()}
};


int main()
{
    int left, right;
    string op;
    cin >> left >> op >> right;
    cout << binOps[op](left, right) << endl;

    cout << "Hello World!" << endl;
    return 0;
}

