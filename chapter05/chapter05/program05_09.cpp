//
//  program05_09.cpp
//  chapter05
//
//  Created by chenyijun on 17/2/24.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    unsigned int vowelCnt = 0;
    char ch;
    cout << "请输入一段文本：" << endl;
    while(cin >> ch)
    {
        if('a' == ch)
            ++vowelCnt;
        if('e' == ch)
            ++vowelCnt;
        if('i' == ch)
            ++vowelCnt;
        if('o' == ch)
            ++vowelCnt;
        if('u' == ch)
            ++vowelCnt;
    }
    
    cout << "您输入的文本中共有 " << vowelCnt << " 个元音字母" << endl;
    
    return 0;
}

