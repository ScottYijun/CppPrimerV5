//
//  program03.cpp
//  chapter03
//
//  Created by chenyijun on 17/2/8.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word, line;
    cout << "请选择读取符符串的方式：1表示逐词读取，2表示整行读取" << endl;
    char ch;
    cin >> ch;
    if('1' == ch)
    {
        cout << "请输入字符串：  Welcome to C++ family!  " << endl;
        cin >> word;
        cout << "系统读取的有效字符串是：" << endl;
        cout << word << endl;
        return 0;
    }
    
    //清空输入缓冲区
    cin.clear();
    cin.sync();
    if('2' == ch)
    {
        cout << "请输入字符串：  Welcome to C++ family!   " << endl;
        getline(cin, line);
        //while(getline(cin, line))
        //{
            cout << "系统读取的有效字符串是：" << endl;
            cout << line << endl;
        //}
        return 0;
    }
    
    cout << "您的输入有误！" << endl;
    
    return -1;
}



