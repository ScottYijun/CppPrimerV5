//
//  program07_29.cpp
//  chapter07
//
//  Created by chenyijun on 17/4/17.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;



class Screen
{
private:
    unsigned height = 0;
    unsigned width = 0;
    unsigned cursor = 0;
    string contents;
    
public:
    Screen() = default;
    Screen(unsigned ht, unsigned wd): height(ht), width(wd), contents(ht * wd, ' ')
    {
        
    }
    
    Screen(unsigned ht, unsigned wd, char c): height(ht), width(wd), contents(ht * wd, c)
    {
        
    }
    
public:
    Screen move(unsigned r, unsigned c)
    {
        cursor = r * width + c;
        contents[0] = 'A';
        //返回一个副本，后续的操作都是对这个副本的值进行修改
        return *this;
    }
    
    Screen set(char ch)
    {
        contents[cursor] = ch;
        return *this;
    }
    
    Screen set(unsigned r, unsigned c, char ch)
    {
        contents[r * width + c] = ch;
        return *this;
    }
    
    Screen display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }
    
    void do_display(std::ostream &os)
    {
        os << contents;
    }
};


int main()
{
    Screen myScreen(5, 5, 'X');
    //set是对move返回的副本进行操作，display是对set返回的副本进行操作
    myScreen.move(4, 0).set('#').display(cout);
    cout << endl;
    myScreen.display(cout);
    cout << "\n";
    
    return 0;
}

