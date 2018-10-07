//
//  program15_29.cpp
//  chapter15
//
//  Created by chenyijun on 2017/12/7.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>
#include <ostream>
#include <vector>
#include <memory>

using namespace std;

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book = "", double sales_price = 0.0)
    :bookNo(book), price(sales_price)
    {
        cout << "Quote constructor is running===========" << endl;
    }
    
    string isbn() const
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
        cout << "bookNo = " << bookNo << " price = " << price << endl;
    }
    
    virtual ~Quote()
    {
        cout << "Quote destructor is running=========" << endl;
    }
    
    friend ostream &operator << (ostream &, Quote &);
    
private:
    std::string bookNo;//书籍的ISBN编号
    
protected:
    double price = 0.0;//代表普通状态下不打折的价格
};

ostream& operator << (ostream &os, Quote &e)
{
    os << "\tUsing operator << (ostram &, Quote &);" << endl;
    return os;
}

class Bulk_quote: public Quote
{
public:
    Bulk_quote(const string &book = "", double sales_price = 0.0, size_t qty = 0, double disc = 0.0)
    :Quote(book, sales_price), min_qty(qty), discount(disc)
    {
        cout << "Bulk_constructor is running" << endl;
    }
    double net_price(size_t cnt) const
    {
        if(cnt > min_qty)
            return cnt * discount * price;
        else
            return cnt * price;
    }
    
    ~Bulk_quote()
    {
        cout << "Bulk_quote destructor is running" << endl;
    }
    
private:
    size_t min_qty;
    double discount;
};

ostream &operator << (ostream &os, Bulk_quote &bq)
{
    os << "\tUsing operator << (ostram &, Bulk_quote &)" << endl;
    return os;
}

int main(int argc, const char *argv[])
{
    vector<shared_ptr<Quote>> itemVec;
    for(size_t i = 0; i != 10; ++i)
    {
        itemVec.push_back(make_shared<Bulk_quote>("C++ Primer", 6, 5, 0.5));
    }
    
    double sum = 0;
    for(auto iter: itemVec)
    {
        sum += iter->net_price(10);
    }
    cout << sum << endl;
    return 0;
}
