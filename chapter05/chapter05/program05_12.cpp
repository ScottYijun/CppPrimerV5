//
//  program05_12.cpp
//  chapter05
//
//  Created by chenyijun on 17/2/24.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    unsigned int ffCnt = 0, flCnt = 0, fiCnt = 0;
    char ch, prech = '\0';
    cout << "请输入一段文本：" << endl;
    while(cin >> ch)
    {
        bool b1 = true;
        if('f' == prech)
        {
            switch(ch)
            {
                case 'f':
                    ++ffCnt;
                    break;
                case 'l':
                    ++flCnt;
                    break;
                case 'i':
                    ++fiCnt;
                    break;
            }
        }
        
        if(!b1)
            prech = '\t';
        else
            prech = ch;
    }
    
    cout << "ff的数量是：" << ffCnt << endl;
    cout << "fl的数量是：" << flCnt << endl;
    cout << "fi的数量是：" << fiCnt << endl;
    
    return 0;
}

