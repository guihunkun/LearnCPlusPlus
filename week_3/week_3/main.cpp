//
//  main.cpp
//  week_3
//
//  Created by 曲晓昆 on 2019/11/25.
//  Copyright © 2019 曲晓昆. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

int strcmpg(const char *p1, const char *p2)
{
    int res = 0;
    while(!(res = *p1 - *p2) && *p1)
    {
        p1++;
        p2++;
    }
    return res;
}

int count(long long num)
{
    int n;
    if(num == 0)
        return 0;
    n = 1;
    while(num/=10)
    {
        n++;
    }
    return n;
}

void printThousands(long long num, int cnt)
{
    bool flag = num > 0?true:false;
    int n = count(num);
    if(n <= cnt)
    {
        cout<<num<<endl;
        return ;
    }
    if(!flag)
        cout<<"-";
    num = abs(num);
    int N = n+n/cnt;
    if(n%cnt == 0)
        N--;
    vector<char> record(N);
    int dig, j = 0;
    for(int i = 0; i < N; i++)
    {
        if(j == cnt)
        {
            record.push_back(',');
            j = 0;
        }
        else
        {
            dig = num%10;
            record.push_back(dig - 0 + '0');
            j++;
            num /= 10;
        }
    }
    reverse(record.begin(), record.end());
    for(int i = 0; i < record.size(); i++)
    {
        cout<<record[i];
    }
    cout<<endl;
}

bool isPalindrome(long long x)
{
#if 1
    if(x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }
    long long revertedNumber = 0;
    while(x > revertedNumber)
    {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }
    // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
    // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
    // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
    return x == revertedNumber || x == revertedNumber/10;
#endif
    
#if 0
    if (x < 0)
        return false;
    long long div = 1;
    while (x / div >= 10)
    {
      div *= 10;
    }
    while (x != 0)
    {
      long long l = x / div;
      long long r = x % 10;
      if (l != r)
          return false;
      x = (x % div) / 10;
      div /= 100;
    }
    return true;
#endif
}

void printPalindrome(long long left, long long right)
{
    for(long long i = left; i <= (int)pow(right, 1.0/3); i++)
    {
        if(isPalindrome(i) && isPalindrome(pow(i,2)) && isPalindrome(pow(i,3)))
            cout<<i<<" ";
    }
    cout<<endl;
}


int main(int argc, const char * argv[])
{
    // Question 1
    string s1,s2;
    s1 = "abf";
    s2 = "abc";
    cout<<strcmpg(s1.c_str(),s2.c_str())<<endl;
    
    // Qusetion 2
    printThousands(-7654321, 3);
    
    // Question 3
    printPalindrome(11, 99999);
    
    return 0;
}
