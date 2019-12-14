//
//  main.cpp
//  week_5
//
//  Created by 曲晓昆 on 2019/12/14.
//  Copyright © 2019 曲晓昆. All rights reserved.
//


#include"iostream"
#include"vector"
#include"cassert"
#include"queue"
#include"algorithm"
#include"fstream"
#include"stdlib.h"
#include"map"
#include"set"
#include <utility>

using namespace std;


char * strcpy(char * destination, const char * source)
{
    assert(destination != NULL && source != NULL);
    if(destination == source)
        return destination;
    char * res = destination;
    while(*source != '\0')
    {
        *destination++ = *source++;
    }
    *destination = '\0';
    return res;
}

void encryption(string& original, string& secret)
{
    if(original.size() == 0)
        secret = "";
    secret = original;
    vector<int> record = {4,9,6,2,8,7,3};
    char c;
    int j = 0;
    for(int i = 0; i < original.size(); ++i)
    {
        if(original[i] >= '0' && original[i] <= '9')
        {
            // ASCII  a-97  w-119   z-122
            c = ((original[i] - '0')%6 + 'w')%('z' + 1);
            if(c < 'a')
                c += 'a';
            secret[i] = c;
            continue;
        }
        if((original[i] >= 'a' && original[i] <= 'z'))
        {
            c = (original[i] + record[(j++)%record.size()])%('z' + 1);
            if(c < 'a')
                c += 'a';
            secret[i] = c;
            continue;
        }
        if((original[i] >= 'A' && original[i] <= 'Z'))
        {
            // ASCII Z-90
            c = (original[i] + record[(j++)%record.size()])%('Z' + 1);
            if(c < 'A')
                c += 'A';
            secret[i] = c;
        }
    }
}

int main(int argc, const char * argv[])
{
    
    // Question 1
    cout<<"*********** Question1 ***********"<<endl;
    string s1 = "welcome";
    string s2 = "quxiaokun";
    const char * ch = s2.c_str();
    char s[100];
    strcpy(s, s1.c_str());
    cout<<s<<endl;
    cout<<strlen(s)<<endl;
    
    strcpy(s, ch);
    cout<<s<<endl;
    cout<<strlen(s)<<endl;
    
    
    // Question 2
    cout<<"*********** Question2 ***********"<<endl;
    string original = "Li87Zhen0624ye_empyrean.com.cn@269";
    string secret;
    encryption(original, secret);
    cout<<"befor encrytion :"<<original<<endl;
    cout<<"after encrytion :"<<secret<<endl;
    
    

    return 0;
}
