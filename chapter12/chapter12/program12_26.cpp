//
//  program12_26.cpp
//  chapter12
//
//  Created by chenyijun on 2017/6/9.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main(int argc, const char * argv[])
{
    allocator<string> alloc;
    //分配10个未初始化的string
    auto const p = alloc.allocate(10);
    string s;
    string *q = p;//q指向第一个string
    while(cin >> s && q != p + 10)
        alloc.construct(q++, s);//用s初始化*q
    const size_t size = q - p;  //记住读取了多少个string
    cout << endl << "output=============" << endl;
    //使用数组
    for(size_t i = 0; i < size; i++)
    {
        cout << p[i] << " " << endl;
    }
    
    while(q != p)                   //使用完毕后释放已构造的string
        alloc.destroy(--q);
    alloc.deallocate(p, 10);       //释放内存
    cout << "hello world" << endl;
    return 0;
}
