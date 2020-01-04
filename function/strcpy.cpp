#include"iostream"

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

int main(int argc, const char * argv[])
{
    
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
        

    return 0;
}

