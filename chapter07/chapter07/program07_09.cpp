//
//  program07_03.cpp
//  chapter07
//
//  Created by chenyijun on 17/4/4.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

class Person
{
public:
    string getName() const {return strName; }
    string getAddress() const {return strAddress; }
    
    
    
public:
    string strName;
    string strAddress;
    
};

std::istream &read(std::istream &is, Person &per)
{
    is >> per.strName >> per.strAddress;
    return is;
}

std::ostream &print(std::ostream &os, const Person &per)
{
    os << "name: " << per.getName() << "       address: " <<  per.getAddress() << endl;
    return os;
}

int main()
{
    Person person;
    
    if(read(cin, person))
    {
        print(cout, person);
    }
    else
    {
        //没有输入！ 警告读者
        cerr << "No data?!" << endl;
        return -1;//表示失败
    }
    
    return 0;
}