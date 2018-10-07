//
//  program05_24.cpp
//  chapter05
//
//  Created by chenyijun on 17/2/25.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    cout << "请依次输入被除数和除数:" << endl;
    int ival1, ival2;
    cin >> ival1 >> ival2;
    if(0 == ival2)
    {
        throw runtime_error("除数不能为0");
    }
    cout << "两数相除的结果是：" << ival1 / ival2 << endl;
    
    
    return 0;
}


