//
//  main.cpp
//  chapter02
//
//  Created by chenyijun on 17/1/22.
//  Copyright (c) 2017年 chenyijun. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "bool is size = " << sizeof(bool) << std::endl;
    std::cout << "char is size = " << sizeof(char) << std::endl;
    std::cout << "char min value = " << SCHAR_MIN << std::endl;
    std::cout << "char max value = " << SCHAR_MAX << std::endl;
    std::cout << "uchar max value = " << UCHAR_MAX << std::endl;
    
    std::cout << "short is size = " << sizeof(short) << std::endl;
    std::cout << "short min value = " << SHRT_MIN << std::endl;
    std::cout << "char max value = " << SHRT_MAX << std::endl;
    std::cout << "uchar max value = " << USHRT_MAX << std::endl;
    
    std::cout << "int is size = " << sizeof(int) << std::endl;
    std::cout << "int min value = " << INT_MIN << std::endl;
    std::cout << "int max value = " << INT_MAX << std::endl;
    std::cout << "uint max value = " << UINT_MAX << std::endl;
    
    std::cout << "long is size = " << sizeof(long) << std::endl;
    std::cout << "long min value = " << LONG_MIN << std::endl;
    std::cout << "long max value = " << LONG_MAX << std::endl;
    std::cout << "ulong max value = " << ULONG_MAX << std::endl;
    
    std::cout << "long long is size = " << sizeof(long long) << std::endl;
    std::cout << "long long min value = " << LLONG_MIN << std::endl;
    std::cout << "long long max value = " << LLONG_MAX << std::endl;
    std::cout << "uclong long max value = " << ULLONG_MAX << std::endl;
    
    std::cout << "float is size = " << sizeof(float) << std::endl;
    
    std::cout << "double is size = " << sizeof(double) << std::endl;
    
    std::cout << "long double is size = " << sizeof(long double) << std::endl;
    
    return 0;
}
