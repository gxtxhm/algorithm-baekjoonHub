#include <string>
#include <vector>

using namespace std;

string solution(string s, vector<int> n) {
    string answer = "";
    for(int i=0;i<n.size();i++)
    {
        s[n[i]]='1';
    }
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!='1')answer+=s[i];
    }
    return answer;
}