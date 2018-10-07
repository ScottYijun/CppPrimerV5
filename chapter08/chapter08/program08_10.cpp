//
//  program08_07.cpp
//  chapter08
//
//  Created by chenyijun on 17/4/27.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;


int main()
{
    //打开文件
    ifstream in("/Users/chenyijun/project/CppPrimerV5/chapter08/chapter08/program08_10");
    if(!in)
    {
        cerr << "无法打开输入文件" << endl;
        return -1;
    }
    
    string line;
    vector<string> words;
    
    while(getline(in, line))                            //从文件中读取一行
    {
        words.push_back(line);                          //添加到vector中
    }
    
    in.close();                                         //输入完毕，关闭文件
    
    vector<string>::const_iterator it = words.begin();  //迭代器
    while(it != words.end())                            //遍历vector
    {
        istringstream line_str(*it);
        string word;
        while(line_str >> word)                         //通过istringstream从vector中读取数据
        {
            cout << word << "  ";
        }
        cout << endl;
        ++it;
    }
    cout << "run sucess============" << endl;
    return 0;
}
