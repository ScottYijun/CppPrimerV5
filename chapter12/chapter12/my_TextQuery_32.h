//
//  my_TextQuery_32.h
//  chapter12
//
//  Created by chenyijun on 2017/6/11.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#ifndef MY_TEXTQUERY_32_h
#define MY_TEXTQUERY_32_h

#include <vector>
#include <string>
#include <map>
#include <memory>
#include <set>
#include <fstream>
#include "my_QueryResult_32.h"

class QueryResult;//这个声明类是必须的，查询函数需返回QueryResult类型
class TextQuery
{
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
    void display_map();//调试辅助函数；打印映射表
private:
    StrBlob file;//输入文件
    //将每个单词映射到它所出现的行号的集合
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
    //规范文本：删除标点，并转换为小写
    static std::string cleanup_str(const std::string&);
};


#endif /* MY_TEXTQUERY_32_h */
