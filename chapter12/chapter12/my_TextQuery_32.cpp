//
//  my_TextQuery_32.cpp
//  chapter12
//
//  Created by chenyijun on 2017/6/11.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include "my_TextQuery_32.h"
#include "make_plural.h"

#include <cstddef>
#include <memory>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <utility>
#include <string>

using std::size_t;
using std::shared_ptr;
using std::istringstream;
using std::string;
using std::getline;
using std::vector;
using std::map;
using std::set;
using std::cerr;
using std::cout;
using std::cin;
using std::ostream;
using std::endl;
using std::ifstream;
using std::ispunct;
using std::tolower;
using std::strlen;
using std::pair;

//读取输入文件，建立映射
TextQuery::TextQuery(ifstream &is)
    :file(new vector<string>)
{
    string text;
    while(getline(is, text))//读取文件的每一行
    {
        file.push_back(text);//保存读入的文本行
        unsigned long n = file.size() - 1;//当前行号
        istringstream line(text);//从行中分离出单词
        string word;
        while(line >> word)//对行中的每个单词
        {
            word = cleanup_str(word);
            //如果单词还未在wm中，使用下标操作将其添加进去
            auto &lines = wm[word];//lines 是一个shared_ptr
            if(!lines)
            {
                lines.reset(new set<line_no>); //分配一个新的set
            }
            lines->insert(n);//插入当前行号
        }
    }
}

//cleanup_str删除标点同，并将所有文本转换为小写形式，从而查询是大小写不敏感的
string TextQuery::cleanup_str(const string &word)
{
    string ret;
    for(auto it = word.begin(); it != word.end(); ++it)
    {
        if(!ispunct(*it))
        {
            ret += tolower(*it);
        }
    }
    return ret;
}

QueryResult TextQuery::query(const string &sought) const
{
    //如果未找到sought,将返回一个指向下面这个set的指针
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    //使用fine而不是下标操作的原因是避免将不在wm中的单词添加进去！
    auto loc = wm.find(cleanup_str(sought));
    if(loc == wm.end())
    {
        return QueryResult(sought, nodata, file);//未找到
    }
    else
    {
        return QueryResult(sought, loc->second, file);
    }
}

ostream &print(ostream &os, const QueryResult &qr)
{
    //如果找到了单词，打印出现次数及所有出现的行号
    os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << endl;
    //打印单词出现的每一行
    for(auto num: *qr.lines)//对set中每个元素
    {
        //不让用户对从0开始的文件本行号困惑
        os << "\t(line " << num + 1 << ") " << qr.file.begin().deref(num) << endl;
    }
    return os;
}

//调用函数
void TextQuery::display_map()
{
    auto iter = wm.cbegin(), iter_end = wm.cend();
    //对map中的每个单词
    for(; iter != iter_end; ++iter)
    {
        cout << "word: " << iter->first << " {";
        //以常量引用方式获取位置向量，避免拷贝
        auto text_locs = iter->second;
        auto loc_iter = text_locs->cbegin();
        auto loc_iter_end = text_locs->cend();
        //打印此单词出现的所有行号
        while(loc_iter != loc_iter_end)
        {
            cout << *loc_iter;
            if(++loc_iter != loc_iter_end)
                cout << ", ";
        }
        cout << "}\t"; //此单词的输出列表结束
    }
    cout << endl;//结束整个map的输出
}
