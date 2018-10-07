//
//  program03_36.cpp
//  chapter03
//
//  Created by chenyijun on 17/2/20.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    const int sz = 5;  //常量sz作为数组的维度
    vector<int> a, b;
    int i;
    srand((unsigned)time(NULL));  //生成随机数种子
    //通过for循环为数组元素赋值
    for(i = 0; i < sz; ++i)
    {
        //每次循环生成一个10以内的随机数并添加到a中
        a.push_back(rand() % 10);
    }
    cout << "系统数据已经生成，请输入您猜测的5个数字（0〜9），可以重复：" << endl;
    int uVal;
    //通过for循环为数组元素赋值
    for(i = 0; i < sz; ++i)
    {
        if(cin >> uVal)
            b.push_back(uVal);
    }
    cout << "系统生成的数据是：" << endl;
    for(auto val : a)
    {
        cout << val << "  ";
    }
    cout << endl;
    
    cout << "您猜测的灵敏据是：" << endl;
    for(auto val: b)
    {
        cout << val << "  ";
    }
    cout << endl;
    //令it1和it2分别指向vector对象a和b的首元素
    auto it1 = a.cbegin();
    auto it2 = b.cbegin();
    while(it1 != a.cend() && it2 != b.cend())
    {
        if(it1 != it2)
        {
            cout << "您猜测错误，两个数组不相等" << endl;
            return -1;
        }
        ++it1;   //it1向后移动一位
        ++it2;   //it2向后移动一位
    }
    
    cout << "恭喜您全都猜对了！" << endl;
    
    return 0;
}


