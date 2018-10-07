//
//  program09_50_2.cpp
//  chapter09
//
//  Created by chenyijun on 17/5/9.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
    vector<string> vs = {"12.3", "-4.56", "+7.8e-2"};
    int sum = 0;
    for(auto iter = vs.begin(); iter != vs.end(); ++iter)
        sum += stof(*iter);
    
    cout << "和：" << sum << endl;
    
    return 0;
}
