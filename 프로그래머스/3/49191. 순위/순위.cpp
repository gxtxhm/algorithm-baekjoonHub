#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer=0;
    
    vector<unordered_set<int>> wins(n+1);
    vector<unordered_set<int>> loses(n+1);
    
    for(auto& item : results)
    {
        // wins[n] : n 이 이긴 선수목록
        wins[item[0]].insert(item[1]);
        // loses[n] : n 을 이긴 선수목록
        loses[item[1]].insert(item[0]);
    }
    
    for(int i=1;i<=n;i++)
    {
        // n 이 이긴선수는 n을 이긴 선수모두도 이긴것으로 간주
        for(int c : loses[i])wins[c].insert(wins[i].begin(),wins[i].end());
        // n이 패배한 선수를 이긴 선수들을 n도 이겼다고 간주
        for(int c : wins[i])loses[c].insert(loses[i].begin(),loses[i].end());
    }
    
    for(int i=1;i<=n;i++)
    {
        if(wins[i].size()+loses[i].size()==n-1)
            answer++;
    }
    
    return answer;
}