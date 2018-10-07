//
//  program07_11.cpp
//  chapter07
//
//  Created by chenyijun on 17/4/6.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include "Sales_data.h"
using namespace std;


int main()
{
    cout << "构造函数调用：" << endl;
    Sales_data data1;
    Sales_data data2("978-7-121-15535-2");
    Sales_data data3("978-7-121-15535-2", 100, 128, 109);
    Sales_data data4(cin);
    
    cout << "书籍的销售情况是：" << endl;
    cout << "data1:" << data1 << endl;
    cout << "data2:" << data2 << endl;
    cout << "data3:" << data3 << endl;
    cout << "data4:" << data4 << endl;
    
    return 0;
}