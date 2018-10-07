//
//  program07_40.cpp
//  chapter07
//
//  Created by chenyijun on 17/4/23.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;

class Book
{
    //这里一定要重载>>操作符 否则Book(std::istream &is)会报
    //invalid operands to binary expression('std::istream'(aka 'basic_istream<char>') and 'Book')的错误
    friend std::istream& operator >> (std::istream&, Book&);
private:
    string Name, ISBN, Author, Publisher;
    double Price = 0;
    
public:
    Book() = default;
    Book(const string &n, const string &I, double pr, const string &a, const string &p)
    {
        Name = n;
        ISBN = I;
        Price = pr;
        Author = a;
        Publisher = p;
    }
    
    Book(std::istream &is)
    {
        is >> *this;
    }
    
};

//接收5个参数
std::istream& operator >> (std::istream& in, Book& s)
{
    
    in >> s.Name >> s.ISBN >> s.Author >> s.Publisher >> s.Price;
    // check that the inputs succeeded
    if (in)
    {
        cout << "Name==============" << s.Name << endl;
        cout << "ISBN==============" << s.ISBN << endl;
        cout << "Author============" << s.Author << endl;
        cout << "Publisher=========" << s.Publisher << endl;
        cout << "price=============" << s.Price << endl;
    }
    else
    {
        s = Book();  // input failed: reset object to default state
    }
    return in;
}


int main()
{
    cout << "please input data====" << endl;
    
    Book book(cin);
    cout << "input finished===============" << endl;
    return 0;
}

