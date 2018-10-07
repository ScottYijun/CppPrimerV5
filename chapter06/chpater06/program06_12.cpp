//
//  program06_12.cpp
//  chpater06
//
//  Created by chenyijun on 17/2/27.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

void mySWAP(int &i, int &j)
{
    int temp = i;
    i = j;
    j = temp;
}

int main()
{
    int a = 55, b = 99;
    cout << "交换前： a = " << a << ", b = " << b << endl;
    mySWAP(a, b);
    cout << "交换后： a = " << a << ", b = " << b << endl;
    return 0;
}



