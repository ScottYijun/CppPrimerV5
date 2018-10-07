//
//  program13_22.cpp
//  chapter13
//
//  Created by chenyijun on 2017/6/13.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class HasPtr
{
public:
    HasPtr(const string &s = string())
    :ps(new string(s)), i(0)
    {
        
    }
    
    HasPtr(const HasPtr &p)             //拷贝构造函数
    :ps(new string(*p.ps)), i(p.i)
    {
        
    }
    
    HasPtr& operator=(const HasPtr&);   //拷贝赋值运算符
    HasPtr& operator=(const string&);   //赋予新string
    string& operator*();                //解引用
    ~HasPtr();
    
private:
    string *ps;
    int i;
};

HasPtr::~HasPtr()
{
    delete ps;//释放string内存
}

inline HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    auto newps = new string(*rhs.ps);   //拷贝指针指向的对象
    delete ps;                          //销毁原string
    ps = newps;                         //指向新string
    i = rhs.i;                          //使用内置的int赋值
    return *this;                       //返回一个此对象的引用
}

HasPtr& HasPtr::operator=(const string &rhs)
{
    *ps = rhs;
    return *this;
}

string& HasPtr::operator*()
{
    return *ps;
}

int main(int argc, const char * argv[])
{
    HasPtr h("hi mom!");
    HasPtr h2(h);//行为类值，h2, h3和h指向不同string
    HasPtr h3 = h;
    h2 = "hi dad!";
    h3 = "hi son!";
    cout << "h: " << *h << endl;
    cout << "h2: " << *h2 << endl;
    cout << "h3: " << *h3 << endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
