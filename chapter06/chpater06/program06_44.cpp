//
//  program06_44.cpp
//  chpater06
//
//  Created by chenyijun on 17/3/8.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    
    string str1("chenyijun");
    string str2("yijun");
    
    bool shortStr = isShorter(str1, str2);
    if(true == shortStr)
        cout << str1 << endl;
    else
        cout << str2 << endl;
    
    
    return 0;
}