//
//  program13_19.cpp
//  chapter13
//
//  Created by chenyijun on 2017/6/12.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Employee
{
private:
    static int sn;
    
public:
    Employee()
    {
        mysn = sn++;
    }
    
    Employee(const string &s)
    {
        name = s;
        mysn = sn++;
    }
    
    Employee(Employee &e)
    {
        name = e.name;
        mysn = sn++;
    }
    
    Employee& operator=(Employee &rhs)
    {
        name = rhs.name;
        return *this;
    }
    
    const string &get_name()
    {
        return name;
    }
    
    int get_mysn()
    {
        return mysn;
    }
    
private:
    string name;
    int mysn;
};

int Employee::sn = 0;

void f(Employee &s)
{
    cout << s.get_name() << ":" << s.get_mysn() << endl;
}

int main(int argc, const char * argv[])
{
    Employee a("陈"), b = a, c;
    c = b;
    f(a);
    f(b);
    f(c);
    
    std::cout << "Hello, World!\n";
    return 0;
}
