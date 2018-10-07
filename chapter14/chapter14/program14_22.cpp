//
//  文件名：program14_22.cpp
//  工程名：chapter14
//  简介：
//  创建日期：Created by chenyijun on 2017/8/8.
//  版权：Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include "Sales_data_14_02.h"

using namespace std;

int main()
{
    Sales_item trans1, trans2;
    std::cout << "请输销售记录：" << std::endl;
    std::cin >> trans1 >> trans2;
    trans1 = trans2;
    std::cout << "汇总信息：ISBN，售出本数，销售额和平均售价为" << trans1 << std::endl;
    trans2 = std::string("sssssssß");
    std::cout << "汇总信息：ISBN，售出本数，销售额和平均售价为" << trans2 << std::endl;

    cout << "Hello World!" << endl;
    return 0;
}
