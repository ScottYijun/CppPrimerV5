//
//  program04_26.cpp
//  chapter04
//
//  Created by chenyijun on 17/2/23.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    unsigned int quiz1;
    quiz1 |= 1U << 27;
    int val1 = quiz1;
    cout << "val======" << val1 << endl;
    
    unsigned long quiz2;
    quiz2 |= 1UL << 27;
    long val2 = quiz2;
    cout << "val======" << val2 << endl;
    
    return 0;
}
