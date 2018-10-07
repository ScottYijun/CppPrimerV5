//
//  program11_33.cpp
//  chapter11
//
//  Created by chenyijun on 2017/5/21.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <map>

using namespace std;
//建立转换映射
map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> trans_map;//保存转换到规则
    string key;//要转换的单词
    string value;//替换后的内容
    //读取第一个单词存入key中，行中剩余内容存入value
    while(map_file >> key && getline(map_file, value))
    {
        if(value.size() > 1)//检查是否有转换规则
            trans_map[key] = value.substr(1);//跳过前导空格
        else
            throw runtime_error("no rule for " + key);
    }
    
    return trans_map;
}

//生成转换文件
const string& transform(const string &s, const map<string, string> &m)
{
    //实际的转换工作：此部分是程序的核心
    //map<string, string>::const_iterator map_it = m.find(s);
    auto map_it = m.find(s);
    //如果单词在转换规map中
    if(map_it != m.end())
        return map_it->second;//使用替换短语
    else
        return s;//否则返回原string
}
//单词转换程序
void word_transform(ifstream &map_file, ifstream &input)
{
    //map<string, string> trans_map = buildMap(map_file);
    auto trans_map = buildMap(map_file);//保存转换规则
    cout << "here is our transformation map:" <<endl;
    
    for(map<string, string>::const_iterator entry = trans_map.begin(); entry != trans_map.end(); ++entry)
        cout << "key: " << entry->first << "\tvalue: " << entry->second << endl;
    
    cout << "\n\n";
    string text;//保存输入中的每一行
    while(getline(input, text))//读取一行输入
    {
        istringstream stream(text);//读取每个单词
        string word;
        bool firstword = true;
        while(stream >> word)
        {
            if(firstword)
                firstword = false;
            else
                cout << " ";//在单词间打印一个空格
            //transform返回它的第一个参数或其转换之后的形式
            cout << transform(word, trans_map);//打印输出
        }
        cout << endl;//完成一行的转换
    }
}

int main(int argc, const char * argv[])
{
    if(argc != 3)
        throw runtime_error("wrong number of arguments");
    
    ifstream map_file(argv[1]);
    if(!map_file)
        throw runtime_error("no transformation file");
    
    ifstream input(argv[2]);
    if(!input)
        throw runtime_error("no input file");
    word_transform(map_file, input);
    return 0;
}
