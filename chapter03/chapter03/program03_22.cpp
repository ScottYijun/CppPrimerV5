//
//  program03_22.cpp
//  chapter03
//
//  Created by chenyijun on 17/2/13.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> text;
    string s;
    cout << "输入字符串" << endl;
    //利用getline读取一句话，直接回车产生一个空串，表示段落结束
    while(getline(cin, s))
        text.push_back(s);   //逐个添加到text中
    cout << "输出字符串" << endl;
    //利用迭代器遍历全部字符串，遇空串停止循环
    for(auto it = text.begin(); it != text.end() && !it->empty(); ++it)
    {
        //利用迭代器遍历当前字符串
        for(auto it2 = it->begin(); it2 != it->end(); ++it2)
        {
            *it2 = toupper(*it2);  //利用toupper改写成大写形式
        }
        cout << *it << endl;  //输出当前字符串
    }
    
    return 0;
}
