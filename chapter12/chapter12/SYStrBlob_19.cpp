//
//  SYStrBlob_19.cpp
//  chapter12
//
//  Created by chenyijun on 2017/6/7.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include "SYStrBlob_19.h"

StrBlob::StrBlob():data(make_shared<vector<string>>())
{
    
}

StrBlob::StrBlob(initializer_list<string> i1):data(make_shared<vector<string>>(i1))
{
    
}

void StrBlob::check(size_type i, const string &msg) const
{
    if(i >= data->size())
        throw out_of_range(msg);
}

string& StrBlob::front()
{
    //如果vector为空，check会抛出一个异常
    check(0, "front on empty StrBlob");
    return data->front();
}

//const版本front
const string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

//const版本back
const string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}
