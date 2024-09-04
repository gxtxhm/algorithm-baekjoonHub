#include <string>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    vector<vector<int>> dist(n+1,vector<int>(n+1,1e8));
    for (auto& item : fares)
    {
        dist[item[0]][item[1]] = item[2];
        dist[item[1]][item[0]] = item[2];
    }
    
    for(int i=1;i<=n;i++)dist[i][i]=0;
    
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
    
    // 각자 타고 갈때 비용을 초기값으로
    answer=dist[s][a]+dist[s][b];
    
    for(int k=1;k<=n;k++)
    {
        if(dist[s][k]+dist[k][a]+dist[k][b]<answer)
            answer=dist[s][k]+dist[k][a]+dist[k][b];
    }
    
    return answer;
}