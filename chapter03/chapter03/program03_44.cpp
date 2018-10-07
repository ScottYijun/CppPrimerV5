//
//  program03_44.cpp
//  chapter03
//
//  Created by chenyijun on 17/2/21.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

using int_array = int[4];

int main()
{
    int ia[3][4] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
    cout << "利用范围for语句输出多维数组的内容：" << endl;
    for(int_array &row: ia)
    {
        for(int &col: row)
        {
            cout << col << "  ";
        }
        cout << endl;
    }
    
    cout << "利用普通for语句和下标运算符输出多维数组的内容：" << endl;
    for(int i = 0; i != 3; ++i)
    {
        for(int j = 0; j != 4; ++j)
        {
            cout << ia[i][j] << "  ";
        }
        cout << endl;
    }
    
    cout << "利用普通for语句和指针输出多维数组的内容：" << endl;
    for(int_array *p = ia; p != ia + 3; ++p)
    {
        for(int *q = *p; q != *p + 4; ++q)
        {
            cout << *q << "  ";
        }
        cout << endl;
    }
    return 0;
}