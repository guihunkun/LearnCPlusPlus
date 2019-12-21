//
//  main.cpp
//  week_6
//
//  Created by 曲晓昆 on 2019/12/21.
//  Copyright © 2019 曲晓昆. All rights reserved.
//
#include <assert.h>
#include <queue>
#include <set>
#include <string>
#include <math.h>
#include "week_6.h"
#include <iostream>

using namespace std;
void extractbNum(int num, set<int>& record)
{
    if(num == 0)
        record.insert(0);
    int num2 = num;
    int a;
    while(num2)
    {
        a = num2%10;
        record.insert(a);
        num2 /= 10;
    }
#if 0
    // just for test
    set<int>::iterator iter = record.begin();
    for(; iter != record.end(); iter++)
    {
        cout<<(*iter)<<endl;
    }
#endif
}

void containAllNums(int num)
{
    set<int> record;
    num = abs(num);
    extractbNum(num, record);
    extractbNum(num*2, record);
    extractbNum(num*3, record);
    if(record.size() == 9 && record.find(0) == record.end())
        cout<<num<<endl;
}


void generateNums(vector<int>& nums, int n, int left, int right)
{
    srand((unsigned)time(NULL));
    for(int i = 0; i < n; i++)
    {
        nums.push_back(rand()%(right - left + 1) + left);
    }
}


int findKnums(vector<int>& nums, int k, vector<int>& result)
{
    assert(nums.size() > k);
#if 1
    int res = 0;
    sort(nums.begin(), nums.end());
    for(size_t i = nums.size()-1; i >= nums.size() - k; --i)
    {
        res += nums[i];
        result.push_back(nums[i]);
    }
    return res;
#else
    int res = 0, num;
    priority_queue<int,vector<int>,greater<int> > q;
    int i;
    for(i = 0; i < k && i < nums.size(); i++)
        q.push(nums[i]);
    while(i < nums.size())
    {
        if(nums[i] > q.top())
        {
            q.pop();
            q.push(nums[i]);
        }
        i++;
    }
    while(!q.empty())
    {
        num = q.top();
        q.pop();
        res += num;
        result.push_back(num);
    }
    return res;
#endif
}


void replace(string& s, const string& t, const string& v)
{
    string res;
    if(s.find(t) == string::npos)
        return;
    string s1 = s;
    while(true)
    {
        size_t start = s1.find(t);
        if(start != string::npos)
        {
            res += s1.substr(0,start);
            res += v;
            s1 = s1.substr(start + t.size(), s1.size() - start);
        }
        else
            break;
    }
    s = res;
}


void testForQuestion3()
{
    string s1 = "I am guihun";
    string t1 = "guihun";
    string v1 = "quxiaokun";
    cout<<"Before replace s1 = "<<s1<<endl;
    replace(s1, t1, v1);
    cout<<"After replace s1 = "<<s1<<endl;
    
    string s2 = "Hello world";
    string t2 = "world";
    string v2 = "C plus plus";
    cout<<"Before replace s2 = "<<s2<<endl;
    replace(s2, t2, v2);
    cout<<"After replace s2 = "<<s2<<endl;
    
    string s3 = "I love mathematics";
    string t3 = "matics";
    string v3 = "matical logic";
    cout<<"Before replace s3 = "<<s3<<endl;
    replace(s3, t3, v3);
    cout<<"After replace s3 = "<<s3<<endl;
}

double distance(Point a, Point b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double triarea(Point p1, Point p2, Point p3)
{
    double a,b,c;
    a = sqrt((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
    b = sqrt((p3.x-p1.x)*(p3.x-p1.x) + (p3.y-p1.y)*(p3.y-p1.y));
    c = sqrt((p2.x-p3.x)*(p2.x-p3.x) + (p2.y-p3.y)*(p2.y-p3.y));
    return 0.25*sqrt((a+b+c)*(a+b-c)*(a+c-b)*(b+c-a));
}

String::String(const char *str)
{
    if(str == NULL)
    {
        m_data = new char[1];
        *m_data = '\0';
    }
    else
    {
        m_data = new char[strlen(str) + 1];
        strcpy(m_data, str);
    }
}

String::String(const String& other)
{
    m_data = new char[strlen(other.m_data) + 1];
    strcpy(m_data, other.m_data);
}

String::~String(void)
{
    if(m_data != NULL)
    {
        delete [] m_data;
        m_data = NULL;
    }
}

String & String::operator = (const String &other)
{
    if(this == &other)
    {
        return *this;
    }
    delete [] m_data;
    m_data = new char[strlen(other.m_data) + 1];
    strcpy(m_data, other.m_data);
    return *this;
}

int String::getLength()
{
    return (int)strlen(m_data);
}

void Point::set(double _x, double _y)
{
    x = _x;
    y = _y;
}

Circle::Circle(Point a, double _r)
{
    o.set(a.x, a.y);
    r = _r;
}

double Circle::getArea()
{
    return PI*r*r;
}

double Circle::getPerim()
{
    return 2*PI*r;
}

void Circle::printShapeInfo()
{
    cout<<"Circle information:"<<endl;
    cout<<"Center coordinate is "<<"("<<o.x<<", "<<o.y<<")"<<endl;
    cout<<"Radius r = "<<r<<endl;
}

void Circle::showShape()
{
    cout<<"This is a circle"<<endl;
}

Circle::~Circle()
{
    
}

Square::Square(double l, double r, double b, double t)
{
    left = l;
    right = r;
    bot = b;
    top = t;
}

double Square::getArea()
{
    return (right - left)*(top - bot);
}
double Square::getPerim()
{
    return 2*(right - left + top - bot);
}
void Square::printShapeInfo()
{
    cout<<"Square information:"<<endl;
    cout<<"left = "<<left<<endl;
    cout<<"right = "<<right<<endl;
    cout<<"bot = "<<bot<<endl;
    cout<<"top = "<<top<<endl;
}
void Square::showShape()
{
    cout<<"This is a square"<<endl;
}
Square::~Square()
{
    
}


Rectangle::Rectangle(double l, double r, double b, double t)
{
    left = l;
    right = r;
    bot = b;
    top = t;
}

double Rectangle::getArea()
{
    return (right - left)*(top - bot);
}
double Rectangle::getPerim()
{
    return 2*(right - left + top - bot);
}
void Rectangle::printShapeInfo()
{
    cout<<"Rectangle information:"<<endl;
    cout<<"left = "<<left<<endl;
    cout<<"right = "<<right<<endl;
    cout<<"bot = "<<bot<<endl;
    cout<<"top = "<<top<<endl;
}
void Rectangle::showShape()
{
    cout<<"This is a rectangle"<<endl;
}

Rectangle::~Rectangle()
{
    
}


Trapezoid::Trapezoid(Point a, Point b, Point c, Point d)
{
    p1.set(a.x, a.y);
    p2.set(b.x, b.y);
    p3.set(c.x, c.y);
    p4.set(d.x, d.y);
}
double Trapezoid::getArea()
{
    return triarea(p1, p2, p4) + triarea(p2, p3, p4);
}
double Trapezoid::getPerim()
{
    return distance(p1, p2) + distance(p2, p3) + distance(p3, p4) + distance(p4, p1);
}
void Trapezoid::printShapeInfo()
{
    cout<<"Trapezoid information:"<<endl;
    cout<<"p1("<<p1.x<<", "<<p1.y<<")"<<"   "<<"p2("<<p2.x<<", "<<p2.y<<")"<<endl;
    cout<<"p3("<<p3.x<<", "<<p3.y<<")"<<"   "<<"p4("<<p4.x<<", "<<p4.y<<")"<<endl;
}
void Trapezoid::showShape()
{
    cout<<"This is a trapezoid"<<endl;
}
Trapezoid::~Trapezoid()
{
    
}

Triangle::Triangle(Point a, Point b, Point c)
{
    p1.set(a.x, a.y);
    p2.set(b.x, b.y);
    p3.set(c.x, c.y);
}
double Triangle::getArea()
{
    double a,b,c;
    a = sqrt((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
    b = sqrt((p3.x-p1.x)*(p3.x-p1.x) + (p3.y-p1.y)*(p3.y-p1.y));
    c = sqrt((p2.x-p3.x)*(p2.x-p3.x) + (p2.y-p3.y)*(p2.y-p3.y));
    return 0.25*sqrt((a+b+c)*(a+b-c)*(a+c-b)*(b+c-a));
}
double Triangle::getPerim()
{
    return distance(p1, p2) + distance(p2, p3) + distance(p3, p1);
}
void Triangle::printShapeInfo()
{
    cout<<"Triangle information:"<<endl;
    cout<<"p1("<<p1.x<<", "<<p1.y<<")"<<endl;
    cout<<"p2("<<p2.x<<", "<<p2.y<<")"<<endl;
    cout<<"p3("<<p3.x<<", "<<p3.y<<")"<<endl;
}
void Triangle::showShape()
{
    cout<<"This is a triangle"<<endl;
}
Triangle::~Triangle()
{
    
}



int main(int argc, const char * argv[])
{
    // Question 1
    cout<<"**************** Question 1 ****************"<<endl;
    //192 219 273 327 783 792 798 819 918 978
    int num = 192;
    //cin>>num;
    containAllNums(num);
    /*
    for(int i = 0; i < 1000; i++)
        containAllNums(i);
    */
    
    
    // Question 2
    cout<<"**************** Question 2 ****************"<<endl;
    vector<int> nums, result;
    int K = 7;
    generateNums(nums, 30, 1, 100);
    int res = findKnums(nums, K, result);
    cout<<"The sum of k max nums is :"<<res<<endl;

    
    // Question 3
    cout<<"**************** Question 3 ****************"<<endl;
    string s = "aabbabcbaabaaacbab";
    string t = "bab";
    string v = "abdc";
    cout<<"Before replace s = "<<s<<endl;
    replace(s, t, v);
    cout<<"After replace s = "<<s<<endl;
    testForQuestion3();
    
    
    // Question 4
    cout<<"**************** Question 4 ****************"<<endl;
    string s1 = "guihun";
    String ss1(s1.c_str());
    cout<<"The length of ss1 is "<<ss1.getLength()<<endl;
    string s2 = "quxiaokun";
    String ss2(s2.c_str());
    String ss3(ss2);
    cout<<"The length of ss3 is "<<ss3.getLength()<<endl;
    String ss4 = ss3;
    cout<<"The length of ss4 is "<<ss4.getLength()<<endl;
    cout<<endl;
    
    Point a,b,c,d;
    a.set(0,0);
    b.set(1,0);
    c.set(1,1);
    d.set(0,1);
    double r = 1;
    Shape *sp;
    
    Circle cir(a, r);
    sp = &cir;
    sp->showShape();
    sp->printShapeInfo();
    cout<<"The circle area = "<<cir.getArea()<<endl;
    cout<<"The circle perimeter = "<<cir.getPerim()<<endl;
    cout<<endl;
    
    Rectangle rec(0,2,0,2);
    sp = &rec;
    sp->showShape();
    sp->printShapeInfo();
    cout<<"The rectangle area = "<<sp->getArea()<<endl;
    cout<<"The rectangle perimeter = "<<sp->getPerim()<<endl;
    cout<<endl;
    
    
    Triangle tri(a,b,d);
    sp = &tri;
    sp->showShape();
    sp->printShapeInfo();
    cout<<"The triangle area = "<<sp->getArea()<<endl;
    cout<<"The triangle perimeter = "<<sp->getPerim()<<endl;
    cout<<endl;
    
    
    return 0;
}
