#include <iostream>

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

int main(int argc, const char * argv[])
{
    string s1,s2;
    s1 = "abc";
    s2 = "abc";
    cout<<strcmpg(s1.c_str(),s2.c_str())<<endl;
    return 0;
}
