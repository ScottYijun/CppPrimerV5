//
//  program13_30.cpp
//  chapter13
//
//  Created by chenyijun on 2017/6/14.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
    friend void swap(HasPtr &lhs, HasPtr &rhs);
    
public:
    //构造函数分配新的string和新的计数器，将计数器置为1
    HasPtr(const string &s = string())
    :ps(new string(s)), i(0), use(new size_t(1))
    {
        
    }
    //拷贝构造函数拷贝所有三个数据成员，并递增计数器
    HasPtr(const HasPtr &p)
    :ps(p.ps), i(p.i), use(p.use)       //拷贝构造函数
    {
        ++*use;
    }
    HasPtr& operator=(const HasPtr&);   //拷贝构造函数
    HasPtr& operator=(const string&);   //拷贝赋值运算符
    string& operator*();                //解引用
    ~HasPtr();
    
private:
    string *ps;
    int i;
    size_t *use;                        //用来记录有多少个对象共享*ps的成员
};

HasPtr::~HasPtr()
{
    if(--*use == 0)                     //如果引用计数变为0
    {
        delete ps;                      //释放string内存
        delete use;                     //释放计数器内存
    }
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    ++*rhs.use;                         //递增右侧运算对象的引用计数
    if(--*use == 0)                     //然后递减本对象的引用计数
    {
        delete ps;                      //如果没有其他用户
        delete use;                     //释放本对象分配的成员
    }
    ps = rhs.ps;                        //将数据从rhs拷贝到本对象
    i = rhs.i;
    use = rhs.use;
    return *this;                       //返回本对象
}

HasPtr& HasPtr::operator=(const string &rhs)
{
    *ps = rhs;
    return *this;
}

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    cout << "交换 " << *lhs.ps << "和" << *rhs.ps << endl;
    swap(lhs.ps, rhs.ps);               //交换指针，而不是string数据
    swap(lhs.i, rhs.i);                 //交换int成员
}

string& HasPtr::operator*()
{
    return *ps;
}

int main(int argc, const char * argv[])
{
    HasPtr h("hi mom!");
    HasPtr h2(h);//行为类值，h2, h3和h指向不同string
    cout << "old     h: " << *h << endl;//调用HasPtr::operator*()
    cout << "old     h2: " << *h2 << endl;//调用HasPtr::operator*()
    HasPtr h3 = h;
    cout << "1     h: " << *h << endl;//调用HasPtr::operator*()
    cout << "1     h2: " << *h2 << endl;//调用HasPtr::operator*()
    cout << "1     h3: " << *h3 << endl;//调用HasPtr::operator*()
    h2 = "hi dad!";//调用operator=(const string &rhs)这个函数，h, h2,h3都是“hi daa!”
    cout << "2     h: " << *h << endl;//调用HasPtr::operator*()
    cout << "2     h2: " << *h2 << endl;//调用HasPtr::operator*()
    cout << "2     h3: " << *h3 << endl;//调用HasPtr::operator*()
    h3 = "hi son!";//调用operator=(const string &rhs)这个函数，h, h2,h3都是“hi son!”
    cout << "3     h: " << *h << endl;//调用HasPtr::operator*()
    cout << "3     h2: " << *h2 << endl;//调用HasPtr::operator*()
    cout << "3     h3: " << *h3 << endl;//调用HasPtr::operator*()
    swap(h2, h3);
    cout << "swap     h: " << *h << endl;//调用HasPtr::operator*()
    cout << "swap     h2: " << *h2 << endl;//调用HasPtr::operator*()
    cout << "swap     h3: " << *h3 << endl;//调用HasPtr::operator*()
    
    std::cout << "Hello, World!\n";
    return 0;
}
