//
//  文件名：program14_38.cpp
//  工程名：chapter14
//  简介：
//  创建日期：Created by chenyijun on 2017/8/9.
//  版权：Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>        //istringstream 必须包含这个头文件
#include <vector>
#include <algorithm>

using namespace std;

class StrLenIS
{
public:
    StrLenIS(int len): len(len) { }
    bool operator()(const string &str)
    {
        return str.length() == len;
    }

private:
    int len;
};

void readStr(istream &is, vector<string> &vec)
{
    string word;
    while(is >> word)
    {
        vec.push_back(word);
    }
}

int main()
{
    vector<string> vec;
    readStr(cin, vec);
    const int minLen = 1;
    const int maxLen = 10;
    for(int i = minLen; i <= maxLen; ++i)
    {
        StrLenIS slenIs(i);
        cout << "len:" << i << ", cnt:" << count_if(vec.begin(), vec.end(), slenIs) << endl;
    }

    cout << "Hello World!" << endl;
    return 0;
}

