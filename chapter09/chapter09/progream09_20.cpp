//
//  program09_20.cpp
//  chapter09
//
//  Created by chenyijun on 17/5/1.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <deque>
#include <list>

using namespace std;

int main()
{
    list<int> ilist = {1, 2, 3, 4, 5, 6, 7, 8};//初始化整数list
    deque<int> odd_d, even_d;
    //遍历整数list
    for(auto iter = ilist.cbegin(); iter != ilist.cend(); ++iter)
    {
        if(*iter & 1)//查看最低位，1:奇数，0:偶数
            odd_d.push_back(*iter);
        else
            even_d.push_back(*iter);
    }
    cout << "奇数值有：";
    for(auto iter = odd_d.cbegin(); iter != odd_d.cend(); ++iter)
        cout << *iter << " ";
    cout << endl;
    
    cout << "偶数值有：";
    for(auto iter = even_d.cbegin(); iter != even_d.cend(); ++iter)
        cout << *iter << " ";
    cout << endl;
    
    return 0;
}
