//
//  program10_02.cpp
//  chapter10
//
//  Created by chenyijun on 2017/5/11.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main(int argc, const char *argv[]) {
    
    ifstream in(argv[1]);
    if(!in)
    {
        cout << "打开输入文件失败!" << endl;
        exit(1);
    }
    
    list<string> ls;
    string word;
   
    while(in >> word)
    {
        ls.push_back(word);
    }
    
    cout << "请输入要搜索的字符串：" << endl;
    cin >> word;
    
    cout << "序列中包含 " << count(ls.begin(), ls.end(), word) << " 个 " << word << endl;
    
    return 0;
}
