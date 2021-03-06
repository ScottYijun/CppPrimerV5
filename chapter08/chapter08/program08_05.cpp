//
//  program08_05.cpp
//  chapter08
//
//  Created by chenyijun on 17/4/26.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    //打开文件
    ifstream in("/Users/chenyijun/project/CppPrimerV5/chapter08/chapter08/data.cpp");
    
    if(!in)
    {
        cerr << "无法打开输入文件" << endl;
        return -1;
    }
    
    string line;
    vector<string> words;
    while(in >> line)                                  //从文件中读取每一个单词
    {
        words.push_back(line);                          //添加到vector中
    }
    
    in.close();                                         //输入完毕，关闭文件
    
    vector<string>::const_iterator it = words.begin();  //迭代器
    while(it != words.end())                            //遍历vector
    {
        cout << *it << endl;                            //输出vector中的元素
        ++it;
    }
    
    return 0;
}
