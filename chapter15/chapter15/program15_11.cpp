//
//  program15_11.cpp
//  chapter15
//
//  Created by chenyijun on 2017/12/03.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>

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
    virtual void debug()
    {
        cout << "bookNo=" << bookNo << " price=" << price << endl;
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

class Bulk_quote: public Quote
{
public:
    Bulk_quote() = default;
    //书号， 售价，适用折扣政策的最低购买量，折扣额
    Bulk_quote(const std::string &book = "", double sales_price = 0, size_t qty = 0, double disc_rate = 0)
    :Quote(book, sales_price), min_qty(qty), discount(disc_rate)
    {
        
    }
    //覆盖基类的函数版本以实现基于大量购买的折扣政策
    double net_price(size_t cnt) const override //如果不加override，net_price这个函数也是虚函数 p528
    {
        if(cnt >= min_qty)
        {
            return cnt * discount * price;
        }
        else
        {
            return cnt * price;
        }
    }
    
    virtual void debug() override
    {
        Quote::debug();//bookNo变量为private，所以不能直接访问bookNo只能调用基类的debug()函数来显示
        cout << "min_qty=" << min_qty << "  discount=" << discount << endl;
    }
    
private:
    size_t min_qty;//适用折扣政策的最低购买量
    double discount;//以小数表示的折扣额
};

int main()
{
    Quote quote("20171203", 85.6);
    //cout是ostream的对象
    print_total(cout, quote, 8);
    quote.debug();
    cout << "\n\n" << endl;
    
    Bulk_quote bulk_quote("2017-13-03", 85.6, 8, 0.8);
    print_total(cout, bulk_quote, 8);
    bulk_quote.debug();
    
    std::cout << "Hello, World!\n";
    return 0;
}
