//
//  program08_02.cpp
//  chapter08
//
//  Created by chenyijun on 17/4/26.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>//处理异常

using namespace std;

//不能拷贝IO对象，不能将形象或返回类型设置为流类型
istream& f(istream &in)//进行IO操作的函数通常以引用方式传递和返回值
{
    string v;
    while(in >> v, !in.eof())//直到遇到文件结束符才停止读取
    {
        if(in.bad())//不可恢复的错误，IO流崩溃
        {
            throw runtime_error("IO流错误");//抛出异常
        }
        
        if(in.fail())//可以恢复的错误； 比如输入类型不匹配
        {
            cerr << "数据错误，请重试：" << endl;
            in.clear();//将in中所有条件状态位复位，将流的状态设置为有效，返回void,  恢复正常
            in.ignore(100, '\n');//读取并忽略最多100个字符，包括'\n'
            continue;
        }
        
        cout << v << endl;
    }
    
    in.clear();
    return in;//返回引用
}//读写一个IO对象会改变其状态，因此传递和返回的引用不能是const的；


int main()
{
    std::cout << "Hello, World!\n";
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ostringstream msg;//字符串输出流， 向string写入数据
    msg << "C++ Primer 第五版" << endl;
    istringstream in(msg.str()); //返回msg所保存的string拷贝
    f(in);

    return 0;
}
