//
//  program07_47.cpp
//  chapter07
//
//  Created by chenyijun on 17/4/24.
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
    
    //这段代码隐式地把cin转换成Sales_data，这个转换执行了接受一个istream的Sales_data构造函数，Sales_data(std::istream &is)
    //该构造函数通过读取标准输入创建一个一个（临时的）Sales_data对象，随后将得到的对象传递给combine。
    data1.combine(static_cast<Sales_data>(cin));  //正确：static_cast可以使用explicit的构造函数
    
    //编译器用给定的string自动创建一个Sales_data对象。调用的是Sales_data(const std::string &book): bookNo(book)这个构造函数
    //新生成的这个（临时）Sales_data对象被传递给combine，因为combine的参数是一个常量引用，所以可以给该参数传递一个临时量。
    string null_book = "9999-569-6565";
    data1.combine(Sales_data(null_book));  //正确：实参是一个显式构造的Sales_data 对象
    
    data1.combine(Sales_data("9999-569-6565"));
    
    cout << "书籍的销售情况是：" << endl;
    cout << "data1:" << data1 << endl;
    cout << "data2:" << data2 << endl;
    cout << "data3:" << data3 << endl;
    
    return 0;
}
