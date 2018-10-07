//
//  program03_35.cpp
//  chapter03
//
//  Created by chenyijun on 17/2/20.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    const int sz = 10;  //常量sz作为数组的维度
    int a[sz];
    //通过for循环为数组元素赋值
    for(int i = 0; i < 10; ++i)
    {
        a[i] = i;
    }
    
    cout << "初始化状态下数组的内容是：" << endl;
    for(auto val: a)
        cout << val << "   ";
    cout << endl;
    
    int *p = begin(a);   //令p指向数组的首元素
    while(p != end(a))
    {
        *p = 0;  //修改p所指元素的值
        ++p;     //p向后移动一位
    }
    
    cout << "修改后的数组内容是：" << endl;
    //通过范围for循环输出数组的全部元素
    for(auto val: a)
        cout << val << "   ";
    cout << endl;
    
    return 0;
}


