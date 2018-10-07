//
//  program13_50.cpp
//  chapter13
//
//  Created by chenyijun on 2017/7/26.
//  Copyright © 2017年 chenyijun. All rights reserved.
//


#include "String_13_48.h"

#include <cstring>
using std::strlen;

#include <algorithm>
using std::copy;

#include <cstddef>
using std::size_t;

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

#include <utility>
using std::swap;

#include <initializer_list>
using std::initializer_list;

#include <memory>
using std::uninitialized_copy;

#include <vector>
using std::vector;

// define the static allocator member
std::allocator<char> String::a;

// copy-assignment operator拷贝赋值运算符
String &String::operator=(const String &rhs)
{
    // copying the right-hand operand before deleting the left handles self-assignment
    auto newp = a.allocate(rhs.sz);    // copy the underlying string from rhs
    uninitialized_copy(rhs.p, rhs.p + rhs.sz, newp);
    
    if(p)
        a.deallocate(p, sz);        // free the memory used by the left-hand operand
    p = newp;                       // p now points to the newly allocated string
    sz = rhs.sz;                    // update the size
    cout << "拷贝赋值运算符 rhs==" << rhs << "    &rhs=" << &rhs << "     this=" << this << endl;
    return *this;
}

// move assignment operator移动赋值运算符
String &String::operator=(String &&rhs) noexcept
{
    // explicit check for self-assignment
    if(this != &rhs)
    {
        if(p)
        {
            a.deallocate(p, sz);    // do the work of the destructor
        }
        p = rhs.p;                  // take over the old memory
        sz = rhs.sz;
        rhs.p = nullptr;            // deleting rhs.p is safe
        rhs.sz = 0;
    }
    cout << "移动赋值运算符 rhs==" << rhs << "     &rhs=" << &rhs << "     this=" << this << endl;
    return *this;
}

String &String::operator=(const char *cp)
{
    if(p)
    {
        a.deallocate(p, sz);
    }
    p = a.allocate(sz = strlen(cp));
    uninitialized_copy(cp, cp + sz, p);
    return *this;
}

String &String::operator=(char c)
{
    if(p)
    {
        a.deallocate(p, sz);
    }
    p = a.allocate(sz = 1);
    *p = c;
    return *this;
}

String &String::operator=(initializer_list<char> il)
{
    // no need to check for self-assignment
    if(p)
    {
        a.deallocate(p, sz);            // do the work of the destructor
    }
    p = a.allocate(sz = il.size());     // do the work of the destructor
    uninitialized_copy(il.begin(), il.end(), p);
    return *this;
}

// named functions for operators
ostream &print(ostream &os, const String &s)
{
    auto p = s.begin();
    while(p != s.end())
        os << *p++;
    return os;
}

String add(const String &lhs, const String &rhs)
{
    String ret;
    ret.sz = rhs.size() + lhs.size();                   // size of the combined String
    ret.p = String::a.allocate(ret.sz);                 // allocate new space
    uninitialized_copy(lhs.begin(), lhs.end(), ret.p);  // copy the operands
    uninitialized_copy(rhs.begin(), rhs.end(), ret.p + lhs.sz);
    return ret;                                         // return a copy of the newly created String
}

String make_plural(size_t ctr, const String &word, const String &ending)
{
    return (ctr != 1) ? add(word, ending) : word;
}

ostream &operator<<(ostream &os, const String &s)
{
    return print(os, s);
}

String operator+(const String &lhs, const String &rhs)
{
    return add(lhs, rhs);
}
//返回值为String类对象
String getStr()
{
    //定义一个局部对象，然后将局部对象作为结果返回
    String obj;
    //返回值是String类型
    return obj;
}
    
int main()
{
    String s1("One"), s2("Two");
    cout << "s1==" << s1 << "   s2==" << s2 << endl << endl;
    String s3(s2);
    cout << "s1==" << s1 << "   s2==" << s2 << "   s3==" << s3 << endl << endl;
    s3 = s1;
    cout << "s1==" << s1 << "   s2==" << s2 << "   s3==" << s3 << endl << endl;
    s3 = String("Three");
    cout << "s1==" << s1 << "   s2==" << s2 << "   s3==" << s3 << endl << endl;
    
    vector<String> vstr;
    vstr.push_back(s1);
    cout << endl;
    vstr.push_back(std::move(s2));
    cout << endl;
    vstr.push_back(String("Three"));
    cout << endl;
    vstr.push_back("Four");
    cout << endl;
    for_each(vstr.begin(), vstr.end(), [](const String &s) {cout << s << " ";});
    cout << endl;
    //getStr() 函数返回了一个String类型的对象（临时无名对象）， 之后调用类的函数
    cout << "strStr().size()==============" << getStr().size() << endl;
    return 0;
}


