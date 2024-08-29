#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> graph(n+1);
    vector<int> dist(n+1,-1);
    queue<int> q;
    
    for(auto& item : edge)
    {
        graph[item[0]].push_back(item[1]);
        graph[item[1]].push_back(item[0]);
    }
    
    q.push(1);
    dist[1]=0;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(int neighbor : graph[cur])
        {
            if(dist[neighbor]==-1)
            {
                dist[neighbor]= dist[cur]+1;
                q.push(neighbor);
            }
        }
    }
    int maxNum=0;
    for(int i=1;i<n+1;i++)
    {
        if(maxNum<dist[i])
            maxNum=dist[i];
    }
    
    for(int i=1;i<n+1;i++)
    {
        if(maxNum==dist[i])
            answer++;
    }
    
    return answer;
}