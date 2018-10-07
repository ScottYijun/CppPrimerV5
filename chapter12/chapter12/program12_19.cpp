//
//  program12_19.cpp
//  chapter12
//
//  Created by chenyijun on 2017/6/7.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include "SYStrBlob_19.h"

int main(int argc, const char * argv[])
{
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        cout << b2.size() << endl;
    }
    cout << b1.size() << endl;
    cout << b1.front() << " " << b1.back() << endl;
    
    const StrBlob b3 = b1;
    cout << b3.front() << " " << b3.back() << endl;
    
    for(auto it = b1.begin(); neq(it, b1.end()); it.incr())
        cout << it.deref() <<endl;
    
    return 0;
}
