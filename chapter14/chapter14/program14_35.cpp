//
//  文件名：program14_35.cpp
//  工程名：chapter14
//  简介：
//  创建日期：Created by chenyijun on 2017/8/9.
//  版权：Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>
#include<sstream>        //istringstream 必须包含这个头文件

using namespace std;

class ReadString
{
public:
    ReadString(istream &is = cin):is(is) { }
    std::string operator()()
    {
        string line;
        if(!getline(is, line))
        {
            line = " ";
        }

        return line;
    }

private:
    istream &is;
};

int main()
{
    ReadString readstring;

    cout << "readstring==========" << readstring() << endl;

    cout << "Hello World!" << endl;
    return 0;
}

