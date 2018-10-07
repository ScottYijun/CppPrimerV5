//
//  StrVec_13_49.cpp
//  chapter13
//
//  Created by chenyijun on 2017/7/26.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include "StrVec_13_49.h"

#include <string>
using std::string;

#include <memory>
using std::allocator;

#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;

// errata fixed in second printing -- 
// StrVec's allocator should be a static member not an ordinary member

// definition for static data member
allocator<string> StrVec::alloc;  

// all other StrVec members are inline and defined inside StrVec_13_49.h


StrVec::~StrVec() noexcept
{
    free();
}

inline
std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    // allocate space to hold as many elements as are in the range
    auto data = alloc.allocate(e - b);
    
    // initialize and return a pair constructed from data and
    // the value returned by uninitialized_copy
    return {data, uninitialized_copy(b, e, data)};
}

inline
StrVec::StrVec(StrVec &&s) noexcept  // move won't throw any exceptions
// member initializers take over the resources in s
: elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    // leave s in a state in which it is safe to run the destructor
    cout << "StrVec 移动构造函数 move destructor=================" << endl;
    s.elements = s.first_free = s.cap = nullptr;
}

inline
StrVec::StrVec(const StrVec &s)
{
    // call alloc_n_copy to allocate exactly as many elements as in s
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

inline
void StrVec::free()
{
    // may not pass deallocate a 0 pointer; if elements is 0, there's no work to do
    if (elements) {
        // destroy the old elements in reverse order
        for (auto p = first_free; p != elements; /* empty */)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

inline
StrVec &StrVec::operator=(std::initializer_list<std::string> il)
{
    // alloc_n_copy allocates space and copies elements from the given range
    auto data = alloc_n_copy(il.begin(), il.end());
    free();   // destroy the elements in this object and free the space
    elements = data.first; // update data members to point to the new space
    first_free = cap = data.second;
    return *this;
}

inline
StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
    cout << "StrVec 移动赋值运算符 move assignment=================" << endl;
    // direct test for self-assignment
    if (this != &rhs) {
        free();                   // free existing elements
        elements = rhs.elements;  // take over resources from rhs
        first_free = rhs.first_free;
        cap = rhs.cap;
        // leave rhs in a destructible state
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

inline
StrVec &StrVec::operator=(const StrVec &rhs)
{
    // call alloc_n_copy to allocate exactly as many elements as in rhs
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

inline
void StrVec::reallocate()
{
    // we'll allocate space for twice as many elements as the current size
    auto newcapacity = size() ? 2 * size() : 1;
    
    // allocate new memory
    auto newdata = alloc.allocate(newcapacity);
    
    // move the data from the old memory to the new
    auto dest = newdata;  // points to the next free position in the new array
    auto elem = elements; // points to the next element in the old array
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    
    free();  // free the old space once we've moved the elements
    
    // update our data structure to point to the new elements
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

StrVec::StrVec(std::initializer_list<std::string> il)
{
    // call alloc_n_copy to allocate exactly as many elements as in il
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

inline
void StrVec::push_back(const std::string& s)
{
    chk_n_alloc(); // ensure that there is room for another element
    // construct a copy of s in the element to which first_free points
    alloc.construct(first_free++, s);  
}

inline
void StrVec::push_back(std::string &&s) 
{
    chk_n_alloc(); // reallocates the StrVec if necessary
    alloc.construct(first_free++, std::move(s));
}
