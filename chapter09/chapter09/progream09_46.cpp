//
//  program09_46.cpp
//  chapter09
//
//  Created by chenyijun on 17/5/8.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void name_string(string &name, const string &prefix, const string &suffix)
{
    name.insert(0, " ");
    name.insert(0, prefix);//输入前缀
    name.insert(name.size(), " ");
    name.insert(name.size(), suffix);   //插入后缀
}

int main()
{
    string s = "James Bond";
    name_string(s, "Mr.", "II");
    cout << s << endl;
    
    s = "M";
    name_string(s, "Mrs.", "III");
    cout << s << endl;
    
    return 0;
}
