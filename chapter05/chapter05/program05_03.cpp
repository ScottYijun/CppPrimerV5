//
//  program05_03.cpp
//  chapter05
//
//  Created by chenyijun on 17/2/24.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    int val = 0, sum = 0;
    while(val <= 10)
        sum += val, ++val;   //代码不句清晰，可读性降低了
    
    cout << "val======" << val << "   sum = " << sum << endl;
    
    return 0;
}

