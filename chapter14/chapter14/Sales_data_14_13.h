//
//  文件名：Sales_data_14_13.h
//  工程名：chapter14
//  简介：
//  创建日期：Created by chenyijun on 2017/8/7.
//  版权：Copyright © 2017年 chenyijun. All rights reserved.
//

#ifndef Sales_data_14_13_h
#define Sales_data_14_13_h

#include <iostream>
#include <string>

class Sales_data
{
    friend std::istream& operator>>(std::istream&, Sales_data&);
    friend std::ostream& operator<<(std::ostream&, const Sales_data&);
    friend bool operator<(const Sales_data&, const Sales_data&);
    friend bool operator==(const Sales_data&, const Sales_data&);
    friend Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs);//重载减法运算符
    
public:
    Sales_data() = default;
    Sales_data(const std::string &book): bookNo(book) {  }
    Sales_data(std::istream &is) { is >> *this; }
    
public:
    Sales_data& operator+=(const Sales_data&);
    Sales_data& operator-=(const Sales_data &rhs);//重载-=运算符
    std::string isbn() const { return bookNo; }
    double avg_price() const;

private:
    std::string bookNo;                 //书号
    unsigned units_sold = 0;            //出售册数
    double revenue = 0.0;               //收入
};

inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn();
}

Sales_data operator+(const Sales_data&, const Sales_data&);

inline bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
    return (lhs.units_sold == rhs.units_sold) &&
           (lhs.revenue == rhs.revenue) &&
           (lhs.isbn() == rhs.isbn());
}

inline bool operator !=(const Sales_data &lhs, const Sales_data &rhs)
{
    return !(lhs == rhs);
}

Sales_data& Sales_data::operator +=(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data operator +(const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data ret(lhs);
    ret += rhs;
    return ret;
}
//添加重载-运算符
Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sub = lhs;
    sub -= rhs;
    return sub;
}
//添加重载-=运算符
Sales_data& Sales_data::operator-=(const Sales_data &rhs)
{
    units_sold -= rhs.units_sold;
    revenue -= rhs.revenue;
    return *this;
}

std::istream& operator>>(std::istream& in, Sales_data& s)
{
    double price;
    in >> s.bookNo >> s.units_sold >> price;

    if(in)
        s.revenue = s.units_sold * price;
    else
        s = Sales_data();

    return in;
}

std::ostream& operator <<(std::ostream& out, const Sales_data& s)
{
    const char sep = '\t';
    out << "\n\t" << s.isbn() << sep << s.units_sold << sep
        << s.revenue << sep << s.avg_price();

    return out;
}

double Sales_data::avg_price() const
{
    if(units_sold)
        return revenue / units_sold;
    else
        return 0;
}

#endif /* Sales_data_14_13_h */
