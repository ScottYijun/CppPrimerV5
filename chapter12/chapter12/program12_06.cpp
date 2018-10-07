//
//  program12_06.cpp
//  chapter12
//
//  Created by chenyijun on 2017/6/6.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <vector>
#include <new>

using std::cout;
using std::endl;
using std::vector;
using std::nothrow;
using std::cin;

vector<int> *new_vector(void)
{
    return new (nothrow) vector<int>;
}

void read_ints(vector<int> *pv)
{
    int v;
    while(cin >> v)
    {
        pv->push_back(v);
    }
}

void print_ints(vector<int> *pv)
{
    for(const auto &v: *pv)
        cout << v << " ";
    cout << endl;
}

int main(int argc, const char * argv[])
{
    
    vector<int> *pv = new_vector();
    if(!pv)
    {
        cout << "内存不足！" << endl;
        return -1;
    }
    
    read_ints(pv);
    print_ints(pv);
    delete pv;
    pv = nullptr;
    std::cout << "Hello, World!\n";
    return 0;
}
