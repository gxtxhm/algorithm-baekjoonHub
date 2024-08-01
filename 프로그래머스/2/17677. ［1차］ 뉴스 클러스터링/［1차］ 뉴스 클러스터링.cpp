#include <string>
#include <cctype>
#include <unordered_map>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    unordered_map<string, int> um1;
    unordered_map<string, int> um2;

    for (int i = 0; i < str1.length() - 1; i++)
    {
        string s;
        s += str1[i];
        s += str1[i + 1];
        if (str1[i] == ' ' || str1[i + 1] == ' ')continue;
        if (isalpha(str1[i]) && isalpha(str1[i + 1]))
        {
            s[0] = tolower(s[0]);
            s[1] = tolower(s[1]);

            if (um1.find(s) != um1.end())
                um1[s]++;
            else
                um1.insert({ s,1 });
        }
    }
    for (int i = 0; i < str2.length() - 1; i++)
    {
        string s;
        s += str2[i];
        s += str2[i + 1];
        if (isalpha(str2[i])&& isalpha(str2[i + 1]))
        {
            s[0] = tolower(s[0]);
            s[1] = tolower(s[1]);

            if (um2.find(s) != um2.end())
                um2[s]++;
            else
                um2.insert({ s,1 });
        }
    }
    int a = 0, b = 0;
    unordered_map<string, int> temp;
    if (um1.size() > um2.size())
    {
        temp = um1;
        um1 = um2;
        um2 = temp;
    }
    for (auto& item : um1)
    {
        if (um2.find(item.first) != um2.end())
        {
            a += min(item.second, um2[item.first]);
        }
        else
            b += item.second;

    }
    for (auto& item : um2)
    {
        if (um1.find(item.first) != um1.end())
        {
            b += max(item.second, um1[item.first]);
        }
        else
            b += item.second;
    }
    if (a == 0 && b == 0)return 65536;
    answer = (int)(((float)a / b) * 65536);
    return answer;
}