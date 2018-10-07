//
//  program19.cpp
//  chapter01
//
//  Created by chenyijun on 2017/01/21.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

int main()
{
    std::cout << "请输入两个数：" << std::endl;
    int v1, v2;
    std::cin >> v1 >> v2;
    if(v1 > v2)
    {
        while(v1 >= v2)
        {
            std::cout << v1 << " ";
            --v1;
        }
    }
    else
    {
        while(v2 >=v1)
        {
            std::cout << v2 << " ";
            --v2;
        }
    }
    
    std::cout << std::endl;
    
    return 0;
}

