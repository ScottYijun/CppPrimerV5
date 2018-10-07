//
//  program09_41.cpp
//  chapter09
//
//  Created by chenyijun on 17/5/7.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
    vector<char> vc = {'H', 'e', 'l', 'l', 'o'};
    string s(vc.data(), vc.size());
    cout << s << endl;
    
    return 0;
}
