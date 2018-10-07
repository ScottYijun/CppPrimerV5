//
//  program15_30.cpp
//  chapter15
//
//  Created by chenyijun on 2017/12/10.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>
#include <ostream>
#include <vector>
#include <memory>
#include <set>//multiset

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

// calculate and print the price for the given number of copies, applying any discounts
double print_total(ostream &os, const Quote &item, size_t n)
{
    // depending on the type of the object bound to the item parameter
    // calls either Quote::net_price or Bulk_quote::net_price
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() // calls Quote::isbn
    << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}


class Basket
{
public:
    //Basket使用合成的默认构造函娄和拷贝制成员
    void add_item(const std::shared_ptr<Quote> &sale)
    {
        items.insert(sale);
    }
    //打印每本书的总价和购物篮中所有书的总价
    double total_receipt(std::ostream &) const;
    
private:
    //该函数用于比较shared_ptr,multiset成员会用到它
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs)
    {
        return lhs->isbn() < rhs->isbn();
    }
    //multiset保存多个报价,按照compare成员排序
    std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};

double Basket::total_receipt(ostream &os) const
{
    double sum = 0.0;//保存实时计算出的总价格
    //iter指向ISBN相同的一批元素中的第一个
    //upper_bound返回一个迭代器，该迭代器指向这批元素的最后一个的下一位置
    for(auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
    {
        //我们知道在当前的Basket中至少有一个该关键字的元素
        //打印该书籍对应的项目
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << endl;//打印最终的总价格
    return sum;
}

int main(int argc, const char *argv[])
{
    Basket sale;
    sale.add_item(shared_ptr<Quote>(new Quote("123", 25)));
    sale.add_item(shared_ptr<Quote>(new Quote("456", 35)));
    sale.add_item(shared_ptr<Quote>(new Quote("789", 45)));
    
    sale.total_receipt(cout);

    return 0;
}
