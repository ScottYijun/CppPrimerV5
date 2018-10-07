//
//  program10_06.cpp
//  chapter10
//
//  Created by chenyijun on 2017/5/12.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


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
        cout << val << " ";
    }
    cout << endl;
    
    fill_n(vi.begin(), vi.size(), 0);
    for(auto iter = vi.begin(); iter != vi.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
    
    return 0;
}
