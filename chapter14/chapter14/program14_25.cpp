//
//  文件名：program14_25.cpp
//  工程名：chapter14
//  简介：
//  创建日期：Created by chenyijun on 2017/8/8.
//  版权：Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>
#include<sstream>        //istringstream 必须包含这个头文件

using namespace std;

class Date
{
    friend std::istream& operator>>(std::istream&, Date&);
    friend ostream& operator<<(ostream &os, const Date &dt);
    friend bool operator==(const Date &d1, const Date &d2);
    friend bool operator!=(const Date &d1, const Date &d2);

public:
    Date()
    {

    }

    Date(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    Date& operator=(const string &date);

private:
    int year;
    int month;
    int day;
};


istream& operator>>(std::istream& is, Date& inDt)
{
    is >> inDt.year >> inDt.month >> inDt.day;
    if(!is)
    {
        inDt = Date(0, 0, 0);
        cout << "input data error====================" << endl;
    }
    return is;
}

ostream& operator<<(ostream& os, const Date& d)
{
    const char sep = '\t';
    os << "year:" << d.year << sep << "month:" << d.month << sep << "day:" << d.day << endl;
    return os;
}

Date& Date::operator =(const string &date)
{
    //接受"1970-1-1"形式的日期字符串
    istringstream in(date);
    char ch1, ch2;
    in >> year >> ch1 >> month >> ch2 >> day;
    if(!in || ch1 != '-' || ch2 != '-')
        throw std::invalid_argument("Bad date");
    if(month < 1 || month > 12 || day < 1 || day > 31)
        throw std::invalid_argument("Bad date");

    return *this;
}

bool operator==(const Date &d1, const Date &d2)
{
    return (d1.year == d2.year) && (d1.month == d2.month) && (d1.day == d2.day);
}

bool operator!=(const Date &d1, const Date &d2)
{
    return !(d1 == d2);
}

int main()
{
    Date date;
    date = std::string("2017-08-08");
    cout << "date==========" << date << endl;

    cout << "Hello World!" << endl;
    return 0;
}

