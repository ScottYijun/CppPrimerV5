//
//  program05_21.cpp
//  chapter05
//
//  Created by chenyijun on 17/2/25.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string currString, preString;
    bool bl = true;
    cout << "请输入字符串" << endl;
    while(cin >> currString)
    {
        if(!isupper(currString[0]))
            continue;
        if(currString == preString)
        {
            bl = false;
            cout << "连续出现的字符串是：" << currString << endl;
            break;
        }
        preString = currString;
    }
    
    if(bl)
        cout << "没有连续出现的字符串" << endl;
    
    return 0;
}

