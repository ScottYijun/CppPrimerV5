//
//  program12_20.cpp
//  chapter12
//
//  Created by chenyijun on 2017/6/9.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "SYStrBlob_20.h"

using namespace std;


int main(int argc, const char * argv[]) {
    
    ifstream in(argv[1]);
    if(!in)
    {
        cout << "无法打开输入文件" << endl;
        return -1;
    }
    
    StrBlob b;
    string s;
    while(getline(in, s))
    {
        b.push_back(s);
    }
    
    for(auto it = b.begin(); neq(it, b.end()); it.incr())
    {
        cout << it.deref() << endl;
    }
    
    return 0;
}
