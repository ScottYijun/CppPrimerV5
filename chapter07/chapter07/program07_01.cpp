//
//  program07_01.cpp
//  chapter07
//
//  Created by chenyijun on 17/4/4.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include "Sales_data.h"
using namespace std;


int main() {
    cout << "请输入交易记录（ＩＳＢＮ， 销售量，原价，实际售价）：" << endl;

    Sales_data total;  //保存下一条交易记录的变量
    //读入并处理剩余交易记录
    if(cin >> total)
    {
        Sales_data trans;
        while (cin >> trans)
        {
            //如果我们仍在处理相同的书
            if(total.isbn() == trans.isbn())
            {
                total += trans;  //更新总销售额
            }
            else
            {
                //打印前一本书的结果
                cout << "前一本书的结果:" << total << endl;
                total = trans;  //total现在表示下一本书的销售额
            }
        }
        cout << "total:" << total << endl;   //打印最后一本书的结果
    }
    else
    {
        //没有输入！警告读者
        cerr << "No data!" << endl;
        return -1; //表示失败
    }
    
    return 0;
}
