//
//  program15_02.cpp
//  chapter15
//
//  Created by chenyijun on 2017/10/6.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include "program15_02.h"

using std::cout;
using std::endl;

class Student: public People
{
public:
    friend void PrintStudent(Student &s);
    friend void PrintPeople(People &p);
};

// 正确，可以通过派生类对象访问基类的protected成员
void PrintStudent(Student &s)
{
    s.name = "Songlee";
    cout << s.name << endl;
}


// 错误，不能通过基类对象访问基类的protected成员
//void PrintPeople(People &p)
//{
//    p.name = "Songlee";
//    cout << p.name << endl;
//}

int main()
{
    Student stu;
    PrintStudent(stu);
    
    std::cout << "Hello, World!\n";
    return 0;
}
