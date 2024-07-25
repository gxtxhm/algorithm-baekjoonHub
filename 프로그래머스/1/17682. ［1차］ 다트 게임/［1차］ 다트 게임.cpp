#include <string>

using namespace std;

int convert(char c,int n)
{
    if(c=='S')
        return n;
    else if(c=='D')
        return n*n;
    else 
        return n*n*n;
}

int solution(string dartResult) {
    int answer = 0;
    
    int prev=0,cur=0;
    
    string s;
    for(int i=0;i<dartResult.length();i++)
    {
        
        if(dartResult[i]=='S'||dartResult[i]=='D'||dartResult[i]=='T')
        {
            answer+=prev;
            prev=cur;
            cur = stoi(s);
            cur = convert(dartResult[i],cur);
            s="";
        }
        else if(dartResult[i]>='0'&&dartResult[i]<='9')
        {
            s+=dartResult[i];
        }
        else if(dartResult[i]=='*')
        {
            prev*=2;
            cur*=2;
        }
        else if(dartResult[i]=='#')
        {
            cur*=-1;
        }
    }
    answer+=prev+cur;
    
    return answer;
}