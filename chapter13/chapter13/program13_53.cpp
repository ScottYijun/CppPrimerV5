//
//  program13_53.cpp
//  chapter13
//
//  Created by chenyijun on 2017/7/27.
//  Copyright © 2017年 chenyijun. All rights reserved.
//


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
using std::string;

// for swap but we do not provide a using declaration for swap

// HasPtr with added move constructor
class HasPtr
{
    friend void swap(HasPtr &, HasPtr &);
public:
    // default constructor and constructor that takes a string
    HasPtr(const std::string &s = std::string())
    :ps(new std::string(s)), i(0)
    {
        cout << "HasPtr======默认构造函数==========================" << endl;
    }
    // copy constructor
    HasPtr(const HasPtr &p)
    :ps(new std::string(*p.ps)), i(p.i)
    {
        cout << "HasPtr======复制构造函数==========================" << endl;
    }
    // move constructor
    HasPtr(HasPtr &&p) noexcept
    :ps(p.ps), i(p.i)
    {
        cout << "HasPtr======移动构造函数==========================" << endl;
        p.ps = 0;
    }
    // assignment operator is both the move- and copy-assignment operator
    //赋值运算符既是移 动赋值运算符，也是拷贝赋值运算符
    HasPtr& operator=(HasPtr rhs)
    {
        cout << "HasPtr====赋值运算符=========================" << endl;
        swap(*this, rhs);
        return *this;
    }

    //拷贝赋值运算符
//    HasPtr& operator=(const HasPtr &rhs)
//    {
//        cout << "HasPtr====拷贝赋值运算符=========================" << endl;
//        auto newp = new string(*rhs.ps);    //拷贝底层string
//        delete ps;                          //释放旧内存
//        ps = newp;                          //从右侧运算对象拷贝数据到本对象
//        i = rhs.i;
//        return *this;                       //返回本对象
//    }
    
    inline HasPtr& operator=(HasPtr &&rhs) noexcept
    {
        cout << "HasPtr====移动赋值运算符=========================" << endl;
        if(this != &rhs)
        {
            delete ps;          //释放旧string
            ps = rhs.ps;        //从rhs接管string
            rhs.ps = nullptr;   //将rhs置于析构安全状态
            rhs.i = 0;
        }
        return *this;           //返回一个此对象的引用
    }
    
    // destructor
    ~HasPtr()
    {
        delete ps;
    }
    
private:
    std::string *ps;
    int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);   // swap the pointers, not the string data
    swap(lhs.i, rhs.i);     // swap the int members
}

int main()
{
    HasPtr hp("hi mom");
    HasPtr hp2(hp);
    cout << "hp==========1=====" << &hp << endl;
    cout << "hp2=========1=====" << &hp2 << endl << endl;
    hp = hp2;// hp2 is an lvalue; copy constructor used to copy hp2
    cout << "hp==========2=====" << &hp << endl;
    cout << "hp2=========2=====" << &hp2 << endl;
    hp = std::move(hp2);// move constructor moves hp2
    cout << "hp==========3=====" << &hp << endl;
    cout << "hp2=========3=====" << &hp2 << endl;
    return 0;
}


