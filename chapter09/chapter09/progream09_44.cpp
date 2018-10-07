//
//  program09_44.cpp
//  chapter09
//
//  Created by chenyijun on 17/5/7.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void replace_string(string &s, const string &oldVal, const string &newVal)
{
    unsigned long p = 0;
    while((p = s.find(oldVal, p)) != string::npos)  //在s中查找oldVal
    {
        s.replace(p, oldVal.size(), newVal);        //将找到的子串替换为newVal的内容
        p += newVal.size();                         //下标调整到新插入的内容之后
    }
}

int main()
{
    string s = "tho thru tho!";
    replace_string(s,  "thru", "through");
    cout << s << endl;
    
    replace_string(s, "tho", "though");
    cout << s << endl;
    
    replace_string(s, "through", "");
    cout << s << endl;
    
    return 0;
}
