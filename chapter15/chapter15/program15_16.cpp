//
//  program15_16.cpp
//  chapter15
//
//  Created by chenyijun on 2017/12/03.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using std::cout;
using std::endl;
using std::string;

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

class Disc_quote: public Quote
{
public:
    Disc_quote(const string &book = "", double sales_price = 0.0, size_t qty = 0, double disc = 0.0)
    :Quote(book, sales_price), quantity(qty), discount(disc)
    {
        
    }
    //这样写的虚函数属性继承Quote，最好还是在前面加上virtual这样使代码更清晰，如果把基类的virtula关键字去掉，这样写会报错
    //double net_price(size_t cnt) const = 0;
    virtual double net_price(size_t cnt) const = 0;
    
protected:
    size_t quantity;
    double discount;
};

class Limite_quote: public Disc_quote
{
public:
    Limite_quote() = default;
    //书号， 售价，适用折扣政策的最低购买量，折扣额
    Limite_quote(const std::string &book = "", double sales_price = 0, size_t qty = 0, double disc_rate = 0)
    :Disc_quote(book, sales_price, qty, disc_rate)
    {
        min_qty = qty;
        discount = disc_rate;
    }
    //覆盖基类的函数版本以实现基于大量购买的折扣政策
    double net_price(size_t cnt) const override //如果不加override，net_price这个函数也是虚函数 p528
    {
        if(cnt <= min_qty)
        {
            return cnt * discount * price;
        }
        else
        {
            return quantity * discount * price + (cnt - min_qty) * price;
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

    
    Limite_quote limite_quote("2017-13-03", 85.6, 8, 0.8);
    print_total(cout, limite_quote, 8);
    print_total(cout, limite_quote, 9);
    limite_quote.debug();
    
    std::cout << "Hello, World!\n";
    return 0;
}
