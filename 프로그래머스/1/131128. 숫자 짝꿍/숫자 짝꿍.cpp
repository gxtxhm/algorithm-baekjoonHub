#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> a(10,0);
    vector<int> b(10,0);
    
    for(int i=0;i<X.length();i++)
    {
        a[X[i]-'0']++;
    }
    for(int i=0;i<Y.length();i++)
    {
        b[Y[i]-'0']++;
    }
    
    for(int i=9;i>=0;i--)
    {
        if(a[i]>=1&&b[i]>=1)
        {
            int j = (a[i]>b[i])?b[i]:a[i];
            for(int k=0;k<j;k++)
                answer+=i+'0';
        }
    }
    if(answer=="")return "-1";
    for(int i=0;i<answer.length();i++)
    {
        if(answer[i]!='0')return answer;
    }
    return "0";
}