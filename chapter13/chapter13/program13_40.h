//
//  program13_40.h
//  chapter13
//
//  Created by chenyijun on 2017/7/15.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#ifndef STRVEC_h
#define STRVEC_h

#include <string>
#include <memory>
#include <utility>

class StrVec
{
public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr)
    {
        
    }
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    StrVec(std::initializer_list<std::string> il);
    ~StrVec();
    void push_back(const std::string &);
    
    
    size_t size() const
    {
        return first_free - elements;
    }
    
    size_t capacity() const
    {
        return cap - elements;
    }
    std::string *begin() const
    {
        return elements;
    }
    std::string *end() const
    {
        return first_free;
    }
    void reserve(size_t count);//重分配容量
    void resize(size_t count);//重置元素个数
    
private:
    std::allocator<std::string> alloc;//分配元素
    void chk_n_alloc()
    {
        if(size() == capacity())
            reallocate();
    }
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
    void free();
    void reallocate();
    std::string *elements;//分配的内存中的首元素
    std::string *first_free;//最后一个实际元素之后的位置
    std::string *cap;//分配的内存末尾之后的位置
};


#endif //STRVEC_h
