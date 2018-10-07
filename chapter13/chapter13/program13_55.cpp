//
//  program13_55.cpp
//  chapter13
//
//  Created by chenyijun on 2017/7/27.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include "StrBlob13_55.h"

int main(int argc, const char * argv[])
{
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        cout << "b2大小为" << b2.size() << endl;
        cout << "b2首尾无素为" << b2.front() << " " << b2.back() << endl;
    }
    
    cout << "b1大小为" << b1.size() << endl;
    cout << "b1首尾无素为" << b1.front() << " " << b1.back() << endl;
    
    StrBlob b3 = b1;
    b3.push_back("next");
    cout << "b3大小为" << b3.size() << endl;
    cout << "b3首尾无素为" << b3.front() << " " << b3.back() << endl;
    
    cout << "b1全部元素：" << endl;
    for(auto it = b1.begin(); neq(it, b1.end()); it.incr())
        cout << it.deref() << endl;
    
    std::cout << "Hello, World!\n";
    return 0;
}
