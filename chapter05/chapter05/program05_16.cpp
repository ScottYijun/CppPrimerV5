//
//  program05_16.cpp
//  chapter05
//
//  Created by chenyijun on 17/2/25.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    int forCount = 0;
    for(int i = 0; i < 10; ++i)
    {
        forCount += i;
    }
    cout << "forCount=============" << forCount << endl;;
    
    int whileCount = 0, j = 0;
    while(j < 10)
    {
        whileCount += j;
        ++j;
    }
    cout << "whileCount============" << whileCount << endl;
    
    return 0;
}

