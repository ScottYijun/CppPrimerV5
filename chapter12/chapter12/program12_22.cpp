//
//  program12_22.cpp
//  chapter12
//
//  Created by chenyijun on 2017/6/9.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "SYStrBlob_22.h"

using namespace std;


int main(int argc, const char * argv[]) {
    
    const StrBlob b = {"Hello", "World", "!"};
    
    for(auto it = b.begin(); neq(it, b.end()); it.incr())
    {
        cout << it.deref() << endl;
    }
    
    return 0;
}
