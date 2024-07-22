#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(int i=0;i<s.length();i++)
    {
        int cnt=0;
        while(cnt<index)
        {
            s[i]++;
            if(s[i]>122)s[i]-=26;
            bool b=false;
            for(int j=0;j<skip.length();j++)
            {
                if(s[i]==skip[j])
                {
                    b=true;break;
                }
            }
            if(b)continue;
            cnt++;
                
        }
    }
    
    return s;
}