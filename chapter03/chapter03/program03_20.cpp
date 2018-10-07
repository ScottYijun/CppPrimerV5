//
//  program03_20.cpp
//  chapter03
//
//  Created by chenyijun on 17/2/13.
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
        vInt.push_back(iVal);
    
    if(0 == vInt.size())
    {
        cout << "没有任何元素 " << endl;
        return -1;
    }
    
    cout << "首尾两项的和依次是：" << endl;
    //利用decltype推断i的类型
    for(decltype(vInt.size()) i = 0; i < vInt.size() / 2; ++i)
    {
        //求首尾两项的和
        cout << vInt[i] + vInt[vInt.size() - i - 1] << "  ";
        //每行输出5个数字
        if(0 == (i + 1) % 5)
            cout << endl;
    }
    
    //如果元素数是奇数，单独处理最后一个元素
    if(0 != vInt.size() % 2)
    {
        cout << vInt[vInt.size() / 2];
    }
    
    return 0;
}

//int main()
//{
//    vector<int> vInt;
//    int iVal;
//    cout << "请输入一组数字:" << endl;
//    while(cin >> iVal)
//    {
//        vInt.push_back(iVal);
//    }
//    
//    if(0 == vInt.size())
//    {
//        cout << "没有任何元素" << endl;
//        return -1;
//    }
//    
//    cout << "相邻两项的和依次是：" << endl;
//    //利用decltype推断i的类型
//    for(decltype(vInt.size()) i = 0; i < vInt.size() - 1; i += 2)
//    {
//        //求相邻两项的和
//        cout << vInt[i] + vInt[i + 1] << "  ";
//        //每行输出5个数字
//        if((i + 2) % 10 != 0)
//        {
//            cout << endl;
//        }
//    }
//    //如果元素数是奇数，单独处理最后一个元素
//    if(0 != vInt.size() % 2)
//    {
//        cout << vInt[vInt.size() - 1];
//    }
//    
//    return 0;
//}
