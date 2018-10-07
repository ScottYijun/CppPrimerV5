//
//  program12_24.cpp
//  chapter12
//
//  Created by chenyijun on 2017/6/9.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[])
{
    char c;
    //分配和个字符的动态数组
    //因此最多存放着个字符
    char *r = new char[20];
    int l = 0;
    while(cin.get(c))
    {
        if(isspace(c))//空格符，制表符等空白符
        {
            break;
        }
        
        r[l++] = c;//存入动态数组
        if(20 == l)//已读入了个字符
        {
            cout << "达到数组容量上限" << endl;
            break;
        }
    }
    
    r[l] = 0;
    cout << r << endl;
    //释放动态数组
    delete[] r;
    
    return 0;
}
