//
//  program03_24.cpp
//  chapter03
//
//  Created by chenyijun on 17/2/14.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vInt;
    int iVal;
    cout << "请输入一组数字：" << endl;
    while(cin >> iVal)
    {
        vInt.push_back(iVal);
    }
    
    if(vInt.cbegin() == vInt.cend())
    {
        cout << "没有任何元素" << endl;
        return -1;
    }
    
    cout << "首尾两项的和依次是:" << endl;
    
    auto beg = vInt.begin();
    auto end = vInt.end();
    //利用auto推断it的类型
    for(auto it = beg; it != beg + (end - beg) / 2; ++it)
    {
        //求首尾两项的和
        cout << (*it + *(beg  + (end - it) - 1)) << "  ";
        //每行输出5个数字
        if(0 == (it - beg + 1) % 5)
            cout << endl;
    }
    
    //如果元素个数是奇数，单独处理最后一个元素
    if(0 != vInt.size() % 2)
        cout << *(beg + (end - beg) / 2);
    
    return 0;
}

//int main()
//{
//    vector<int> vInt;
//    int iVal;
//    cout << "请输入一组数字：" << endl;
//    while(cin >> iVal)
//        vInt.push_back(iVal);
//    
//    if(vInt.cbegin() == vInt.cend())
//    {
//        cout << "没有任何元素" << endl;
//        return -1;
//    }
//    
//    unsigned long count = vInt.size();
//    cout << "个数＝＝＝＝＝" << count;
//    cout << "相邻两项的和依次是：" << endl;
//    
//    //如果元素个数是奇数，单独处理最后一个元素
//    if(0 != (count % 2))
//    {
//        //利用auto推断it的类型
//        for(auto it = vInt.cbegin(); it != vInt.cend() - 1; ++it)
//        {
//            //求相邻两项的和
//            cout << (*it + *(++it)) << "   ";
//            //每行输出5个数字
//            if((it - vInt.cbegin() + 1) % 10 == 0)
//                cout << endl;
//        }
//        
//        cout << *(vInt.cend() - 1);
//    }
//    else
//    {
//        //利用auto推断it的类型
//        for(auto it = vInt.cbegin(); it != vInt.cend(); ++it)
//        {
//            //求相邻两项的和
//            cout << (*it + *(++it)) << "   ";
//            //每行输出5个数字
//            if((it - vInt.cbegin() + 1) % 10 == 0)
//                cout << endl;
//        }
//    }
//    
//    return 0;
//}
//
