//
//  program07_21.cpp
//  chapter07
//
//  Created by chenyijun on 17/4/11.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include "Sales_data.h"
using namespace std;



int main()
{
    cout << "请输入交易记录(ISBN)，销售量，原价，实际售价:" << endl;
    Sales_data total(cin);                      //保存当前求和结果的变量
    
    if(cin)
    {                                           //读入第一条交易记录
        Sales_data trans(cin);                  //保存和的变量
        do                                      //保存下一条交易数据的变量
        {
                                                //读放剩余的交易
            if(total.isbn() == trans.isbn())    //检查isbn
            {
                total.combine(trans);           //更新变量total当前的值
            }
            else
            {
                print(cout, total) << endl;     //输出结果
                total = trans;                  //处理下一本书
            }
        }while(read(cin, trans));
        
        print(cout, total) << endl;             //输出最后一条交易
    }
    else
    {
        cerr << "No data?!" << endl;            //没有输入！ 警告读者
        return -1;                              //表示失败
    }
    
    return 0;
}