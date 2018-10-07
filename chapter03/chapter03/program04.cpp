//
//  program04.cpp
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
    string s1, s2;
    cout << "请输入两个字符串:" << endl;
    cin >> s1 >> s2;
    auto len1 = s1.size();
    auto len2 = s2.size();
    cout << "len1 = " << len1 << "   len2 =" << len2 << endl;
    if(len1 == len2)
        cout << s1 << "  和  " << s2 << "  的长度都是  " << len1 << endl;
    else if(len1 > len2)
        cout << s1 << " 比 " << s2 << "  的长度多  " << len1 - len2 <<endl;
    else
        cout << s1 << " 比 " << s2 << "  的长度小  " << len2 - len1 <<endl;
    
    return 0;
}

//int main()
//{
//    string s1, s2;
//    cout << "请输入两个字符串:" << endl;
//    cin >> s1 >> s2;
//    if(s1 == s2)
//        cout << "两个字符串相等" << endl;
//    else if(s1 > s2)
//        cout << s1 << " 大于 " << s2 << endl;
//    else
//        cout << s2 << " 大于  " << s1 << endl;
//    
//    return 0;
//}
