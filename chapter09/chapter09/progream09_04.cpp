//
//  program09_04.cpp
//  chapter09
//
//  Created by chenyijun on 17/4/30.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool search_vec(vector<int>::iterator beg, vector<int>::iterator end, int val)
{
    for(; beg != end; ++beg)            //遍历范围
    {
        if(*beg == val)                 //检查是否与给定值相等
        {
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<int> iList = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << search_vec(iList.begin(), iList.end(), 3) << endl;
    cout << search_vec(iList.begin(), iList.end(), 8) << endl;
    return 0;
}
