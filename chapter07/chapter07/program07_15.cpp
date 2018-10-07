//
//  program07_15.cpp
//  chapter07
//
//  Created by chenyijun on 17/4/6.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Person
{
    friend std::istream& operator >> (std::istream&, Person&);
    
private:
    string strName;             //姓名
    string strAddress;          //地址
    
public:
    Person() = default;
    
    Person(const string &name, const string &add)
    {
        strName = name;
        strAddress = add;
    }
    
    
    
    Person(std::istream &input)  { input >> *this; }
    
    string getName() const
    {
        return strName;         //返回姓名
    }
    
    string getAddress() const
    {
        return strAddress;      //返回地址
    }


};

std::istream& operator >> (std::istream& in, Person& per)
{
    in >> per.strName >> per.strAddress;
    
    return in;
}


int main()
{
    cout << "请输入姓名和地址:" << endl;
    Person person(cin);
    cout << "name: " << person.getName() << "       address: " << person.getAddress() << endl;
    
    return 0;
}