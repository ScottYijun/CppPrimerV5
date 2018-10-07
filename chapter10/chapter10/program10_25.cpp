//
//  program10_25.cpp
//  chapter10
//
//  Created by chenyijun on 2017/5/16.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include "make_plural.h"

using namespace std;
using namespace std::placeholders;

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

inline void output_words(vector<string> &words)
{
    for(auto iter = words.begin(); iter != words.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
}

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);    //将words按字典序排序，删除重复单词
    for_each(words.begin(), words.end(), [](const string &s) {cout << s << " ";});
    
    cout << endl;
    //获取一个迭代器，指向最后一个满足size() >= sz的元素之后的位置
    auto wc = partition(words.begin(), words.end(), bind(check_size, _1, sz));
    //计算满足size >= sz的元素的数目
    auto count = wc - words.begin();
    cout << endl;
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer " << endl;
    //打印长度大于等于给定值的单词，每个单词后面接一个空格
    for_each(words.begin(), wc, [](const string &s) { cout << s << " ";});
    cout << endl;
}

int main(int argc, const char *argv[])
{
    ifstream in(argv[1]);
    if(!in)
    {
        cout << "打开输入文件失败！" << endl;
        exit(1);
    }
    vector<string> words;
    string word;
    while(in >> word)
        words.push_back(word);
    
    biggies(words, 6);
    
    return 0;
}
