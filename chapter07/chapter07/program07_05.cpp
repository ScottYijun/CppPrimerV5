//
//  program07_05.cpp
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
    string getName() const {return strName; }           //返回姓名
    string getAddress() const {return strAddress;}      //返回地址
    void setName(const string  sName) { strName = sName; }
    void setAddress(const string  sAddress) {strAddress = sAddress;}
    
private:
    string strName;                                     //姓名
    string strAddress;                                  //地址
};

int main()
{
    Person person;
    person.setName("chenyijun");
    person.setAddress("新湖路1号");
    cout << "name = " << person.getName() << endl;
    cout << "address = " << person.getAddress() << endl;
    
    return 0;
}