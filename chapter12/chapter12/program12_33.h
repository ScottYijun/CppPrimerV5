//
//  program12_33.h
//  chapter12
//
//  Created by chenyijun on 2017/6/11.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#ifndef PROGRAM12_33_h
#define PROGRAM12_33_h

#include <memory>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <vector>
#include <iostream>

class QueryResult;//declaration needed for return type in the query function
class TextQuery
{
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
    void display_map();//debugging aid: print the map
    
private:
    std::shared_ptr<std::vector<std::string>> file;//输入文件
    //maps each word to the set of the lines in which that word appears
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
    //canonicalizes text: removes punctuation and makes everything lower case
    static std::string cleanup_str(const std::string&);
};

class QueryResult
{
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    typedef std::vector<std::string>::size_type line_no;
    typedef std::set<line_no>::const_iterator line_it;
    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f)
    :sought(s), lines(p), file(f)
    {
        
    }
    line_it begin() const { return lines->cbegin(); }
    line_it end() const { return lines->cend(); }
    std::shared_ptr<std::vector<std::string>> get_file() { return file; }
    
private:
    std::string sought;//word this query represents
    std::shared_ptr<std::set<line_no>> lines;//lines it's on
    std::shared_ptr<std::vector<std::string>> file;//input file
};

std::ostream &print(std::ostream&, const QueryResult&);


#endif /* PROGRAM12_33_h */
