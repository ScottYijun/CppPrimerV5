//
//  program12_27.cpp
//  chapter12
//
//  Created by chenyijun on 2017/6/10.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include "program12_27.h"

using std::cout;
using std::endl;


void runQueries(std::ifstream& infile)
{
    TextQuery tq(infile);
    while(true)
    {
        std::cout << "enter word to lock for, or q to quit:" << endl;
        string s;
        if(!(std::cin >> s) || (s == "q"))
            break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}

int main(int argc, const char * argv[])
{
    std::ifstream in(argv[1]);
    if(!in)
    {
        cout << "无法打开输入文件" << endl;
        return -1;
    }
    runQueries(in);
    
    cout << "hello world" << endl;
    return 0;
}
