//
//  program04_02.cpp
//  chapter04
//
//  Created by chenyijun on 17/2/22.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    vector<int> vec;
    srand((unsigned)time(NULL));
    cout << "系统自动为向量生成一组元素......"<< endl;
    
    for(int i = 0; i != 10; ++i)
    {
        vec.push_back(rand() % 100);
    }
    
    cout << "生成的向理数据是：" << endl;
    
    for(auto c: vec)
    {
        cout << c << "  ";
    }
    cout << endl;
    cout << "验证添加的括号是否正确:" << endl;
    
    cout << "*vec.begin()的值是:" << *vec.begin() << endl;
    cout << "*(vec.begin())的值是:" << *(vec.begin()) << endl;
    cout << "*vec.begin() + 1的值是:" << *vec.begin() + 1<< endl;
    cout << "(*(vec.begin())) + 1的值是:" << (*(vec.begin())) + 1 << endl;
    
    return 0;
}
