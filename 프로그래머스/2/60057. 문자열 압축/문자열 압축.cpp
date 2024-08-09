#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 1001;
    
    if(s.length()==1)
        return 1;
    
    for(int i=1;i<=s.length()/2;i++)
    {
        string temp = "";
        int j;
        for(j=0;j<=s.length()-i;j+=i)
        {
            int cnt=1;
            while(s.substr(j,i)==s.substr(j+i,i))
            {
                cnt++; j+=i;
            }
            if(cnt>1)
            {
                temp += to_string(cnt) + s.substr(j-i,i);
            }
            else
                temp+=s.substr(j,i);
        }
        if(j>s.length()-i)
            temp+=s.substr(j);
        if(temp.length()<answer)
            answer=temp.length();
    }
    
    return answer;
}