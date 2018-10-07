//
//  program06_26.cpp
//  chpater06
//
//  Created by chenyijun on 17/2/27.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    for(int i = 0; i != argc; ++i)
    {
        cout << "argc[" << i << "]:" << argv[i] <<endl;
    }
    
    return 0;
}