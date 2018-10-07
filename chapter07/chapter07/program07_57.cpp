//
//  program07_57.cpp
//  chapter07
//
//  Created by chenyijun on 17/4/57.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

class Account
{
public:
    void calculate()
    {
        amount += (amount * interestRate);
    }
    
    static double rate()
    {
        return interestRate;
    }
    
    static void rate(double newRate)
    {
        interestRate = newRate;
    }
    
private:
    std::string owner;
    double amount;
    static double interestRate;         // 类内声明
    static double initRate();
};

//为什么？因为静态成员属于整个类，而不属于某个对象，如果在类内初始化，会导致每个对象都包含该静态成员，这是矛盾的。
//http://www.cnblogs.com/graphics/archive/2010/07/07/1772733.html
double Account::interestRate = 0.0;// 类外初始化，不必再加static关键字
//void Account::rate(double newRate)
//{
//    interestRate = newRate;
//}

double Account::initRate()
{
    //interestRate = 0.0;
    //return interestRate;
    return 0.0;
}

int main()
{
    //定义并初始化一个静态成员
    //double Account::interestRate = initRate();
    cout << "start=================" << endl;
    double r;
    r = Account::rate();            //使用作用域运行符访问静态成员
    cout << "r=========1=========" << r << endl;
    Account ac1;
    Account *ac2 = &ac1;
    //调用静态成员函灵敏rate的等价形式
    r = ac1.rate();                 //通过Account的对象或引用
    cout << "r=========2=========" << r << endl;
    r = ac2->rate();                //能过指向Account对象的指针
    cout << "r=========3=========" << r << endl;
   
    return 0;
}

