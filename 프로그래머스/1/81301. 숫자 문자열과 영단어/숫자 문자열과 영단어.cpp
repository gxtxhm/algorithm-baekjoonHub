#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string s) {
    int answer = 0;
    map<string,int> m;
    m.insert({"one",1});
    m.insert({"two",2});
    m.insert({"three",3});
    m.insert({"four",4});
    m.insert({"five",5});
    m.insert({"six",6});
    m.insert({"seven",7});
    m.insert({"eight",8});
    m.insert({"nine",9});
    m.insert({"zero",0});
    string si="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            answer*=10;
            answer+=s[i]-'0';
        }
        else
        {
            si+=s[i];
            if(m.find(si)!=m.end())
            {
                answer*=10;
                answer+=m[si];
                si="";
            }
        }
    }
    
    return answer;
}