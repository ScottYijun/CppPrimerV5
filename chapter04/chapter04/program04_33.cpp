//
//  program04_33.cpp
//  chapter04
//
//  Created by chenyijun on 17/2/23.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    int x = 10, y = 20;
    //检查条件为真的情况
    bool someValue = true;
    someValue ? (++x, ++y): (--x, --y);
    cout << "x=========" << x << endl;
    cout << "y=========" << y << endl;
    cout << "someValue=" << someValue << endl;
    
    x = 10, y = 20;
    //检查条件为真的情况
    someValue = true;
    someValue ? ++x, ++y : --x, --y;
    cout << "x=========" << x << endl;
    cout << "y=========" << y << endl;
    cout << "someValue=" << someValue << endl;
    
    x = 10, y = 20;
    //检查条件为假的情况
    someValue = false;
    someValue ? ++x, ++y : --x, --y;
    cout << "x=========" << x << endl;
    cout << "y=========" << y << endl;
    cout << "someValue=" << someValue << endl;
    
    x = 10, y = 20;
    //检查条件为假的情况
    someValue = false;
    someValue ? (++x, ++y) : (--x, --y);
    cout << "x=========" << x << endl;
    cout << "y=========" << y << endl;
    cout << "someValue=" << someValue << endl;
    
    return 0;
}
