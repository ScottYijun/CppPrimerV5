//
//  program08_07.cpp
//  chapter08
//
//  Created by chenyijun on 17/4/27.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

istream& f(istream &in)
{
    string v;
    while(in >> v, !in.eof())       //直到遇到文件结束符才停止读取
    {
        if(in.bad())
        {
            throw runtime_error("IO流错误");
        }
        
        if(in.fail())
        {
            cerr << "数据错误，请重试：" << endl;
            in.clear();
            in.ignore(100, '\n');
            continue;
        }
        cout << v << endl;
    }
    
    in.clear();
    return in;
}


int main(int argc, char *argv[])
{
    ostringstream msg;          //字符串输出流
    msg << "C++ Primer 第五版" << endl;
    istringstream in(msg.str());
    f(in);
    
    return 0;
}
