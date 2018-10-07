//
//  program09_38.cpp
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
    vector<int> vi;
    unsigned long s, c;
    for(s = vi.size(), c = vi.capacity(); s <= c; s++)
        vi.push_back(1);
    cout << "1空间：" << vi.capacity() << "元素数：" << vi.size() << endl;
    for(s = vi.size(), c = vi.capacity(); s <= c; s++)
        vi.push_back(1);
    cout << "2空间：" << vi.capacity() << "元素数：" << vi.size() << endl;
    for(s = vi.size(), c = vi.capacity(); s <= c; s++)
        vi.push_back(1);
    cout << "3空间：" << vi.capacity() << "元素数：" << vi.size() << endl;
    for(s = vi.size(), c = vi.capacity(); s <= c; s++)
        vi.push_back(1);
    cout << "4空间：" << vi.capacity() << "元素数：" << vi.size() << endl;
    for(s = vi.size(), c = vi.capacity(); s <= c; s++)
        vi.push_back(1);
    cout << "5空间：" << vi.capacity() << "元素数：" << vi.size() << endl;
    for(s = vi.size(), c = vi.capacity(); s <= c; s++)
        vi.push_back(1);
    
    
    return 0;
}
