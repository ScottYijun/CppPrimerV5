

#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
//#include "QueryResult.h"

/* this version of the query classes includes two
 * members not covered in the book:  
 *   cleanup_str: which removes punctuation and 
 *                converst all text to lowercase
 *   display_map: a debugging routine that will print the contents
 *                of the lookup mape
*/

class QueryResult
{
    
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    typedef std::vector<std::string>::size_type line_no;
    typedef std::set<line_no>::const_iterator line_it;
    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p,
                std::shared_ptr<std::vector<std::string>> f):
    sought(s), lines(p), file(f) { }
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
    std::shared_ptr<std::vector<std::string>> get_file()
    {
        return file;
    }
private:
    std::string sought;  // word this query represents
    std::shared_ptr<std::set<line_no>> lines; // lines it's on
    std::shared_ptr<std::vector<std::string>> file;  //input file
};

std::ostream &print(std::ostream&, const QueryResult&);

class QueryResult; // declaration needed for return type in the query function
class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const; 
    void display_map();        // debugging aid: print the map
    
private:
    std::shared_ptr<std::vector<std::string>> file; // input file
    // maps each word to the set of the lines in which that word appears
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;

	// canonicalizes text: removes punctuation and makes everything lower case
    static std::string cleanup_str(const std::string&);
};
#endif
