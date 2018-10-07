//
//  program10_34.cpp
//  chapter10
//
//  Created by chenyijun on 2017/5/17.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;


int main(int argc, const char *argv[])
{
    if(2 != argc)
    {
        cout << "在命令行添加命令参数 文件名路径" << endl;
        return -1;
    }
    
    ifstream in(argv[1]);
    if(!in)
    {
        cout << "打开输入文件失败！" << endl;
        exit(1);
    }
    
    vector<int> vi;
    int v;
    while(in >> v)//从文件中读取整数
    {
        vi.push_back(v);
    }
    cout << "原始顺序：" << endl;
    for(auto iter = vi.cbegin(); iter != vi.cend(); ++iter)
        cout << *iter << " ";
    cout << endl;
    cout << "新的顺序：" << endl;
    for(auto r_iter = vi.crbegin(); r_iter != vi.crend(); ++r_iter)
        cout << *r_iter << " ";
    cout << endl;
    
    return 0;
}
