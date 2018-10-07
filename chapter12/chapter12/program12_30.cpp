//
//  program12_30.cpp
//  chapter12
//
//  Created by chenyijun on 2017/6/10.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <sstream>  //istringstream
#include "program12_30.h"
#include "make_plural.h"
#include <cstdlib> //for EXIT_FAILURE

using std::size_t;
using std::shared_ptr;
using std::istringstream;
using std::string;
using std::getline;
using std::vector;
using std::map;
using std::set;
using std::cerr;
using std::cout;
using std::cin;
using std::ostream;
using std::endl;
using std::ifstream;
using std::ispunct;
using std::tolower;
using std::strlen;
using std::pair;

// read the input file and build the map of lines to line numbers
TextQuery::TextQuery(ifstream &is): file(new vector<string>)
{
    string text;
    while(getline(is, text)) // for each line in the file
    {
        file->push_back(text);// remember this line of text
        unsigned long n = file->size() - 1;// the current line number
        istringstream line(text); // separate the line into words
        string word;
        while(line >> word)
        {
            word = cleanup_str(word);
            //if word isn't already in wm, subscripting adds a new entry
            auto &lines = wm[word];//lines is a shared_ptr
            if(!lines)//that pointer is null the first time we see word
            {
                lines.reset(new set<line_no>);// allocate a new set
            }
            lines->insert(n);// insert this line number
        }
    }
}

// not covered in the book -- cleanup_str removes
// punctuation and converts all text to lowercase so that
// the queries operate in a case insensitive manner
string TextQuery::cleanup_str(const string &word)
{
    string ret;
    for(auto it = word.begin(); it != word.end(); ++it)
    {
        if(!ispunct(*it))
        {
            ret += tolower(*it);
        }
    }
    return ret;
}

QueryResult TextQuery::query(const string &sought) const
{
    // we'll return a pointer to this set if we don't find sought
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    //use find and not a subscript to avoid adding words to wm!
    auto loc = wm.find(cleanup_str(sought));
    if(loc == wm.end())
    {
        return QueryResult(sought, nodata, file);
    }
    else
    {
        return QueryResult(sought, loc->second, file);
    }
}

ostream &print(ostream &os, const QueryResult &qr)
{
    //if the word was found, print the count and all occurrences
    os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << endl;
    // print each line in which the word appeared
    for(auto num: *qr.lines)
    {
        // don't confound the user with text lines starting at 0
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
    }
    return os;
}

// debugging routine, not covered in the book
void TextQuery::display_map()
{
    auto iter = wm.cbegin(), iter_end = wm.cend();
    //for each word in the map
    for(; iter != iter_end; ++iter)
    {
        cout << "word: " << iter->first << " {";
        // fetch location vector as a const reference to avoid copying it
        auto text_locs = iter->second;
        auto loc_iter = text_locs->cbegin(), loc_iter_end = text_locs->cend();
        // print all line numbers for this word
        while(loc_iter != loc_iter_end)
        {
            cout << *loc_iter;
            if(++loc_iter != loc_iter_end)
                cout << ", ";
        }
        cout << "}\n";// end list of output this word
    }
    cout << endl; // finished printing entire map
}

void runQueries(ifstream &infile)
{
    //infile is an ifstream that is the file we want to query
    TextQuery tq(infile); // store the file and build the query map
    // iterate with the user: prompt for a word to find and print results
    while(true)
    {
        cout << "enter word to look for, or q to quit:" << endl;
        string s;
        // stop if we hit end-of-file on the input or if a 'q' is entered
        if(!(cin >> s) || s == "q")
            break;
        // run the query and print the results
        print(cout, tq.query(s)) << endl;
    }
}

int main(int argc, const char * argv[])
{
    // open the file from which user will query words
    ifstream infile;
    // open returns void, so we use the comma operator XREF(commaOp)
    // to check the state of infile after the open
    if (argc < 2 || !(infile.open(argv[1]), infile)) {
        cerr << "No input file!" << endl;
        return EXIT_FAILURE;
    }
    runQueries(infile);
    
    cout << "hello world" << endl;
    return 0;
}
