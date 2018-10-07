//
//  program06_07.cpp
//  chpater06
//
//  Created by chenyijun on 17/2/26.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

//该函数公用于统计执行的次数
unsigned myCnt()  //完成函数的任务不需要任何参数
{
    static unsigned iCnt = -1;  //iCnt 是静态局部变量
    ++iCnt;
    return iCnt;
}

int main()
{
    cout << "请输入任意字符后按回车键继续" << endl;
    char ch;
    while(cin >> ch)
    {
        cout << "函数myCnt的执行次数是：" << myCnt() << endl;
    }
    
    return 0;
}

