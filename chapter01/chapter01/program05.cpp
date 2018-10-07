//
//  program05.cpp
//  chapter01
//
//  Created by chenyijun on 2017/01/20.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

int main()
{
    
    std::cout << "请输入两个数：" << std::endl;
    int param1 = 0;
    int param2 = 0;
    std::cin >> param1 >> param2;
    std::cout << param1 << "和" << param2 << "的和为：" << (param1 + param2) << std::endl;
    std::cout << param1 << "和" << param2 << "的差为：" << (param1 - param2) << std::endl;
    std::cout << param1 << "和" << param2 << "的积为：" << (param1 * param2) << std::endl;
    std::cout << param1 << "和" << param2 << "的商为：" << (param1 / param2) << std::endl;
    std::cout << std::endl;
    return 0;
}
