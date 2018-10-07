//
//  program03_39.cpp
//  chapter03
//
//  Created by chenyijun on 17/2/21.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str1[80], str2[80];
    cout << "请输入两个字符串：" << endl;
    cin >> str1 >> str2;
    //利用cstring头文件中定义的strcmp函数比较大小
    auto result = strcmp(str1, str2);
    cout << "result================" << result << endl;
    if(result > 0)
        cout << "第一个字符串大于第二个字符串" << endl;
    else if(result < 0)
        cout << "第一个字符串小于第二个字符串" << endl;
    else if(0 == result)
        cout << "两个字符串相等" << endl;
    else
        cout << "未定义的结果" << endl;
    
    return 0;
}
