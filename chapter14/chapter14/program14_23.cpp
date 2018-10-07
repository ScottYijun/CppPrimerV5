//
//  文件名：program14_23.cpp
//  工程名：chapter14
//  简介：
//  创建日期：Created by chenyijun on 2017/8/8.
//  版权：Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include "StrVec_14_23.h"

#include <cstring>
using std::strlen;

#include <algorithm>
using std::copy;

#include <cstddef>
using std::size_t;

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

#include <utility>
using std::swap;

#include <initializer_list>
using std::initializer_list;

#include <memory>
using std::uninitialized_copy;

#include <string>
using std::string;

#include <vector>
using std::vector;

using std::allocator;

// errata fixed in second printing --
// StrVec's allocator should be a static member not an ordinary member

// definition for static data member
allocator<string> StrVec::alloc;


int main()
{

    std::initializer_list<std::string> slist = {"wu yen", "sfdsf", "chen", "sfdsf"};
    StrVec vec = slist;
    std::cout << "strVec==========================size==" << vec.size() << std::endl;

    return 0;
}
