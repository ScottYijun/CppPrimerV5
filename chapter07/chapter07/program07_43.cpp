//
//  program07_43.cpp
//  chapter07
//
//  Created by chenyijun on 17/4/23.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//该类型没有显式定义默认构造函数，编译器也不会为它合成一个
class NoDefault
{
public:
    NoDefault(int i)
    {
        val = i;
        cout << "NoDefault构造函数＝＝＝＝＝＝＝＝＝＝＝" << endl;
    }
    
    int val;
};

class C
{
public:
    NoDefault nd;
    //必须显式调用Nodefault的带参构造函数初始化nd
    C(int i = 0): nd(i)
    {
        cout << "C构造函数＝＝＝＝＝＝＝＝＝＝＝" << endl;
    }
};



int main()
{
    C c;  //使用了类型Ｃ的默认构造函数
    cout << c.nd.val << endl;
    
    vector<C> vec(10);
    
    return 0;
}

