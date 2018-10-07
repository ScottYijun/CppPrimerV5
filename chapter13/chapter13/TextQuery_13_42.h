//
//  TextQuery_13_42.h
//  chapter13
//
//  Created by chenyijun on 2017/7/17.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include "QueryResult_13_42.h"

class QueryResult;
class TextQuery
{
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
    void display_map();
    
private:
    //std::shared_ptr<std::vector<std::string>> file; //input file
    std::shared_ptr<StrVec> file; //input file
    // maps each word to the set of the lines in which that word appears
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
    // canonicalizes text: removes punctuation and makes everything lower case
    static std::string cleanup_str(const std::string&);
};


#endif //TEXTQUERY_H
