//
//  program06_03.cpp
//  chpater06
//
//  Created by chenyijun on 17/2/26.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

int fact(int a, int b)
{
    cout << "call fact======================" << endl;
    int sum = a + b;
    return sum;
}

int main(int argc, const char * argv[]) {
    
    cout << "sum = " << fact(10, 20) << endl;
    return 0;
}
