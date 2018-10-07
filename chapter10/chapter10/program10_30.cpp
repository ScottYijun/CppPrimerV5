//
//  program10_30.cpp
//  chapter10
//
//  Created by chenyijun on 2017/5/17.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>


using namespace std;


int main(int argc, const char *argv[])
{
    cout << "输入整数" << endl;
    //创建流迭代器从标准输入整数
    istream_iterator<int> in_iter(cin);
    //尾后迭代器
    istream_iterator<int> eof;
    vector<int> vi;
    while(in_iter != eof)
        vi.push_back(*in_iter++);   //存入vector并递增迭代器
    
    sort(vi.begin(), vi.end());
    
    ostream_iterator<int> out_iter(cout, " ");
    copy(vi.begin(), vi.end(), out_iter);
    cout << endl;
//    for(auto v: vi)
//        cout << v << " ";
//    cout << endl;
    return 0;
}
