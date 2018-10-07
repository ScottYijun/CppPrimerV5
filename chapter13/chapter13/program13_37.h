//
//  program13_37.h
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
    explicit Message(const string &str = "")
    :contents(str)
    {
        
    }
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
    void debug_print();
    
private:
    string contents;
    set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();
    void addFldr(Folder *f)
    {
        folders.insert(f);
    }
    void remFldr(Folder *f)
    {
        folders.erase(f);
    }
};

void swap(Message&, Message&);

class Folder
{
    friend void swap(Message&, Message&);
    friend class Message;
    
public:
    ~Folder();
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    Folder() = default;
    void save(Message&);
    void remove(Message&);
    void debug_print();
    
private:
    set<Message*> msgs;
    void add_to_Messages(const Folder&);
    void remove_from_Msgs();
    void addMsg(Message *m)
    {
        msgs.insert(m);
    }
    //删除一条消息
    void remMsg(Message *m)
    {
        msgs.erase(m);
    }
};

#endif //MESSAGE_h
