//
//  program06_32.cpp
//  chpater06
//
//  Created by chenyijun on 17/3/01.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

int &get(int *array, int index)
{
    cout << "index[" << index << "] = " << array[index] << "  ";
    if(0 == index % 3)
        cout << endl;
    return array[index];
}

int main()
{
    int ia[10];
    for(int i = 0; i != 10; ++i)
    {
        //get(ia, i)  返回是一个数组的引用ia[i]    相当于 ia[i] = i;
        get(ia, i) = i;
    }
    cout << endl;
    
    for(int j = 0; j != 10; ++j)
    {
        cout << "ia[" << j << "] = " << ia[j] << "  ";
        if(0 == j % 3)
            cout << endl;
    }
    
    return 0;
}



