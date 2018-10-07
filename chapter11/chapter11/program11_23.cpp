//
//  program11_23.cpp
//  chapter11
//
//  Created by chenyijun on 2017/5/21.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

void add_child(multimap<string, string> &families, const string &family, const string &child)
{
    families.insert({family, child});
}

int main(int argc, const char * argv[])
{
    multimap<string, string> families;
    add_child(families, "张", "强");
    add_child(families, "张", "刚");
    add_child(families, "王", "五");
    
    for(auto f: families)
    {
        cout << f.first << "家的孩子：" << f.second << endl;
    }
    
    return 0;
}
