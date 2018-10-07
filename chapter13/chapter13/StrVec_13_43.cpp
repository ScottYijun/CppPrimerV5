//
//  StrVec_13_43.cpp
//  chapter13
//
//  Created by chenyijun on 2017/7/22.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include "StrVec_13_43.h"
#include <vector>
#include <utility>

void StrVec::push_back(const std::string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if(elements)
    {
        //for(auto p = first_free; p != elements;)
        //    alloc.destroy(--p);
        
        std::for_each(elements, first_free, [this](std::string &s){ alloc.destroy(&s); });
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
    free();
}

StrVec::StrVec(std::initializer_list<std::string> il)
{
    //调用alloc_n_copy分配与列表il中元素数目一样多的空间
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 *  size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::reserve(size_t count)
{
    if(size() < count)
    {
        auto newdata = alloc.allocate(count);
        auto dest = newdata;
        auto elem = elements;
        for(size_t i = 0; i != size(); ++i)
            alloc.construct(dest++, std::move(*elem++));
        free();
        elements = newdata;
        first_free = dest;
        cap = elements + count;
    }
}

void StrVec::resize(size_t count)
{
    if(count < size())
    {
        for(auto iter = elements + count; iter != first_free; ++iter)
            alloc.destroy(iter);
        first_free = elements + count;
    }
    
    if(count > size())
    {
        for(size_t i = 0; i != count - size(); ++i)
            alloc.construct(first_free, std::string());
    }
}


