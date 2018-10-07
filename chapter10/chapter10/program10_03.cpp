//
//  program10_03.cpp
//  chapter10
//
//  Created by chenyijun on 2017/5/11.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>  //accumulate()函数


using namespace std;

int main(int argc, const char *argv[])
{
    ifstream in(argv[1]);
    if(!in)
    {
        cout << "打开输入文件失败!" << endl;
        exit(1);
    }
    
    vector<int> vi;
    int val;
    while(in >> val)
    {
        vi.push_back(val);
    }
    
    cout << "序列中整数之和为 " << accumulate(vi.begin(), vi.end(), 0) << endl;
    
    return 0;
}
