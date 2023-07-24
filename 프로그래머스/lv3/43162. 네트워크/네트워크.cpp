#include <string>
#include <vector>
#include<queue>
using namespace std;

int check[201];

int BFS(int startId,int n,vector<vector<int>> com)
{
    if(check[startId]==1)return 0;
    
    queue<int> q;
    q.push(startId);
    check[startId]=1;
    
    while(!q.empty())
    {
        int id = q.front();q.pop();
        
        for(int i=0;i<com[id].size();i++)
        {
            if(com[id][i]==1&&check[i]!=1)
            {
                check[i]=1;
                q.push(i);
            }
        }
    }
    return 1;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<n;i++)
    {
        answer+=BFS(i,n,computers);
    }
    
    return answer;
}