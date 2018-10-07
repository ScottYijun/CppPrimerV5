//
//  QueryResult_13_42.h
//  chapter13
//
//  Created by chenyijun on 2017/7/17.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <memory>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include "StrVec_13_42.h"

class QueryResult
{
    friend std::ostream& print(std::ostream&, const QueryResult&);
    
public:
    typedef std::vector<std::string>::size_type line_no;
    typedef std::set<line_no>::const_iterator line_it;
    QueryResult(std::string s,
                std::shared_ptr<std::set<line_no>> p,
                //std::shared_ptr<std::vector<std::string>> f):
                std::shared_ptr<StrVec> f):
    sought(s), lines(p), file(f)
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
    //std::shared_ptr<std::vector<std::string>> get_file()
    std::shared_ptr<StrVec> get_file()
    {
        return file;
    }
    
private:
    std::string sought;                             // word this query represents
    std::shared_ptr<std::set<line_no>> lines;       // lines it's on
    //std::shared_ptr<std::vector<std::string>> file; //input file
    std::shared_ptr<StrVec> file; //input file
};

std::ostream &print(std::ostream&, const QueryResult&);

#endif //QUERYRESULT_H
