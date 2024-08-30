#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string,vector<string>> graph;
vector<string> answer;
bool dfs(string node, int cnt,int total)
{
    if(cnt==total)
        return true;
    
    for(int i=0;i<graph[node].size();i++)
    {
        string next = graph[node][i];
        
        graph[node].erase(graph[node].begin()+i);
        answer.push_back(next);
        
        if(dfs(next,cnt+1,total))
            return true;
        
        answer.pop_back();
        graph[node].insert(graph[node].begin()+i,next);
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    
    for(auto& item : tickets)
        graph[item[0]].push_back(item[1]);
    
    for(auto& item : graph)
        sort(item.second.begin(),item.second.end());
    
    answer.push_back("ICN");
    dfs("ICN",0,tickets.size());
    
    return answer;
}