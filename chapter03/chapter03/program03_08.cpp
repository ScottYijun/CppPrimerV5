//
//  program03_08.cpp
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
    cout << "请输入一个字符串，可以包含空格:" << endl;
    getline(cin, s);
//    int i = 0;
//    while('\0' != s[i])
//    {
//        s[i] = 'X';
//        ++i;
//    }
    for(unsigned int i = 0; i < s.size(); ++i)
    {
        s[i] = 'X';
    }
    cout << s << endl;
    
    return 0;
}

