//
//  program11_08.cpp
//  chapter11
//
//  Created by chenyijun on 2017/5/20.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

string &trans(string &s)
{
    for(int p = 0; p < s.size(); p++)
    {
        if(s[p] >= 'A' && s[p] <= 'Z')
            s[p] -= ('A' - 'a');
        else if(s[p] == ',' || s[p] == '.')
            s.erase(p, 1);
    }
    
    return s;
}

int main(int argc, const char * argv[])
{
    ifstream in(argv[1]);
    if(!in)
    {
        cout << "打开输入文件失败！" << endl;
        exit(1);
    }
    
    vector<string> unique_word;     //不重复的单词
    string word;
    while(in >> word)
    {
        trans(word);
        if(find(unique_word.begin(), unique_word.end(), word) == unique_word.end())
            unique_word.push_back(word);//添加不重复单词
    }
        
    for(const auto &w: unique_word) //打印不重复单词
    {
        //打茚结果
        cout << w << " ";
    }
    cout << endl;
    
    return 0;
}
