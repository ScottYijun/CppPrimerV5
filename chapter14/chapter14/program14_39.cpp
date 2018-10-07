//
//  文件名：program14_39.cpp
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

class StrLenBetween
{
public:
    StrLenBetween(int minLen, int maxLen): minLen(minLen), maxLen(maxLen)
    {

    }

    bool operator()(const string &str)
    {
        return str.length() >= minLen && str.length() <= maxLen;
    }

private:
    int minLen;
    int maxLen;
};

class StrNotShorterThan
{
public:
    StrNotShorterThan(int len): minLen(len) {}
    bool operator()(const string &str)
    {
        return str.length() >= minLen;
    }

private:
    int minLen;
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
    StrLenBetween slenBetween(1, 9);
    StrNotShorterThan sNotShorterThan(10);

    cout << "len 1 - 9:" << count_if(vec.begin(), vec.end(), slenBetween) << endl;
    cout << "len >= 10:" << count_if(vec.begin(), vec.end(), sNotShorterThan) << endl;

    cout << "Hello World!" << endl;
    return 0;
}

