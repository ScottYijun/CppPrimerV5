//
//  program13_37.cpp
//  chapter13
//
//  Created by chenyijun on 2017/7/2.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>
#include "program13_37.h"
#include <vector>
#include <utility>

using std::cerr;
using std::endl;
using std::cout;
using std::vector;

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for(auto f: lhs.folders)
        f->remMsg(&lhs);
    for(auto f: rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for(auto f: lhs.folders)
        f->addMsg(&lhs);
    for(auto f: rhs.folders)
        f->addMsg(&rhs);
}

Message::Message(const Message &m)
:contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

Message& Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

Message::~Message()
{
    remove_from_Folders();
}

void Message::add_to_Folders(const Message &m)
{
    for(auto f: m.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders()
{
    for(auto f: folders)
        f->remMsg(this);
    folders.clear();
}

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::debug_print()
{
    cerr << "Message:\n\t" << contents << endl;
    cerr << "Appears in " << folders.size() << " Folders" << endl;
}

void Folder::add_to_Messages(const Folder &f)
{
    for(auto msg: f.msgs)
        msg->addFldr(this);
}

Folder::Folder(const Folder &f)
:msgs(f.msgs)
{
    add_to_Messages(f);
}

Folder& Folder::operator=(const Folder &f)
{
    remove_from_Msgs();
    msgs = f.msgs;
    add_to_Messages(f);
    return *this;
}

Folder::~Folder()
{
    remove_from_Msgs();
}

void Folder::remove_from_Msgs()
{
    while(!msgs.empty())
        (*msgs.begin())->remove(*this);
}

void Folder::save(Message &m)
{
    msgs.insert(&m);
    m.addFldr(this);
}

void Folder::remove(Message &m)
{
    msgs.erase(&m);
    m.remFldr(this);
}

void Folder::debug_print()
{
    cerr << "Folder contains " << msgs.size() << " message" << endl;
    int ctr = 1;
    for(auto m: msgs)
    {
        cerr << "Message " << ctr++ << ":\n\t" << m->contents << endl;
    }
}


int main()
{
    string s1("contents1== 星期一");
    string s2("contents2== 星期二");
    string s3("contents3== 星期三");
    string s4("contents4== 星期四");
    string s5("contents5== 星期五");
    string s6("contents6== 星期六");
    
    Message m1(s1);
    Message m2(s2);
    Message m3(s3);
    Message m4(s4);
    Message m5(s5);
    Message m6(s6);
    
    Folder f1;
    Folder f2;
    
    m1.save(f1);
    m3.save(f1);
    m5.save(f1);
    m1.save(f2);
    m2.save(f2);
    m4.save(f2);
    m6.save(f2);
    
    m1.debug_print();
    f2.debug_print();
    
    cout << "create some copies==============\n" << endl;
    Message c1(m1);
    Message c2(m2), c4(m4), c6(m6);
    m1.debug_print();
    f2.debug_print();
    
    cout << "now some assignments==============\n" << endl;
    m2 = m3;
    m4 = m5;
    m6 = m3;
    m1 = m5;
    m1.debug_print();
    f2.debug_print();
    
    cout << "finally, self-assignment==============\n" << endl;
    m2 = m2;
    m1 = m1;
    m1.debug_print();
    f2.debug_print();
    
    cout << "vector==============\n" << endl;
    
    vector<Message> vm;
    cout << "容量======capacity: " << vm.capacity() << endl;
    vm.push_back(m1);
    
    cout << "容量======capacity: " << vm.capacity() << endl;
    vm.push_back(m2);
    
    cout << "容量======capacity: " << vm.capacity() << endl;
    vm.push_back(m3);
    
    cout << "容量======capacity: " << vm.capacity() << endl;
    vm.push_back(m4);
    
    cout << "容量======capacity: " << vm.capacity() << endl;
    vm.push_back(m5);
    
    cout << "容量======capacity: " << vm.capacity() << endl;
    vm.push_back(m6);
    
    cout << "vector=======Folder=======\n" << endl;
    
    vector<Folder> vf;
    cout << "容量======capacity: " << vf.capacity() << endl;
    vf.push_back(f1);
    
    cout << "容量======capacity: " << vf.capacity() << endl;
    vf.push_back(f2);
    
    cout << "容量======capacity: " << vf.capacity() << endl;
    vf.push_back(Folder(f1));
    
    cout << "容量======capacity: " << vf.capacity() << endl;
    vf.push_back(Folder(f2));
    
    cout << "容量======capacity: " << vf.capacity() << endl;
    vf.push_back(Folder());
    
    Folder f3;
    f3.save(m6);
    cout << "容量======capacity: " << vf.capacity() << endl;
    vf.push_back(f3);
    
    std::cout << "Hello, World!\n";
    return 0;

}
