//
//  program04_10.cpp
//  chapter04
//
//  Created by chenyijun on 17/2/22.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    int num;
    while(cin >> num)
    {
        if(42 == num)
        {
            cout << "num=============" << num << endl;
            break;
        }
    }
    
    return 0;
}
