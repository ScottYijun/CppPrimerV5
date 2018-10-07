//
//  program06_27.cpp
//  chpater06
//
//  Created by chenyijun on 17/2/27.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

int iCount(initializer_list<int> i1)
{
    int count = 0;
    //遍历i1的每一个元素
    for(auto val: i1)
        count += val;
    
    return count;
}

int main()
{
    //使用列表初始化的方式构建initializer_list<int>对象
    //然后把它作为实参传递给函数iCount
    cout << "1, 6, 9的和是：" << iCount({1, 6, 9}) << endl;
    cout << "4, 5, 9, 18的和是：" << iCount({4, 5, 9, 18}) << endl;
    cout << "10, 10, 10, 10, 10, 10, 10的和是：" << iCount({10, 10, 10, 10, 10, 10, 10}) << endl;
    
    return 0;
}


