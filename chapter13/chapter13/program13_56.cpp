//
//  program13_56.cpp
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
    
private:
    vector<int> data;
};

//
Foo Foo::sorted() &&
{
    cout << "右值引用版本===================" << endl;
    sort(data.begin(), data.end());
    return *this;
}
//const
Foo Foo::sorted() const &
{
    cout << "左值引用版本===================" << endl;
    Foo ret(*this);
    //return ret.sorted();
    return Foo(*this).sorted();
}

int main()
{
    Foo f;
    f.sorted();
    
    cout << "hello world===============" << endl;
    return 0;
}
