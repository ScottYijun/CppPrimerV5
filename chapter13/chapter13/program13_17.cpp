//
//  program13_17.cpp
//  chapter13
//
//  Created by chenyijun on 2017/6/12.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class numbered
{
private:
    static int seq;
    
public:
    numbered()
    {
        mysn = seq++;
    }
    //13.15
    numbered(numbered &n)
    {
        mysn = seq++;
    }
    int mysn;
};

int numbered::seq = 0;

void f(numbered s)
{
    cout << s.mysn << endl;
}

int main(int argc, const char * argv[])
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    
    std::cout << "Hello, World!\n";
    return 0;
}
