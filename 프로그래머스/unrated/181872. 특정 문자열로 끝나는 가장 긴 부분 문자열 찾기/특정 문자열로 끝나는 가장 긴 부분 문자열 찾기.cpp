#include <string>
#include <vector>

using namespace std;

string solution(string s, string pat) {
    string answer = "";
    int idx = 0;
    int before = 0;
    while (string::npos != (idx = s.find(pat, idx)))
    {
        
        idx += pat.length();
        before = idx;
    }
    return s.substr(0, before);
}