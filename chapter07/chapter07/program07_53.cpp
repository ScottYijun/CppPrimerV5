//
//  program07_53.cpp
//  chapter07
//
//  Created by chenyijun on 17/4/25.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

class Debug
{
public:
    constexpr Debug(bool b = true): hw(b), io(b), other(b) { }
    constexpr Debug(bool h, bool i, bool o): hw(h), io(i), other(o) { }
    constexpr bool any() { return (hw || io || other); }
    
    void set_io(bool b) { io = b; }
    void set_hw(bool b) { hw = b; }
    void set_other(bool b) { other = b; }
    
private:
    bool hw;
    bool io;
    bool other;
};



int main()
{
    constexpr Debug io_sub(false, true, false);             //调式IO
    if(io_sub.any())                                        //等价于if(true)
    {
        cerr << "print appropriate error messags" << endl;
    }
    constexpr Debug prod(false);                            //无调式
    if(prod.any())                                          //等价于if(false)
    {
        cerr << "print an error message" << endl;
    }
    
    return 0;
}

