#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 1;
    unordered_map<int,int> um;
    for(int it : tangerine)
        um[it]++;
    
    vector<pair<int,int>> v;
    for(auto& it : um)
        v.push_back(it);
    
    sort(v.begin(),v.end(),[](auto& a,auto& b){return a.second>b.second;});
    
    int sum=v[0].second;
    if(sum>=k)
        return 1;
    for(int i=1;i<v.size();i++)
    {
        if(k>sum+v[i].second)
        {
            sum+=v[i].second;
            answer++;
        }
        else
        {
            answer++;
            break;
        }
    }
    return answer;
}