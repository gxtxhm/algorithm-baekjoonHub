#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";
    
    bool first=true;
    
    for(int i=0;i<s.length();i++)
    {
        if(first&&s[i]!=' ')
        {
            if(isalpha(s[i])&&islower(s[i]))
            {
                s[i]-=32;
            }
            first=false;
        }
        else
        {
            if(s[i]==' ')
                first=true;
            else if(isalpha(s[i]))
                s[i]=tolower(s[i]);
        }
    }
    
    return s;
}