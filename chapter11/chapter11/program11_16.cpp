//
//  program11_16.cpp
//  chapter11
//
//  Created by chenyijun on 2017/5/21.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

int main(int argc, const char * argv[])
{
    map<int, int> m;
    m[1] = 10;
    auto it = m.begin();
    for(auto temp: m)
        cout << "temp.first=" << temp.first << " temp.second=" << temp.second << endl;
    
    it->second = 20;
    for(auto temp: m)
        cout << "temp.first=" << temp.first << " temp.second=" << temp.second << endl;
    
    cout << m.size() << endl;
    
    return 0;
}
