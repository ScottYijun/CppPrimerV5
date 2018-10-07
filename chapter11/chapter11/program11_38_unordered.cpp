//
//  program11_38_unordered.cpp
//  chapter11
//
//  Created by chenyijun on 2017/5/21.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>

using namespace std;

unordered_map<string, string> buildMap(ifstream &map_file)
{
    unordered_map<string, string> trans_map;//保存转换规则
    string key;//要转换的单词
    string value;//用来替换的内容
    //读取第一个单词存入key,这一行的剩余内容存入value
    while(map_file >> key && getline(map_file, value))
    {
        if(value.size() > 1)//检查是否确实存在转换规则
            trans_map[key] = value.substr(1);//跳过前导空白
        else
            throw runtime_error("no rule for " + key);
    }
    
    return trans_map;
}

const string &transform(const string &s, const unordered_map<string, string> &m)
{
    //完成具本体转换工作，这个函数是程序的核心
    auto map_it = m.find(s);
    //如果这个单词在转换映射表中
    if(map_it != m.cend())
        return map_it->second;//用映射表指定内容替换单词
    else
        return s;//否则原样返回单词
}

//第一个参数为转换规则文件
//第二个参数是要转换的文本文件
void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);//保存转换规则
    //调试用：映射表创建好后打印它
    cout << "Here is our transformation map:\n\n";
    for(auto entry: trans_map)
        cout << "key: " << entry.first << "\tvalue: " << entry.second << endl;
    cout << "\n\n";
    //对给定文本进行转换
    string text;//保存从输入读取的每一行
    while(getline(input, text)) //从输入读取一行
    {
        istringstream stream(text);//读取每个单词
        string word;
        bool firstword = true;//控制是否打印空格
        while(stream >> word)
        {
            if(firstword)
                firstword = false;
            else
                cout << " ";//打单词间打印空格
            //转换结果可能是另一个字符串也可能是原单词
            cout << transform(word, trans_map);//打印结果
        }
        cout << endl;//当前行转换完毕，打印回车
    }
}

int main(int argc, const char * argv[])
{
    //打开两个文件并检查是否打开成功
    if(argc != 3)
        throw runtime_error("wrong number of arguments");
    
    ifstream map_file(argv[1]);//打开转换规则文件
    if(!map_file)//检查是否打开成功
        throw runtime_error("no transformation file");
    
    ifstream input(argv[2]);//打开转换的文件
    if(!input)//检查是否打开成功
        throw runtime_error("no input file");
    
    word_transform(map_file, input);
    
    return 0;//退出主函数时文件会自动关闭
}
