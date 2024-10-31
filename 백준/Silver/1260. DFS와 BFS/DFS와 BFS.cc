#include<bits/stdc++.h>
using namespace std;

void dfs(int start,vector<bool>& ch,vector<vector<int>>& g)
{
    if(ch[start]==true)return;
    
    ch[start]=true;
    cout<<start<<" ";
    for(int i=0;i<g[start].size();i++)
    {
        if(ch[g[start][i]]==false)
            dfs(g[start][i],ch,g);
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n,m,v;cin>>n>>m>>v;
    
    vector<vector<int>> graph(n+1,vector<int>());
    vector<bool>ch(n+1,false);
    for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        graph[a].push_back(b);graph[b].push_back(a);
    }
	for(int i=1;i<=n;i++)
    {
        sort(graph[i].begin(),graph[i].end());
    }
    dfs(v,ch,graph);
    cout<<"\n";
    
    vector<bool>ch2(n+1,false);
    queue<int> q;
    
    q.push(v);
    ch2[v]=true;
    while(!q.empty())
    {
        int x= q.front();q.pop();
        cout<<x<<" ";
        for(int i=0;i<graph[x].size();i++)
        {
            if(ch2[graph[x][i]]==false)
            {
                q.push(graph[x][i]);ch2[graph[x][i]]=true;
            }
        }
    }
    
    
	return 0;
}