#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, vector<pair<int, int>>> um;
    unordered_map<string, int> sum;

    for (int i = 0; i < genres.size(); i++)
    {
        if (um.find(genres[i]) == um.end())
        {
            vector<pair<int, int>>v;
            v.push_back({ i,plays[i] });
            um.insert({ genres[i],v });
            sum.insert({ genres[i],plays[i] });
        }
        else
        {
            um[genres[i]].push_back({ i,plays[i] });
            sum[genres[i]] += plays[i];
        }
    }

    vector<pair<string, vector<pair<int, int>>>> uv;
    for (auto item : um)
    {
        uv.push_back(item);
    }
    
    sort(uv.begin(), uv.end(),
        [&sum]
        (pair<string, vector<pair<int, int>>>& a, pair<string, vector<pair<int, int>>>& b)
        {
            
            if (sum[a.first] > sum[b.first])return true;
            else return false;
        });

    for (int i = 0; i < uv.size(); i++)
    {
        sort(uv[i].second.begin(), uv[i].second.end(), []
        ( pair<int, int>& a, pair<int, int>& b)
            {
                if (a.second == b.second)
                    return a.first < b.first;
                else if (a.second > b.second)
                    return true;
                else
                    return false;
            });

        answer.push_back(uv[i].second[0].first);
        if(uv[i].second.size()==1)continue;
        answer.push_back(uv[i].second[1].first);
    }

    return answer;
}