//
//  program15_20.cpp
//  chapter15
//
//  Created by chenyijun on 2017/12/04.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Base
{
public:
    void pub_mem();
    
protected:
    int prot_mem;
    
private:
    char priv_mem;
};

class Pub_Derv: public Base
{
public:
    int f()
    {
        return prot_mem;
    }
    void memfcn(Base &b)
    {
        b = *this;
        cout << "Pub_Derv=====================" << endl;
    }
};

class Priv_Derv: private Base
{
public:
    int f1() const
    {
        return prot_mem;
    }
    void memfcn(Base &b)
    {
        b = *this;
        cout << "Priv_Derv==================" << endl;
    }
};

class Prot_Derv: protected Base
{
public:
    int f2()
    {
        return prot_mem;
    }
    void memfcn(Base &b)
    {
        b = *this;
        cout << "Prot_Derv==================" << endl;
    }
    
};

class Derived_from_Public: public Pub_Derv
{
public:
    int use_base()
    {
        return prot_mem;
    }
    void memfcn(Base &b)
    {
        b = *this;
        cout << "Derived_from_Public==================" << endl;
    }
};

class Derived_from_Protected: protected Prot_Derv
{
public:
    int use_base()
    {
        return prot_mem;
    }

    void memfcn(Base &b)
    {
        b = *this;
        cout << "Derived_from_Protected==================" << endl;
    }
};

//class Derived_from_Private: private Priv_Derv
//{
//public:
//    int use_base()
//    {
//        return priv_mem;
//    }
    
//    void memfcn(Base &b)
//    {
//        b = *this;
//        cout << "Derived_from_Protected==================" << endl;
//    }
//};

int main()
{
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    //Derived_from_Private dd2;
    Derived_from_Protected dd3;
    Base base;
    Base *p = new Base;
    p = &d1;//d1的类型是Pub_Derv
    //p = &d2;//d2的类型是Priv_derv
    //p = &d3;//d3的类型是Prot_Derv
    
    p = &dd1;//dd1的类型是Derived_from_Public
    //p = &dd2;//dd2的类型是Derived_from_Private
    //p = &dd3;//dd3的类型是Derived_from_Protected
    d1.memfcn(base);
    d2.memfcn(base);
    d3.memfcn(base);
    dd1.memfcn(base);
    //dd2.memfcn(base);
    dd3.memfcn(base);
    
    std::cout << "Hello, World!\n";
    return 0;
}
