#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    string num ="0123456789ABCDEF";
    string s="0";
    for(int i=1;i<=t*100;i++)
    {
        string temp="";
        int tn = i;
        while(tn>0)
        {
            temp += num[tn%n];
            tn/=n;
        }
        reverse(temp.begin(),temp.end());
        s+=temp;
    }
    for(int i=p-1;i<s.length();i+=m)
    {
        answer+=s[i];
        if(answer.length()==t)break;
    }
    
    return answer;
}