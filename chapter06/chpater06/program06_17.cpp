//
//  program06_17.cpp
//  chpater06
//
//  Created by chenyijun on 17/2/27.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

bool HasUpper(const string &str)  //判断字符串是否含有大写字母
{
    for(auto c: str)
    {
        if(isupper(c))
            return true;
    }
    
    return false;
}

void ChangeToLower(string &str)  //把字符串的所有大写字母转成小写
{
    for(auto &c: str)
        c = tolower(c);
}

int main()
{
    cout << "请输入一个字符串：" << endl;
    string str;
    cin >> str;
    if(HasUpper(str))
    {
        ChangeToLower(str);
        cout << "转换后的字符串是：" << str << endl;
    }
    else
    {
        cout << "该字符串不含大写字母，无须转换" << endl;
    }
    
    return 0;
}



