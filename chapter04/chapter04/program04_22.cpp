//
//  program04_22.cpp
//  chapter04
//
//  Created by chenyijun on 17/2/23.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string finalgrade;
    int grade;
    cout << "请输入您要检查的成绩：" << endl;
    //确保输入的成绩合法
    while(cin >> grade && grade >= 0 && grade <= 100)
    {
        //使用三层嵌套的条件表达式
        finalgrade = (grade > 90) ? "high pass"
        : (grade > 75) ? "pass"
        : (grade > 60) ? "low pass" : "fail";
        
        cout << "该成绩所处的档次是：" << finalgrade << endl;
        cout << "请输入您要检查的成绩：" << endl;
    }
    
    return 0;
}
