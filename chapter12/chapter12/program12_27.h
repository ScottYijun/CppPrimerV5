//
//  program12_27.h
//  chapter12
//
//  Created by chenyijun on 2017/6/10.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#ifndef PROGRAM12_27_h
#define PROGRAM12_27_h

#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <iterator>

using std::shared_ptr;
using std::vector;
using std::string;
using std::ifstream;

class QueryResult;
class TextQuery
{
public:
    using LineNo = vector<string>::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string&) const;
    
private:
    shared_ptr<vector<string>> input;
    std::map<string, shared_ptr<std::set<LineNo>>> result;
};

class QueryResult
{
public:
    friend std::ostream& print(std::ostream&, const QueryResult&);
    
public:
    QueryResult(const string& s, shared_ptr<std::set<TextQuery::LineNo>> set, shared_ptr<vector<string>> v)
    :word(s), nos(set), input(v)
    {
        
    }
    
private:
    string word;
    shared_ptr<std::set<TextQuery::LineNo>> nos;
    shared_ptr<vector<string>> input;
};

TextQuery::TextQuery(std::ifstream& ifs):input(new vector<string>)
{
    LineNo lineNo{0};
    for(string line; std::getline(ifs, line); ++lineNo)
    {
        input->push_back(line);
        std::istringstream line_stream(line);
        for(string text, word; line_stream >> text; word.clear())
        {
            //避免读一个单词后跟标点符号（如：word，）
            std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
            //use reference avoid count of shared_ptr add.
            auto &nos = result[word];
            if(!nos) nos.reset(new std::set<LineNo>);
            nos->insert(lineNo);
        }
    }
}

QueryResult TextQuery::query(const string& str) const
{
    //使用静态只分配一次。
    static shared_ptr<std::set<LineNo>> nodate(new std::set<LineNo>);
    auto found = result.find(str);
    if(found == result.end())
    {
        return QueryResult(str, nodate, input);
    }
    else
    {
        return QueryResult(str, found->second, input);
    }
}

std::ostream& print(std::ostream& out, const QueryResult& qr)
{
    out << qr.word << "  occurs  " << qr.nos->size()
    << (qr.nos->size() > 1? " times" : " time") << std::endl;
    for(auto i : *qr.nos)
    {
        out << "\t(line " << i + 1 << ") " << qr.input->at(i) << std::endl;
    }
    return out;
}

#endif /* PROGRAM12_27_h */
