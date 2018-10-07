//
//  文件名：program14_40.cpp
//  工程名：chapter14
//  简介：
//  创建日期：Created by chenyijun on 2017/8/14.
//  版权：Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>        //istringstream 必须包含这个头文件
#include <vector>
#include <algorithm>
#include "make_plural.h"

using namespace std;

class IsShoter
{
public:
    bool operator() (const string &s1, const string &s2) const
    {
        return s1.size() < s2.size();
    }
};

class NotShorterThan
{
public:
    NotShorterThan(int len): miniLen(len)
    {

    }
    bool operator() (const string &str)
    {
        return str.size() >= miniLen;
    }

private:
    int miniLen;
};

class PrintString
{
public:
    //PrintString() = delete;
    PrintString(ostream &o = cout): os(o)
    {

    }

    void operator() (const string &str)
    {
        cout << str << " ";
    }

private:
    ostream &os;

};

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());

    for_each(words.begin(), words.end(), PrintString(cerr));
    cerr << endl;
    auto end_unique = unique(words.begin(), words.end());

    words.erase(end_unique, words.end());

    for_each(words.begin(), words.end(), PrintString(cerr));
    cerr << endl;

}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    IsShoter is;
    //stable_partition(words.begin(), words.end(), is);
    stable_sort(words.begin(), words.end(), is);

    NotShorterThan nst(sz);
    auto wc = find_if(words.begin(), words.end(), nst);

    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer " << endl;

    PrintString ps;
    for_each(wc, words.end(), ps);
    cout << endl;
}

int main()
{
    vector<string> words;

    string next_word;
    while(cin >> next_word)
    {
        words.push_back(next_word);
    }

    biggies(words, 6);

    cout << "Hello World!" << endl;
    return 0;
}

