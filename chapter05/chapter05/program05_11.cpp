//
//  program05_11.cpp
//  chapter05
//
//  Created by chenyijun on 17/2/24.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    unsigned int spaceCnt = 0, tabCnt = 0, newlineCnt = 0;
    char ch;
    cout << "请输入一段文本：" << endl;
    while(cin >> ch)
    {cout << "ch==========" << ch << endl;
        switch(ch)
        {
            case 'a':
            case 'A':
                ++aCnt;
                break;
            case 'e':
            case 'E':
                ++eCnt;
                break;
            case 'i':
            case 'I':
                ++eCnt;
                break;
            case 'o':
            case 'O':
                ++oCnt;
                break;
            case 'u':
            case 'U':
                ++uCnt;
                break;
            case ' ':
                ++spaceCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case '\n':
                ++newlineCnt;
                break;
            default:
                break;
        }
    }
    
    cout << "元音字母 a 的数量是：" << aCnt << endl;
    cout << "元音字母 e 的数量是：" << eCnt << endl;
    cout << "元音字母 i 的数量是：" << iCnt << endl;
    cout << "元音字母 o 的数量是：" << oCnt << endl;
    cout << "元音字母 u 的数量是：" << uCnt << endl;
    
    cout << "空格的数量是：" << spaceCnt << endl;
    cout << "制表符的数量是：" << tabCnt << endl;
    cout << "换行符的数量是：" << newlineCnt << endl;
    
    return 0;
}


