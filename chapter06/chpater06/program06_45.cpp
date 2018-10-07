//
//  program06_45.cpp
//  chpater06
//
//  Created by chenyijun on 17/3/8.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

inline void reset(int &i)
{
    i = 0;
}

inline int myCompare(const int val, const int *p)
{
    return (val > *p) ? val : *p;
}

int main()
{
    int a = 10;
    int b = 20;
    int *pi = &b;
    cout << "max=============" << myCompare(a, pi) << endl;
    cout << "org    a = " << a << "    b = " << b << endl;
    reset(a);
    cout << "new    a = " << a << "    b = " << b << endl;
    return 0;
}


