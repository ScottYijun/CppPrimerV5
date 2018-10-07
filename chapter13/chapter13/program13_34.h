//
//  program13_36.h
//  chapter13
//
//  Created by chenyijun on 2017/7/2.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#ifndef MESSAGE_h
#define MESSAGE_h

#include <set>
#include <string>

using std::set;
using std::string;

class Folder;

class Message
{
    friend void swap(Message&, Message&);
    friend class Folder;
    
public:
    //folders被隐式初始化为空集合
    explicit Message(const std::string &str = ""): 
		contents(str) { }  
  
    //拷贝控制成员，用来管理指向本Message的指针
    Message(const Message&);//拷贝构造函数
    Message& operator=(const Message&);//拷贝赋值运算符
    ~Message();//析构函数
    //从给定Folder集合中添加／删除本Message
    void save(Folder&);
    void remove(Folder&);
    void debug_print();
    
private:
    string contents;//实际消息文本
    set<Folder *> folders;//包含本Message的Folder
    //拷贝构造函数，拷贝赋值运算符和析构函数所使用的工具函数
    //将本Message添加到指向参数的Folder中
    void add_to_Folders(const Message&);
    //从folders中的每个Folder中删除本Message
    void remove_from_Folders();
    //used by Folder class to add self to this Message's set of Folder's
    void addFldr(Folder *f)
    {
        folders.insert(f);
    }

    void remFldr(Folder *f)
    {
        folders.erase(f);
    }

};

// declaration for swap should be in the same header as Message itself
void swap(Message&, Message&);

class Folder
{
    friend void swap(Message&, Message&);
    friend class Message;
    
public:
    ~Folder();// remove self from Messages in msgs
    Folder(const Folder&);// add new folder to each Message in msgs
    Folder& operator=(const Folder&);// delete Folder from lhs messages, add Folder to rhs messages
    Folder() = default;//默认构造函数
    void save(Message&);// add this message to folder
    void remove(Message&);// remove this message from this folder
    void debug_print();// print contents and it's list of Folders
    
private:
    set<Message*> msgs;// messages in this folder
    void add_to_Messages(const Folder&);// add this Folder to each Message
    void remove_from_Msgs();     // remove this Folder from each Message
    void addMsg(Message *m)
    {
        msgs.insert(m);
    }
    
    void remMsg(Message *m)
    {
        msgs.erase(m);
    }
};

#endif //MESSAGE_h
