//
//  program05_25.cpp
//  chapter05
//
//  Created by chenyijun on 17/2/25.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    cout << "请依次输入被除数和除数：" << endl;
    int ival1, ival2;
    while(cin >> ival1 >> ival2)
    {
        try{
            if(0 == ival2)
            {
                throw runtime_error("除数不能为0");
            }
            cout << "两数相除的结果是：" << ival1 / ival2 << endl;
        }
        catch(runtime_error err)
        {
            cout << err.what() << endl;
            cout << "需要继续吗（y or n）?" << endl;
            char ch;
            cin >> ch;
            if('y' != ch && 'Y' != ch)
                break;
        }
    }
    
    return 0;
}

