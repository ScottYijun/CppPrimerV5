//
//  program10_04.cpp
//  chapter10
//
//  Created by chenyijun on 2017/5/12.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>


using namespace std;

int main(int argc, const char *argv[])
{
    ifstream in(argv[1]);
    if(!in)
    {
        cout << "打开输入文件失败!" << endl;
        exit(1);
    }
    
    vector<double> vd;
    double val;
    while(in >> val)
    {
        vd.push_back(val);
    }

    cout << "序列中浮点数之和为 " << accumulate(vd.begin(), vd.end(), 0.0) << endl;
    
    return 0;
}
