//
//  program06_10.cpp
//  chpater06
//
//  Created by chenyijun on 17/2/27.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

//在函数体内部通过解引用操作改变指针所指的内容
void mySWAP(int *p, int *q)
{
    int temp = *p;   //temp是一个整数
    *p = *q;
    *q = temp;
}

int main()
{
    int a = 5, b = 10;
    int *r = &a, *s = &b;
    cout << "交换前：a = " << a << ", b = " << b << endl;
    mySWAP(r, s);
    cout << "交换后：a = " << a << ", b = " << b << endl;
    return 0;
}


