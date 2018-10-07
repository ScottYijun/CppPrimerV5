//
//  program11_12.cpp
//  chapter11
//
//  Created by chenyijun on 2017/5/21.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[])
{
    ifstream in(argv[1]);
    if(!in)
    {
        cout << "打开输入文件失败！" << endl;
        exit(1);
    }
    
    vector<pair<string, int>> data; //pair的vector
    string s;
    int v;
    while(in >> s && in >> v)       //读取一个字符串和一个整数
    {
        //data.push_back(pair<string, int>(s, v));//第一种方式初始化
        //data.push_back({s, v});//列表初始化
        data.push_back(make_pair(s, v));//make_pair初始化
    }
    
    for(const auto &d: data)        //打印单词行号
        cout << d.first << " " << d.second << endl;
    cout << endl;
    return 0;
}
