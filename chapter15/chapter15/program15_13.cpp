//
//  program15_13.cpp
//  chapter15
//
//  Created by chenyijun on 2017/12/3.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using std::endl;
using std::cout;
using std::string;
using std::ostream;

class Base
{
public:
    Base(string szNm): basename(szNm)
    {
        
    }
    string name()
    {
        return basename;
    }
    virtual void print(ostream &os)
    {
        os << basename;
    }
    
private:
    string basename;
};

class Derived: public Base
{
public:
    Derived(string szName, int iVal): Base(szName), mem(iVal)
    {
        
    }
    void print(ostream &os)
    {
        Base::print(os);
        os << " ==== " << mem << endl;
    }
    
private:
    int mem;
};

int main()
{
    Derived derived("chenyijun", 30);
    derived.print(cout);
    
    return 0;
}


