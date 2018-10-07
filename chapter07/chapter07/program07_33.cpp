//
//  program07_33.cpp
//  chapter07
//
//  Created by chenyijun on 17/4/19.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using namespace std;


class Window_mgr
{
public:
    void clear();
};

class Screen
{
    friend void Window_mgr::clear();        //不定义友元，编译通不过
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(unsigned ht, unsigned wd, char c)
        :height(ht), width(wd), contents(ht * wd, c)
    {
        
    }
    
    pos size() const;
    
private:
    unsigned height = 0, width = 0;
    unsigned cursor = 0;
    string contents;
    
    Screen::pos ht = 24, wd = 80;
};

Screen::pos Screen::size() const        //pos前面要加作用域
{
    return height * width;
}

void Window_mgr::clear()
{
    Screen myScreen(10, 20, 'X');
    cout << "请理之前myScreen的内容是：" << endl;
    cout << myScreen.contents << endl;
    cout << "size=======" << myScreen.size() << endl;
    myScreen.contents = "";
    cout << "请理之后myScreen的内容是：" << endl;
    cout << myScreen.contents << endl;
}

int main()
{
    Window_mgr w;
    w.clear();
    
    return 0;
}

