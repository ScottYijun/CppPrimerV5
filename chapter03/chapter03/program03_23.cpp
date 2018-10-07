//
//  program03_23.cpp
//  chapter03
//
//  Created by chenyijun on 17/2/14.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    vector<int> vInt;
    srand((unsigned)time(NULL));   //生成随机数种子
    for(int i = 0; i < 10; ++i)    //循环10次
    {
        //每次循环生成一个1000以内的随机数并添加到vInt中
        vInt.push_back(rand() % 1000);
    }
    cout << "随机生成的10个数据是：" << endl;
    //利用常量迭代器读取原始数据
    for(auto it = vInt.cbegin(); it != vInt.cend(); ++it)
    {
        cout << *it << "   ";//输出当前数据
    }
    cout << endl;
    
    for(auto it2 = vInt.begin(); it2 != vInt.end(); ++it2)
    {
        *it2 *= 2;
        cout << *it2 << "   ";
    }
    cout << endl;
    
    return 0;
}

