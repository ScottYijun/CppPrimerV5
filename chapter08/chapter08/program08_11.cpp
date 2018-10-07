//
//  program08_11.cpp
//  chapter08
//
//  Created by chenyijun on 17/4/27.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};


int main(int argc, char *argv[])
{
    string line, word;                          //分别保存来自输入的一行和单词
    vector<PersonInfo> people;                  //保存来自输入的所有记录
    istringstream record;
    cout << "please input data" << endl;
    while(getline(cin, line))
    {
        PersonInfo info;                        //创建一个保存此记录数据的对象
        record.clear();                         //重复使用字符串流时，每次都要调用clear
        record.str(line);                       //将记录绑定到则读入的行
        record >> info.name;                    //读取名字
        while(record >> word)                   //读取电话号码
        {
            info.phones.push_back(word);        //保持它们
        }
        
        people.push_back(info);                 //将此记录追加到people末尾
    }
    
    cout << "people.size=============" << people.size() << endl;
    return 0;
}
