//
//  my_StrBlob_32.h
//  chapter12
//
//  Created by chenyijun on 2017/6/11.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#ifndef MY_StrBlob_32_h
#define MY_StrBlob_32_h

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

using namespace std;

//提前声明，StrBlob中的友类声明所需
class StrBlobPtr;


class StrBlob
{
    friend class StrBlobPtr;
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> i1);
    StrBlob(vector<string> *p);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    //添加和删除元素
    void push_back(const string &t) { data->push_back(t); }
    void pop_back();
    //元素访问
    string& front();
    const string& front() const;
    string& back();
    const string& back() const;
    
    //提供给StrBlobPtr的接口
    StrBlobPtr begin(); //定义StrBlobPtr后才能定义这两个函数
    StrBlobPtr end();
    //const版本
    StrBlobPtr begin() const;
    StrBlobPtr end() const;
    
private:
    shared_ptr<std::vector<std::string>> data;
    //如果data[i]不合法，抛出一个异常
    void check(size_type i, const std::string &msg) const;
};

inline StrBlob::StrBlob(): data(make_shared<vector<string>>())
{
    
}

inline StrBlob::StrBlob(initializer_list<string> i1)
        :data(make_shared<vector<string>>(i1))
{
    
}

inline StrBlob::StrBlob(vector<string> *p)
        :data(p)
{
    
}

inline void StrBlob::check(size_type i, const string &msg) const
{
    if(i >= data->size())
        throw out_of_range(msg);
}

inline string& StrBlob::front()
{
    //如果vector为空，check会抛出一个异常
    check(0, "front on empty StrBlob");
    return data->front();
}

//const版本front
inline const string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

inline string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

//const版本back
inline const string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

inline void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

//当试图访问一个不存在的元素时，StrBlobPtr抛出一个异常
class StrBlobPtr
{
    friend bool eq(const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr()
    :curr(0)
    {
        
    }
    
    StrBlobPtr(StrBlob &a, size_t sz = 0)
    :wptr(a.data), curr(sz)
    {
        
    }
    StrBlobPtr(const StrBlob &a, size_t sz = 0)
    :wptr(a.data), curr(sz)
    {
        
    }
    
    string& deref() const;
    string& deref(int off) const;
    StrBlobPtr& incr();//前缀递增
    StrBlobPtr& decr();//前缀递减
    
private:
    //若检查成功，check返回一个指向vector的shared_ptr
    shared_ptr<vector<string>> check(size_t, const string&) const;
    //保存一个weak_ptr，意味着底层vector可能会被销毁
    weak_ptr<vector<string>> wptr;
    size_t curr;//在数组中的当前位置
};

inline shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock();//vector还存在吗？
    if(!ret)
    {
        throw runtime_error("unbound StrBlobPtr");
    }
    if(i >= ret->size())
    {
        throw out_of_range(msg);
    }
    return ret;//否则，返回指向vector的shared_ptr;
}

inline string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr]; //(*p)是对象所指向的vector
}

inline string& StrBlobPtr::deref(int off) const
{
    auto p = check(curr + off, "dereference past end");
    return (*p)[curr + off];//(*p)是对象所指向的vector
}

//前缀递增：返回递增后的对象的引用
inline StrBlobPtr& StrBlobPtr::incr()
{
    //如果curr已经指向容器的尾后位置，就不能递增它
    check(curr, "increment past end of StrBlobPtr");
    ++curr;//推进当前位置
    return *this;
}

//前缀递减：返回递减后的对象的引用
inline StrBlobPtr& StrBlobPtr::decr()
{
    //如果curr已经为0, 递减它就会产生一个非法下标
    --curr;//递减当前位置
    check(-1, "decrement past begin of StrBlobPtr");
    return *this;
}

//StrBlob的begin和end成员的定义
inline StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

//const版本
inline StrBlobPtr StrBlob::begin() const
{
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end() const
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

//StrBlobPtr的比较操作
inline bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    //若底层的vector是同一个
    if(l == r)
    {
        //则两个指针都是空，或都是指向相同元素时，它们相等
        return (!r || lhs.curr == rhs.curr);
    }
    else
    {
        return false;//若指向不同vector,则不可能相等
    }
}

inline bool neq(const StrBlobPtr lhs, const StrBlobPtr &rhs)
{
    return !eq(lhs, rhs);
}

#endif /* MY_StrBlob_32_h */
