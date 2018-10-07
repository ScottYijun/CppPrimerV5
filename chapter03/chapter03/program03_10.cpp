//
//  program03_10.cpp
//  chapter03
//
//  Created by chenyijun on 17/2/12.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    const string s = "Keep out!";
    for(auto &c : s)
    {
        c = 'X';
    }
    
    return 0;
}

//int main()
//{
//    string s, result;
//    cout << "请输入一个字符串，最好含有某些标点符号：" << endl;
//    getline(cin, s);
//    for(decltype(s.size()) i = 0; i < s.size(); ++i)
//    {
//        if(!ispunct(s[i]))
//            result += s[i];
//    }
//    
//    cout << result << endl;
//    
//    return 0;
//}

//int main()
//{
//    string s;
//    cout << "请输入一个字符串，最好含有某些标点符号：" << endl;
//    getline(cin, s);
//    for(auto c : s)
//    {
//        if(!ispunct(c))
//            cout << c;
//    }
//    cout << endl;
//    
//    return 0;
//}
//
