#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    int oN=0,cN=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        {
            oN++;
        }
        else
        {
            cN++;
            if(oN<cN)
                return false;
        }
    }
    if(oN==cN)
        return true;
    else 
        return false;
}