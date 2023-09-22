#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int c1,c2;
    c1=c2=0;
    
    for(int i=0;i<s.length();i++)
    {
        s[i] = tolower(s[i]);
        
        if(s[i]=='p')c1++;
        if(s[i]=='y')c2++;
    }
    

    return (c1==c2);
}