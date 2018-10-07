//
//  SYStrBlob.h
//  chapter12
//
//  Created by chenyijun on 2017/6/5.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#ifndef SYStrBlob_h
#define SYStrBlob_h

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

using namespace std;

class StrBlob
{
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> i1);
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
    
private:
    shared_ptr<std::vector<std::string>> data;
    //如果data[i]不合法，抛出一个异常
    void check(size_type i, const std::string &msg) const;
};


#endif /* SYStrBlob_h */
