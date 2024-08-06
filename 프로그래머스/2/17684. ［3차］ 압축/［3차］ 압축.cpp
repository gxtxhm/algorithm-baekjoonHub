#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> um;
    for (int i = 0; i < 26; i++)
        um[string(1, (char)('A' + i))] = i + 1;

    int idP = 0;
    int v = 27;
    while (msg.length() != 0)
    {
        idP = 0;
        string s = "";
        s = msg[idP];
        while (um.find(s) != um.end())
        {
            s += msg[++idP];
        }
        um.insert({ s,v++ });
        msg = msg.substr(s.length() - 1);
        answer.push_back(um[s.substr(0,s.length()-1)]);
    }

    return answer;
}