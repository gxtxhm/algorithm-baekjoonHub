#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    long long answer = 0;
    long long pi = stoll(p);
    for(int i=0;i<t.length()-p.length()+1;i++)
    {
        string c = t.substr(i,p.length());
        if(stoll(c)<=pi)
            answer++;
    }
    return answer;
}