//
//  program06_47.cpp
//  chpater06
//
//  Created by chenyijun on 17/3/8.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
//递归函数输出vector<int>的内容
void print(vector<int> vInt, unsigned index)
{
    unsigned long sz = vInt.size();
    //设置在此处输出调试信息
#ifdef DEBUG
    cout << "vector对象的大小是：" << sz << endl;
#endif
    if(!vInt.empty() && index < sz)
    {
        cout << vInt[index] << endl;
        print(vInt, index + 1);
    }
}

int main()
{
    vector<int> v = {1, 3, 5, 7, 9, 11, 13, 15};
    print(v, 0);
    
    return 0;
}
