#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void convertSharp(string &s)
{
    string ss="";
    
    for(int i=0;i<s.length();i++)
    {
        if(i<s.length()-1 && s[i+1]=='#')
        {
            ss+=s[i]+32;i++;
        }
        else
            ss+=s[i];
    }
    s=ss;
}

string conS(string& s)
{
    string c = "";
    int i = 0;
    for (i = 0; i < s.length(); i++)
    {
        if (s[i] == ',')break;
        else c += s[i];
    }
    if (i < s.length())
        s = s.substr(i + 1);
    return c;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    convertSharp(m);
    int longestTime =-1;
    for (string s : musicinfos)
    {
        string startT, endT;
        string title = "", song = "";
        
        startT = (conS(s));
        endT = (conS(s));
        title = conS(s);
        song = conS(s);
        int t = stoi(endT.substr(0, 2)) * 60 + stoi(endT.substr(3));
        t -= stoi(startT.substr(0, 2)) * 60 + stoi(startT.substr(3));
        string so = "";
        convertSharp(song);
        for (int i = 0; i < t; i++)
            so += song[i % song.length()];
        if(so.find(m)!=string::npos)
        {
            if(longestTime < t)
            {
                longestTime = t;
                answer = title;
            }
        }
    }
    if (longestTime == -1)return "(None)";

    return answer;
}