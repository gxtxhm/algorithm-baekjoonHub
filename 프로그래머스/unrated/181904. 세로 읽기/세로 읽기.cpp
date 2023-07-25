#include <string>
#include <vector>

using namespace std;

string solution(string s, int m, int c) {
    string answer = "";
    for(int i=0;i<s.length();)
    {
        answer+=s[i+c-1];
        i+=m;
    }
    return answer;
}