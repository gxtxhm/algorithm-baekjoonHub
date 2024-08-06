#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> um;
    for (int i = 0; i < 26; i++)
        um[string(1, (char)('A' + i))] = i + 1;

    int v = 27;
    string w="";
    for(int i=0;i<msg.length();i++)
    {
        w+=msg[i];
        if(um.find(w)==um.end())
        {
            um[w]=v++;
            w.pop_back();
            answer.push_back(um[w]);
            w=msg[i];
        }
    }
    answer.push_back(um[w]);
    return answer;
}