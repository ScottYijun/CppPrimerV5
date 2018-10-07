//
//  文件名：program14_49.cpp
//  工程名：chapter14
//  简介：
//  创建日期：Created by chenyijun on 2017/8/15.
//  版权：Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;



class Date
{
    friend ostream& operator <<(ostream &os, const Date &dt);
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

    operator bool()
    {
        vector<vector<int>> days_per_month = {
            {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
            {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
        };
        cout << "operator bool() is call====================" << endl;
        return 1 <= month && month <= 12 && 1 <= day && day <= days_per_month[isLeapYear() ? 1 : 0][month - 1];
    }

    bool isLeapYear()
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

private:
    int year, month, day;
};

ostream& operator<<(ostream& os, const Date& d)
{
    const char sep = '\t';
    os << "year:" << d.year << sep << "month:" << d.month << sep << "day:" << d.day << endl;
    return os;
}


int main()
{
    Date date(2018, 23, 32);

    if(date)
        cout << "isYear==================";
    else
        cout << date << endl;

    cout << "Hello World!" << endl;
    return 0;
}

//class MyClass
//{
//public:
//    MyClass(int value):mValue(value)
//    {
//        
//    }
//    explicit operator bool ()
//    {
//        cout << "mmeber function:operator bool() called "<<mValue<<endl;
//        return mValue;
//        }
//        bool operator == ( const bool &rhs )
//        {
//            cout << "mmeber function:bool operator == ( const bool &rhs ) called"<<endl;
//            return (bool)mValue == rhs;
//        }
//    private:
//        int mValue;
//        };
//        
//        bool operator == ( const MyClass &lhs, bool rhs )
//        {
//            cout << "global bool operator ==( const MyClass &lhs, bool &rhs ) "<<endl;
//            return true;
//        }
//        
//        bool operator == ( const bool &rhs,const MyClass &lhs )
//        {
//            cout << "global bool operator == ( bool &rhs,const MyClass &lhs )"<<endl;
//            return true;
//        }
//        
//        int main()
//        {
//            MyClass c1(0);
//            MyClass c2(10);
//            if ( c1 )
//            {
//                cout << " test1 true "<<endl;
//            }
//            else
//            {
//                cout << " test1 false"<<endl;
//            }
//            
//            //bool result = (true == c1);
//            if ( true == c1 )
//            {
//                cout << "test2 true"<<endl;
//            }
//            else
//            {
//                cout << "test2 false"<<endl;
//            }
//            
//            
//            if ( c2 == false )
//            {
//                cout << "test3 true"<<endl;
//            }
//            else
//            {
//                cout << "test3 false"<<endl;
//            }
//            cout << "hello world" << endl;
//        }
