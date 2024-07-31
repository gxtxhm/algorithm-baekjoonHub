#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    map<string, int> m;
    vector<pair<int, string>> cacheList;

    if (cacheSize == 0)
        return cities.size() * 5;

    for (int i = 0; i < cities.size(); i++)
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
    int i;
    for (i = 0; m.size()<cacheSize; i++)
    {
        if (m.find(cities[i]) != m.end())
        {
            answer += 1;
            m[cities[i]] = i;
            for (int j = 0; j <cacheList.size(); j++)
                if (cacheList[j].second == cities[i])
                    cacheList[j].first = i;
        }
        else
        {
            answer += 5;
            m.insert({ cities[i],i });
            cacheList.push_back({ i,cities[i] });
        }

    }

    for (; i < cities.size(); i++)
    {
        // 캐시 히트
        if (m.find(cities[i]) != m.end())
        {
            answer += 1;
            m[cities[i]] = i;
            for (int j = 0; j < cacheSize; j++)
                if (cacheList[j].second == cities[i])
                    cacheList[j].first = i;
        }
        // 캐시 미스
        else
        {
            answer += 5;
            int minId = 0;
            // 가장오래된거 빼고 새로 넣어야함
            for (int j = 1; j < cacheSize; j++)
            {
                if (cacheList[minId].first > cacheList[j].first)
                    minId = j;
            }
            m.erase(cacheList[minId].second);
            cacheList[minId] = make_pair(i, cities[i]);

            m.insert({ cities[i],i });
        }
    }

    return answer;
}