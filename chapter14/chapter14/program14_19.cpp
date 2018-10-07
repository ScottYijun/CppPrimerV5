//
//  文件名：program14_19.cpp
//  工程名：chapter14
//  简介：
//  创建日期：Created by chenyijun on 2017/8/7.
//  版权：Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

class Date
{
    friend std::istream& operator>>(std::istream&, Date&);
    friend ostream& operator<<(ostream &os, const Date &dt);
    friend bool operator==(const Date &d1, const Date &d2);
    friend bool operator!=(const Date &d1, const Date &d2);
    friend bool operator<(const Date &d1, const Date &d2);
    friend bool operator<=(const Date &d1, const Date &d2);
    friend bool operator>(const Date &d1, const Date &d2);
    friend bool operator>=(const Date &d1, const Date &d2);

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

bool operator==(const Date &d1, const Date &d2)
{
    return (d1.year == d2.year) && (d1.month == d2.month) && (d1.day == d2.day);
}

bool operator!=(const Date &d1, const Date &d2)
{
    return !(d1 == d2);
}

bool operator<(const Date &d1, const Date &d2)
{
    return (d1.year < d2.year) || (d1.year == d2.year && d1.month < d2.month)
            ||(d1.year == d2.year && d1.month == d2.month && d1.day < d2.day);
}

bool operator <=(const Date &d1, const Date &d2)
{
    return (d1 < d2) || (d1 == d2);
}

bool operator >(const Date &d1, const Date &d2)
{
    return !(d1 <= d2);
}

bool operator >=(const Date &d1, const Date &d2)
{
    return (d1 > d2) || (d1 == d2);
}

int main()
{
    Date date1(2017, 8, 7);
    Date date2(2017, 8, 8);
    bool isValue = (date1 >= date2);
    cout << "date==========" << isValue << endl;

    cout << "Hello World!" << endl;
    return 0;
}
