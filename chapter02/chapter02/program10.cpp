//
//  program10.cpp
//  chapter02
//
//  Created by chenyijun on 17/1/24.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

//该程序仅用于说明：函数内部不宜定义与全局变量同名的新变量
int reused = 42;  //reused 拥有全局作用域
int main()
{
    int unique = 0;
    std::cout << reused << " " << unique << std::endl;
    int reused = 0;
    std::cout << reused << " " << unique << std::endl;
    std::cout << ::reused << " " << unique << std::endl;
    
    return 0;
}
