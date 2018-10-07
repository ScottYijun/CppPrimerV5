//
//  program03_32.cpp
//  chapter03
//
//  Created by chenyijun on 17/2/20.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int sz = 10; //常量sz作为vector的容量
    vector<int> vInt, vInt2;
    //通过for循环为vector对象的元素赋值
    for(int i = 0; i < sz; ++i)
    {
        vInt.push_back(i);
    }
    
    for(int j = 0; j < sz; ++j)
        vInt2.push_back(vInt[j]);
    
    //通过范围for循环输出vector对象的全部元素
    for(auto val: vInt2)
        cout << val << "   ";
    cout << endl;
    return 0;
}


//int main()
//{
//    const int sz = 10; //常量sz作为数组的维度
//    int a[sz], b[sz];
//    //通过for循环为数组元素赋值
//    for(int i = 0; i < sz; ++i)
//    {
//        a[i] = i;
//    }
//    
//    for(int j = 0; j < sz; ++j)
//    {
//        b[j] = a[j];
//    }
//    //通过范围for循环输出数组的全部元素
//    for(auto val: b)
//    {
//        cout << val << "  ";
//    }
//    cout << endl;
//    
//    return 0;
//}
