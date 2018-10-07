//
//  program13_49.cpp
//  chapter13
//
//  Created by chenyijun on 2017/7/26.
//  Copyright © 2017年 chenyijun. All rights reserved.
//


#include "String_13_48.h"
#include "StrVec_13_49.h"
#include "StrFolderMessage_13_49.h"

#include <cstring>
using std::strlen;

#include <algorithm>
using std::copy;

#include <cstddef>
using std::size_t;

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

#include <utility>
using std::swap;

#include <initializer_list>
using std::initializer_list;

#include <memory>
using std::uninitialized_copy;

#include <vector>
using std::vector;


int main()
{
    String s1("One"), s2("Two");
    cout << "s1==" << s1 << "   s2==" << s2 << endl << endl;
    String s3(s2);
    cout << "s1==" << s1 << "   s2==" << s2 << "   s3==" << s3 << endl << endl;
    s3 = s1;
    cout << "s1==" << s1 << "   s2==" << s2 << "   s3==" << s3 << endl << endl;
    s3 = String("Three");
    cout << "s1==" << s1 << "   s2==" << s2 << "   s3==" << s3 << endl << endl;
    
    vector<String> vstr;
    vstr.push_back(s1);
    cout << endl;
    vstr.push_back(std::move(s2));
    cout << endl;
    vstr.push_back(String("Three"));
    cout << endl;
    vstr.push_back("Four");
    cout << endl;
    for_each(vstr.begin(), vstr.end(), [](const String &s) {cout << s << " ";});
    cout << endl << endl;
    
    
    cout << "StrVec测试===============================" << endl;
    String str1("hello");
    String str2 = "world";
    const char *cstr = "good morning";
    String str3(cstr);
    cout << "str1======= " << str1 << "  str2===== " << str2 << "     str==== " << str3 << endl;
    std::initializer_list<std::string> slist = {"wu yen", "sfdsf", "chen", "sfdsf"};
    StrVec vec(slist);
    std::cout << "strVec==========================size==" << vec.size() << std::endl;
    cout << endl << endl;
    cout << "Message测试===============================" << endl;
    String strFolderMessage1("strFolderMessage1==================contents1");
    String strFolderMessage2("strFolderMessage2==================contents2");
    String strFolderMessage3("strFolderMessage3==================contents3");
    String strFolderMessage4("strFolderMessage4==================contents4");
    String strFolderMessage5("strFolderMessage5==================contents5");
    String strFolderMessage6("strFolderMessage6==================contents6");
    
    // all new messages, no copies yet
    Message m1(strFolderMessage1);
    Message m2(strFolderMessage2);
    Message m3(strFolderMessage3);
    Message m4(strFolderMessage4);
    Message m5(strFolderMessage5);
    Message m6(strFolderMessage6);
    
    Folder f1;
    Folder f2;
    
    m1.save(f1); m3.save(f1); m5.save(f1);
    m1.save(f2);
    m2.save(f2); m4.save(f2); m6.save(f2);
    
    m1.debug_print();
    f2.debug_print();
    
    // create some copies
    Message c1(m1);
    Message c2(m2), c4(m4), c6(m6);
    
    m1.debug_print();
    f2.debug_print();
    
    // now some assignments
    m2 = m3;
    m4 = m5;
    m6 = m3;
    m1 = m5;
    
    m1.debug_print();
    f2.debug_print();
    
    // finally, self-assignment
    m2 = m2;
    m1 = m1;
    
    m1.debug_print();
    f2.debug_print();
    
    vector<Message> vm;
    cout << "capacity: " << vm.capacity() << endl;
    vm.push_back(m1);
    
    cout << "capacity: " << vm.capacity() << endl;
    vm.push_back(m2);
    
    cout << "capacity: " << vm.capacity() << endl;
    vm.push_back(m3);
    
    cout << "capacity: " << vm.capacity() << endl;
    vm.push_back(m4);
    
    cout << "capacity: " << vm.capacity() << endl;
    vm.push_back(m5);
    
    cout << "capacity: " << vm.capacity() << endl;
    vm.push_back(m6);
    
    vector<Folder> vf;
    cout << "capacity: " << vf.capacity() << endl;
    vf.push_back(f1);
    
    cout << "capacity: " << vf.capacity() << endl;
    vf.push_back(f2);
    
    cout << "capacity: " << vf.capacity() << endl;
    vf.push_back(Folder(f1));
    
    cout << "capacity: " << vf.capacity() << endl;
    vf.push_back(Folder(f2));
    
    cout << "capacity: " << vf.capacity() << endl;
    vf.push_back(Folder());
    
    Folder f3;
    f3.save(m6);
    cout << "capacity: " << vf.capacity() << endl;
    vf.push_back(f3);

    return 0;
}


