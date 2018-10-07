//
//  program10_37.cpp
//  chapter10
//
//  Created by chenyijun on 2017/5/18.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>


using namespace std;


int main(int argc, const char *argv[])
{
    ostream_iterator<int> out_iter(cout, " ");
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //用流迭代器和copy输出int序列
    copy(vi.begin(), vi.end(), out_iter);
    cout << endl;
    
    list<int> li;
    //vi[2],也就是第3个元素的位置转换为反向迭代器
    vector<int>::reverse_iterator re(vi.begin() + 2);
    //vi[7],也就是第8个元素的位置转换为反向迭代器
    vector<int>::reverse_iterator rb(vi.begin() + 7);
    //用反向迭代器将元素逆序拷贝到list
    copy(rb, re, back_inserter(li));
    copy(li.begin(), li.end(), out_iter);
    cout << endl;
    return 0;
}
