//
//  program06_42.cpp
//  chpater06
//
//  Created by chenyijun on 17/3/01.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

//最后一个形参赋予了默认实参
string mak_plural(size_t ctr, const string &word, const string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

int main()
{
    cout << "success 的单数形式是:" << mak_plural(1, "success", "es") << endl;
    cout << "success 的单数形式是:" << mak_plural(2, "success", "es") << endl;
    
    //一般情况下调用该函数只需要两个实参
    cout << "failure 的单数形式是:" << mak_plural(1, "failure") << endl;
    cout << "failure 的单数形式是:" << mak_plural(2, "failure") << endl;
    return 0;
}




