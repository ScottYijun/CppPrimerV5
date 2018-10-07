//
//  文件名：program14_43.cpp
//  工程名：chapter14
//  简介：
//  创建日期：Created by chenyijun on 2017/8/14.
//  版权：Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>        //istringstream 必须包含这个头文件
#include <vector>
#include <algorithm>
#include <functional>


using namespace std;

bool dividedByAll(vector<int> &ivec, int dividend)
{
    int nInt = count_if(ivec.begin(), ivec.end(), bind1st(modulus<int>(), dividend));
    cout << "nInt=====================" << nInt << endl;
    return  nInt == 0;
}


int main()
{
    vector<int> nInt = {12, 36, 58, 96, 78, 62};

    bool bValue = dividedByAll(nInt, 3);
    if(bValue)
        cout << "所有的数都能被3整除======" << endl;
    else
        cout << "有的数不能被3整除======" << endl;

    bool bValue2 = dividedByAll(nInt, 2);
    if(bValue2)
        cout << "所有的数都能被2整除======" << endl;
    else
        cout << "有的数不能被2整除======" << endl;

    cout << "Hello World!" << endl;
    return 0;
}

