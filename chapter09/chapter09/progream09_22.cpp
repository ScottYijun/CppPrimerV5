//
//  program09_22.cpp
//  chapter09
//
//  Created by chenyijun on 17/5/3.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <vector>


using namespace std;

int main()
{
    
    vector<int> ivec = {1, 1, 2, 1};//int的vector
    int some_val = 1;
    
    vector<int>::iterator iter = ivec.begin();
    int org_size = ivec.size(), new_ele = 0;//原大小和新素个数
    
    //每个循环步都重新计算“mid”，保证正确指向ivec中原中央元素
    while(iter != (ivec.begin() + org_size / 2) + new_ele)
    {
        if(*iter == some_val)
        {
            iter = ivec.insert(iter, 2 * some_val);//iter指向新元素
            new_ele++;
            iter++;
            iter++;//将iter推进到旧元素的下一个位置
        }
        else
            iter++;//简单推进iter
    }
    
    //用begin()犯获取vector首元素迭代器，遍历vector中的所有元素
    for(iter = ivec.begin(); iter != ivec.end(); ++iter)
    {
        cout << "*iter============" << *iter << endl;
    }
    
    return 0;
}
