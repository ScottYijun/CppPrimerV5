//
//  program09_31.cpp
//  chapter09
//
//  Created by chenyijun on 17/5/5.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <forward_list>

using namespace std;


int main()
{
    forward_list<int> iflst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = iflst.before_begin();                   //前驱节点
    auto curr = iflst.begin();                          //首节点
    
    while(curr != iflst.end())
    {
        if(*curr & 1)                                   //奇数
        {
            curr = iflst.insert_after(curr, *curr);     //插入到当前元素之后
            prev = curr;                                //prev移动到新插入元素
            ++curr;                                     //curr移动到下一元素
        }
        else                                            //偶数
        {
            curr = iflst.erase_after(prev);             //删除，curr指向下一元素
        }
    }
    
    for(curr = iflst.begin(); curr != iflst.end(); ++curr)
        cout << *curr << " ";
    cout << endl;
    
    return 0;
}


//int main()
//{
//    list<int> ilst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    auto curr = ilst.begin();                       //首节点
//    
//    while(curr != ilst.end())
//    {
//        if(*curr & 1)                               //奇数
//        {
//            curr = ilst.insert(curr, *curr);        //插入到当前元素之前
//            ++curr;
//            ++curr;                                 //移动到下一个元素
//        }
//        else                                        //偶数
//        {
//            curr = ilst.erase(curr);                //删除，指向下一元素
//        }
//    }
//    
//    for(curr = ilst.begin(); curr != ilst.end(); ++curr)
//        cout << *curr << " ";
//    cout << endl;
//    
//    return 0;
//}






