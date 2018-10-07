//
//  program07_50.cpp
//  chapter07
//
//  Created by chenyijun on 17/4/24.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Person
{
    friend std::istream& operator >> (std::istream&, Person&);
    
private:
    string strName;
    string strAddress;
    
public:
    Person() = default;
    
    Person(const string &name, const string &add)
    {
        strName = name;
        strAddress = add;
    }
    
    explicit Person(std::istream &input) { input >> *this; }
    
    string getName() const
    {
        return strName;
    }
    
    string getAddress() const
    {
        return strAddress;
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

