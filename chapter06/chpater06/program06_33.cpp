//
//  program06_33.cpp
//  chpater06
//
//  Created by chenyijun on 17/3/01.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

//递归函数输出vector<int>的内容
void print(vector<int> vInt, unsigned index)
{
    unsigned long sz = vInt.size();
    if(!vInt.empty() && index < sz)
    {
        cout << "vInt[" << index << "] = " << vInt[index] << endl;
        print(vInt, index + 1);
    }
}

void print(vector<int> vInt)
{
    for(auto val: vInt)
    {
        cout << "val = " << val << endl;
    }
}

int main()
{
    vector<int> v = {1, 3, 5, 7, 9, 11, 13, 15};
    print(v, 0);
    print(v);
    return 0;
}


