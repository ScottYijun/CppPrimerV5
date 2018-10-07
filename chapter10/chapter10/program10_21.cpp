//
//  program10_21.cpp
//  chapter10
//
//  Created by chenyijun on 2017/5/16.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

void mutable_lambda(void)
{
    int i = 5;
    auto f = [i]()  mutable->bool { if(i > 0) { i--; return false;} else return true; };
    for(int j = 0; j < 6; j++)
    {
        cout << f() << " ";
    }
    cout << endl;
}

int main(int argc, const char *argv[])
{
    mutable_lambda();
    return 0;
}
