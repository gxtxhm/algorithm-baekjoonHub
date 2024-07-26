#include <string>
#include <vector>
#include <map>
using namespace std;

// 1. 선물지수 알아내기
// 2. 선물을 더 많이준쪽이 하나 받음
// 3. 같거나 없다면 선물지수 많은쪽이 받음
// 4. 지수도 같다면 x

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    // 준 수, 받은 수
    map<string, pair<int, int>> num;
    // 기준 이름, 기준이 선물준 이름, 줬는지여부, 몇개
    map<string, map<string, pair<bool, int>>> rela;

    for (int i = 0; i < friends.size(); i++)
    {
        num.insert({ friends[i],{0,0} });
        map<string, pair<bool, int>> c;
        for (int j = 0; j < friends.size(); j++)
        {
            if (friends[i] != friends[j])
                c.insert({ friends[j],{false,0} });
        }
        rela.insert({ friends[i],c });
    }

    for (int i = 0; i < gifts.size(); i++)
    {
        int idx = gifts[i].find(' ');
        string a = gifts[i].substr(0, idx);
        string b = gifts[i].substr(idx + 1);

        rela[a][b].first = true;
        rela[b][a].first = true;
        rela[a][b].second++;
        num[a].first++;
        num[b].second++;
    }
    int max = -1;
    for (int i = 0; i < friends.size(); i++)
    {
        int cnt = 0;
        int giftNum = num[friends[i]].first - num[friends[i]].second;
        for (int j = 0; j < friends.size(); j++)
        {
            if (friends[i] != friends[j])
            {
                // 선물교류가 있었다
                if (rela[friends[i]][friends[j]].first == true)
                {
                    // i 가 더 많이 줬다.
                    if (rela[friends[i]][friends[j]].second > rela[friends[j]][friends[i]].second)
                    {
                        cnt++;
                    }
                    else if (rela[friends[i]][friends[j]].second ==
                        rela[friends[j]][friends[i]].second)
                    {
                        int n1 = num[friends[j]].first - num[friends[j]].second;
                        if (giftNum > n1)
                            cnt++;
                    }
                }
                else
                {
                    int n1 = num[friends[j]].first - num[friends[j]].second;
                    if (giftNum > n1)
                        cnt++;
                }
            }
        }
        if (cnt > max)
            max = cnt;
    }

    return max;
}