//
//  program09_49.cpp
//  chapter09
//
//  Created by chenyijun on 17/5/8.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void find_longest_word(ifstream &in)
{
    string s;
    string longest_word;
    unsigned long max_length = 0;
    
    while(in >> s)
    {
        if(s.find_first_of("bdfghjklpqty") != string::npos)
            continue;       //包含上出头或下出头字母
        cout << s << " ";
        if(max_length < s.size())   //新单词更长
        {
            max_length = s.size();//记录长度和单词
            longest_word = s;
        }
    }
    cout << endl << "最长字符串：" << longest_word << endl;
}

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if(!in)
    {
        cerr << "无法打开输入文件" << endl;
        return -1;
    }
    
    find_longest_word(in);
    
    return 0;
}
