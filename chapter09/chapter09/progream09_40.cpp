//
//  program09_40.cpp
//  chapter09
//
//  Created by chenyijun on 17/5/6.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


int main()
{
    vector<string> svec;
    vector<string> svec2;
    vector<string> svec3;
    vector<string> svec4;
//    svec.resize(1024);
//    string word;
    cout << "capacityp=====" << svec.capacity() << "         size===" << svec.size()<<endl;

//    while(cin >> word)
    for(int i = 0; i < 256; i++)
    {
        svec.push_back("wrold");
    }
    svec.resize(svec.size() + svec.size() / 2);
    cout << "capacityp=====" << svec.capacity() << "          size===" << svec.size() <<endl;
    
    for(int i = 0; i < 512; i++)
    {
        svec2.push_back("wrold");
    }
    svec2.resize(svec2.size() + svec2.size() / 2);
    cout << "capacityp=====" << svec2.capacity() << "          size===" << svec2.size() <<endl;
    
    for(int i = 0; i < 1000; i++)
    {
        svec3.push_back("wrold");
    }
    svec3.resize(svec3.size() + svec3.size() / 2);
    cout << "capacityp=====" << svec3.capacity() << "          size===" << svec3.size() <<endl;
    
    for(int i = 0; i < 1048; i++)
    {
        svec4.push_back("wrold");
    }
    svec4.resize(svec4.size() + svec4.size() / 2);
    cout << "capacityp=====" << svec4.capacity() << "          size===" << svec4.size() <<endl;
    return 0;
}
