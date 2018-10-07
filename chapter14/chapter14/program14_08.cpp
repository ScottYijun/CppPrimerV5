//
//  文件名：program14_08.cpp
//  工程名：chapter14
//  简介：
//  创建日期：Created by chenyijun on 2017/8/6.
//  版权：Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

class Employee
{
    friend ostream& operator<<(ostream &os, const Employee &emp);
public:
    Employee();
    Employee(string name, int age, string sex)
    {
        m_name = name;
        m_age = age;
        m_sex = sex;
    }

private:
    string m_name;
    int m_age;
    string m_sex;
};

ostream& operator<<(ostream& os, const Employee& emp)
{
    const char sep = '\t';
    os << "姓名:" << emp.m_name << sep << "年龄:" << emp.m_age << sep << "性别:" << emp.m_sex << endl;
    return os;
}

int main()
{
    Employee employee("天山云海路", 28, "男");
    cout << "employee==========" << employee << endl;


    cout << "Hello World!" << endl;
    return 0;
}
