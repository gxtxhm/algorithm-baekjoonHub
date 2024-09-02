#include <iostream>
#include <vector>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    vector<vector<int>> dist(N+1,vector<int>(N+1,1e9));
    
    for(auto& item :road)
    {
        if(dist[item[0]][item[1]]!=1e9)
        {
            if(dist[item[0]][item[1]]>item[2])
            {
                dist[item[0]][item[1]]=item[2];
                dist[item[1]][item[0]]=item[2];
            }
        }
        else
        {
            dist[item[0]][item[1]]=item[2];
            dist[item[1]][item[0]]=item[2];
        }
    }
    for(int i=1;i<=N;i++)
        dist[i][i]=0;
    
    for(int k=1;k<=N;k++)
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                if(dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
    
    for(int i=1;i<=N;i++)
        if(dist[1][i]<=K)
            answer++;

    return answer;
}