//
//  program15_01.cpp
//  chapter15
//
//  Created by chenyijun on 2017/10/6.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include "program15_01.h"

void Preson::eat()
{
    std::cout << "eat================\n";
}

void Preson::See()
{
    std::cout << "See================\n";
}

class Preson2: public Preson
{
public:
    Preson2()
    {
        
    }
    ~Preson2()
    {
        
    }
    
    void See()
    {
        std::cout << "See========2========\n";
    }
    
    void eat()
    {
        std::cout << "eat=========2=======\n";
    }
};

int main()
{
    
    Preson son;
    son.eat();
    son.See();
    
    Preson2 son2;
    son2.eat();
    son2.See();
    std::cout << "Hello, World!\n";
    return 0;
}
