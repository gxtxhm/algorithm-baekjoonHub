#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n,m;cin>>n>>m;
    
    vector<vector<int>> arr(n,vector<int>(m,0));
    vector<vector<bool>> ch(n,vector<bool>(m,false));
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        for(int j=0;j<m;j++)
            arr[i][j] = s[j]-'0';
    }
	
    queue<pair<int,int>>q;
    
    q.push({0,0});
    ch[0][0]=true;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    dp[0][0]=1;
    while(!q.empty())
    {
        pair<int,int> x = q.front();q.pop();
        for(int i=0;i<4;i++)
        {
            if(x.first + dx[i] >=0 && x.first + dx[i] < n && 
               x.second + dy[i] >=0 && x.second + dy[i]<m && 
               arr[x.first+dx[i]][x.second+dy[i]]==1
              && ch[x.first+dx[i]][x.second+dy[i]]==false)
            {
                q.push({x.first+dx[i],x.second+dy[i]});
                ch[x.first+dx[i]][x.second+dy[i]]=true;
                dp[x.first+dx[i]][x.second+dy[i]]=dp[x.first][x.second]+1;
                if(x.first+dx[i]==n-1 && x.second+dy[i] == m-1)
                {
                    cout<<dp[x.first+dx[i]][x.second+dy[i]];return 0;
                }
            }
        }
    }
    
    
	return 0;
}