//
//  program03_45.cpp
//  chapter03
//
//  Created by chenyijun on 17/2/21.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int ia[3][4] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};
    cout << "利用范围for语句输出多维数组的内容：" << endl;
    for(auto &row: ia)
    {
        for(auto &col: row)
        {
            cout << col << "  ";
        }
        cout << endl;
    }
    
    cout << "利用普通for语句和下标运算符输出多维数组的内容：" << endl;
    for(auto i = 0; i != 3; ++i)
    {
        for(auto j = 0; j != 4; ++j)
        {
            cout << ia[i][j] << "  ";
        }
        cout << endl;
    }
    
    cout << "利用普通for语句和指针输出多维数组的内容：" << endl;
    for(auto *p = ia; p != ia + 3; ++p)
    {
        for(auto *q = *p; q != *p + 4; ++q)
        {
            cout << *q << "  ";
        }
        cout << endl;
    }
    return 0;
}