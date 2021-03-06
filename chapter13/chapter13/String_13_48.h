//
//  String_13_48.h
//  chapter13
//
//  Created by chenyijun on 2017/7/24.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#ifndef STING_13_48_h
#define STING_13_48_h

#include <cstring>
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <initializer_list>
#include <memory>

using std::cout;
using std::endl;

class String
{
    friend String operator+(const String &, const String &);
    friend String add(const String &, const String &);
    friend std::ostream &operator<<(std::ostream &, const String &);
    friend std::ostream &print(std::ostream &, const String &);
    
public:
    String() = default;
    
    // cp points to a null terminated array, allocate new memory & copy the array
    String(const char *cp)
    :sz(std::strlen(cp)), p(a.allocate(sz))
    {
        std::uninitialized_copy(cp, cp + sz, p);
    }
    
    // copy constructor: allocate a new copy of the characters in s 拷贝构造函数
    String(const String &s)
    :sz(s.sz), p(a.allocate(s.sz))
    {
        std::uninitialized_copy(s.p, s.p + sz, p);
        cout << "拷贝构造函数===s=" << &s << "    this===" << this << endl;
    }
    
    // move constructor: copy the pointer, not the characters, no memory allocation or deallocation
    String(String &&s) noexcept
    :sz(s.size()), p(s.p)
    {
        s.p = 0;
        s.sz = 0;
        cout << "移动构造函数=====s==" << &s << "     this=" << this << endl;
    }
    
    String(size_t n, char c)
    :sz(n), p(a.allocate(n))
    {
        std::uninitialized_fill_n(p, sz, c);
    }
    
    // allocates a new copy of the data in the right-hand operand; deletes the memory used by the left-hand operand
    String &operator=(const String &);
    // moves pointers from right- to left-hand operand
    String &operator=(String &&) noexcept;
    
    // unconditionally delete the memory because each String has its own memory
    ~String() noexcept
    {
        if(p)
            a.deallocate(p, sz);
    }
    
    // additional assignment operators
    String &operator=(const char *);                    // car = "Studebaker"
    String &operator=(char c);                            // model = 'T'
    String &operator=(std::initializer_list<char>);     //car = {'a', '4'}
    
    const char *begin()
    {
        return p;
    }
    
    const char *begin() const
    {
        return p;
    }
    
    const char *end()
    {
        return p + sz;
    }
    
    const char *end() const
    {
        return p + sz;
    }
    
    size_t size() const
    {
        return sz;
    }
    
    void swap(String &s)
    {
        auto tmp = p;
        p = s.p;
        s.p = tmp;
        
        auto cnt = sz;
        sz = s.sz;
        s.sz = cnt;
    }
    
private:
    std::size_t sz = 0;
    char *p = nullptr;
    static std::allocator<char> a;
};

String make_plural(size_t ctr, const String &, const String &);
inline void swap(String &s1, String &s2)
{
    s1.swap(s2);
}

#endif //STING_13_48_h
