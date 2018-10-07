//
//  program10_11.cpp
//  chapter10
//
//  Created by chenyijun on 2017/5/14.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

inline void output_words(vector<string> &words)
{
    for(auto iter = words.begin(); iter != words.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl << endl;
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

void elimDups(vector<string> &words)
{
    output_words(words);//原始数据
    sort(words.begin(), words.end());//排序
    output_words(words);//排序后输出
    
    //http://www.cplusplus.com/reference/algorithm/unique/
    auto end_unique = unique(words.begin(), words.end());//把重复元素移动到最后，并没有真的删除，它只是覆盖相邻的元素
    output_words(words);//输入unique的元素
    
    words.erase(end_unique, words.end());//删除相关的元素
    output_words(words);//输出数据
    
    stable_sort(words.begin(), words.end(), isShorter);//按单词长度排序
    output_words(words);//输出数据
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
    {
        words.push_back(word);
    }
    
    elimDups(words);
    
    return 0;
}
