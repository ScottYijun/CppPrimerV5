//
//  program12_15.cpp
//  chapter12
//
//  Created by chenyijun on 2017/6/7.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <memory>

using namespace std;

struct destination {};
struct connection {};

connection connect(destination *pd)
{
    cout << "打开连接" << endl;
    return connection();
}

void disconnect(connection c)
{
    cout << "关闭连接" << endl;
}

//未使用shared_ptr的版本
void f(destination &d)
{
    cout << "直接管理connect" << endl;
    connection c = connect(&d);
    //忘记调用disconnect关闭连接
    cout << endl;
}

void end_connection(connection *p)
{
    disconnect(*p);
}

//使用shared_ptr的版本
void f1(destination &d)
{
    cout << "用shared_ptr管理connect" << endl;
    connection c = connect(&d);
    
    //shared_ptr<connection> p(&c, end_connection);
    shared_ptr<connection> p(&c, [](connection *p) {disconnect(*p); });
    //忘记调用disconnect关闭连接
    cout << endl;
}

int main(int argc, const char * argv[])
{
    destination d;
    f(d);
    f1(d);
    return 0;
}
