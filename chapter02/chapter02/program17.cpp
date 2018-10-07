//
//  program17.cpp
//  chapter02
//
//  Created by chenyijun on 17/1/25.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

int main()
{
    
    int i, &ri = i;
    i = 5;
    ri = 10;
    std::cout << "i=========" << i << "    ri=======" << ri << std::endl;
    
    return 0;
}
