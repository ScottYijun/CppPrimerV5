//
//  program02.cpp
//  chapter03
//
//  Created by chenyijun on 17/2/8.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

//int main()
//{
//    string line;
//循环读取，每次读入一整行，直至文件结束或遇到异常输入
//    cout << "请输入您的字符串，可以包含空格：" << endl;
//    while(getline(cin, line))
//    {
//        cout << line << endl;
//    }
//    
//    return 0;
//}

int main()
{
    string word;
    //循环读取，每次读入一个词，直至文件结束或遇到异常输入
    cout << "请输入您的单词，不可以包含空格：" << endl;
    while(cin >> word)
    {
        cout << word << endl;
    }
    
    
    return 0;
}