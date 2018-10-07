//
//  program12_32.cpp
//  chapter12
//
//  Created by chenyijun on 2017/6/11.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include "my_TextQuery_32.h"
#include "make_plural.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>//包含EXIT_FAILURE的定义

using std::string;
using std::ifstream;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

void runQueries(ifstream &infile)
{
    //infile是一个ifstream,指向我们要查询的文件
    TextQuery tq(infile);//保存文件并创建映射表
    //程序主循环，提示用户输入一个单词，查询此单词并打印结果
    while(true)
    {
        cout << "enter word to look for, or q to quit:" << endl;
        string s;
        //若遇到文件尾或用户输入了q时循环终止
        if(!(cin >> s) || s == "q")
            break;
        //执行查询并打印结果
        print(cout, tq.query(s)) << endl;
    }
}

//程序接受唯一的命令行参数，表示文件文件名
int main(int argc, const char * argv[])
{
    //打开要查询的文件
    ifstream infile;
    //打开文件失败败，程序异常退出
    if(argc < 2 || !(infile.open(argv[1]), infile))
    {
        cerr << "No input file!" << endl;
        return EXIT_FAILURE;
    }
    runQueries(infile);
    cout << "hello world" << endl;
    return 0;
}
