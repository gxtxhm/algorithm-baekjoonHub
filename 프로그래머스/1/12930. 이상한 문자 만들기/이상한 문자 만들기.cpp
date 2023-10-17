#include <string>
#include <vector>
#include <cctype>
using namespace std;

string solution(string s) {
    string answer = "";

    int cnt = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            cnt = 0;
        }

        else
        {
            if (cnt % 2 == 0)
                s[i] = (char)toupper(s[i]);
            else
                s[i] = (char)tolower(s[i]);
            cnt++;
        }
    }

    return s;
}