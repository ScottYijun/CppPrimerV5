//
//  文件名：program14_07.cpp
//  工程名：chapter14
//  简介：
//  创建日期：Created by chenyijun on 2017/8/6.
//  版权：Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

class String
{
    friend ostream& operator<<(ostream &os, const String &Str);

public:
    String() { }
    String(char *cStr):str(cStr)
    {

    }

private:
    char *str;

};

ostream& operator<<(ostream &os, const String &Str)
{
    std::cout << Str.str;
    return os;
}

int main()
{
    String sStr("字符串测试========");
    cout << sStr << endl;

    cout << "Hello World!" << endl;
    return 0;
}
