//
//  main.cpp
//  week_4
//
//  Created by 曲晓昆 on 2019/12/3.
//  Copyright © 2019 曲晓昆. All rights reserved.
//


#include"iostream"
#include"vector"
#include"cassert"
#include"queue"
#include"algorithm"
#include"point.h"
#include"fstream"
#include"stdlib.h"
#include"map"
#include"set"
#include <utility>
using namespace std;

long long sequenceRec(long long n)
{
    assert(n > 0);
    if(n <= 2)
        return n-1;
    return sequenceRec(n-1) + sequenceRec(n-2);
}

long long sequenceNoRec(long long n)
{
    assert(n > 0);
    if( n <= 2)
        return n-1;
    long long a = 0, b =1;
    long long num;
    for(int i = 1; i < n; i++)
    {
        num = a;
        a = b;
        b += num;
    }
    return a;
}

int findKnum(vector<int>& nums, int k)
{
#if 0
    assert(nums.size() > k);
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
#else 
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
    return q.top();
#endif
}

// Dynamic programming
int maxSubArray(vector<int>& nums)
{
#if 1
    int result = INT_MIN;
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    result = dp[0];
    for(int i = 1; i < nums.size(); i++)
    {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        result = max(result, dp[i]);
    }
    return result;
#endif
#if 0
    int result = INT_MIN;
    int dp(nums[0]);
    result = dp;
    for(int i = 1; i < nums.size(); i++)
    {
        dp = max(dp + nums[i], nums[i]);
        result = max(result, dp);
    }
    return result;
#endif
}

// Brute force
int maxSubArray2(vector<int>& nums)
{
    int max = INT_MIN;
    for(int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for(int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if(sum > max)
            {
                max = sum;
            }
        }
    }
    return max;
}

static bool cmp(const MyPoint p1, const MyPoint p2)
{
    if(p1.x() == p2.x())
        return p1.y() < p2.y();
    else
        return p1.x() < p2.x();
}

void writeSortPoints(vector<MyPoint>& points, string s)
{
    sort(points.begin(), points.end(), cmp);
    ofstream ofs;
    ofs.open(s.c_str(), ios::out);
    for(int i = 0; i < points.size(); i++)
    {
        ofs<<points[i].x()<<", "<<points[i].y()<<endl;
    }
    ofs.close();
}

bool isIntersectArray(const vector<MyPoint>& fstVec, const vector<MyPoint>& scdVec)
{
    // 是否两组点列中有相同的点表示相交，因为第一组点也不是一条直线上的
    if(fstVec.size() == 0 || scdVec.size() == 0)
        return false;
    vector<MyPoint> points = fstVec;
    points.insert(points.end(), scdVec.begin(), scdVec.end());
    sort(points.begin(), points.end(), cmp);
    int x = points[0].x();
    int y = points[0].y();
    for(unsigned int i = 1; i < points.size(); i++)
    {
        if(x == points[i].x())
        {
            if(y == points[i].y())
                return true;
        }
        else
        {
            x = points[i].x();
            y = points[i].y();
        }
    }
    return false;
}

// input format
/*  n1 n2 represent the number of two sets of points to be read in later
 n1 n2
 2 3
 4 5
 67 -23
 */
void readWriteSortPoints(string readFile, string writeFile)
{
    MyPoint p(2,3);
    vector<MyPoint> points;
    vector<MyPoint> fstVec, scdVec;
    int n1, n2;
    ifstream infile;
    infile.open("a.log");
    infile>>n1;
    infile>>n2;
    int x,y;
    for(int i = 0; i < n1; i++)
    {
        infile>>x;
        infile>>y;
        p.setX(x);
        p.setY(y);
        fstVec.push_back(p);
        points.push_back(p);
    }
    for(int i = 0; i < n2; i++)
    {
        infile>>x;
        infile>>y;
        p.setX(x);
        p.setY(y);
        scdVec.push_back(p);
        points.push_back(p);
    }
    infile.close();
    
    sort(points.begin(), points.end(), cmp);
    ofstream ofs;
    ofs.open(writeFile.c_str(), ios::out);
    for(int i = 0; i < points.size(); i++)
    {
        ofs<<points[i].x()<<", "<<points[i].y()<<endl;
    }
    bool flag = isIntersectArray(fstVec, scdVec);
    if(flag)
    {
        ofs<<"True";
    }
    else
    {
        ofs<<"FALSE";
    }
    ofs.close();
}

// Not done
double stringToDouble(string s)
{
    
    return 0;
}

int main()
{

    // Question 1
    cout<<"******Question 1******"<<endl;
    long long n = 15;
    long long num = sequenceRec(n);
    cout<<num<<endl;
    
    num = sequenceNoRec(n);
    cout<<num<<endl;
    
    
    // Question 2
    cout<<"******Question 2******"<<endl;
    int k = 2;
    int kNum;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(-5);
    nums.push_back(9);
    nums.push_back(8);
    nums.push_back(3);
    nums.push_back(-6);
    kNum = findKnum(nums, k);
    cout<<kNum<<endl;
    
    
    // Question 3
    cout<<"******Question 3******"<<endl;
    int res;
    res = maxSubArray(nums);
    cout<<res<<endl;
    
    
    // Question 4
    cout<<"******Question 4******"<<endl;
#if 0
    MyPoint p(2,1);
    vector<MyPoint> points;
    int x,y;
    int N;
    cout<<"Please input the number of points: ";
    cin>>N;
    if(N < 0)
    {
        cout<<"The number of points should more than 0"<<endl;
        return 0;
    }
    for(int i = 0; i < N; i++)
    {
        cin>>x;
        cin>>y;
        p.setX(x);
        p.setY(y);
        points.push_back(p);
    }
    writeSortPoints(points, "result.log");
#endif
    
    readWriteSortPoints("a.log", "result.log");
    
    
    // Question 5
    cout<<"******Question 5******"<<endl;
    string s = "1.5E3";
    double e = stringToDouble(s);
    cout<<e<<endl;
    
    return 0;
}

