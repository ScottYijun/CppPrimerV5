//
//  文件名：program14_36.cpp
//  工程名：chapter14
//  简介：
//  创建日期：Created by chenyijun on 2017/8/9.
//  版权：Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>        //istringstream 必须包含这个头文件
#include <vector>

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

void testReadString()
{
    ReadString rs;
    vector<string> vec;
    while(true)
    {
        string line = rs();
        if(!line.empty())
        {
            vec.push_back(line);
        }
        else
        {
            break;
        }
    }

    for(auto iter: vec)
    {
        cout << "====================" << iter << endl;
    }
}

int main()
{
    testReadString();

    cout << "Hello World!" << endl;
    return 0;
}

