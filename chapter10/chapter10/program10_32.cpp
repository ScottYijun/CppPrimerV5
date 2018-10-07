//
//  program10_32.cpp
//  chapter10
//
//  Created by chenyijun on 2017/5/17.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <numeric>
#include "Sales_item.h"

using namespace std;


int main(int argc, const char *argv[])
{
    ifstream in(argv[1]);
    if(!in)
    {
        cout << "打开输入文件失败！" << endl;
        exit(1);
    }
        //创建流迭代器从文件读入字符串
    istream_iterator<string> in_iter(in);
    //尾后迭代器
    istream_iterator<string> eof;
    vector<Sales_item> vs;
    //读入交易记录，存入vector
    while(in_iter != eof)
        vs.push_back(*in_iter++);
    
    if(vs.empty())
    {
        //设没有输入！读取数据错误
        cerr << "No data?!" << endl;
        return -1;//表示读取数据失败
    }
    
    //将交易记录接ISBN排序
    sort(vs.begin(), vs.end(), compareIsbn);
    auto start = vs.begin();
    while(start != vs.end())
    {
        auto item = *start;//相同ISBN的交易记录中的第一条
        //在后续记录中查找第一个ISBN与item不同者
        auto r = find_if(start + 1, vs.end(), [item] (const Sales_item &item1) {return item1.isbn() != item.isbn();});
        //将范围[start, r)间的交易记录累加并输出
        cout << accumulate(start + 1, r, item) << endl;
        //start指向下一个段交易记录中的第一个
        start = r;
    }
    cout << endl;
    
    return 0;
}
