//
//  program06_21.cpp
//  chpater06
//
//  Created by chenyijun on 17/2/27.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int myCompare(const int val, const int *p)
{
    return (val > *p) ? val : *p;
}

int main()
{
    srand((unsigned)time(NULL));
    int a[10];
    for(auto &i: a)
        i = rand() % 100;
    cout << "请输入一个数：" << endl;
    int j;
    cin >> j;
    cout << "您输入的数与数组首元素中较大的是：" << myCompare(j,a) << endl;
    cout << "数组的全部元素是：" << endl;
    for(auto i: a)
        cout << i << "  ";
    cout << endl;
    return 0;
}

