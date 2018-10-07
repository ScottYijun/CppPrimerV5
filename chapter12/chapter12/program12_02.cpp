//
//  program12_02.cpp
//  chapter12
//
//  Created by chenyijun on 2017/6/5.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include "SYStrBlob.h"

using std::cout;
using std::endl;

int main(int argc, const char * argv[])
{
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        cout << "b2.size==================" << b2.size() << endl;
    }
    
    cout << "b1.size==================" << b1.size() << endl;
    cout << b1.front() << "  " << b1.back() << endl;
    
    const StrBlob b3 = b1;
    cout << b3.front() << "  " << b3.back() << endl;
    return 0;
}
