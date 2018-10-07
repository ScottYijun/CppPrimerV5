

#ifndef SALES_DATA_H
// we're here only if SALESITEM_H has not yet been defined 
#define SALES_DATA_H

// Definition of Sales_item class and related functions goes here
#include <iostream>
#include <string>

class Sales_data {
    
    // these declarations are explained section 7.2.1, p. 270
    // and in chapter 14, pages 557, 558, 561
    friend std::istream& operator >> (std::istream&, Sales_data&);
    friend std::ostream& operator << (std::ostream&, const Sales_data&);
    friend bool operator < (const Sales_data&, const Sales_data&);
    friend bool operator == (const Sales_data&, const Sales_data&);
    
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
    
public:
    // constructors are explained in section 7.1.4, pages 262 - 265
    // default constructor needed to initialize members of built-in type
    Sales_data() = default;
    //explicit Sales_data(const std::string &book): bookNo(book)
    Sales_data(const std::string &book): bookNo(book)
    {
        //std::cout << "call ======Sales_data(const std::string &book): bookNo(book)=============" << std::endl;
    }
    //explicit Sales_data(std::istream &is)
    Sales_data(std::istream &is)
    {
        //std::cout << "call ======Sales_data(std::istream &is)=============" << std::endl;
        is >> *this;
    }
    //Sales_data(std::istream &is);
    Sales_data(const std::string &book, const unsigned num, const double sellp, const double salep);
    

//定义公有函数成员
public:
    // operations on Sales_item objects
    // member binary operator: left-hand operand bound to implicit this pointer
    Sales_data& operator += (const Sales_data&);
    
    // operations on Sales_item objects
    double avg_price() const;
    std::string isbn() const { return bookNo; }
    //combine函数用于把两个ISBN相同的销售记录合并在一起
    Sales_data& combine(const Sales_data &rhs)
    {
        units_sold += rhs.units_sold;                   //累加书籍的销售量
        saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold)
                    / (rhs.units_sold + units_sold);    //重新计算实现销售价格
        discount = saleprice / sellingprice;            //重新计算实际折扣
        revenue += rhs.revenue;                         //总销售额
        return *this;                                   //返回合并后的结果
    }

    
// 定义私有数据成员
private:
    std::string bookNo;             // 书籍编号，隐式初始化为空串
    unsigned units_sold = 0;        // 销售量，显式初始化为0
    double sellingprice = 0.0;      // 原始价格，显式初始化为0.0
    double saleprice = 0.0;         // 实售价格，显式初始化为0.0
    double discount = 0.0;          // 折扣，显式初始化为0.0
    double revenue = 0.0;           // 总收入
};

Sales_data::Sales_data(const std::string &book, const unsigned num, const double sellp, const double salep)
{
    bookNo = book;
    units_sold = num;
    sellingprice = sellp;
    saleprice = salep;
    if(0 != sellingprice)
    {
        discount = saleprice / sellingprice;   //计算实际折扣
    }
}

//Sales_data::Sales_data(std::istream &is)
//{
//    is >> *this;
//}

//add
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}



//read
std::istream& read(std::istream &is, Sales_data &item)
{
    is >> item.bookNo >> item.units_sold >> item.sellingprice >> item.saleprice;
    
    return is;
}

//print
std::ostream& print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << "  " << item.sellingprice << "  " << item.saleprice
    << "  " << item.discount;
    return os;
}


// used in chapter 10
inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    //return lhs.isbn() == rhs.isbn();
    return lhs.isbn() < rhs.isbn();
}

// nonmember binary operator: must declare a parameter for each operand
Sales_data operator + (const Sales_data&, const Sales_data&);

inline bool operator == (const Sales_data &lhs, const Sales_data &rhs)
{
    // must be made a friend of Sales_item
    return lhs.units_sold == rhs.units_sold &&
           lhs.revenue == rhs.revenue &&
           lhs.isbn() == rhs.isbn();
}

inline bool operator != (const Sales_data &lhs, const Sales_data &rhs)
{
    return !(lhs == rhs); // != defined in terms of operator==
}

// assumes that both objects refer to the same ISBN
Sales_data& Sales_data::operator += (const Sales_data& rhs)
{
    units_sold += rhs.units_sold; 
    revenue += rhs.revenue; 
    return *this;
}

// assumes that both objects refer to the same ISBN
Sales_data operator + (const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data ret(lhs);  // copy (|lhs|) into a local object that we'll return
    ret += rhs;           // add in the contents of (|rhs|) 
    return ret;           // return (|ret|) by value
}

//接收4个参数分别为：ISBN，销售量，原价，实际售价
std::istream& operator >> (std::istream& in, Sales_data& s)
{

    in >> s.bookNo >> s.units_sold >> s.sellingprice >> s.saleprice;
    // check that the inputs succeeded
    if (in)
        s.revenue = s.units_sold * s.saleprice;
    else 
        s = Sales_data();  // input failed: reset object to default state
    return in;
}

std::ostream& operator << (std::ostream& out, const Sales_data& s)
{
    out << s.isbn() << " " << s.units_sold << " "
        << s.revenue << " " << s.avg_price();
    return out;
}

double Sales_data::avg_price() const
{
    if (units_sold) 
        return revenue / units_sold;
    else 
        return 0;
}
#endif
