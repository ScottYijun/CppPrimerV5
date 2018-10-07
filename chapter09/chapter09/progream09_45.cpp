//
//  program09_45.cpp
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
    name.insert(name.begin(), 1, ' ');
    name.insert(name.begin(), prefix.begin(), prefix.end());//输入前缀
    name.append(" ");
    name.append(suffix.begin(), suffix.end());
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
