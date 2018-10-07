//
//  文件名：program14_05.cpp
//  工程名：chapter14
//  简介：
//  创建日期：Created by chenyijun on 2017/8/6.
//  版权：Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

class Date
{
    friend ostream& operator<<(ostream &os, const Date &dt);
public:
    Date();
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

ostream& operator<<(ostream& os, const Date& d)
{
    const char sep = '\t';
    os << "year:" << d.year << sep << "month:" << d.month << sep << "day:" << d.day << endl;
    return os;
}

int main()
{
    Date date(2017, 8, 6);
    cout << "date==========" << date << endl;


    cout << "Hello World!" << endl;
    return 0;
}
