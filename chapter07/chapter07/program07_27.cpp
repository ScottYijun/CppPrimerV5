//
//  program07_27.cpp
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
    Screen(unsigned ht, unsigned wd)
            :height(ht), width(wd), contents(ht * wd, ' ')
    {
        
    }
    Screen(unsigned ht, unsigned wd, char c)
            :height(ht), width(wd), contents(ht * wd, c)
    {
        
    }
    
public:
    Screen& move(unsigned r, unsigned c)
    {
        cursor = r * width + c;
        return *this;
    }
    
    Screen& set(char ch)
    {
        contents[cursor] = ch;
        return *this;
    }
    
    Screen& set(unsigned r, unsigned c, char ch)
    {
        contents[r * width + c] = ch;
        return *this;
    }
    
    const Screen& display(std::ostream &os) const
    {
        cout << "const Screen& display======================" << endl;
        do_display(os);
        return *this;
    }
    Screen &display(std::ostream &os)
    {
        cout << "Screen& display======================" << endl;
        do_display(os);
        return *this;
    }
    
private:
    void do_display(std::ostream &os) const
    {
        os << contents;
    }
};


int main()
{
    cout << "Screen测试:" << endl;
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << endl;
    myScreen.display(cout);
    cout << "\n";
    
    return 0;
}

