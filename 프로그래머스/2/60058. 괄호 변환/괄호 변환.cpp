#include <string>
#include <vector>

using namespace std;

string solution(string p) {
    string u = "";
    if(p=="")return "";
    // 분리
    int cnt=0;
    bool b = true;
    string v="";
    for(int i=0;i<p.length();i++)
    {
        if(p[i]=='(')cnt++;
        else cnt--;
        u+=p[i];
        if(cnt<0){b=false;}
        if(cnt==0){
            v = p.substr(i+1);
            break;
        }
    }
    string result = solution(v);
    // u가 올바른 괄호 문자열이면
    if(b)
        return u+result;
    else
    {
        string im="(";
        im+=result;
        im+=")";
        u = u.substr(1,u.length()-2);
        for(int i=0;i<u.length();i++)
        {
            if(u[i]=='(')u[i]=')';
            else u[i]='(';
        }
        return im+=u;
    }
    return "";
}