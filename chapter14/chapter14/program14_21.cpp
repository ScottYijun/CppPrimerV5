//
//  文件名：program14_21.cpp
//  工程名：chapter14
//  简介：
//  创建日期：Created by chenyijun on 2017/8/8.
//  版权：Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include "Sales_data_14_21.h"

using namespace std;

int main()
{
    Sales_data trans1, trans2;
    std::cout << "请输入两条ISBN相同的销售记录：" << std::endl;
    std::cin >> trans1 >> trans2;

    std::cout << "两条销售记录的和" << trans1+trans2 << std::endl;

    cout << "Hello World!" << endl;
    return 0;
}

