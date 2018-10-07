//
//  program03_31.cpp
//  chapter03
//
//  Created by chenyijun on 17/2/20.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    const int sz = 10;
    int vInt[sz];
    //通过for循环为数组元素赋值
    for(int i = 0; i < 10; ++i)
    {
        vInt[i] = i;
    }
    //通过范转for循环输出数组的全部元素
    for(auto a: vInt)
    {
        cout << a << "   ";
    }
    
    cout << endl;
    
    return 0;
}
