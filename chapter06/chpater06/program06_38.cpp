//
//  program06_38.cpp
//  chpater06
//
//  Created by chenyijun on 17/3/01.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//


#include <iostream>
#include <string.h>

using namespace std;

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
//返回一个引用，该引用所引的对象是一个含有5个整数的数组
decltype(odd) &arrPtr(int i)
{
    return (i % 2) ? odd : even;
}

int main()
{
    for(auto od: odd)
        cout << "odd=====" << od << endl;
    int *a = arrPtr(1);
    
    for(int i = 0; i < 5; ++i)
        a[i] = i * 3;
    
    for(int j = 0; j < 5; ++j)
        cout << "a[" << j << "] = " << a[j] << endl;
    
    return 0;
}

