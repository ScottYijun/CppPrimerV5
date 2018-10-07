//
//  program07_42.cpp
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
    
    Book(const string &n, const string &I, double pr, const string &a, const string &p)
    {
        Name = n;
        ISBN = I;
        Price = pr;
        Author = a;
        Publisher = p;
        cout << "第一个构造函数=================" << endl;
    }
    Book() : Book("", "", 0, "", "")
    {
        cout << "第2个构造函数=================" << endl;
    }
    //Book(std::istream &is)
    Book(std::istream &is): Book()
    {
        is >> *this;
    }
    
    void print()
    {
        cout << "Name = " << Name << "\nISBN = " << ISBN << "\nAuthor = " << Author << "\nPublisher = " << Publisher << endl;
    }
    
};

//接收5个参数
std::istream& operator >> (std::istream& in, Book& s)
{
    
    in >> s.Name >> s.ISBN >> s.Author >> s.Publisher >> s.Price;
    // check that the inputs succeeded
    if (in)
    {
        cout << "Name=======org=======" << s.Name << endl;
        cout << "ISBN=======org=======" << s.ISBN << endl;
        cout << "Author=====org=======" << s.Author << endl;
        cout << "Publisher==org=======" << s.Publisher << endl;
        cout << "price======org=======" << s.Price << endl;
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
    book.print();
    return 0;
}

