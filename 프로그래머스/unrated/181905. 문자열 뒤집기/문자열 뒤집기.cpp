#include <string>
#include <vector>

using namespace std;

string solution(string m, int s, int e) {
    string answer = "";
    for (int i = s; i <= (s + e) / 2; i++)
    {
        char a = m[i];
        m[i] = m[e - (i - s)];
        m[e - (i - s)] = a;
    }
    return m;
}