//
//  program06_11.cpp
//  chpater06
//
//  Created by chenyijun on 17/2/27.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

void reset(int &i)
{
    i = 0;
}

int main()
{
    int a = 10;
    cout << "重置前：a = " << a << endl;
    reset(a);
    cout << "重置后：a = " << a << endl;
    return 0;
}


