//
//  program10_07b.cpp
//  chapter10
//
//  Created by chenyijun on 2017/5/12.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[])
{
    vector<int> vec;
    vec.reserve(10);
    fill_n(back_inserter(vec), 10, 0);
    
    for(auto iter = vec.begin(); iter != vec.end(); ++iter)
    {
        cout << *iter <<  " ";
    }
    cout << endl;
    
    
    return 0;
}
