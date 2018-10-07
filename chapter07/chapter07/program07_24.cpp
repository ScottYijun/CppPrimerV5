//
//  program07_24.cpp
//  chapter07
//
//  Created by chenyijun on 17/4/11.
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
    void print()
    {
        cout << "width = " << width << "\theight = " << height << "\tcursor = " << cursor << "\tcontents = " << contents << endl;
    }
};

int main()
{
    cout << "打印屏幕信息:" << endl;
    Screen screen1;
    screen1.print();
    
    Screen screen2(50, 100);
    screen2.print();
    
    Screen screen3(5, 2, 'A');  // 5 * 2 个'A'
    screen3.print();
    
    
    return 0;
}



