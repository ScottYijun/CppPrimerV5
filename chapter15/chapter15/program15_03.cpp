//
//  program15_03.cpp
//  chapter15
//
//  Created by chenyijun on 2017/11/19.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include "program15_03.h"

using std::cout;
using std::endl;

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price):
    bookNo(book), price(sales_price)
    {
    }
    
    std::string isbn() const
    {
        return bookNo;
    }
    //返回给定数量的书籍的销售总额，派生类改写并使用不同的折扣计算方法
    virtual double net_price(std::size_t n) const
    {
        return n * price;
    }
    
    virtual ~Quote() = default;//对析构函数进行动态绑定
    
private:
    std::string bookNo;//书籍的ISBN编号
    
protected:
    double price = 0.0;//代表普通状态下不打折的价格
};

double print_total(std::ostream &os, const Quote &item, size_t n)
{
    //根据传入item形参的对象类型调用Quote::net_price
    //或者Bulk_quote::net_price
    double ret = item.net_price(n);
    os << "ISBN:" << item.isbn() << " # sold:" << n << " total due: " << ret << endl;
    return ret;
}


int main()
{
    Quote quote("20171203", 85.6);
    //cout是ostream的对象
    print_total(cout, quote, 8);
    
    std::cout << "Hello, World!\n";
    return 0;
}
