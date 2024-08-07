#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool compare(const pair<string,int>& a, const pair<string,int>& b)
{
    return a.second < b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> v;
    map<string, int> m;
    string ss = "";
    int n = 0;
    for (int i = 1; i < s.length() - 1; i++)
    {
        if (s[i] == '}')
        {
            m.insert({ ss,n }); ss = ""; i++; n = 0;
        }
        else if (s[i] != '{')
        {
            ss += s[i];
            if (s[i] != ',')n++;
        }
        
    }

    vector<pair<string, int>> mv(m.begin(), m.end());
    sort(mv.begin(), mv.end(), compare);

    unordered_set<string> us;
    for (const auto& item : mv)
    {
        vector<string> iv; ss = "";
        for (int i = 0; i < item.first.length(); i++)
        {
            if (item.first[i] == ',')
            {
                iv.push_back(ss); ss = "";
            }
            else ss += item.first[i];
        }
        iv.push_back(ss);
        for (int i = 0; i < iv.size(); i++)
        {
            if (us.find(iv[i]) == us.end())
            {
                us.insert(iv[i]);
                answer.push_back(stoi(iv[i]));
            }
        }
    }
    return answer;
}