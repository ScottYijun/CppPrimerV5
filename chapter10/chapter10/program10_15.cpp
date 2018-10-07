//
//  program10_15.cpp
//  chapter10
//
//  Created by chenyijun on 2017/5/14.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>


using namespace std;

void add(int a)
{
    auto sum = [a] (int b) { return a + b; };
    cout << sum(1) <<endl;
}

int main(int argc, const char *argv[])
{
    add(5);
    add(16);
    return 0;
}
