//
//  program10_14.cpp
//  chapter10
//
//  Created by chenyijun on 2017/5/14.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>


using namespace std;


int main(int argc, const char *argv[])
{
    auto sum = [] (int a, int b) { return a + b; };
    
    cout << sum(12, 31) << endl;
    
    return 0;
}
