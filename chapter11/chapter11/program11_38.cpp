//
//  program11_38.cpp
//  chapter11
//
//  Created by chenyijun on 2017/5/21.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::ifstream;
using std::unordered_map;
using std::string;

//using namespace std;

int main(int argc, const char * argv[])
{
    ifstream in(argv[1]);
    if(!in)
    {
        cout << "打开输入文件失败！" << endl;
        exit(1);
    }
    
    unordered_map<string, size_t> word_count;   //string到count的映射
    string word;
    while(in >> word)
        ++word_count[word];//这个单词的出现次数加1
    
    for(const auto &w: word_count)//对map中的每个元素
    {
        //打印结果
        cout << w.first << "出出了 " << w.second << " 次" << endl;
    }
    return 0;
}
