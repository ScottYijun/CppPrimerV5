//
//  program10_01.cpp
//  chapter10
//
//  Created by chenyijun on 2017/5/11.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[]) {
    
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
    
    cout << "请输入要搜索的整数：" << endl;
    cin >> val;
    
    cout << "序列中包含 " << count(vi.begin(), vi.end(), val) << " 个" << val << endl;
    
    return 0;
}
