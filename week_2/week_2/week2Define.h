//
//  week2Define.h
//  week_2
//
//  Created by 曲晓昆 on 2019/11/18.
//  Copyright © 2019 曲晓昆. All rights reserved.
//

#ifndef week2Define_h
#define week2Define_h

#include <string>
#include <vector>
using namespace std;

#define MAX_INT1  (INT_MAX)
const int MAX_INT2 = INT_MAX;

enum EDA2 {argus, aether, rce, fpd, qa};

struct Personal
{
    string name;
    vector<int> tel; //int tel[11];
    Personal(string na, vector<int>& phone);
    void printTel();
};

vector<int> intVect;

struct Point
{
    int x,y;
    Point(int _x = 0, int _y = 0);
    void printPoint();
};


#endif /* week2Define_h */
