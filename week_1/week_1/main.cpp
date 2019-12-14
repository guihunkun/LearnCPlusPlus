//
//  main.cpp
//  week_1
//
//  Created by 曲晓昆 on 2019/11/11.
//  Copyright © 2019 曲晓昆. All rights reserved.
//

#include <iostream>

using namespace std;


void print_1()
{
    cout<<"Hello, World!"<<endl;
}

void print_2(int n)
{
    cout<<"第一种打印：";
    for( int i = 1; i <= n; i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"第二种打印："<<endl;
    for(int i = 1; i <= n; i++)
    {
        cout<<i<<endl;
    }
}

void init()
{
    print_1();
    print_2(9);
}

int main(int argc, const char * argv[])
{
    init();
    return 0;
}
