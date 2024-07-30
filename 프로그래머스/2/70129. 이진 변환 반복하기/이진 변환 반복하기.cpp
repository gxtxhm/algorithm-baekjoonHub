#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int convCnt=0;
    int eraseZero=0;
    
    while(s!="1")
    {
        int len=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='0')len++;
            else eraseZero++;
        }
    
        int num = len;
        string con;
        while(num>0)
        {
            con+=(num%2)+'0';
            num/=2;
        }
        // string reverse
        for(int i=0;i<con.length()/2;i++)
        {
            char c = con[i];
            con[i]= con[con.length()-1-i];
            con[con.length()-1-i]=c;
        }
        s=con;
        convCnt++;
    }
    answer.push_back(convCnt);
    answer.push_back(eraseZero);
    return answer;
}