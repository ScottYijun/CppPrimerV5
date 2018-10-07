//
//  program09_05.cpp
//  chapter09
//
//  Created by chenyijun on 17/4/30.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int>::iterator search_vec(vector<int>::iterator beg, vector<int>::iterator end, int val)
{
    for(; beg != end; ++beg)    //遍历范围
    {
        if(*beg == val)         //检查是否与给定值相等
        {
            return beg;         //搜索成功，返回元素对应迭代码
        }
    }
    return end;                 //搜索失败，返回尾后迭代器
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<int> iList = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    cout << search_vec(iList.begin(), iList.end(), 3) - iList.begin() << endl;
    cout << search_vec(iList.begin(), iList.end(), 8) - iList.begin()<< endl;
    return 0;
}
