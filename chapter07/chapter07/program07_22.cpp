//
//  program07_22.cpp
//  chapter07
//
//  Created by chenyijun on 17/4/11.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

class Person
{
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
    

    string getName() const {return strName; }
    string getAddress() const {return strAddress; }
};


int main()
{
    cout << "修改你的Person类使其隐藏实现的细节:" << endl;
    Person person("chenyijun", "深圳市宝安区西乡银田路1号");
    cout << "name: " << person.getName() << "    address: " << person.getAddress() << endl;
    
    return 0;
}

