#include <string>
#include <vector>

using namespace std;

int solution(string s, string pat) {
    int answer = 0;
    for(int i=0;i<s.length();i++)
    {
        if(s.substr(i,pat.length())==pat)answer++;
    }
    return answer;
}