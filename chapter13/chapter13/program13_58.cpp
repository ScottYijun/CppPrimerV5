//
//  program13_58.cpp
//  chapter13
//
//  Created by chenyijun on 2017/7/27.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::sort;

class Foo
{
public:
    Foo sorted() &&;//用于可改变的右值
    Foo sorted() const &;//可用于任何类型的Foo
    void push_back(const int &num);
    void print();
    
private:
    vector<int> data;
};

//本对象为右值，因此可以原址排序
Foo Foo::sorted() &&
{
    cout << "右值引用版本===================" << endl;
    sort(data.begin(), data.end());
    return *this;
}
//本对象是const或是一个左值，哪种情况我们都不对其进行原址排离序
Foo Foo::sorted() const &
{
    cout << "左值引用版本===================" << endl;
    Foo ret(*this);//拷贝一个副本
    //return ret.sorted();
    return Foo(*this).sorted();
}

void Foo::push_back(const int &num)
{
    data.push_back(num);
}
    
void Foo::print()
{
    for(auto it:data)
    {
        cout << "value==========" << it << endl;
    }
}
    
int main()
{
    Foo f;
    f.push_back(50);
    f.push_back(20);
    f.push_back(30);
    f.push_back(70);
    f.push_back(60);
    f.push_back(10);
    f.push_back(40);
    f.sorted();
    f.print();
    cout << "hello world===============" << endl;
    return 0;
}
