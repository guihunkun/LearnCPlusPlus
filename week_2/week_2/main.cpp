//
//  main.cpp
//  week_2
//
//  Created by 曲晓昆 on 2019/11/18.
//  Copyright © 2019 曲晓昆. All rights reserved.
//

#include <iostream>
#include <vector>
#include "assert.h"
#include "stdlib.h"
#include <algorithm>
#include "week2Define.h"

using namespace std;

static bool cmp(const Point a, const Point b)
{

    if(a.x != b.x)
        return a.x < b.x;
    else
        return a.y < b.y;
}

Point::Point(int _x, int _y)
{
    x = _x;
    y = _y;
}

void Point::printPoint()
{
    cout<<"Point: x = "<<x<<", y = "<<y<<endl;
}

Personal::Personal(string na, vector<int>& phone)
{
    name = na;
    tel = phone;
}

void Personal::printTel()
{
    cout<<"tel :";
    for(int i = 0; i < tel.size(); i++)
    {
        if(i == 3)
            cout<<"-";
        if(i == 7)
            cout<<"-";
        cout<<tel[i];
    }
    cout<<endl;
}

void writeInt(vector<int>& nums, int n)
{
    assert(n >= 0);
    for(int i = 0; i < n; i++)
    {
        nums.push_back(i);
    }
}

void printAll(Personal& gh, vector<int>& nums)
{
    cout<<"INT_MAX = "<<MAX_INT1<<endl;
    cout<<"INT_MAX = "<<MAX_INT2<<endl;
    cout<<"EDA2 :";
    for(int i = argus; i <= qa; i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
    cout<<"EDA2 :";
    for(int i = argus; i <= qa; i++)
    {
        switch(i)
        {
            case 0:
                cout<<"argus"<<" ";
                break;
            case 1:
                cout<<"aether"<<" ";
                break;
            case 2:
                cout<<"rce"<<" ";
                break;
            case 3:
                cout<<"fpd"<<" ";
                break;
            case 4:
                cout<<"qa"<<" ";
                break;
            default:
                cout<<"EDA2";
        }
    }
    cout<<endl;
    
    cout<<"Personal:"<<endl;
    cout<<"name: "<<gh.name<<endl;
    gh.printTel();
    
    cout<<"intVect :";
    for(int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    
}

void readWritePoint()
{
    int n;
    int x,y;
    cout<<"Please input the number of points(ex: 1):  ";
    cin>>n;
    if(n < 0)
    {
        cout<<"The number of points should >= 0"<<endl;
        return ;
    }
    if(n == 0)
    {
        cout<<"There is no points;"<<endl;
        return ;
    }
    vector<Point> poly;
    Point p;
    cout<<"Please input coordinate(ex: 2 3):"<<endl;
    for(int i = 0; i < n; i++)
    {
        cin>>x>>y;
        p.x = x;
        p.y = y;
        poly.push_back(p);
    }
    
    sort(poly.begin(), poly.end(), cmp);
    cout<<"All points:"<<endl;
    for(int i = 0; i < poly.size(); i++)
    {
        cout<<"Point"<<" "<<(i+1)<<" : "<<"("<<poly[i].x<<","<<poly[i].y<<")"<<endl;
    }
}

void helpTest(vector<int>& nums, int n, int left, int right)
{
    srand((unsigned)time(NULL));
    for(int i = 0; i < n; i++)
    {
        nums.push_back(rand()%(right - left + 1) + left);
    }
}
void printVecInt(vector<int>& nums)
{
    cout<<endl;
    for(int i = 0; i < nums.size(); i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}

void BubbleSort2(vector<int>& nums)
{
    int newn;
    long n = nums.size();
    do{
        newn = 0;
        for(int i = 1; i < n; i ++)
            if( nums[i-1] > nums[i] )
            {
                swap(nums[i-1], nums[i]);
                // 记录最后一次的交换位置,在此之后的元素在下一轮扫描中均不考虑
                newn = i;
            }
        n = newn;
    }while(newn > 0);
}


void BubbleSort(vector<int>& nums)
{
    if(nums.size() == 0)
        return;
    for(int i = 0; i < nums.size() - 1; i++)
    {
        for(int j = 0; j < nums.size() - 1 - i; j++)
        {
            if(nums[j] > nums[j+1])
                swap(nums[j], nums[j+1]);
        }
    }
}

void detection(vector<int>& nums)
{
    if(nums.size() == 0)
        return ;
    for(int i = 0; i < nums.size() - 1; i++)
    {
        if(nums[i] > nums[i+1])
        {
            cout<<"There is a problem with sorting"<<endl;
        }
    }
}

int main(int argc, const char * argv[])
{
    
    Point p1(2),p2(3,4);
    p1.printPoint();
    p2.printPoint();
    
    writeInt(intVect, 10);
    
    string name = "quxiaokun";
    vector<int> phone{1,5,6,0,0,1,5,9,9,9,9};
    Personal gh(name,phone);
    
    printAll(gh, intVect);
    
    readWritePoint();
    
    vector<int> nums;
    helpTest(nums, 10, 0, 100);
    cout<<"before sort:";
    printVecInt(nums);
    //BubbleSort(nums);
    BubbleSort2(nums);
    detection(nums);
    cout<<"after sort :";
    printVecInt(nums);
    
    return 0;
}
