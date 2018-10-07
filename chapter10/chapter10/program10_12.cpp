//
//  program10_12.cpp
//  chapter10
//
//  Created by chenyijun on 2017/5/14.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Sales_data.h"

using namespace std;


int main(int argc, const char *argv[])
{
    ifstream in(argv[1]);
    if(!in)
    {
        cout << "打开输入文件失败!" << endl;
        exit(1);
    }
    
    vector<Sales_data> sds;
    Sales_data sd;
    while(read(in, sd))
        sds.push_back(sd);
    
    sort(sds.begin(), sds.end(), compareIsbn);
    
    for(const auto &s: sds)
    {
        print(cout, s);
        cout << endl;
    }
    
    return 0;
}
