
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int before = 0;

    for (int i = 0; i < s.length();)
    {
        string t = "";
        while (i < s.length() && s[i] != ' ')
        {
            t += s[i];
            i++;
        }
        if (t == "Z")answer -= before;
        else
        {
            int n = stoi(t);
            answer += n;
            before = n;
        }
        i++;
    }

    return answer;
}