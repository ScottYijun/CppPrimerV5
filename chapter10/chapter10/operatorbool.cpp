//
//  operatorbool.cpp
//  chapter10
//
//  Created by chenyijun on 2017/8/15.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>


using namespace std;


class MyClass
{
public:
    MyClass(int value):mValue(value)
    {
        
    }
    operator bool ()
    {
        cout << "mmeber function:operator bool() called "<<mValue<<endl;
        return mValue;
        }
        bool operator == ( const bool &rhs )
        {
            cout << "mmeber function:bool operator == ( const bool &rhs ) called"<<endl;
            return (bool)mValue == rhs;
        }
    private:
        int mValue;
        };
        
        bool operator == ( const MyClass &lhs, bool rhs )
        {
            cout << "global bool operator ==( const MyClass &lhs, bool &rhs ) "<<endl;
            return true;
        }
        
        bool operator == ( const bool &rhs,const MyClass &lhs )
        {
            cout << "global bool operator == ( bool &rhs,const MyClass &lhs )"<<endl;
            return true;
        }
        
        int main()
        {
            MyClass c1(0);
            MyClass c2(10);
            if ( c1 )
            {
                cout << " test1 true "<<endl;
            }
            else
            {
                cout << " test1 false"<<endl;
            }
            
            //bool result = (true == c1);
            if ( true == c1 )
            {
                cout << "test2 true"<<endl;
            }
            else
            {
                cout << "test2 false"<<endl;
            }
            
            
            if ( c2 == false )
            {
                cout << "test3 true"<<endl;
            }
            else
            {
                cout << "test3 false"<<endl;
            }
        }



