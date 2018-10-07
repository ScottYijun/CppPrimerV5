//
//  program03_07.cpp
//  chapter03
//
//  Created by chenyijun on 17/2/12.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cout << "请输入一个字符串，可以包含空格：" << endl;
    getline(cin, s);   //读取整行，遇回车符结束
    for(char &c : s)
    {
        c = 'X';
    }
    
    cout << s << endl;
    
    return 0;
}
