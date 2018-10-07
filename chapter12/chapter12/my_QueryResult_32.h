//
//  my_QueryResult_32.h
//  chapter12
//
//  Created by chenyijun on 2017/6/11.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#ifndef MY_QUERYRESULT_32_h
#define MY_QUERYRESULT_32_h

#include <vector>
#include <string>
#include <set>
#include <memory>
#include <iostream>
#include "my_StrBlob_32.h"

class QueryResult
{
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    typedef std::vector<std::string>::size_type line_no;
    typedef std::set<line_no>::const_iterator line_it;
    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, StrBlob f)
    :sought(s), lines(p), file(f)
    {
        
    }
    
    std::set<line_no>::size_type size() const
    {
        return lines->size();
    }
    
    line_it begin() const
    {
        return lines->cbegin();
    }
    
    line_it end() const
    {
        return lines->cend();
    }
    
    StrBlob get_file()
    {
        return file;
    }
    
private:
    std::string sought;//要查询的单词
    std::shared_ptr<std::set<line_no>> lines;//单词出现的行号的集号
    StrBlob file;//输入文件
};

std::ostream &print(std::ostream&, const QueryResult&);


#endif /* MY_QUERYRESULT_32_h */
